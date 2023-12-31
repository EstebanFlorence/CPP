#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define CLR_RMV "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"

class	PhoneBook
{
	private:
		Contact		contacts[8];

	public:

		void		displayMenu();
		void		pressButton();
		void		exitPhone();
		int			addContact(int &);
		int			searchContact(int);
		void		displayBook();
		void		displayContact(int);
		int			errorPhone(int);

};

#endif