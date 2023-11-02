#include "Contact.hpp"

std::string Contact::getFname() {return (this->firstName);}
std::string Contact::getLname() {return (this->lastName);}
std::string Contact::getNickname() {return (this->nickName);}
std::string Contact::getNumber() {return (this->phoneNumber);}
std::string Contact::getSecret() {return (this->darkSecret);}

std::string	Contact::trunContact(std::string s)
{
	if (s.length() < 10)
		return (s);
	s = s.substr(0, 7);
	s = s + "...";
	return (s);
}

int	Contact::setFname(std::string s)
{
	if (s.empty())
		return (1);
	this->firstName.clear();
	this->firstName = s;
	return (0);
}
int	Contact::setLname(std::string s)
{
	if (s.empty())
		return (1);
	this->lastName.clear();
	this->lastName = s;
	return (0);
}
int	Contact::setNickname(std::string s)
{
	if (s.empty())
		return (1);
	this->nickName.clear();
	this->nickName = s;
	return (0);
}
int	Contact::setNumber(std::string s)
{
	if (s.empty())
		return (1);
	this->phoneNumber.clear();
	this->phoneNumber = s;
	return (0);
}
int	Contact::setSecret(std::string s)
{
	if (s.empty())
		return (1);
	this->darkSecret.clear();
	this->darkSecret = s;
	return (0);
}
