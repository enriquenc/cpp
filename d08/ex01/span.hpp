// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 13:36:42 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 13:36:43 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include 

class Span
{
private:

    unsigned int _n;
public:
    std::vector<int> _store;



    Span(void);
    Span(unsigned int n);
    Span(Span const &obj);
    ~Span(void);
    Span &operator=(Span const &obj);

    void addNumber(int nbr);
    int shortestSpan(void);
    int longestSpan(void);
    void addWithIter(std::vector<int>::iterator begin , std::vector<int>::iterator end);
};

#endif