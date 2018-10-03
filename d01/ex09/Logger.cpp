// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 19:11:43 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 19:11:43 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger(std::string name)
{
	this->name = name;
}

void Logger::logToConsole(std::string str)
{
	std::cout << makeLogEntry(str);
}

std::string Logger::makeLogEntry(std::string str)
{
	std::string s;

	time_t curr_time;
    curr_time = time(NULL);

    tm *tm_local = localtime(&curr_time);
    s = "[" + std::to_string(tm_local->tm_year + 1900) + ' ' + std::to_string(tm_local->tm_mon + 1) + ' '
    + std::to_string(tm_local->tm_mday) + '_' + std::to_string(tm_local->tm_hour) + ':' + std::to_string(tm_local->tm_min)
	+ ':' + std::to_string(tm_local->tm_sec) + "] ";
	
	s += str;
	return s; 
}

void Logger::logToFile(std::string str)
{
	std::ofstream file(this->name);
	file << makeLogEntry(str);
	file.close();
}

void Logger::log(std::string const & dest, std::string const & message)
{
	std::string logTypes[] = {"logToConsole", "logToFile"};

	typedef void (Logger::*ptr)(std::string str);
	ptr logs[] = {&Logger::logToConsole, &Logger::logToFile};

	for(int i = 0; i < 2; i++)
		if(logTypes[i] == dest)
		{
			(this->*(logs[i]))(message);
			break;
		}
}