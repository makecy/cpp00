#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0), total(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::format_field(const std::string& field) const
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

bool PhoneBook::is_number(const std::string& str) const
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::add_contact()
{
	std::string f, l, n, p, d;

	std::cout << "Enter First Name: "; std::getline(std::cin, f);
    std::cout << "Enter Last Name: "; std::getline(std::cin, l);
    std::cout << "Enter Nickname: "; std::getline(std::cin, n);
    int attempts = 3;
	while (attempts > 0)
    {
        std::cout << "Enter Phone Number: "; std::getline(std::cin, p);
        if (is_number(p))
            break;
		attempts--;
        std::cout << "Error: Phone number must contain only digits! Attempts left: " << attempts << std::endl;
    }

    if (attempts == 0)
    {
        std::cout << "Failed to add contact due to invalid phone number." << std::endl;
        return;
    }
    std::cout << "Enter Darkest Secret: "; std::getline(std::cin, d);

	if (f.empty() || l.empty() || n.empty() || p.empty() || d.empty())
    {
        std::cout << "Error: Fields cannot be empty!" << std::endl;
        return;
    }
	    contacts[index].set_values(f, l, n, p, d);
    index = (index + 1) % 8;
    if (total < 8)
        total++;
}

void PhoneBook::search_contact() const
{
    if (total == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < total; ++i)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format_field(contacts[i].get_field("first_name")) << "|"
                  << std::setw(10) << format_field(contacts[i].get_field("last_name")) << "|"
                  << std::setw(10) << format_field(contacts[i].get_field("nickname")) << std::endl;
    }

    int id;
    std::cout << "Enter index to view details: ";
    std::cin >> id;
    std::cin.ignore();

    if (id >= 0 && id < total)
        contacts[id].display_contact();
    else
        std::cout << "Invalid index." << std::endl;
}