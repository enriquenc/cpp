// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/10 22:47:05 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/10 22:48:19 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>

class Base
{
public:
    virtual ~Base(){};
};

class A: public Base
{

};

class B: public Base
{

};

class C: public Base
{

};

Base * generate(void)
{
    int r = rand()%3;
    switch (r)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return NULL;
}

void identify_from_pointer(Base * p)
{
   if (dynamic_cast<A*>(p) == p)
       std::cout << 'A' << std::endl;
   else if (dynamic_cast<B*>(p) == p)
       std::cout << 'B' << std::endl;
   else if (dynamic_cast<C*>(p) == p)
       std::cout << 'C' << std::endl;
}

void identify_from_reference(Base & p)
{
	Base a;
    try {
        a = dynamic_cast<A&>(p);
        std::cout << 'A' << std::endl;
    }
    catch (const std::exception& e)
    {
        try {
            a = dynamic_cast<B&>(p);
            std::cout << 'B' << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << 'C' << std::endl;
        }
    }

}

int main() {
    srand(time(NULL));
    Base *random_class = generate();
    identify_from_reference(*random_class);
    identify_from_pointer(random_class);
    return 0;
}
