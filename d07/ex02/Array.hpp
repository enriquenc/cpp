// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/11 18:23:09 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/11 18:23:10 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array
{
private:

    unsigned int _n;
    T* array;

public:

    Array<T>(void)
    {
        _n = 0;
        array = new T(_n);
    }
    Array<T>(unsigned int n)
    {
        _n = n;
        array = new T[_n];
    }
    Array<T>(Array const & obj)
    {
        *this = obj;
    }
    Array &operator=(Array const & obj)
    {
        _n = obj._n;
        delete array;
        array = new T[_n];
        for(unsigned int i = 0; i < _n; i++)
            array[i] = obj.array[i];
        return *this;
    }

    unsigned int const &size(void) const
    {
        return _n;
    }

    T &operator[](long long int index)
    {
        if (index >= 0 && index < _n)
            return array[index];
        else
            throw std::overflow_error("Error: array index out of bounds.");
    }


};

#endif