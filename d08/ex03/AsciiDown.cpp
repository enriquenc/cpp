//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "AsciiDown.h"

AsciiDown::AsciiDown()
{
    _symbol = 'd';
}

AsciiDown::~AsciiDown() {}

void AsciiDown::action(char **array)
{
    (**array)--;
}