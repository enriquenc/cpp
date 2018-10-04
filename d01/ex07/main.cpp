// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/03 18:43:24 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/03 18:43:25 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    std::stringstream buffer;
    std::string str;
    std::string file_name;
    std::string to_find;
    std::string to_change;
    size_t  start_pos = 0;
    if (argc == 4)
    {
        file_name = argv[1];
        to_find = argv[2];
        to_change = argv[3];

        std::ifstream file(file_name.c_str());
        buffer << file.rdbuf();
        if(errno)
                std::cerr << argv[0] << ": " << file_name << ' ' << std::strerror(errno) << std::endl;
        str = buffer.str();
        while((start_pos = str.find(to_find, start_pos)) != std::string::npos) {
            str.replace(start_pos, to_find.length(), to_change);
            start_pos += to_change.length();
        }
        file_name += ".replace";
        std::ofstream out(file_name.c_str());
        out << str;
        out.close();
        file.close();
    }
    else
        std::cout << "Usage: ./replace [filename] [s1] [s2]" << std::endl;
    return 0;
}
