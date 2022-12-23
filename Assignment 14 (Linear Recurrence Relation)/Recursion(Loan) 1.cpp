// design and implenent linear recurrence relation for various loan scheme
#include <iostream>
#include <math.h>
using namespace std;
class loan
{
public:
    float principle, time;

    float homeloan(float principle, float time)
    {
        if (time <= 0)
        {
            return principle;
        }
        else
        {
            return (homeloan(principle * (1 + (0.01 * 12.35)), time - 1));
        }
    }
    float educationloan(float principle, float time)
    {
        if (time <= 0)
        {
            return principle;
        }
        else
        {
            return (educationloan(principle * (1 + (0.01 * 8.6)), time - 1));
        }
    }
    float carloan(float principle, float time)
    {
        if (time <= 0)
        {
            return principle;
        }
        else
        {
            return (carloan(principle * (1 + (0.01 * 9.6)), time - 1));
        }
    }
    float personaloan(float principle, float time)
    {
        if (time <= 0)
        {
            return principle;
        }
        else
        {
            return (personaloan(principle * (1 + (0.01 * 9.40)), time - 1));
        }
    }
};

int main()
{
    int principle, time;

    loan z;
    cout << "------------ WELCOME TO SBI ------------\n"
         << endl;
    cout << "------------ LOAN SCHEME ------------\n\n";
    int ch = 0;
    while (ch != 5)
    {
        cout << "Select which loan you are interested in: \n1)Home loan\n2)Education loan\n3)Car loan\n4)Personal Loan\n5)Exit\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter principle amount for Home loan : ";
            cin >> principle;
            cout << endl;
            cout << "Enter Time Period : ";
            cin >> time;
            cout << endl;
            cout << "Your final paying amount will be: " << z.homeloan(principle, time) << endl;
            cout << "If you choose EMI then EMI per month will be ";
            cout << principle * 12.35 * pow(1 + 12.35 / 1200, 12 * time) / ((pow(1 + 12.35 / 1200, 12 * time) - 1) * 1200) << endl;
            cout << "--------------------------------------------------------------------------------------------\n"
                 << endl;
            break;
        case 2:
            cout << "Enter principle amount for Education loan : ";
            cin >> principle;
            cout << endl;
            cout << "Enter Time Period : ";
            cin >> time;
            cout << endl;
            cout << "Your final paying amount will be : " << z.educationloan(principle, time) << endl;
            cout << "If you choose EMI then EMI per month will be ";
            cout << principle * 8.6 * pow(1 + 8.6 / 1200, 12 * time) / ((pow(1 + 8.6 / 1200, 12 * time) - 1) * 1200) << endl;
            cout << "--------------------------------------------------------------------------------------------\n"
                 << endl;
            break;
        case 3:
            cout << "Enter principle amount for Car loan : ";
            cin >> principle;
            cout << endl;
            cout << "Enter Time Period : ";
            cin >> time;
            cout << endl;
            cout << "Your final paying amount will be : " << z.carloan(principle, time) << endl;
            cout << "If you choose EMI then EMI per month will be ";
            cout << principle * 9.6 * pow(1 + 9.6 / 1200, 12 * time) / ((pow(1 + 9.6 / 1200, 12 * time) - 1) * 1200) << endl;
            cout << "--------------------------------------------------------------------------------------------\n"
                 << endl;
            break;
        case 4:
            cout << "Enter principle amount for Personal loan : ";
            cin >> principle;
            cout << endl;
            cout << "Enter Time Period : ";
            cin >> time;
            cout << endl;
            cout << "Your final paying amount will be : " << z.personaloan(principle, time) << endl;
            cout << "If you choose EMI then EMI per month will be ";
            cout << principle * 9.4 * pow(1 + 9.4 / 1200, 12 * time) / ((pow(1 + 9.4 / 1200, 12 * time) - 1) * 1200) << endl;
            cout << "--------------------------------------------------------------------------------------------\n"
                 << endl;
            break;
        }
    }
}