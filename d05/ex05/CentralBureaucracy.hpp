// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   CentralBureaucracy.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/09 19:04:41 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/09 19:04:41 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP

#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

class CentralBureaucracy
{
private:
    typedef struct  s_queue
    {
        std::string _target;
        struct s_queue *next;
    }               t_queue;


    t_queue *_targets;
    t_queue *_targets_end;
    int _filled_offices;
    OfficeBlock _offices[20];


    CentralBureaucracy(CentralBureaucracy const &obj);
    CentralBureaucracy &operator=(CentralBureaucracy const &obj);

public:

    CentralBureaucracy(void);
    ~CentralBureaucracy(void);


    void queueUp(std::string const &target);
    void addBureaucrat(Bureaucrat &obj);

    void doBureaucracy(void);
};

#endif
