/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:04:35 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/12/31 16:48:24 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

Phonebook::Phonebook()
{
	_contact_count = 0;
}

void	Phonebook::add()
{
	int	pos = _contact_count % 8;

	std::string input = "";
	while (input == "" )
	{
		std::cout << "Enter your First Name: ";
		if (!std::getline(std::cin, input))
			return ;
	}
	_contact[pos].set_firstname(input);
	input = "";
	while (input == "")
	{
		std::cout << "Enter your Last Name: ";
		if (!std::getline(std::cin, input))
			return ;
	}
	_contact[pos].set_lastname(input);
	input = "";
	while (input == "")
	{
		std::cout << "Enter your Nickname: ";
		if (!std::getline(std::cin, input))
			return ;
	}
	_contact[pos].set_nickname(input);
	input = "";
	while (input == "")
	{
		std::cout << "Enter your Phone Number: ";
		if (!std::getline(std::cin, input))
			return ;
	}
	_contact[pos].set_phonenumber(input);
	input = "";
	while (input == "")
	{
		std::cout << "Enter your Darkest Secret: ";
		if (!std::getline(std::cin, input))
			return ;
	}
	_contact[pos].set_darkestsecret(input);
	_contact_count++;
	std::cout << "Contact added successfully." << std::endl;
}

void	Phonebook::search()
{
	std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

	for(int i = 0; i < _contact_count && i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formate_args(_contact[i].get_firstname()) << "|";
		std::cout << std::setw(10) << formate_args(_contact[i].get_lastname()) << "|";
		std::cout << std::setw(10) << formate_args(_contact[i].get_nickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << " ------------------------------------------- " << std::endl;

	int	index = -1;
	std::string input = "";

	std::cout << "Enter the index of the contact you want to view: ";
	if (std::getline(std::cin, input) && input.length() == 1 && isdigit(input[0]))
		index = input[0] - '0';
	if (index >= 0 && index < _contact_count && index < 8)
	{
		std::cout << "First Name: " << _contact[index].get_firstname() << std::endl;
		std::cout << "Last Name: " << _contact[index].get_lastname() << std::endl;
		std::cout << "Nickname: " << _contact[index].get_nickname() << std::endl;
		std::cout << "Phone Number: " << _contact[index].get_phonenumber() << std::endl;
		std::cout << "Darkest Secret: " << _contact[index].get_darkestsecret() << std::endl;
	}
	else
		std::cout << "Wrong index entered." << std::endl;
}
