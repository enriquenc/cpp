//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_ASCIIDOWN_H
#define EX03_ASCIIDOWN_H

#include "Symbol.h"

class AsciiDown: public Symbol {
public:
    AsciiDown(void);
    ~AsciiDown(void);

    void action(char **array);
    void push_back(std::ifstream &file) { file.close(); }
};


#endif //EX03_ASCIIDOWN_H
