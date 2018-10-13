//
// Created by Taras MASLYANKO on 10/13/18.
//

#include "GetChar.h"
#include <iostream>

GetChar::GetChar() {
    _symbol = '_';
}

GetChar::~GetChar() {}

void GetChar::action(char **array) {
    std::cin >> **array;
}