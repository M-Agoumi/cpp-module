//
// Created by magoumi on 12/2/2021.
//

#include <iostream>
#include <string>
#include <string.h>

class PhoneNumber
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkSecret;

	public:
	std::string display()
	{
		return "|" + truncate(firstName) + "|" + truncate(lastName) + "|" + truncate(nickname);
	}

	private:
	std::string truncate(std::string str)
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
};

class PhoneBook
{
	public:
		const static int ADD = 1;
		const static int SEARCH = 2;
		const static int EXIT = 0;

	private:
		PhoneNumber *phone[8];
		int			index = 0;


	public:
	int readCommand()
	{
		std::string command;

		while (true) {
			std::cout << "Enter your command" << std::endl;
			std::cin >> command;
			if (!strcmp(command.c_str(), "add"))
				return ADD;
			if (!strcmp(command.c_str(), "search"))
				return SEARCH;
			if (!strcmp(command.c_str(), "exit"))
				return EXIT;

			std::cout << "Unknown Command " << command << std::endl;
		}
	}

	void save()
	{
		phone[index] = new PhoneNumber;
		std::cout << "Enter First Name:   ";
		std::cin >> phone[index]->firstName;
		std::cout << "Enter Last Name:    ";
		std::cin >> phone[index]->lastName;
		std::cout << "Enter Nickname:     ";
		std::cin >> phone[index]->nickname;
		std::cout << "Enter Phone Number: ";
		std::cin >> phone[index]->phoneNumber;
		std::cout << "Enter Dark Secret:  ";
		std::cin >> phone[index]->darkSecret;

		if (++index == 8)
			index = 0;
	}

	void search()
	{
		int i = 0;

		while (i < 8)
		{
			if (phone[i])
				std::cout << (i + 1) <<  phone[i]->display() << std::endl;
			else
				break;
			i++;
		}
	}
};

int			main()
{
	std::string  phones[8];
    int		command = 1;
	PhoneBook *phone;

	phone = new PhoneBook();
	while (command)
	{
		command = phone->readCommand();
		
		if (command == PhoneBook::ADD)
			phone->save();
		if (command == PhoneBook::SEARCH)
			phone->search();
	}

    return 0;
}
