//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "Symbol.h"

Symbol& Symbol::operator=(Symbol const &obj){ static_cast<void>(obj);
    return  *this;}

Symbol::Symbol() {

}

Symbol::~Symbol() {}

char Symbol::getSymbol() const {
    return _symbol;
}

void Symbol::setSymbol(char symbol)
{
    _symbol = symbol;
}