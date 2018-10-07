// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EvalExpr.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 16:59:43 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/04 16:59:44 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "EvalExpr.hpp"
#include <sstream>
#include <iostream>


Fixed &EvalExpr::make_sum(std::stringstream &ss)
{
	char	op;
	Fixed *nbr1 = new Fixed();
	Fixed *nbr2 = new Fixed();

	nbr1 = &(make_mult(ss));
	while (1)
	{
		if (!(ss >> op))
			break;	
		if (op != '-' && op != '+')
		{
			ss.unget();
			return *nbr1;
		}
		nbr2 = &(make_mult(ss));
		if (op == '+')
			*nbr1 = *nbr1 + *nbr2;
		else
			*nbr1 = *nbr1 - *nbr2;	
	}
	//system("leaks eval_expr");
	return *nbr1;
}

Fixed &EvalExpr::make_mult(std::stringstream &ss)
{
	char	op = 0;
	Fixed *nbr1 = new Fixed();
	Fixed *nbr2 = new Fixed();
	
	nbr1 = &(make_brackets(ss));
	while (1)
	{
		if (!(ss >> op))
			break;		
		if (op != '*' && op != '/' && op != '%')
		{
			ss.unget();
			return *nbr1;
		}
		*nbr2 = make_brackets(ss);
		if (op == '/')
			*nbr1 = *nbr1 / *nbr2;
		else if (op == '%')
			*nbr1 = *nbr1 % *nbr2;
		else if (op == '*')
			*nbr1 = *nbr1 * *nbr2;
	}
	return *nbr1;
}

Fixed &EvalExpr::make_brackets(std::stringstream &ss)
{
	char op;
	float nbr;

	ss >> op;
	if (op == '(')
	{
		Fixed *n = new Fixed(make_sum(ss));
		ss >> op;
		if (op != ')')
			ss.unget();
		return *n;
	}
		
	ss.unget();
	ss >> nbr;
	Fixed *nbr1 = new Fixed(nbr);
	return *nbr1;
}

Fixed &EvalExpr::calculate(std::string expression)
{
	std::stringstream ss(expression);
	
	return (make_sum(ss));
}