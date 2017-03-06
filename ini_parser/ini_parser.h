#ifndef QIHOO_INI_PARSER_H_
#define QIHOO_INI_PARSER_H_

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <tr1/unordered_map>

namespace qh
{
    class INIParser
    {
    public:
        INIParser()
        {
        }
        ~INIParser()
        {
        }

        //! \brief 解析一个磁盘上的INI文件
        //! \param[in] - const std::string & ini_file_path
        //! \return - bool
        bool Parse(const std::string& ini_file_path)
        {
            /*FILE *fp = NULL;
            fp = fopen(ini_file_path.data(), "r");
            if(fp == NULL)
                return false;

            fseek(fp, 0L, SEEK_END);
            size_t flen = ftell(fp);

            char *str = new char[flen];
            fseek(fp, 0L, SEEK_SET);
            fread(str, flen-1, 1, fp);
            str[flen] = 0;*/
            std::string str;
            std::ifstream readFile(ini_file_path.data());
            if(!readFile)
                return false;
            while(readFile >> str)
            {
                //std::cout << str << std::endl;
                size_t found;
                while((found = str.find("\\n")) != std::string::npos)
                {
                    str = str.substr(0, found) + '\n' + str.substr(found + 2);
                }
                //std::cout << str << " " << str.size() << std::endl;
                if(!Parse(str.data(), str.size()))
                    return false;
            }

            return true;
        }

        //! \brief 解析一段形如INI格式的内存数据。
        //!   例如：ini_data="a:1||b:2||c:3"
        //!         调用<code>Parse(ini_data, ini_data_len, "||", ":")</code>即可解析出这段数据。
        //!         解析完毕之后
        //!         Get("a")=="1" && Get("b")=="2" && Get("c")=="3"
        //! \param[in] - const char * ini_data
        //! \param[in] - size_t ini_data
        //! \param[in] - const std::string & line_seperator
        //! \param[in] - const std::string & key_value_seperator
        //! \return - bool
        bool Parse(const char* ini_data, size_t ini_data_len,
            const std::string& line_seperator = "\n", const std::string& key_value_seperator = "=")
        {
            //printf("%s %d\n", ini_data, (int)ini_data_len);
            bool ret = false;
            std::set<std::string> keyAndValues;
            std::string iniStr(ini_data, ini_data_len);
            iniStr += line_seperator;

            size_t found;
            while((found = iniStr.find(line_seperator)) != std::string::npos)
            {
                //std::cout << iniStr.substr(0, found) << std::endl;
                keyAndValues.insert(iniStr.substr(0, found));
                iniStr = iniStr.substr(found + std::string(line_seperator).size());
            }
            std::set<std::string>::iterator it;
            for(it = keyAndValues.begin(); it != keyAndValues.end(); ++it)
            {
                std::string temp = *it;
                if((found = temp.find(key_value_seperator)) == std::string::npos)
                    continue;
                //std::cout << key_value_seperator.size() << std::endl;
                //std::cout << found << " " << key_value_seperator.size() << std::endl;
                keyToValue_[temp.substr(0, found)] = temp.substr(found + key_value_seperator.size());
                ret = true;
                //std::cout << temp.substr(0, found) << " " << temp.substr(found + key_value_seperator.size()) << std::endl;
            }


            return ret;
        }

        //! \brief 从默认section中查找某个key，并返回找到的value。如果找不到，返回一个空串
        //! \param[in] - const std::string & key
        //! \param[in] - bool * found - 输出参数，true表明找到这个key
        //! \return - const std::string& - 返回的具体key对应的value
        const std::string& Get(const std::string& key, bool* found)
        {
            if(keyToValue_.find(key) == keyToValue_.end())
                if(found)
                    *found = false;
            if(found)
                *found = true;
            return keyToValue_[key];
        }

        //const std::string& Get(const std::string& section, const std::string& key, bool* found);

    private:
        std::tr1::unordered_map<std::string, std::string> keyToValue_;
    };
}

#endif
