#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class	Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkSecret;

	public:
		Contact();
		~Contact();

		std::string	getFname();
		std::string	getLname();
		std::string	getNickname();
		std::string	getNumber();
		std::string	getSecret();

		int			setFname(std::string);
		int			setLname(std::string);
		int			setNickname(std::string);
		int			setNumber(std::string);
		int			setSecret(std::string);

};

#endif