#include <iostream>
using namespace std;
class person
{
private:
    string name;
    int age;

public:
    void get();
    void display();
};
void person::get()
{
    cout << "Enter Your Name: \n";
    cin>> name;
    cout<<"Enter Age: \n";
    cin>>age;
}
void person::display() 
{
    cout<<"Name: \n"<<name;
    cout<<"Age: \n"<<age;
}
class patient:public person
{
private:
    string disease, gender;
    int pid, status;
    float original_bill;
    int loop;
    static int bed;
    // static int number;
    string insurance1;
    int ins;
    float insurance_claim;
    float final_bill;

public:
    void get_data();
    int calc_bill();
    void display();
    static int bed_count();
};
void patient::get_data()
{
    person::get();
    cout << "Disease: \n";
    cin >> disease;
    cout << "Patient Id: \n";
    cin >> pid;
    cout << "After Few Checkups\n";
    cout << "Cured(1) Or Not Cured\n";
    cin >> status;
    if (status == 1)
        bed++;
    if (bed > 50)
    {
        bed = 50;
    }
    else
        bed--;
    cout << "Gender: \n";
    cout << "1. LIC\n";
    cout << "2. SBI Life Insurance\n";
    cout << "3. HDFC Life Insurance\n";
    cout << "4. ICICI Prudential Life Insurance\n";
    cout << "5. Bajaj Allianz Life Insurance\n";
    cout << "6. No Insurance\n";
    cout << "Enter Your Insurance Provider: \n";
    cin >> ins;
}
int patient::calc_bill()
{
    if (disease == "Fever")
    {
        original_bill = 500.80;
    }
    else if (disease == "Cancer")
    {
        original_bill = 100001.50;
    }
    else if (disease == "Covid-19")
    {
        original_bill = 5000.50;
    }
    else if (disease == "Heart Attack")
    {
        original_bill = 10000.50;
    }
    else if (disease == "Diabetes")
    {
        original_bill = 1000.50;
    }
    else
    {
        cout << disease << " cannot Be Treated Here \n";
    }
    if (ins == 1)
    {
        insurance_claim = 0.50;
    }
    else if (ins == 2)
    {
        insurance_claim = 0.40;
    }
    else if (ins == 3)
    {
        insurance_claim = 0.30;
    }
    else if (ins == 4)
    {
        insurance_claim = 0.20;
    }
    else if (ins == 5)
    {
        insurance_claim = 0.15;
    }
    else
    {
        insurance_claim = 0.0;
    }
    final_bill = original_bill * insurance_claim;
    return final_bill;
}
int patient::bed_count()
{
    return bed;
}
void patient::display()
{
    person::display();
    cout << "Disease: " << disease << "\n";
    cout << "Patient Id: " << pid << "\n";
    cout << "Bill: " << original_bill << "\n";
    cout << "Gender: " << gender << "\n";
    cout << "Insurance: " << insurance1 << "\n";
    // cout << "Remaining Bed: " << bed << "\n";
    cout << " Original Bill: \n"
         << original_bill << "\n";
    cout << "Insurance Claim: \n"
         << insurance_claim << "\n";
    cout << "Final Bill: " << final_bill << "\n";
}
int patient::bed = 50;
int main()
{
    int number, count;
    string username, password;
    string admin1 = "Hari";
    string admin2 = "Kishore";
    string pass1 = "Hari";
    string pass2 = "Kishore";
    cout << "**********************************************\n";
    cout << "*                  Admin Login               *\n";
    cout << "**********************************************\n";
    cout << "Enter the username: ";
    cin >> username;
    cout << "Enter the password: ";
    cin >> password;
    if (username == admin1 && password == pass1 || username == admin2 && password == pass2)
    {
        cout << "Login Successful\n";
        patient p1;
        cout << "Enter Number Of Patients: \n";
        cin >> number;
        for (count = 1; count <= number; count++)
        {
            p1.get_data();
            p1.calc_bill();
            p1.display();
            cout << "Remaining Bed: " << p1.bed_count() << "\n";
        }
    }
    else
    {
        cout << "Login Failed \n";
    }
}

