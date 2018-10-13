//
// Created by Taras MASLYANKO on 10/13/18.
//

#ifndef EX03_SYMBOL_H
#define EX03_SYMBOL_H

#include <fstream>

class Symbol {
protected:

    char _symbol;

    Symbol &operator=(Symbol const & obj);
public:
    Symbol(void);
    virtual ~Symbol();

    virtual void action(char **array) = 0;
    void setSymbol(char symbol);
    char getSymbol(void) const;
    virtual void push_back(std::ifstream &file) = 0;
};



#endif //EX03_SYMBOL_H
