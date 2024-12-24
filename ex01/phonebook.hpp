#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>

class Phonebook
{
	private:
    Contact contacts[8];
    int index;
    int total;
    std::string format_field(const std::string& field) const;
	bool is_number(const std::string& str) const;

	public:

	Phonebook();
	~Phonebook();

    void add_contact();
    void search_contact() const;
};




#endif