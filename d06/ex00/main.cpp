#include <iostream>
#include <string>
#include <climits>
#include <float.h>
#include <iomanip>

int main(int argc, char **argv) {

    if (argc == 2)
    {
        long double nbr;
        try {
            nbr = std::stold(argv[1]);
        }
        catch (const std::exception& e)
        {
            std::cout << "Bad input." << std::endl;
            return (0);
        }
        std::string s_nbr(argv[1]);

        if (nbr >= 0 && nbr <= 31)
            std::cout << "char: Non displayable" << std::endl;
        else if (nbr > 31 && nbr < 128)
            std::cout << "char: " << '\''  <<static_cast<char>(nbr) << '\'' << std::endl;
        else
            std::cout << "char: impossible" << std::endl;

        if (nbr >= INT_MIN && nbr <= INT_MAX)
            std::cout << "int: " << static_cast<int>(nbr) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;

        if (nbr < -FLT_MAX || s_nbr == "-inff")
            std::cout << "float: -inff" << std::endl;
        else if (nbr > FLT_MAX || s_nbr == "+inff")
            std::cout << "float: +inff" << std::endl;
        else if (nbr >= -FLT_MAX && nbr <= FLT_MAX)
        {
            if (nbr == static_cast<int>(nbr))
                std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(nbr) << 'f' << std::endl;
            else
                std::cout << "float: " << static_cast<float>(nbr) << 'f' << std::endl;
        }
        else
            std::cout << "float: impossible" << std::endl;

        if (nbr < -DBL_MAX || s_nbr == "-inf")
            std::cout << "double: -inf" << std::endl;
        else if (nbr > DBL_MAX || s_nbr == "+inf")
            std::cout << "double: +inf" << std::endl;
        else if (nbr >= -DBL_MIN && nbr <= DBL_MAX)
        {
            if (nbr == static_cast<double>(nbr))
                std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(nbr) << std::endl;
            else
                std::cout << "double: " << static_cast<double>(nbr) << std::endl;
        }
        else
            std::cout << "double: impossible" << std::endl;

    }
    else
        std::cout << "usage: ./convert [string]" << std::endl;
    return (0);
}