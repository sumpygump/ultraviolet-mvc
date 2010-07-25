#ifndef UV_INI_H_
#define UV_INI_H_

#include <string>
#include <map>

namespace uv
{

class Ini
{
  protected:
    std::map<std::string, std::string> keyValuePairs;
    
    std::string filename;
    
    void readFile();
    
  public:
    Ini(std::string filename);
    
    std::map<std::string, std::string> getPairs();
};

}

#endif // UV_INI_H_
