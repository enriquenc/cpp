// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 16:59:08 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 16:59:09 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>


class Pony
{
private:

    float   weight;
    int     age;
    int     cheer;
    std::string name;

public:
    
    Pony(std::string p_name, int p_weight, int p_age, int p_cheer);
    ~Pony(void);

    void live();
    void eat(float foods_weight);
    void have_some_fun();
    
    const float &getWeight(void) const;
    const int &getAge(void) const;
    const int &getCheer(void) const;
    const std::string &getName(void) const;
    void setWeight(const float &p_weight);
    void setAge(const int &p_age);
    void setCheer(const float &p_cheer);
};

#endif