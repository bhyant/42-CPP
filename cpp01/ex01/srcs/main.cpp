/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:05:19 by tbhuiyan          #+#    #+#             */
/*   Updated: 2026/01/05 14:50:55 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	int	N = 5;

	Zombie* horde = zombieHorde(N, "test");
	for(int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
