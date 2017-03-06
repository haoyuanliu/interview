#include "ini_parser.h"
#include <string>

namespace qh
{
    bool Parse(const char* ini_data, size_t ini_data_len,
        const std::string& line_seperator = "\n", const std::string& key_value_seperator = "=")
    {
        std::string iniStr(ini_data, ini_data_len);
        return true;
    }
}
