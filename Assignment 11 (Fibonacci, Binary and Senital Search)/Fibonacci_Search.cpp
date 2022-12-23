#include<iostream>
using namespace std;
class student
{
float marks[20];
int n;
public:
void read();
void display();
void Fibonacci();
void sentinel();
int Binary_search();
int LinearSearch()
	{
	cout<<"\n\t***** Performing linear search *****";
	int flag =0, srh_k;
	cout<<" \nEnter search key: ";
	cin>> srh_k;
	for(int i =0; i<n; i++)
	{
		if(srh_k == marks[i])
		{
		cout<<"\nSearch key present at index: "<<i<<" position: "<<i+1;
		flag=1;
		break;
		}
	}
	if(flag==0) cout<<"\nSearch key is not present in record";
	}
};
void student :: sentinel()
{
cout<<"\n\t***** Performing Sentinel search *****";
float srh_k;
cout<<" \nEnter search key: ";
cin>>srh_k;
marks[n]= srh_k;
int flag=0;
for(int i=0; i < n; i++)
{
if(marks[i]==marks[n])
{
cout<<"\nSearch key presentb at index:"<<i<<" and position: "<<i+1;
flag = 1;
break;
}
}
if(flag == 0)
{
cout<<"\n Search key: "<<srh_k<< " not present in array/ record";
}
}
void student :: Fibonacci()
{
		cout<<"\n\t***** Performing Fibonacci search *****";
		float srh_k;
		int flag=0;
		cout<<" \nEnter search key: ";
		cin>>srh_k;
		int fib2=0, fib1=1;
		int fib=fib1+fib2;
		int j=0;
		while(fib < n)
		{
		// j++;
		fib2=fib1;
		fib1=fib;
		fib=fib1+fib2;
		}
		int offset=-1, i=0;
		int k=0, x=0;
		if(srh_k == marks[n-1])
		cout<<"\nSearch key present at index: "<<n-1<<" and position: "<<n;
		else
		{
			while(fib > 1)
			{
				k++;
				i=min(offset+fib2,n);
				if(marks[i] < srh_k)
				{
					fib=fib1;
					fib1=fib2;
					fib2=fib-fib1;
					offset=i;
				}
				else if(marks[i] > srh_k)
				{
					fib=fib2;
					fib1=fib1-fib2;
					fib2=fib-fib1;
					offset=offset;
				}
				else
				{
					cout<<srh_k<<" is present at index:"<<i<<"th and position:"<<i+1;
					flag=1;
					break;
				}
			}
			if(flag==0)
			cout<<"\nRecord does not belong to file";
		}
}
int student:: Binary_search()
{
		cout<<"\n\t***** Performing Binary search *****";
		int flag=0;
		float shr_k;
		cout<<" \nEnter search key: ";
		cin>>shr_k;
		int low=0, high=n-1, mid=(low+high)/2;
		while(low <= high)
		{
		mid=(low+high)/2;
		// mid = (low+high)/2;
		if(shr_k == marks[mid] )
		{
		cout<<shr_k<<" is present at index:"<<mid<<"th and position:"<<mid+1;
		flag=1;
		break;
		}
		else if(shr_k > marks[mid])
		low=mid+1;
		else if(shr_k < marks[mid])
		high=mid-1;
		}
		if(flag==0)
		cout<<"\nRecord does not belong to file";
}
void student :: read()
{
	cout<<"\nEnter the number of students:";
	cin>>n;
	cout<<"\nDisclaimer: Provide marks in sorted order to perfome \"Binary search andFibonacci Search\"\n";
	for (int i=0; i<n; i++)
	{
	cout<<"\nEnter the marks scored by "<< i+1<< "th student :";
	cin>> marks[i];
	}
}
void student :: display()
{
for (int i=0; i<n; i++)
{
cout<<"\nThe marks scored by "<< i+1<< "th student :"<< marks[i];
}
}
int main()
{
	student s1;
	s1.read();
	s1.display();
	int ch, flag=1;
	do
	{
		cout<<"\n\n***** 1.Linear Search 2.Binary search 3.Fibonacci search 4.Sentinel Search5.Exit *****";
		cout<<"\nEnter Type of search to perform: ";
		cin>>ch;
		switch(ch)
			{
				case 1:
				s1.LinearSearch();
				break;
				case 2:
				s1.Binary_search();
				break;
				case 3:
				s1.Fibonacci();
				break;
				case 4:
				s1.sentinel();
				break;
				default:
				cout<<"\n\tTerminating the code. \n\t Thank You :)";
				flag=0;
				break;
			}
	} while (flag==1);
return 0;
}
