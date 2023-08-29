#include "Company.h"

// Сеттер для установки имени для всех классов;
void Employee::set_name(const std::string& name) { this->name = name; }
// Установить тип работы;
void Employee::set_type(const Type_Of_Task& type) { this->type = type; }
Type_Of_Task Employee::get_type() { return type; }
// Сеттер для установки количества подчинённых;
void Manager::set_count_employees(const int& countEmployees) { teamEmployees.resize(countEmployees); }
// Геттер для вызова всей команды рабочих;
std::vector<Employee>& Manager::get_team_employees() { return teamEmployees; }
// Метод разделения задач для рабочих;
void Manager::distribution_of_work(const int& tasks, const int& ID)
{
	if (this->teamEmployees.empty())
	{
		std::cout << "I don't have any workers. " << std::endl;
		return;
	}

	std::srand(tasks + ID);

	int tasksSet = std::rand() % this->teamEmployees.size() + 1;

	std::srand(time(NULL));

	for (int i = 0; i < this->teamEmployees.size(); i++)
	{
		if (tasksSet != 0)
		{
			switch (std::rand() % 3 + 1)
			{
			case 1: this->teamEmployees[i].set_type(A); break;
			case 2: this->teamEmployees[i].set_type(B); break;
			case 3: this->teamEmployees[i].set_type(C); break;
			}
			--tasksSet;
		}
		else this->teamEmployees[i].set_type(NONE);

		switch (this->teamEmployees[i].get_type())
		{
		case A:
			std::cout << "Worker \"" << i + 1 << "\" is working on a task: " << "A" << std::endl;
			break;
		case B:
			std::cout << "Worker \"" << i + 1 << "\" is working on a task: " << "B" << std::endl;
			break;
		case C:
			std::cout << "Worker \"" << i + 1 << "\" is working on a task: " << "C" << std::endl;
			break;
		case NONE:
			std::cout << "Worker \"" << i + 1 << "\" is not working on the task." << std::endl;
			break; 
		}
	}

}
bool Director::is_correct_name(const std::string& name)
{
	if (name[0] < 'A' || name[0] > 'Z') return false;
	for (int i = 1; i < name.length(); ++i)
		if (name[i] < 'a' || name[i] > 'z') return false;

	return true;
}
// Конструктор устанавливающий все параметры;
Director::Director(std::string& name, int& count, int& tasks)
{
	set_name(name);
	managers.resize(count);

	for (int i = 0; i < managers.size(); ++i)
	{
		while (true)
		{
			std::cout << "What is the name of " << i + 1 << " manager: ";
			std::cin >> name;
			if (!is_correct_name(name))
				std::cerr << "Error! Incorect input name. Try again. " << std::endl;
			else
			{
				managers[i].set_name(name);
				break;
			}
		}

		while (true)
		{
			std::cout << "How many employees does " << i + 1 << " manager have: ";
			std::cin >> count;

			if (count < 0) 
				std::cerr << "Error! The number of workers cannot be less than zero. Try again. " << std::endl;
			else
			{
				managers[i].set_count_employees(count);
				break;
			}
		}

		std::vector<Employee> team_employees = managers[i].get_team_employees();

		for (int j = 0; j < team_employees.size(); j++)
		{
			while (true)
			{
				std::cout << "What is the name of " << j + 1 << " employee: ";
				std::cin >> name;
				if (!is_correct_name(name))
					std::cerr << "Error! Incorect input name. Try again. " << std::endl;
				else
				{
					team_employees[j].set_name(name);
					break;
				}
			}
		}
	}
	this->tasks = tasks;
}
// Метод распределения работы по менеджерам;
void Director::call_managers()
{
	system("cls");
	for (int i = 0; i < managers.size(); ++i)
	{
		std::cout << "Manager \"" << i + 1 << "\" received a task from the director. " << std::endl;
		managers[i].distribution_of_work(tasks, (i + 1));
	}
}