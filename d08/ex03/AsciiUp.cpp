//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "AsciiUp.h"

AsciiUp::AsciiUp(void) {
    _symbol = 'u';
}

AsciiUp::~AsciiUp() {}

void AsciiUp::action(char **array)
{
    (**array)++;
}