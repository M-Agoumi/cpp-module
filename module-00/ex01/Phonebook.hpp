/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:59:58 by magoumi           #+#    #+#             */
/*   Updated: 2022/02/28 19:01:25 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by magoumi on 28/2/2022.
//
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact *phone[8];
		int		index;
		bool	firstRun;
		
		void	displayContact();

	public:
		const static int ADD = 1;
		const static int SEARCH = 2;
		const static int EXIT = 0;
		const static int ERROR = -1;

		PhoneBook();
		int		readCommand();
		void	save();
		void	search();
};
