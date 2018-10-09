cmake_minimum_required(VERSION 3.12)
project(ex05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex05
        Bureaucrat.cpp
        Bureaucrat.hpp
        CentralBureaucracy.cpp
        CentralBureaucracy.hpp
        Form.cpp
        Form.hpp
        Intern.cpp
        Intern.hpp
        main.cpp
        OfficeBlock.cpp
        OfficeBlock.hpp
        PresidentialPardonForm.cpp
        PresidentialPardonForm.hpp
        RobotomyRequestForm.cpp
        RobotomyRequestForm.hpp
        ShrubberyCreationForm.cpp
        ShrubberyCreationForm.hpp)
