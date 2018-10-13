//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "PointerToLeft.h"

PointerToLeft::PointerToLeft(void)
{
    _symbol = 'l';
}

PointerToLeft::~PointerToLeft() {}

void PointerToLeft::action(char **array)
{
    (*array)--;
}