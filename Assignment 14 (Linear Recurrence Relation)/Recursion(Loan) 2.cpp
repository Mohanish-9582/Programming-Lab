#include<iostream> 
#include<math.h> 
using namespace std; 

string name;
int time;
float amt;
float rate;

class Loan 
{
	public:
		void getdetails();
		void home();
		void education();
		void gold();
		void displaydetails();
		void rateinfo();
};

void Loan :: getdetails()
{
	cout<<"Enter the name of Customer :";
	cin>>name;
	cout<<"Enter the amount to deposit :";
	cin>>amt;
	cout<<"Enter the time duration(yrs) :";
	cin>>time;	
}

void Loan :: home()
{
	rate=7;
}

void Loan :: education()
{
	rate=3;
}

void Loan :: gold()
{
	rate=10;
}

void Loan :: displaydetails()
{
	cout<<"\nName :"<<name;
	cout<<"\nLoan Amount :"<<amt;
	cout<<"\nTime Duration :"<<time<<" yrs";
	cout<<"\nInterest rate :"<<rate<<" %";
}

void Loan :: rateinfo()
{
	cout<<"Interest Rate Of Different Loans"<<endl;
	cout<<"1.Home Loan-\t7%"<<endl;
	cout<<"2.Education Loan-\t3%"<<endl;
	cout<<"3.Gold Loan-\t10%"<<endl;
}

float finalamt(int t,int amt,float rt)
{
	if(t<=0)
	{
		return amt;
	}
	else
	{
		return (1+(rt/100))*finalamt(t-1,amt,rt);
	}
}

int main()
{
	Loan l;
	int choice;
	int ch;
	do
	{
		cout<<"\n----------WELCOME TO MBI ---------"<<endl;
		cout<<"1.HOME LOAN\n2.EDUCATION LOAN\n3.GOLD LOAN\n4.INTEREST RATE DETAILS\n5.EXIT";
		cout<<"\nENTER YOUR CHOICE :";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				l.getdetails();
				l.home();
				cout<<"\nYOUR HOME LOAN DETAILS";
				l.displaydetails();
				cout<<"\nAmount After "<<time<<" yrs becomes :"<<finalamt(time,amt,rate);
				break;
			case 2:
				l.getdetails();
				l.education();
				cout<<"\nYOUR EDUCATION LOAN DETAILS";
				l.displaydetails();
				cout<<"\nAmount After "<<time<<" yrs becomes :"<<finalamt(time,amt,rate);
				break;
			case 3:
				l.getdetails();
				l.gold();
				cout<<"\nYOUR GOLD LOAN DETAILS";
				l.displaydetails();
				cout<<"\nAmount After "<<time<<" yrs becomes :"<<finalamt(time,amt,rate);
				break;
			case 4:
				l.rateinfo();
				break;
			case 5:
				cout<<"exiting......";
				break;
		}
		cout<<"\n\t !!THANKING YOU FOR VISITING BANK!!"<<endl;
		cout<<"\npress 1 to exit :";
		cin>>ch;
	}
	while(ch==1);
	return 0;
}
