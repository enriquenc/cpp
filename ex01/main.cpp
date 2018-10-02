// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/01 13:26:58 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/01 13:26:59 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Person.hpp"
#include <iomanip>
#include <iostream>

void get_input(std::string &input, std::string text)
{
    std::cout << text;
    if (!(std::getline(std::cin, input)))
        exit (0);
}

void add_user(Person &user)
{
    std::string input;

    get_input(input, "Enter your first name: ");
    user.setFirst_name(input);
    get_input(input, "Enter your last name: ");
    user.setLast_name(input);
    get_input(input, "Enter your nickname: ");
    user.setNickname(input);
    get_input(input, "Enter your login: ");
    user.setLogin(input);
    get_input(input, "Enter your postal address: ");
    user.setPostal_address(input);
    get_input(input, "Enter email address: ");
    user.setEmail_address(input);
    get_input(input, "Enter your phone number: ");
    user.setPhone_number(input);
    get_input(input, "Enter your birthday date: ");
    user.setBirthday_date(input);
    get_input(input, "Enter your favorite meal: ");
    user.setFavorite_meal(input);
    get_input(input, "Enter your underwear color: ");
    user.setUnderwear_color(input);
    get_input(input, "Enter yout darkest secret: ");
    user.setDarkest_secret(input);
}


void print_user(std::string inf)
{
    if (inf.size() > 10)
    {   
        inf[9] = '.';
        inf.resize(10);
    }
    std::cout << std::setw(10) << inf << "|";
}

void print_all(Person *phonebook, int id)
{
    std::cout << "First name: " << phonebook[id].getFirst_name() << std::endl;
    std::cout << "Last name: " << phonebook[id].getLast_name() << std::endl;
    std::cout << "Nickname: " << phonebook[id].getNickname() << std::endl;
    std::cout << "Login: " << phonebook[id].getLogin() << std::endl;
    std::cout << "Postal address: " << phonebook[id].getPostal_address() << std::endl;
    std::cout << "Email address: " << phonebook[id].getEmail_adress() << std::endl;
    std::cout << "Phone number: " <<phonebook[id].getPhone_number() << std::endl;
    std::cout << "Birthday date: " << phonebook[id].getBirthday_date() << std::endl;
    std::cout << "Favorite meal: " << phonebook[id].getFavorite_meal() << std::endl;
    std::cout << "Underwear color: " << phonebook[id].getUnderwear_color() << std::endl;
    std::cout << "Darkest secret: " << phonebook[id].getDarkest_secret() << std::endl;
    
}

void print_all_users(Person *phonebook, int nbr)
{
    std::setfill(' ');
    for (int i = 0; i < nbr; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|";  
        print_user(phonebook[i].getFirst_name());
        print_user(phonebook[i].getLast_name());
        print_user(phonebook[i].getNickname());
        std::cout << std::endl;
    }
}

int main(void)
{
    Person phonebook[8];
    int nbr = 0;
    std::string input;

    while(std::getline(std::cin, input))
    {
        if (input == "EXIT")
            return 0;
        else if (input == "ADD")
        {
            
            if (nbr >= 8)
                std::cout << "Can’t store more than 8 contacts" << std::endl;
            else
            {
                add_user(phonebook[nbr]);
                nbr++;
            }   
        }
        else if (input == "SEARCH")
        {
            if (nbr == 0)
            {
                std::cout << "Phonebook is empty." << std::endl;
                continue ;
            }
            print_all_users(phonebook, nbr);
            std::cout << "Enter index: ";
            if (!(std::getline(std::cin, input)))
                break ;
            if (input[0] > '0' && input[0] < '9' && input[1] == '\0')
                print_all(phonebook, input[0] - 48 - 1); 
            else
                std::cout << "Bad index" << std::endl;
        }
        else
            std::cout << "Wrong command. Input is discarded." << std::endl;
        
    }
    return 0;
}