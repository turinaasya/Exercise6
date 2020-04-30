#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class Worker
{
    string surname;
    int experience, salaryh, hours, salary;
    double premy;
public:
    void setWorker(string srn, int exp, int slh, int hrs)
    {
        surname = srn;
        experience = exp;
        salaryh = slh;
        hours = hrs;
        double p;
        int slr;
        slr = slh * hrs;
        salary = slr;
        if (exp < 1) p = 0;
        else
        {
            if (exp >= 1 && exp < 3) p = 0.05 * slr;
            else
            {
                if (exp >= 3 && exp < 5) p = 0.08 * slr;
                else
                {
                    if (exp >= 5) p = 0.15 * slr;
                }
            }
        }
        premy = p;
    }
    void getWorker()
    {
        cout << surname << endl << "Experience is " << experience << endl << "Hourly wage is " << salaryh << endl << surname << " has worked " << hours << " hours" << endl << "Salary is " << salary << endl << "Premy is " << premy << endl;
        cout << "Information about " << surname << " was written in file 'Workers.txt'" << endl;
        ofstream file;
        file.open("Workers.txt", ios_base::app);
        file << surname << endl << "Experience is " << experience << endl << "Hourly wage is " << salaryh << endl << surname << " has worked " << hours << " hours" << endl << "Salary is " << salary << endl << "Premy is " << premy << endl << endl << endl;
        file.close();
    }
};

int main()
{
    string surname;
    int experience, salaryh, hours, salary, premy;
    cout << "Enter worker's name: "; cin >> surname; cout << endl;
    cout << "Enter worker's experience: "; cin >> experience; cout << endl;
    cout << "Enter worker's hourly wag: "; cin >> salaryh; cout << endl;
    cout << "Enter how much hours " << surname << " has worked: "; cin >> hours; cout << endl;
    Worker objWorker;
    objWorker.setWorker(surname, experience, salaryh, hours);
    objWorker.getWorker();
    system("pause");
    return 0;
}