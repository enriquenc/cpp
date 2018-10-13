//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_POINTERTOLEFT_H
#define EX03_POINTERTOLEFT_H

#include "Symbol.h"

class PointerToLeft: public Symbol {
private:

public:
    PointerToLeft(void);
    ~PointerToLeft(void);

    void action(char **array);
    void push_back(std::ifstream &file) { file.close(); }
};


#endif //EX03_POINTERTOLEFT_H
