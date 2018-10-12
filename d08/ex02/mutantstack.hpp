// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 18:06:25 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 18:06:25 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>

template <typename T>
class MutantStack: public std::stack<T> {
private:

    std::list<T> _list;

public:

    MutantStack(void) {}

    MutantStack(MutantStack const &obj) {
        *this = obj;
    }

    ~MutantStack(void) {}

    MutantStack &operator=(MutantStack const &obj) {
        std::stack<T>::_stack = obj.std::stack<T>::_stack;
        return *this;
    }

    void push( const T & value )
    {
        std::stack<T>::push(value);
        _list.push_back(value);
    }

    void pop(void)
    {
        std::stack<T>::pop();
        _list.pop_back();
    }

    typedef typename std::list<T>::iteratoіr iterator;

    iterator begin(void)
    {
        return (_list.begin());
    }

    iterator end(void)
    {
        return  (_list.end());
    }


};

#endif