#include "Company.h"

bool is_correct_name(const std::string& name)
{
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < name.length(); ++i)
		if (name[i] < 'a' || name[i] > 'z') return false;

	return true;
}


int main()
{
	std::string name;
	int count, tasks;

	while (true)
	{
		std::cout << "Enter the name of the director: ";
		std::cin >> name;
		if (!is_correct_name(name))
			std::cerr << "Error! Incorrect input name. Try again." << std::endl;
		else break;
	}
	
	while (true)
	{
		std::cout << "Enter the number of managers: ";
		std::cin >> count;
		if (count < 1)
		{
			std::cerr << "Error! Incorrect input number of managers. Try again. " << std::endl;
			continue;
		}

		std::cout << "Enter the number of tasks: ";
		std::cin >> tasks;

		if (count < 1)
		{
			std::cerr << "Error! Incorrect input number of tasks. Try again. " << std::endl;
			continue;
		}

		break;
	}

	Director dir(name, count, tasks);
	dir.call_managers();

	return 0;
}