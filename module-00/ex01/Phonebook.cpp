/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 19:00:16 by magoumi           #+#    #+#             */
/*   Updated: 2022/02/28 19:47:02 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by magoumi on 27/2/2022.
//
#include <iostream>
#include <string>
#include "Phonebook.hpp"

const std::string RESET = "\e[0m";
const std::string RED = "\e[31m";
const std::string GREEN = "\e[32m";
const std::string YELLOW = "\e[33m";
const std::string BLUE = "\e[34m";
const std::string MAGENTA = "\e[35m";
const std::string CYAN = "\e[36m";

PhoneBook::PhoneBook()
{
	index = 0;
	firstRun = true;
}

int		PhoneBook::readCommand()
{
	std::string command;

	while (true) {
		std::cout << GREEN + "Enter your command" + YELLOW << std::endl;
		std::getline(std::cin, command);
		if (!std::cin)
			return ERROR;
		std::cout << RESET;
		if (!strcmp(command.c_str(), "add"))
			return ADD;
		else if (!strcmp(command.c_str(), "search"))
			return SEARCH;
		else if (!strcmp(command.c_str(), "exit"))
			return EXIT;
		else
			std::cout << RED + "Unknown Command: " + YELLOW << command << std::endl << GREEN + "available comamnds: " + BLUE + "[add/search/exist]" + RESET << std::endl;
	}
}

void	PhoneBook::save()
{
	phone[index] = new Contact;
	std::string readLine;
	std::cout << GREEN + "Enter First Name   : " + YELLOW;
	std::getline (std::cin, readLine);
	phone[index]->setFirstName(readLine);
	
	std::cout << GREEN + "Enter Last Name    : " + YELLOW;
	std::getline (std::cin,readLine);
	phone[index]->setLastName(readLine);
	
	std::cout << GREEN + "Enter Nickname     : " + YELLOW;
	std::getline (std::cin, readLine);
	phone[index]->setNickname(readLine);

	std::cout << GREEN + "Enter Phone Number : " + YELLOW;
	std::getline (std::cin, readLine);
	phone[index]->setPhoneNumber(readLine);
	
	std::cout << GREEN + "Enter Dark Secret  : " + YELLOW;
	std::getline (std::cin, readLine);
	phone[index]->setDarkSecret(readLine);
	
	std::cout << RESET;

	if (++index == 8)
	{
		firstRun = false;
		index = 0;
	}
}

void	PhoneBook::search()
{
	if (index == 0 && firstRun)
	{
		std::cout << YELLOW + "there no phone number saved yet." << std::endl;
		return ;
	}
	int i = 0;

	std::cout << RED + "____________________________________________" << std::endl;
	std::cout << "|    i    |firstname | lastname | nickname |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	while (i < index || (!firstRun && i < 8))
	{
		if (phone[i])
			std::cout << "|    " + RESET << (i + 1) << "    " <<  phone[i]->display() << std::endl;
		else
			break;
		std::cout << RED + "--------------------------------------------" + RESET << std::endl;
		i++;
	}

	displayContact();
}

void	PhoneBook::displayContact()
{
	std::string readContactIndex;
	int 		contactEntry;

	std::cout << "open contact: ";
	std::getline(std::cin, readContactIndex);
	try {
		contactEntry = stoi(readContactIndex);
	} catch (std::exception &e)
	{
		contactEntry = 0;
	}

	if (contactEntry == 0)
		return ;

	if ((contactEntry <= index) || (!firstRun && contactEntry < 8))
		std::cout << phone[contactEntry - 1]->displayDetailed() << std::endl;
	else
		std::cout << "Invalid Contact" << std::endl;
}

std::string Contact::display()
{
	return RED + "|" + RESET + truncate(firstName) + RED + "|" + RESET + truncate(lastName) + RED + "|" + RESET + truncate(nickname) + RED + "|" + RESET;
}

std::string Contact::displayDetailed()
{
	std::string output;

	output  = GREEN + "First Name   : " + BLUE + firstName + "\n";
	output += GREEN + "Last Name    : " + BLUE + lastName + "\n";
	output += GREEN + "Nickname     : " + BLUE + nickname + "\n";
	output += GREEN + "Phone number : " + BLUE + phoneNumber + "\n";
	output += GREEN + "Dark Secret  : " + BLUE + darkSecret + RESET;

	return output;
}

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getNickname()
{
	return nickname;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

std::string Contact::getDarkSecret()
{
	return darkSecret;
}

void		Contact::setFirstName(std::string name)
{
	firstName = name;
}

void		Contact::setLastName(std::string name)
{
	lastName = name;
}

void		Contact::setNickname(std::string name)
{
	nickname = name;
}

void		Contact::setPhoneNumber(std::string phone)
{
	phoneNumber = phone;
}

void		Contact::setDarkSecret(std::string secret)
{
	darkSecret = secret;
}

std::string Contact::truncate(std::string str)
{
	std::string truncatedString = "";
	size_t i = 0;

	while (i < 10)
	{
		if (i < str.length()) {
			if (i != 9)
				truncatedString = truncatedString + str[i];
			else
				truncatedString = truncatedString + ".";
		} else
			truncatedString = truncatedString + " ";
		i++;
	}

	return truncatedString;
}

int			main()
{
    int		command = 1;
	PhoneBook *phone;

	phone = new PhoneBook();
	while (command)
	{
		command = phone->readCommand();
		
		if (command == PhoneBook::ADD)
			phone->save();
		else if (command == PhoneBook::SEARCH)
			phone->search();
		else if (command == PhoneBook::ERROR) {
			std::cout << RED + "wrong input exiting.." + RESET << std::endl;
			return 1;
		}

		std::cout << std::endl;
	}

    return 0;
}
