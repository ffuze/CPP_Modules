#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <class T>
class Array
{
    private:
        T* _elements;
        unsigned int _size;
    public:
        Array() : _elements(NULL), _size(0) {}
        Array(unsigned int n) : _elements(new T[n]), _size(n) {}
        Array(const Array<T>& copy) : _elements(NULL), _size(0)
        {
            *this = copy;
        }
        ~Array() { delete[] _elements; }
        Array<T>& operator=(const Array<T>& obj)
        {
            if (this != &obj)
            {
                delete[] _elements;
                _size = obj._size;
                if (_size > 0)
                {
                    _elements = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        _elements[i] = obj._elements[i];
                }
                else
                    _elements = NULL;
            }
            return (*this);
        }
        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return _elements[index];
        }
        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::exception();
            return _elements[index];
        }
        unsigned int size() const
        {
            return _size;
        }
};

#endif