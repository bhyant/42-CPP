/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 19:11:37 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/12/31 15:41:32 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void	Contact::set_firstname(std::string firstname)
{
	_firstname = firstname;
}

void	Contact::set_lastname(std::string lastname)
{
	_lastname = lastname;
}

void	Contact::set_nickname(std::string nickname)
{
	_nickname = nickname;
}

void	Contact::set_phonenumber(std::string phonenumber)
{
	_phonenumber = phonenumber;
}

void	Contact::set_darkestsecret(std::string darkestsecret)
{
	_darkestsecret = darkestsecret;
}

std::string	Contact::get_firstname() const
{
	return _firstname;
}

std::string	Contact::get_lastname() const
{
	return _lastname;
}

std::string	Contact::get_nickname() const
{
	return _nickname;
}

std::string	Contact::get_phonenumber() const
{
	return _phonenumber;
}

std::string	Contact::get_darkestsecret() const
{
	return _darkestsecret;
}
