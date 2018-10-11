// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/11 14:30:59 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/11 14:31:02 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <string>

template <typename F>
void function(F &b)
{
    b++;
}

template <typename T, typename L, typename N>
void iter(T *arr, L length, N (*func)(T&))
{
    for (int i = 0; i < length; i++)
        func(arr[i]);
}



int main( void ) {
    std::string a = "abc";
    for(int i = 0; i < 3; i++)
        std::cout << a[i];
    std::cout << std::endl;
    ::iter(&(a[0]), 3, function<char>);
    for(int i = 0; i < 3; i++)
        std::cout << a[i];

    std::cout << std::endl << std::endl;
    int b[] = {1, 2, 3};
    for(int i = 0; i < 3; i++)
        std::cout << b[i];
    std::cout << std::endl;
    ::iter(b, 3, function<int>);
    for(int i = 0; i < 3; i++)
        std::cout << b[i];
    return 0;
}
