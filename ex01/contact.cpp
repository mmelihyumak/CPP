#include "contact.hpp"

void	Contact::setName(std::string name)
{
	this->name = name;
}

void	Contact::setLastname(std::string lastname)
{
	this->lastname = lastname;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestsecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getName(void)
{
	return (this->name);
}

std::string	Contact::getLastname(void)
{
	return (this->lastname);
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string Contact::getPhonenumber(void)
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestsecret(void)
{
	return (this->darkestSecret);
}
