#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include "contacts.hpp"

class Phonebook
{
	private:
		Contact	_contact[8];
		int		_contactcounter;

	public:
		Phonebook(void);
		~Phonebook(void);
	
		void    add_contact();
		void    search_contact();

};