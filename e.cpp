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
      cin >> name;
      
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
    double salary;
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
        salary = 50000.0;
      } else if (designation == "Developer") {
        salary = 30000.0;
      } else if (designation == "Tester") {
        salary = 25000.0;
      } else {
        cout << "Invalid designation" << endl;
        return;
      }
    }
  
    void display_info() {
      Person::display_info(); // call base class display_info()
      
      cout << "Employee ID is: " << emp_id << endl;
      cout << "Employee designation is: " << designation << endl;
      cout << "Employee salary is: $" << salary << endl;
    }
    
    static int get_count() {
      return count;
    }
};

int Employee::count = 0; // initialize count to 0

int main() {
  int count;
  Employee emp;
  cout<<"Enter No. Of Employees: \n";
  cin>>count;

  for (int i = 1; i <= count; i++) {
    cout << "Enter information for employee: " <<i<<endl;
    emp.set_info();
  }

  cout << endl << "Displaying information for all employees:" << endl;
  for (int i = 1; i <= count; i++) {
    cout << "Employee " << i << endl;
    emp.display_info();
    cout << endl;
  }
  
  cout << "Total number of employees: " << Employee::get_count() << endl;

  return 0;
}

