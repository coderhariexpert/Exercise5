#include <iostream>
#include <string>
using namespace std;

class Person {
  private:
    string name;
    int age;
  
  public:
    void set_info() {
      cout << "Enter person name: ";
      cin>>name;
      
      cout << "Enter person age: ";
      cin >> age;
      cin.ignore(); // ignore newline character
    }
  
    void display_info() {
      cout << "Person name is: " << name << endl;
      cout << "Person age is: " << age << endl;
    }
};

class Employee : public Person {
  private:
    string designation;
    double basic_salary;
    double dear_allowance;
    double hr_allowance;
    double gross_salary;
    int emp_id;
    static int count; // static member variable to keep track of the number of employees
  
  public:
    Employee() {
      count++; // increment count when an employee is created
      emp_id = count; // assign employee ID based on count
    }
  
    void set_info() {
      Person::set_info(); // call base class set_info()
      
      cout << "Enter employee designation: ";
      cin >> designation;
      
      if (designation == "Manager") {
        basic_salary = 50000.0;
        dear_allowance = 0.4 * basic_salary;
        hr_allowance = 0.1 * basic_salary;
      } else if (designation == "Developer") {
        basic_salary = 30000.0;
        dear_allowance = 0.3 * basic_salary;
        hr_allowance = 0.05 * basic_salary;
      } else if (designation == "Tester") {
        basic_salary = 25000.0;
        dear_allowance = 0.2 * basic_salary;
        hr_allowance = 0.03 * basic_salary;
      } else {
        cout << "Invalid designation" << endl;
        return;
      }
      
      gross_salary = basic_salary + dear_allowance + hr_allowance;
    }
  
    void display_info() {
      Person::display_info(); // call base class display_info()
      
      cout << "Employee ID is: " << emp_id << endl;
      cout << "Employee designation is: " << designation << endl;
      cout << "Employee basic salary is: $" << basic_salary << endl;
      cout << "Employee dearness allowance is: $" << dear_allowance << endl;
      cout << "Employee house rent allowance is: $" << hr_allowance << endl;
      cout << "Employee gross salary is: $" << gross_salary << endl;
    }
    
    static int get_count() {
      return count;
    }
};

int Employee::count = 0; // initialize count to 0

int main() {
  
  int count;
  cout<<"No Of Employees: \n";
  cin>>count;
  Employee emp;

  for (int i = 1; i <= count; i++) {
    cout << "Enter information for employee " << endl;
    emp.set_info();
  }

  cout << endl << "Displaying information for all employees:" << endl;
  for (int i = 1; i <= count; i++) {
    cout << "Employee " << i + 1 << endl;
    emp.display_info();
    cout << endl;
  }
  
  cout << "Total number of employees: " << Employee::get_count() << endl;

  return 0;
}

