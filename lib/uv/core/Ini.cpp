#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "Ini.h"

uv::Ini::Ini(std::string filename)
{
    this->filename = filename;
    
    this->readFile();
}

void uv::Ini::readFile()
{
    std::ifstream iniStream;

    iniStream.open(this->filename.c_str());

    if (iniStream.is_open()) {
        
        char streamBuffer[256];
        std::stringstream lines;

        while (!iniStream.eof()) {
            //lines << streamBuffer;
            iniStream.getline(streamBuffer, 256);
            std::cout << "Last time, I saw this cool program and I read " << iniStream.gcount() << " characters.  Cool huh?  Looks like " << streamBuffer << std::endl; 
            
            if (iniStream.gcount() == 255 && !strchr(streamBuffer, '\n')) {
                iniStream.putback('\n');
            }
            
            //streamBuffer << std::endl;
        }
        
        //std::cout << lines << std::endl;

    }

    iniStream.close();
}

std::map<std::string, std::string> uv::Ini::getPairs()
{
    return this->keyValuePairs;
}

//std::string uv::Ini::readLine()
//{
    
//}