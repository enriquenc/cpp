//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_CYCLE_H
#define EX03_CYCLE_H

#include "Symbol.h"
#include <vector>
#include <fstream>

class Cycle: public Symbol {
private:
    char _end_symbol;
    std::vector<Symbol *> buf;
public:

    Cycle(void);
    ~Cycle(void);

    void push_back(std::ifstream &file);

    char getEndSymbol(void) const;

    void action(char **array);
};


#endif //EX03_CYCLE_H
