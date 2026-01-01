/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbhuiyan <tbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:31:02 by tbhuiyan          #+#    #+#             */
/*   Updated: 2025/12/31 16:31:31 by tbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

std::string	Phonebook::formate_args(std::string info)
{
	if (info.length() > 10)
		return (info.substr(0, 9) + ".");
	return info;
}
