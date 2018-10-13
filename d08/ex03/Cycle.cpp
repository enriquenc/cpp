//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "Symbol.h"
#include "AsciiDown.h"
#include "AsciiUp.h"
#include "GetChar.h"
#include "PutChar.h"
#include "PointerToLeft.h"
#include "PointerToRight.h"
#include "Cycle.h"

#include <iostream>

Cycle::Cycle() {
    _symbol = '{';
    _end_symbol = '}';
}

Cycle::~Cycle() {}

void Cycle::action(char **array) {
    int i = 0;
    while(1)
    {
        buf[i]->action(array);
        i++;
        if (i == static_cast<int>(buf.size()))
        {
            i = 0;
            if (!**array)
                break;
        }
    }
        
}

char Cycle::getEndSymbol() const {
    return _end_symbol;
}

void Cycle::push_back(std::ifstream &file) {
    char ch;
    while(file.get(ch))
    {
        switch (ch)
        {
            case 'r':
                buf.push_back(new PointerToRight());
                break;
            case 'l':
                buf.push_back(new PointerToLeft());
                break;
            case 'u':
                buf.push_back(new AsciiUp());
                break;
            case 'd':
                buf.push_back(new AsciiDown());
                break;
            case '*':
                buf.push_back(new PutChar());
                break;
            case '_':
                buf.push_back(new GetChar());
                break;
            case '{':
                buf.push_back(new Cycle());
                buf.back()->push_back(file);
            case '}':
                return;
        }
    }
}