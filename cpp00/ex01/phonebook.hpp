#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook
{
	private:
		Contact	contacts[8];

	public:
		Phonebook()
		{
			for (int i = 0; i < 8; i++)
			{
				this->contacts[i] = Contact();
			}
		}
		void	addContact(Contact contact, int index);
		void	printContact(int id);
		void	printList(void);
};

#endif