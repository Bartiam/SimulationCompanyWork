#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

enum Type_Of_Task { A, B, C, NONE };

class Director;

class Employee
{
private:
	Type_Of_Task type;
	std::string name;
public:
	void set_name(const std::string& name);
	void set_type(const Type_Of_Task& type);
	Type_Of_Task get_type();
};

class Manager : public Employee
{
private:
	// Подчиненные менеджера;
	std::vector<Employee> teamEmployees;
public:
	void set_count_employees(const int& countEmployees);
	std::vector<Employee>& get_team_employees();
	void distribution_of_work(const int& tasks, const int& ID);
};

class Director : public Manager
{
private:
	// Поставленная задача;
	int tasks;
	std::vector<Manager> managers;
	// Приватная проверка на правильность ввода имени;
	bool is_correct_name(const std::string& name);
public:
	Director(std::string& name, int& count, int& tasks);
	void call_managers();
};