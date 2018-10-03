// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:12:02 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 19:12:03 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"

int main()
{
	Logger b("file");
	b.log("logToConsole", "stdout");
	b.log("logToFile", "file");
	return 0;
}