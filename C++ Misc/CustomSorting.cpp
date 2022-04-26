#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

class Employee
{
private:
    int empId;
    string firstName;
    string lastName;

public:
    Employee() {}

    Employee(int empId1, string firstName1, string lastName1)
    {
        empId = empId1;
        firstName = firstName1;
        lastName = lastName1;
    }

    int getEmpID()
    {
        return empId;
    }
    void setEmpID(int empId1)
    {
        empId = empId1;
    }

    string getfirstName()
    {
        return firstName;
    }
    void setfirstName(string firstName1)
    {
        firstName = firstName1;
    }

    string getlastName()
    {
        return firstName;
    }
    void setlastName(string lastName1)
    {
        lastName = lastName1;
    }
};

class EmployeeService
{
public:
    bool comparefn(Employee e1, Employee e2)
    {
        return (e1.getlastName().compare(e2.getlastName()));
    }

    void sortLastName(vector<Employee> &employeeList)
    {
        // Employee employeeList.pop_back();
        sort(employeeList.begin(), employeeList.end(), comparefn);
    }

    void printEmployeeList(vector<Employee> &employeeList)
    {
        for (int i = 0; i < employeeList.size(); i++)
        {
            string str = employeeList.at(i).getlastName();
            cout << str;
        }
    }
};

int main()
{
    Employee employee1(1, "Pooja", "Sai");
    Employee employee2(2, "Shreya", "Jain");
    Employee employee3(3, "Dolly", "Singh");
    vector<Employee> employeeList;
    employeeList.push_back(employee1);
    employeeList.push_back(employee2);
    employeeList.push_back(employee3);

    EmployeeService employeeService;
    employeeService.sortLastName(employeeList);
    employeeService.printEmployeeList(employeeList);
}
