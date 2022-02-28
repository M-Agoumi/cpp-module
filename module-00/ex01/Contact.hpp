/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:01:42 by magoumi           #+#    #+#             */
/*   Updated: 2022/02/28 19:01:52 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by magoumi on 28/2/2022.
//

#ifndef __CONTACT__
#define __CONTACT__
#include <iostream>

class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkSecret;

		std::string display();
		std::string displayDetailed();

	private:
		std::string truncate(std::string str);
};

#endif
