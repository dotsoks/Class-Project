#include<iostream>
using namespace std;
//Class Employee (Parent class)
class Employee
{
//class members firstname, lastname and ssn
private:
string firstName;
string lastName;
string SSN;
public:
Employee();
Employee(string, string, string);
string getFirstName();
string getLastName();
string getSSN();
void setFirstName(string);
void setLastName(string);
void setSSN(string);
string getFullName();
};
Employee :: Employee()
{
//set firstname, lastname and SSN to unknown
firstName = "unknown";
lastName = "unknown";
SSN = "unknown";
}
//constructor with parameters
Employee :: Employee(string set_firstname, string set_lastname, string set_ssn)
{
//set firstname, lastname and SSN to unknown
firstName = set_firstname;
lastName = set_lastname;
SSN = set_ssn;
}
//method to return the firstname
string Employee :: getFirstName()
{
return firstName;
}
//method to return the lastname
string Employee :: getLastName()
{
return lastName;
}
//method that returns SSN
string Employee :: getSSN()
{
return SSN;
}
//method to set firstname
void Employee :: setFirstName(string fname)
{
firstName = fname;
}
//method that sets lastname
void Employee :: setLastName(string lname)
{
lastName = lname;
}
//method that sets SSn
void Employee :: setSSN(string ssn)
{
SSN = ssn;
}
//method that returns fullname
string Employee :: getFullName()
{
return lastName + ", " + firstName;
}
//class HourlyEmployee that inherits Employee class
class HourlyEmployee: public Employee
{
private:
float hourlyRate;
int hrsWorked;
public:
HourlyEmployee(string, string, string, float, int);
float getHourlyRate();
int getHrsWorked();
void setHourlyRate(float);
void setHrsWorked(int);
double calcWeeklySalary();
};
//parameterized constructor, call the parent class parameterized constructor
HourlyEmployee:: HourlyEmployee(string fname, string lname, string ssn, float rate, int hrs) : Employee(fname, lname, ssn)
{
hourlyRate = rate;
hrsWorked = hrs;
}
//method that gets hourlyRate
float HourlyEmployee:: getHourlyRate()
{
return hourlyRate;
}
//method that gets hours worked
int HourlyEmployee:: getHrsWorked()
{
return hrsWorked;
}
//method that sets hourlyRate
void HourlyEmployee:: setHourlyRate(float rate)
{
hourlyRate = rate;
}
//method that sets hours worked
void HourlyEmployee:: setHrsWorked(int hrs)
{
hrsWorked = hrs;
}
double HourlyEmployee:: calcWeeklySalary()
{
double overtime = 0.0;
if (hrsWorked > 40)
{
overtime = (hrsWorked - 40)
* (0.5 * hourlyRate);
}
return overtime + hrsWorked * hourlyRate;
}
int main()
{
Employee emp1;
cout<<emp1.getFirstName()<<" "<<emp1.getLastName()<<" "<<emp1.getSSN()<<endl;
cout<<emp1.getFullName()<<endl;
Employee emp2("Alice", "Lackey", "291294949");
cout<<emp2.getFirstName()<<" "<<emp2.getLastName()<<" "<<emp2.getSSN()<<endl;
cout<<emp2.getFullName()<<endl;
HourlyEmployee hremp1("Tom", "Steele", "3235245", 7.8, 20);
cout<<hremp1.getFirstName()<<" "<<hremp1.getLastName()<<" "<<hremp1.getSSN()<<" "<<hremp1.getHourlyRate()<<" "<<hremp1.getHrsWorked()<<endl;
cout<<hremp1.getFullName()<<endl;
cout<<hremp1.calcWeeklySalary()<<endl;
hremp1.setFirstName("Bob");
hremp1.setLastName("Zhang");
hremp1.setSSN("9879870897");
hremp1.setHourlyRate(8.5);
hremp1.setHrsWorked(18);
cout<<hremp1.calcWeeklySalary()<<endl;
}
