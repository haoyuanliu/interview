#include "qh_string.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

namespace qh
{
    // TODO 将在这里写实现代码

    string::string()
        : data_(NULL), len_(0)
    {
    }

    string::string( const char* s )
    {
        if(s == NULL)
            return;
        len_ = strlen(s);
        data_ = new char[len_ + 1];
        strcpy(data_, s);
    }

    string::string( const char* s, size_t len )
    {
        if(s == NULL)
            return;
        len_ = len;
        data_ = new char[len + 1];
        strncpy(data_, s, len_);
    }

    string::string( const string& rhs )
    {
        if(rhs.data_ == NULL)
            return;
        len_ = rhs.size();
        data_ = new char[len_ + 1];
        strcpy(data_, rhs.data_);
    }

    string& string::operator=( const string& rhs )
    {
        if(this != &rhs)
        {
            if(len_ < rhs.len_)
            {
                delete[] data_;
                data_ = new char[rhs.len_ + 1];
            }
            len_ = rhs.len_;
            strcpy(data_, rhs.data_);
        }
        return *this;
    }

    string::~string()
    {
        delete[] data_;
        data_ = NULL;
        len_ = 0;
    }

    size_t string::size() const
    {
        return len_;
    }

    const char* string::data() const
    {
        return data_;
    }

    const char* string::c_str() const
    {
        return data_;
    }

    char& string::operator[]( size_t index )
    {
        assert(index > 0 && index < len_);
        return data_[index];
    }
}
