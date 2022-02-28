/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:01:42 by magoumi           #+#    #+#             */
/*   Updated: 2022/02/28 19:44:04 by magoumi          ###   ########.fr       */
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
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkSecret;

		std::string truncate(std::string str);

	public:
		std::string display();
		std::string displayDetailed();

		std::string getFirstName();
		void 		setFirstName(std::string name);
		std::string getLastName();
		void 		setLastName(std::string name);
		std::string getNickname();
		void 		setNickname(std::string name);
		std::string getPhoneNumber();
		void 		setPhoneNumber(std::string name);
		std::string getDarkSecret();
		void		setDarkSecret(std::string name);
};

#endif
