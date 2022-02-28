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
