// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 16:59:16 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 16:59:17 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Pony.hpp"

void Pony::live()
{
    setAge(getAge() + 1);
    std::cout << "Yeaah boy. " << getName() << " got older by a year. " << "I am " << getAge() << '.' << std::endl;
}
void Pony::eat(float foods_weight)
{
    setWeight(getWeight() + foods_weight);
    std::cout << "Yeahh boy. " << getName() << " ate and became heavier. " << "My weight: " << getWeight() << '.' << std::endl;
}
void Pony::have_some_fun()
{
    setCheer(getCheer() + 1);
    std::cout << "Yeahh boy. " << getName() << " had some fun and became happier. " << "My cheer: " << getCheer() << '.' << std::endl;
}

Pony::Pony(std::string p_name, int p_weight, int p_age, int p_cheer)
{
    this->name = p_name;
    setWeight(p_weight);
    setAge(p_age);
    setCheer(p_cheer);
    std::cout << "Yeah. I am alive! My name is " << getName() << ", my weight - " 
    << getWeight() << " my cheer - " << getCheer() << ", I am " << getAge() << '.' << std::endl;
}

Pony::~Pony(void)
{
    std::cout << "Goodbye! " << getName() << " died." << std::endl;
}

const float &Pony::getWeight(void) const
{
    return this->weight;
}
const int &Pony::getAge(void) const
{
    return this->age;
}
const int &Pony::getCheer(void) const
{
    return this->cheer;
}
const std::string &Pony::getName(void) const
{
    return this->name;
}
void Pony::setWeight(const float &p_weight)
{
    this->weight = p_weight;
}
void Pony::setAge(const int &p_age)
{
    this->age = p_age;
}
void Pony::setCheer(const float &p_cheer)
{
    this->cheer = p_cheer;
}