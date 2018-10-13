// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/13 18:55:43 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/13 18:55:45 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>

void out(std::string exp)
{

    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == ')')
            std::cout << "ParClose ";
        else if (isnumber(exp[i]))
        {
            std::cout << "Num(";
            while (isnumber(exp[i]))
            {
                std::cout << exp[i];
                i++;
            }
            i--;
            std::cout << ") ";
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '^')
            std::cout << "Op(" << exp[i] << ") ";
        else if (exp[i] == '(')
            std::cout << "ParOpen ";
    }
}

void print_stack(std::vector<long> &stack)
{
    std::cout << " ST ";
    for (int i = (stack.size() - 1); i >= 0; i--)
        std::cout << stack[i] << ' ';
    std::cout << "]" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Usage: ./ex04 [expression]" << std::endl;
        return 0;
    }
    std::string exp = argv[1];
    std::string res_str;
    std::stack<char> temp_stack;

    std::cout << "Tokens : ";
    out(exp);
    std::cout << std::endl;

    for(int i = 0; exp[i]; i++)
    {
        if (isnumber(exp[i]))
        {
            res_str += ' ';
            res_str += std::to_string(std::stol(&exp[i]));
            //std::cout << std::to_string(std::stol(&exp[i])).size() - 1;
            i = i + static_cast<int>(std::to_string(std::stol(&exp[i])).size() - 1);
            res_str += ' ';
        }
        else {
            switch (exp[i]) {
                case '-':
                    while (!temp_stack.empty() &&
                           (temp_stack.top() == '*' || temp_stack.top() == '/' || temp_stack.top() == '^' || temp_stack.top() == '+')) {
                        res_str += temp_stack.top();
                        temp_stack.pop();
                    }
                    temp_stack.push(exp[i]);

                    break;
                case '+':
                    while (!temp_stack.empty() &&
                           (temp_stack.top() == '*' || temp_stack.top() == '/' || temp_stack.top() == '^')) {
                        res_str += temp_stack.top();
                        temp_stack.pop();
                    }
                    temp_stack.push(exp[i]);
                    break;
                case '/':
                    while (!temp_stack.empty() && (temp_stack.top() == '*' || temp_stack.top() == '^')) {
                        res_str += temp_stack.top();
                        temp_stack.pop();
                    }
                    temp_stack.push(exp[i]);
                    break;
                case '*':
                    while (!temp_stack.empty() && (temp_stack.top() == '^')) {
                        res_str += temp_stack.top();
                        temp_stack.top();
                    }
                    temp_stack.push(exp[i]);
                    break;
                case '^':
                case '(':
                    temp_stack.push(exp[i]);
                    break;
                case ')':
                    while (!temp_stack.empty() && temp_stack.top() != '(') {
                        res_str += temp_stack.top();
                        temp_stack.pop();
                    }
                    if (!temp_stack.empty())
                        temp_stack.pop();
                    break;
            }
        }
    }

    while (!temp_stack.empty())
    {
        res_str += temp_stack.top();
        temp_stack.pop();

    }
    std::cout << "Postfix : ";
    out(res_str);
    std::cout << std::endl;
    std::vector<long> res_stack;
    long temp1 = 0;
    long temp2 = 0;
    for (int i = 0; res_str[i]; i++)
    {

        if (isnumber(res_str[i]))
        {
            std::cout << "I Num(";
            res_stack.push_back(std::stol(&res_str[i]));
            std::cout << res_stack.back() << ") | OP PUSH      |";
            print_stack(res_stack);
            i = i + static_cast<int>(std::to_string(std::stol(&res_str[i])).size() - 1);
        }
        else
        {
            switch (res_str[i])
            {
                case '^':
                    std::cout << "I Op(^)  | OP Power     |";
                    temp1 = res_stack.back();
                    res_stack.pop_back();
                    temp2 = res_stack.back();
                    res_stack.pop_back();
                    res_stack.push_back(pow(temp1, temp2));
                    print_stack(res_stack);
                    break;
                case '*':
                    std::cout << "I Op(*)  | OP Multiply  |";
                    temp1 = res_stack.back();
                    res_stack.pop_back();
                    temp2 = res_stack.back();
                    res_stack.pop_back();
                    res_stack.push_back(temp2 * temp1);
                    print_stack(res_stack);
                    break;
                case '/':
                    std::cout << "I Op(/)  | OP Division  |";
                    temp1 = res_stack.back();
                    res_stack.pop_back();
                    temp2 = res_stack.back();
                    res_stack.pop_back();
                    res_stack.push_back(temp2 / temp1);
                    print_stack(res_stack);
                    break;
                case '+':
                    std::cout << "I Op(+)  | OP Add       |";
                    temp1 = res_stack.back();
                    res_stack.pop_back();
                    temp2 = res_stack.back();
                    res_stack.pop_back();
                    res_stack.push_back(temp2 + temp1);
                    print_stack(res_stack);
                    break;
                case '-':
                    std::cout << "I Op(-)  | OP Substract |";
                    temp1 = res_stack.back();
                    res_stack.pop_back();
                    temp2 = res_stack.back();
                    res_stack.pop_back();
                    res_stack.push_back(temp2 - temp1);
                    print_stack(res_stack);
                    break;
            }
        }
    }
    std::cout << "Result : " << res_stack.back() << std::endl;
    return 0;
}