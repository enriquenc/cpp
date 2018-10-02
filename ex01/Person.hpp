// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Person.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/01 13:30:30 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/01 13:30:31 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PERSON_CLASS_HPP
#define PERSON_CLASS_HPP

#include <string>

class Person
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;
    
    static int nbInst;
public:
    
    Person(void);
    ~Person(void);

    static int getNbInst(void);

    void setFirst_name(const std::string &first_name);
    void setLast_name(const std::string &last_name);
    void setNickname(const std::string &nickname);
    void setLogin(const std::string &login);
    void setPostal_address(const std::string &postal_address);
    void setEmail_address(const std::string &email_address);
    void setPhone_number(const std::string &phone_number);
    void setBirthday_date(const std::string &birthday_date);
    void setFavorite_meal(const std::string &favorite_meal);
    void setUnderwear_color(const std::string &underwear_color);
    void setDarkest_secret(const std::string &darkest_secret);

    const std::string &getFirst_name(void) const;
    const std::string &getLast_name(void) const;
    const std::string &getNickname(void) const;
    const std::string &getLogin(void) const;
    const std::string &getPostal_address(void) const;
    const std::string &getEmail_adress(void) const;
    const std::string &getPhone_number(void) const;
    const std::string &getBirthday_date(void) const;
    const std::string &getFavorite_meal(void) const;
    const std::string &getUnderwear_color(void) const;
    const std::string &getDarkest_secret(void) const;
};
#endif