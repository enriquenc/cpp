// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 20:53:59 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 20:54:00 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include <iostream> 
#include <fstream> 
#include <vector> 

#include "Symbol.h"
#include "AsciiDown.h"
#include "AsciiUp.h"
#include "GetChar.h"
#include "PutChar.h"
#include "PointerToLeft.h"
#include "PointerToRight.h"
#include "Cycle.h"



int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Usage: ./mindopen [file]" << std::endl;
        return 0;
    }
    char *cpu = new char[30000];
    std::vector<Symbol *> acc;
    char ch;
    std::ifstream file;
    file.open(argv[1]);
    if (!file)
    {
        std::cout << "Bad input file." << std::endl;
        return 0;
    }
    while(file.get(ch))
    {
        switch (ch)
        {
            case 'r':
                acc.push_back(new PointerToRight());
                break;
            case 'l':
                acc.push_back(new PointerToLeft());
                break;
            case 'u':
                acc.push_back(new AsciiUp());
                break;
            case 'd':
                acc.push_back(new AsciiDown());
                break;
            case '*':
                acc.push_back(new PutChar());
                break;
            case '_':
                acc.push_back(new GetChar());
                break;
            case '{':
                acc.push_back(new Cycle());
                acc.back()->push_back(file);
        }
    }
    file.close();
    for(int i = 0; i < static_cast<int>(acc.size()); i++)
        acc[i]->action(&cpu);
}