// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 13:23:21 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 13:23:21 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>

typename T::iterator easyfind(T &cont, int to_find)
{
    return std::find(cont.begin(),cont.end(), to_find);
}

#endif