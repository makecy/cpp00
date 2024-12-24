#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::set_values(const std::string& f, const std::string& l, const std::string& n, const std::string& p, const std::string& d)
{
	first_name = f;
	last_name = l;
	nickname = n;
	phone_number = p;
	darkest_secret = d;
}

void Contact::display_contact() const
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secter: " << darkest_secret << std::endl;
}

std::string Contact::get_field(const std::string& field) const
{
    if (field == "first_name") return first_name;
    if (field == "last_name") return last_name;
    if (field == "nickname") return nickname;
    return "";
}