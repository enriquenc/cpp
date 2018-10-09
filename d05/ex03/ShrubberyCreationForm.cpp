// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 13:36:57 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 13:36:58 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137)
{
    _target = "NO_TARGET";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137)
{
    _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & obj)
{
    *this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & obj)
{
    _target = obj._target;
    return *this;
}

void ShrubberyCreationForm::action(void) const
{
    std::ofstream file (_target + "_shrubbery");
    file << 
    "                             +\n \
                          +---+    +\n \
                      +    |---+   | +---+-+\n \
                +     +---+-+ | +-----+  |  +\n \
             +--+ +---+   |   | |  |     |  +------+\n \
            +  +----------+---+ +  |     +---+     |\n \
         + +++-+                 +-+     |        ++\n \
         |   |   +                       +-+      +-------+\n \
      +--+ +-+   |                               ++     +-+\n \
          +      |       +  +                    ||     |\n \
          |  +---+       |  +-----+       +      +------+\n \
      +   +  |           |                |      |      |    +\n \
      |  +   +-+         |      +         |      |  +   |    |\n \
     +++----+-+         ++      |         |      |  |   |    |\n \
       | |  |                   |         |      +------+-+  |\n \
       | +--+        +          |    ++---+         |        |\n \
       |             |     +----+     |    +        |    + +-+\n \
      ++ +  +---+    +              + |    |        +    |\n \
      ++ ++-------+                 | |    |             |\n \
    +-+   |         ++    +   ++ +--+ |    |     +-------+\n \
          |    +    |     |         +-+ +--+     |     +-+\n \
          | +--+    |     |         |-|          |       |\n \
        + +  +--+   |     |  +--------+    +     |       |\n \
        |           |     | ++       |    ++    ++  +----+\n \
       ++   +-----+-+-----+ ++  ++   +------+   |          +\n \
                  |       |     ||   |      | +-+      +   |\n \
          +---+   +-------+     ||   |  +---+       +--+---+\n \
                +         |  ++ ++   |     +--+ ++\n \
                +--+  +   |  ||      |\n \
                      +-+ |  ++      |\n \
                          |          |\n \
                          |          |\n \
                          |   +      |\n \
                          |   |      |\n \
                          |   +   +  |\n \
                          |       |  |\n \
                          |       +  |\n \
                          |    +     |\n \
                          |    +     |\n \
                          |          |\n \
                          |          |\n \
                          |          |\n \
                          +          |\n \
                        ++   ++  +-+ +-+\n \
                   +----------------------+\n \
               +---+ +-+  +---+  +--+  +--+ +--+\n";
    file.close();
}

std::string const &ShrubberyCreationForm::getTarget(void) const
{
    return _target;
}