// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 13:37:00 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 13:37:01 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "span.hpp"
#include <iostream>
#include <ctime>

int main()
{
    srand(time(NULL));
    int n = 1000;
    std::vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(rand() % n);

    Span d(n);
    d.addWithIter(v.begin(), v.end());
    std::cout << d.shortestSpan() << std::endl;
    std::cout<< d.longestSpan() << std::endl;

    return 0;
}