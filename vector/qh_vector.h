#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

#include <assert.h>

namespace qh
{
    template<class T>
    class vector
    {
    public:
        //ctor
        vector() : data_(NULL), size_(0), capa_(0)
        {
        }

        explicit vector( size_t n, const T& value = T())
        {
            int capa = 1;
            while(capa < n)
                capa <<= 1;
            data_ = new T[capa];
            for (size_t i = 0; i < n; i++)
            {
                data_[i] = value;
            }
            size_ = n;
            capa_ = capa;
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
            int capa = 1;
            while(capa < rhs.size())
                capa <<= 1;
            data_ = new T[capa];
            for(int i = 0; i < rhs.size(); ++i)
                data_[i] = rhs[i];
            size_ = rhs.size_;
            capa_ = capa;
        }

        //dtor
        ~vector()
        {
            if (data_)
            {
                delete[] data_;
                data_ = NULL;
                capa_ = 0;
                size_ = 0;
            }
        }

        //get
        int size() const
        {
            return size_;
        }

        // set & get
        T& operator[](size_t index)
        {
            assert(index >= 0 && index < size_);
            return data_[index];
        }

        // set
        void push_back(const T& element)
        {
            if(size_ >= capa_)
                reserve(capa_ * 2 + 1);

            data_[size_++] = element;
        }
        void pop_back(T* element)
        {
            assert(size_ > 0);
            *element = data_[size_ - 1];
            size_--;
        }

        void resize(size_t newSize)
        {
            if(newSize <= capa_)
            {
                size_ = newSize;
                return;
            }
            reserve(capa_ * 2 + 1);
            capa_ = capa_ * 2 + 1;
            size_ = newSize;
        }

        void reserve(size_t newCapa)
        {
            if(capa_ >= newCapa)
                return;

            T* temp = data_;
            data_ = new T[newCapa];
            for(int i = 0; i < size_; ++i)
                data_[i] = temp[i];
            delete[] temp;
            capa_ = newCapa;
        }

        void clear()
        {
            for(int i = 0; i < size_; ++i)
                data_[i] = 0;
        }

        bool empty()
        {
            return size_ == 0;
        }

    private:
        T*      data_;
        size_t  size_;
        size_t  capa_;
    };
}

#endif
