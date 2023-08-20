#include "PhoneBook.hpp"
#include <iomanip>

void PhoneBook::phonebook(){
	index = 0;
	pointer = 0;
}

int attri_empty_check(std::string temp_first_name, std::string temp_last_name, std::string temp_nickname, std::string temp_phone_number, std::string temp_darkest_secret)
{
	if (temp_first_name.empty() || temp_last_name.empty() || temp_nickname.empty() || temp_phone_number.empty() || temp_darkest_secret.empty())
	{
		std::cout << "wrong input" << std::endl;
		return 1;
	}
	else
		return 0;
}

void PhoneBook::add_contact(){
	pointer = index % 8;
	std::string temp_first_name;
	std::string temp_last_name;
	std::string temp_nickname;
	std::string temp_phone_number;
	std::string temp_darkest_secret;

	std::cout << "enter first name" << std::endl;
	std::cin >> temp_first_name;
	std::cout << "enter last name" << std::endl;
	std::cin >> temp_last_name;
	std::cout << "enter nickname" << std::endl;
	std::cin >> temp_nickname;
	std::cout << "enter phone number" << std::endl;
	std::cin >> temp_phone_number;
	std::cout << "enter darkest secret" << std::endl;
	std::cin >> temp_darkest_secret;
	if(attri_empty_check(temp_first_name, temp_last_name, temp_nickname, temp_phone_number, temp_darkest_secret))
		return;
	contacts[pointer].set_first_name(temp_first_name);
	contacts[pointer].set_last_name(temp_last_name);
	contacts[pointer].set_nickname(temp_nickname);
	contacts[pointer].set_phone_number(temp_phone_number);
	contacts[pointer].set_darkest_secret(temp_darkest_secret);
	index++;
}

void PhoneBook::search_contact(int index){
	if (index >= this->index || index < 0)
	{
		std::cout << "wrong index" << std::endl;
		return;
	}
	std::cout << "first name : " << contacts[index].get_first_name() << std::endl;
	std::cout << "last name : " << contacts[index].get_last_name() << std::endl;
	std::cout << "nickname : " << contacts[index].get_nickname() << std::endl;
	std::cout << "phone number : " << contacts[index].get_phone_number() << std::endl;
	std::cout << "darkest secret : " << contacts[index].get_darkest_secret() << std::endl;
}

void PhoneBook::print_contact(){
	int i = 0;
	if (index == 0)
	{
		std::cout << "no contacts" << std::endl;
		return;
	}
	if (index > 8)
		index = 8;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < index)
	{
		std::cout << i << "|";
		std::cout << std::setw(10) << std::right << contacts[i].get_first_name() << "|";
		std::cout << std::setw(10) << std::right << contacts[i].get_last_name() << "|";
		std::cout << std::setw(10) << std::right << contacts[i].get_nickname() << std::endl;
		i++;
	}
}