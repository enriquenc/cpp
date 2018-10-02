// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/02 21:13:54 by tmaslyan          #+#    #+#             //
//   Updated: 2018/10/02 21:13:55 by tmaslyan         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP
#include "Zombie.hpp"

class ZombieHorde
{
private:
	int		number_of_zombies;
	Zombie	*zombies;
public:
	ZombieHorde(int N);
	~ZombieHorde();

	void set_type();
	void set_name();
	void announce();
	
};

#endif