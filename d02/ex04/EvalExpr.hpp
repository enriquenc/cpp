// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EvalExpr.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 16:59:37 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/04 16:59:37 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef EVALEXPR_CPP
#define EVALEXPR_CPP

#include "Fixed.hpp"
#include <sstream>

class EvalExpr
{
private:
	//string buffer;
	Fixed	&make_sum(std::stringstream &ss);
	Fixed	&make_mult(std::stringstream &ss);
	Fixed	&make_brackets(std::stringstream &ss);

public:

	Fixed 	&calculate(std::string expression);
};

#endif