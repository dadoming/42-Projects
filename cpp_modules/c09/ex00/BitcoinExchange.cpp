#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    // add 
    (void)other;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return ("");
    size_t last = str.find_last_not_of(' ');
    return (str.substr(first, (last - first + 1)));
}

static std::multimap<std::string, float> loadMapFromFile(std::ifstream& file, char separator)
{
    std::multimap<std::string, float> retMap;
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        if (line.find_first_of("0123456789") == std::string::npos)
            continue;
        
        std::istringstream toSplitStream(line);
        std::string date;
        std::string valueStr;

        if(std::getline(toSplitStream, date, separator))
        {
            float value = -1;
            if (std::getline(toSplitStream, valueStr, separator))
            {
                std::istringstream valueStream(valueStr);
                valueStream >> value;
            }
            date = trim(date);
            retMap.insert(std::pair<std::string, float>(date, value));
        }
    }
    file.close();
    return (retMap);
}

bool verifyDate(std::string date)
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    std::istringstream yearStream(year);
    std::istringstream monthStream(month);
    std::istringstream dayStream(day);
    int yearInt = -1;
    int monthInt = -1;
    int dayInt = -1;
    yearStream >> yearInt;
    monthStream >> monthInt;
    dayStream >> dayInt;
    if (yearInt < 2009 || yearInt > 2022)
        return (false);
    if (monthInt < 1 || monthInt > 12)
        return (false);
    if (dayInt < 1 || dayInt > 31)
        return (false);
    if (yearInt == 2009 && monthInt == 1 && dayInt == 1) // because of first date in database
        return (false);
    return (true);
}

float getClosestValue(std::multimap<std::string, float> db, std::string date)
{
    std::string monthAndYear = date.substr(0, 7);
    int day = atoi((date.substr(8, 2)).c_str());

    std::multimap<std::string, float>::iterator db_it = db.begin();
    while (db_it != db.end())
    {
        std::string monthAndYearDatabase = db_it->first.substr(0, 7);
        if (monthAndYearDatabase == monthAndYear)
        {
            int dayDatabase = atoi((db_it->first.substr(8, 2)).c_str());
            while (dayDatabase <= day)
            {
                ++db_it;
                dayDatabase = atoi((db_it->first.substr(8, 2)).c_str());
            }
            return ((--db_it)->second);
        }
        ++db_it;
    }
    return (0);   
}

void BitcoinExchange::exchange(const char* filename){

    std::ifstream infile;
    infile.open(filename, std::ifstream::in);
    if (!infile.is_open())
    {
        std::cerr << "Error opening " << filename << " file" << std::endl;
        return;
    }
    std::multimap<std::string, float> inputMap = loadMapFromFile(infile, '|');

    
    std::ifstream databaseFile;
    databaseFile.open("data.csv", std::ifstream::in);
    if (!databaseFile.is_open())
    {
        std::cerr << "Error opening data.csv file" << std::endl;
        return;
    }
    std::multimap<std::string, float> databaseMap = loadMapFromFile(databaseFile, ',');


    for (std::map<std::string, float>::iterator it = inputMap.begin(); it != inputMap.end(); ++it)
    {
        try
        {
            if (verifyDate(it->first) == false)
                throw BadInputException();
            if (it->second < 0)
                throw NotPositiveException();
            if (it->second > 1000)
                throw NumberTooBigException();
            
            std::multimap<std::string, float>::iterator databaseIt = databaseMap.find(it->first);
            if (databaseIt == databaseMap.end())
            {
                std::cout << it->first << " => " << it->second << " = " << it->second * getClosestValue(databaseMap, it->first)<< std::endl;
            }
            else 
                std::cout << it->first << " => " << it->second << " = " << databaseIt->second * it->second << std::endl;
        }
        catch(const BadInputException& e)
        {
            std::cerr << "Error: " << e.what() << it->first << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

const char* BitcoinExchange::NotPositiveException::what() const throw(){
    return ("Not a positive number");
}

const char* BitcoinExchange::BadInputException::what() const throw(){
    return ("Bad input => ");
}

const char* BitcoinExchange::NumberTooBigException::what() const throw(){
    return ("Number too big");
}
