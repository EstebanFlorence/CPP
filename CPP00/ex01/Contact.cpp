#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}


std::string Contact::getFname() {return (this->firstName);}
std::string Contact::getLname() {return (this->lastName);}
std::string Contact::getNickname() {return (this->nickName);}
std::string Contact::getNumber() {return (this->phoneNumber);}
std::string Contact::getSecret() {return (this->darkSecret);}


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
