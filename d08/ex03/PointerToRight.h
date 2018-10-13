//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_POINTERTORIGHT_H
#define EX03_POINTERTORIGHT_H


#include "Symbol.h"

class PointerToRight: public Symbol {
public:

    PointerToRight(void);
    ~PointerToRight();
    void action(char **array);
    void push_back(std::ifstream &file) { file.close(); }
};


#endif //EX03_POINTERTORIGHT_H
