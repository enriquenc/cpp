//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_ASCIIUP_H
#define EX03_ASCIIUP_H


#include "Symbol.h"

class AsciiUp: public Symbol {
public:
    AsciiUp(void);
    ~AsciiUp(void);

    void action(char **array);
    void push_back(std::ifstream &file) { file.close(); }
};


#endif //EX03_ASCIIUP_H
