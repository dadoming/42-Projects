# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm(target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    *this = other;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
    return ("Couldn't open file");
}

void ShrubberyCreationForm::nextPhase( void ) const
{
    std::string filename = getName() + "_shrubbery";
    std::ofstream ofs;
    
    ofs.open(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!ofs.is_open())
        throw FileNotOpenException();
    
    ofs << "          &&& &&  & &&" << std::endl;
    ofs << "     && &\\/&\\|& ()|/ @, &&" << std::endl;
    ofs << "     &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    ofs << "    &() &\\/&|()|/&\\/ '% '& ()" << std::endl;
    ofs << "   &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    ofs << "  &&   && & &| &| /& & % ()& /&&" << std::endl;
    ofs << "    ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    ofs << "         &&     \\|||" << std::endl;
    ofs << "                 |||" << std::endl;
    ofs << "                 |||" << std::endl;
    ofs << "                 |||" << std::endl;
    ofs << "        , -=-~  .-^- _" << std::endl;

    ofs.close();
}
