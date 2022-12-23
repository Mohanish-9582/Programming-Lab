//Problem Statement: Design and implement program for parity checker of ASCII equivalence of given word.

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class parity_chek
{
	int i, j=0, count=0;
	string str;
	int b[100];
	public:
		void input();
		void findparity();
};

void parity_chek::input()
{
	cout<<"Enter String you want to check: "<<endl;
	cin>>str;
}

void parity_chek::findparity()
{
	cout<<"Input String is: ";
	cout<<str<<endl;
	int n =str.length();
	for( i=0;i<n;i++)
	{
		int val = int (str[i]);
		
		j=0;
		
		while(val>0)
		{
			int p =val%2;
			b[j] =p;
			
			val/=2;
			j++;
		}
		reverse(b,b+j);
		for (int i=0;i<j;i++)
		{
			cout<<b[i];
			
			if(b[i]==1)
			{
				count++;
			}
		}
		cout<<"\t";
	}
	if (count%2==0)
	{
		cout<<"\nEven Parity";
	}
	else
	{
		cout<<"\nOdd Parity";
	}
}

int main()
{
	parity_chek a1;
	a1.input();
	a1.findparity();
	return 0;
}
