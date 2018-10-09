// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CentralBureaucracy.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 19:04:34 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 19:04:35 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void): _targets(NULL),
                                                _targets_end(NULL),
                                                _filled_offices(0)
                                                {}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &obj)
{
    (void)obj;
}

CentralBureaucracy & CentralBureaucracy::operator=(CentralBureaucracy const &obj) {
    (void) obj;
    return *this;
}

CentralBureaucracy::~CentralBureaucracy()
{
    while(_targets)
    {
        delete _targets;
        _targets = _targets->next;
    }
    _targets = NULL;
    _targets_end = NULL;
}

void CentralBureaucracy::queueUp(std::string const &target)
{
    if (!_targets)
    {
        _targets = new t_queue;
        _targets->next = NULL;
        _targets->_target = target;
        _targets_end = _targets;
    }
    else
    {
        _targets_end->next = new t_queue;
        _targets_end->next->next = NULL;
        _targets_end->next->_target = target;
        _targets_end = _targets_end->next;
    }
}

void CentralBureaucracy::addBureaucrat(Bureaucrat &obj)
{
    static int count_bureaucrat = 1;

    if(count_bureaucrat % 2)
    {
        _offices[_filled_offices].setSigningBureaucrat(&obj);
        count_bureaucrat++;
    }
    else
    {
        _offices[_filled_offices].setExecutingBureaucrat(&obj);
        count_bureaucrat++;
        _filled_offices++;
    }
}

void CentralBureaucracy::doBureaucracy()
{
    t_queue *temp = _targets;
    std::string form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    while(temp)
    {
        _offices[rand()%_filled_offices].doBureaucracy(form_names[rand()%4], temp->_target);
        temp = temp->next;
        if (temp) {
            delete _targets;
            _targets = temp;
        }
    }
}