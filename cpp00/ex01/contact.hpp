#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	name;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		
	public:
		Contact()
		{
			this->name = "";
			this->lastname = "";
			this->nickname = "";
			this->phoneNumber = "";
			this->darkestSecret = "";
		}
		void	setFirstname(std::string name);
		void	setLastname(std::string lastname);
		void	setNickname(std::string nickname);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestsecret(std::string darkestSecret);
		std::string	getFirstname(void);
		std::string	getLastname(void);
		std::string	getNickname(void);
		std::string	getPhonenumber(void);
		std::string	getDarkestsecret(void);
};

#endif