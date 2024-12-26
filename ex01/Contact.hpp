#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	public:

	Contact();
	~Contact();

	void set_values(const std::string& f, const std::string& l, const std::string& n, const std::string& p, const std::string& d);
	void display_contact() const;
	std::string get_field(const std::string& field) const;
};

#endif