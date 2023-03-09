# ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

using std::string;

class Harl
{

public:
    void complain( string level );

private:
    static void debug( void );
    static void info( void );
    static void warning( void );
    static void error( void );

};

#endif
