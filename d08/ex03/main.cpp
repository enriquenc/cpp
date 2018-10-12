// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 20:53:59 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/12 20:54:00 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include <iostream> 
#include <fstream> 
#include <vector> 



static char cpu[30000]; 

int main(int argc, char **argv)  
{

    std::vector<char> acc;
    char ch;
    std::ifstream infile(argv[1]);
    while(infile)
    {
        infile.get(ch);
        acc.push_back(ch);
    }
    infile.close();
    unsigned int j = 0;
    int brc = 0;
    for(int i = 0; i < acc.size(); ++i)
    {
    
        if(acc[i] == '>') j++;
        if(acc[i] == '<') j--;
        if(acc[i] == '+') cpu[j]++;
        if(acc[i] == '-') cpu[j]--;
        if(acc[i] == '.') std::cout << cpu[j];
        if(acc[i] == ',') std::cin >> cpu[j];
        if(acc[i] == '[')
        {
            if(!cpu[j])
            {
                ++brc;
                while(brc)
                {
                    ++i;
                    if (acc[i] == '[') ++brc;
                    if (acc[i] == ']') --brc;
                }
            }
            else continue;
        }
        else if(acc[i] == ']')
        {
            if(!cpu[j])
                continue;
            else
            {
                if(acc[i] == ']') brc++;
                while(brc)
                {
                    --i;
                    if(acc[i] == '[') brc--;
                    if(acc[i] == ']') brc++;
                }
                --i;
            }
        }
    }
}