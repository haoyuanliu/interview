#include "ini_parser.h"

namespace qh
{
    INIParser::INIParser()
    {
    }
    INIParser::~INIParser()
    {
    }

    bool INIParser::Parse(const std::string& ini_file_path)
    {
        std::string str;
        std::ifstream readFile(ini_file_path.data());
        if(!readFile)
            return false;
        while(readFile >> str)
        {
            size_t found;
            while((found = str.find("\\n")) != std::string::npos)
            {
                str = str.substr(0, found) + '\n' + str.substr(found + 2);
            }
            if(!Parse(str.data(), str.size()))
                return false;
        }

        return true;
    }


    bool INIParser::Parse(const char* ini_data, size_t ini_data_len,
        const std::string& line_seperator, const std::string& key_value_seperator)
    {
        bool ret = false;
        std::set<std::string> keyAndValues;
        std::string iniStr(ini_data, ini_data_len);
        iniStr += line_seperator;

        size_t found;
        while((found = iniStr.find(line_seperator)) != std::string::npos)
        {
            keyAndValues.insert(iniStr.substr(0, found));
            iniStr = iniStr.substr(found + std::string(line_seperator).size());
        }
        std::set<std::string>::iterator it;
        for(it = keyAndValues.begin(); it != keyAndValues.end(); ++it)
        {
            std::string temp = *it;
            if((found = temp.find(key_value_seperator)) == std::string::npos)
                continue;
            keyToValue_[temp.substr(0, found)] = temp.substr(found + key_value_seperator.size());
            ret = true;
        }


        return ret;
    }

    const std::string& INIParser::Get(const std::string& key, bool* found)
    {
        if(keyToValue_.find(key) == keyToValue_.end())
            if(found)
                *found = false;
        if(found)
            *found = true;
        return keyToValue_[key];
    }

    const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
    {
        if(!Parse(section))
            return keyToValue_[""];
        return Get(key, found);
    }
}
