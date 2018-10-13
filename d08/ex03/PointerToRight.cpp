//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "PointerToRight.h"


PointerToRight::PointerToRight()
{
    _symbol = 'r';
}

PointerToRight::~PointerToRight() {}

void PointerToRight::action(char **array)
{
    (*array)++;
}
