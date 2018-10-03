// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:11:52 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 19:11:52 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger
{
private:
	std::string name;

	void logToConsole(std::string str);
	void logToFile(std::string str);
	std::string makeLogEntry(std::string str);
public:
	Logger(std::string name);
	void log(std::string const & dest, std::string const & message);
};

#endif