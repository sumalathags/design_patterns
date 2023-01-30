#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Employee
{
public:
    virtual void showEmployeeDetails() = 0;
};

class Developer : public Employee // leaf element
{
private:
    string name;
    long empId;
    string position;

public:
    Developer(long empId, string name, string position)
    {
        this->empId = empId;
        this->name = name;
        this->position = position;
    }

    void showEmployeeDetails()
    {
        cout << empId << " " << name << " " << position << endl;
    }
};

class Manager : public Employee // leaf element
{
private:
    string name;
    long empId;
    string position;

public:
    Manager(long empId, string name, string position)
    {
        this->empId = empId;
        this->name = name;
        this->position = position;
    }

    void showEmployeeDetails()
    {
        cout << empId << " " << name << " " << position << endl;
    }
};

class CompanyDirectory : public Employee // composite element
{
private:
    vector<Employee *> employeeList;

public:
    void showEmployeeDetails()
    {
        for (Employee *emp : employeeList)
        {
            emp->showEmployeeDetails();
        }
    }

    void addEmployee(Employee *emp)
    {
        employeeList.push_back(emp);
    }

    void removeEmployee(Employee *emp)
    {
        employeeList.erase(remove(employeeList.begin(), employeeList.end(), emp), employeeList.end());
    }
};

int main()
{
    Developer dev1 = Developer(100, "Lokesh Sharma", "Pro Developer");
    Developer dev2 = Developer(101, "Vinay Sharma", "Developer");
    CompanyDirectory engDirectory = CompanyDirectory();
    engDirectory.addEmployee(&dev1);
    engDirectory.addEmployee(&dev2);

    Manager man1 = Manager(200, "Kushagra Garg", "SEO Manager");
    Manager man2 = Manager(201, "Vikram Sharma ", "Kushagra's Manager");

    CompanyDirectory accDirectory = CompanyDirectory();
    accDirectory.addEmployee(&man1);
    accDirectory.addEmployee(&man2);

    CompanyDirectory directory = CompanyDirectory();
    directory.addEmployee(&engDirectory);
    directory.addEmployee(&accDirectory);
    directory.showEmployeeDetails();
}