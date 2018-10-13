//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_GETCHAR_H
#define EX03_GETCHAR_H

#include "Symbol.h"

class GetChar: public Symbol {
public:
    GetChar(void);
    ~GetChar(void);

    void action(char **array);
    void push_back(std::ifstream &file) { file.close(); }
};


#endif //EX03_GETCHAR_H
