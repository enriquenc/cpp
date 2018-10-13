//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "PutChar.h"
#include <iostream>

PutChar::PutChar(void) {
    _symbol = '*';
}

PutChar::~PutChar() {}

void PutChar::action(char **array)
{
    std::cout << **array;
}

