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
