/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:48:51 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/12/31 16:59:02 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	return (std::cout << "Usage: ./phonebook" << std::endl, 1);
	Phonebook phonebook;
	std::string	cmd;
	while (1)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
	}
	return 0;
}
