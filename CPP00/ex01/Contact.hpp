#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <iomanip>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;

	public:

		std::string	getFname();
		std::string	getLname();
		std::string	getNickname();
		std::string	getNumber();
		std::string	getSecret();
		std::string	trunContact(std::string);

		int			setFname(std::string);
		int			setLname(std::string);
		int			setNickname(std::string);
		int			setNumber(std::string);
		int			setSecret(std::string);

};

#endif