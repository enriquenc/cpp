/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <tmaslyan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 21:14:37 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/10/02 21:14:38 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <ctime>

int main()
{
    srand(time(NULL));
    ZombieHorde test(5);
    test.announce();
    return 0;
}