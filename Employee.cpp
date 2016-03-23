#include<iostream>
#include<string>

using namespace std;

class Employee
{
protected:
	//Class variables
	string ename;
	unsigned int snum;
	float sal;

public:
	//Class Variables
	static int numberOfEmployees;

	//Class methods
	//Constructor
	void setEmployee(string name, unsigned int staffNum)
	{
		ename = name;
		snum = staffNum;
		//numberOfEmployees++;
	}//End constructor

	//Default destructor
	~Employee()
	{
	}//End destructor

	string name()
	{
		return ename;
	}//End name

	unsigned int staffNumber()
	{
		return snum;
	}//End staffNumber

	float salary()
	{
		return sal;
	}//End salary
};

class SalaryEmployee : public Employee{
public:
	void setSalary(float salary)
	{
		sal = salary;
	}//End setSalary

};//End SalaryEmployee class

class HourlyEmployee : public Employee{
private:
	float rate;
	int worked;

public:
	void setHourlyRate(float hRate)
	{
		rate = hRate;
	}//End setHourlyRate

	void setHoursWorked(int hWorked)
	{
		worked = hWorked;
	}//End setHoursWorked

	void setSalary()
	{
		sal = rate*worked;
	}//End setSalary

};//End HourlyEmployee class

class CommissionEmployee : public Employee{
private:
	float base;
	float rate;
	float rev;

public:
	void setBaseSalary(float bSalary)
	{
		base = bSalary;
	}//End setBaseSalary

	void setRate(float cRate)
	{
		rate = cRate;
	}//End setRate

	void setRevenue(float cRev)
	{
		rev = cRev;
	}//End setRevenue

	void setSalary()
	{
		sal = base + rate*rev;
	}//End setSalary

};//End CommissionEmployee class

int main()
{
	SalaryEmployee salEmp;
	HourlyEmployee houEmp;
	CommissionEmployee comEmp;

	Employee *pSalEmp = &salEmp;
	Employee *pHouEmp = &houEmp;
	Employee *pComEmp = &comEmp;

	pSalEmp->setEmployee("Employee 1", 1);
	pHouEmp->setEmployee("Employee 2", 2);
	pComEmp->setEmployee("Employee 3", 3);

	salEmp.setSalary(150.25);
	houEmp.setHourlyRate(12.5);
	houEmp.setHoursWorked(10);
	houEmp.setSalary();
	comEmp.setBaseSalary(75.50);
	comEmp.setRate(0.10);
	comEmp.setRevenue(1000.25);
	comEmp.setSalary();

	cout << salEmp.staffNumber() << " " << salEmp.name() << " " << salEmp.salary() << endl;
	cout << houEmp.staffNumber() << " " << houEmp.name() << " " << houEmp.salary() << endl;
	cout << comEmp.staffNumber() << " " << comEmp.name() << " " << comEmp.salary() << endl;

	Employee obj;
	//cout << obj.numberOfEmployees << endl;

	return 1;
}