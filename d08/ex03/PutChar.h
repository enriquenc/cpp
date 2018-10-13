//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_PUTCHAR_H
#define EX03_PUTCHAR_H

#include "Symbol.h"

class PutChar: public Symbol {
public:
    PutChar(void);
    ~PutChar(void);

    void action(char **array);
    void push_back(std::ifstream &file) { file.close(); }
};


#endif //EX03_PUTCHAR_H
