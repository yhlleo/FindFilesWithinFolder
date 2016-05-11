#include "FindFiles.h"
#include <iostream>
#include <vector>
#include <string>

int main( int argc, char **argv )
{
    FindFiles ff;

    std::vector<std::string> fileNames;
    if ( argc >= 2)
    {
        fileNames = ff.findFiles( argv[1] );
    }
    else
    {
        fileNames = ff.findFiles( "." );
    }

    for ( int i=0; i<fileNames.size(); i++ )
    {
        std::cout << fileNames[i] << std::endl;
    }
}