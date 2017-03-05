#include "ini_parser.h"


namespace qh
{
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
    bool INIParser::Parse(const char* ini_data, size_t ini_data_len,
        const std::string& line_seperator = "\n", const std::string& key_value_seperator = "=")
    {
        bool res = false;
        std::set<std::string> keyValues;
        std::string str(ini_data, ini_data_len);
        std::size_t found;
        do
        {
            keyValues.insert(std::string(str(str.begin(), str.begin() + found)));
            str = str.substr(str.begin() + found + sizeof(line_seperator));
        }
        while((found = str.find(line_seperator)) != std::string::npos);
        keyValues.erase("");
        for(int i = 0; i < keyValues.size(); ++i)
        {
            std::string s = keyValues[i];
            if((found = s.find(key_value_seperator)) == std::string::npos)
                continue;
            keyToValue_[s.substr(0, found)] = s.substr(0 + sizeof(key_value_seperator));
            res = true;
        }
        return res;
    }

    //! \brief 从默认section中查找某个key，并返回找到的value。如果找不到，返回一个空串
    //! \param[in] - const std::string & key
    //! \param[in] - bool * found - 输出参数，true表明找到这个key
    //! \return - const std::string& - 返回的具体key对应的value
    const std::string& INIParser::Get(const std::string& key, bool* found)
    {
        if(keyToValue_.find(key) != keyToValue_.end())
            *found = true;
        return keyToValue_[key];
    }

    const std::string& INIParser::Get(const std::string& section, const std::string& key, bool* found)
    {
        return Get(key, found);
    }
}
