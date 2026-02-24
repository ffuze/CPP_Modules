#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array
{
    private:
        T* elements;
        unsigned int _size;
    public:
        Array() : elements(NULL), _size(0) {}
        Array(unsigned int n) : elements(new T[n]), _size(n) {}
        Array(const Array<T>& copy) : elements(NULL), _size(0)
        {
            *this = copy;
        }
        ~Array()
        {
            delete[] (elements);
        }
        Array<T>& operator=(const Array<T>& obj)
        {
            if (this != &obj)
            {
                delete[] (elements);
                _size = obj._size;
                if (_size > 0)
                {
                    elements = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        elements[i] = obj.elements[i];
                }
                else
                    elements = NULL;
            }
            return (*this);
        }
        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw (std::exception());
            return (elements[index]);
        }
        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw (std::exception());
            return (elements[index]);
        }
        unsigned int size() const
        {
            return (_size);
        }
};

#endif