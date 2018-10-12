// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 13:36:38 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 13:36:39 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"
#include <algorithm>
#include <iostream>

Span::Span(void) {}

Span::Span(unsigned int n):_n(n) {}

Span::Span(Span const &obj)
{
    *this = obj;
}

Span::~Span(void) {}

Span& Span::operator=(Span const &obj) {
    _n = obj._n;
    return *this;
}

void Span::addNumber(int nbr)
{
    if (_store.size() < _n)
        _store.push_back(nbr);
    else
        throw std::out_of_range("the array is full.");
}

int Span::shortestSpan()
{
    if (_store.size() <= 1)
        throw std::out_of_range("there is no span to find.");
    std::sort(_store.begin(), _store.end());
    std::vector<int>::iterator start;
    int shortest_span;
    shortest_span = _store.back();
    for(start = _store.begin(); start < _store.end() - 1; start++)
    {
        if (shortest_span > (*(start + 1) - *start))
            shortest_span = *(start + 1) - *start;
    }
    return shortest_span;
}

int Span::longestSpan()
{
    if (_store.size() <= 1)
        throw std::out_of_range("there is no span to find.");
    std::sort(_store.begin(), _store.end());
    return (_store.back() - _store.front());
}

void Span::addWithIter(std::vector<int>::iterator begin , std::vector<int>::iterator end)
{
    if(begin > end)
        throw std::out_of_range("bad begin and end.");
    while(begin != end)
    {
        addNumber(*begin);
        begin++;
    }
}