/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:01:11 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/12/31 16:35:48 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "../includes/Contact.hpp"

class Phonebook
{
	private:
		Contact	_contact[8];
		int		_contact_count;
		std::string formate_args(std::string text);
	public:
		Phonebook();
		~Phonebook();
		void	add();
		void	search();
};

#endif
