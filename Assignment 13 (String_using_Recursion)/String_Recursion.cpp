//Design and implement a program for generating all possible combinations of given string using
//recursion.
#include<iostream>
#include<string.h>
using namespace std;

char temp[20];
int n=0;

void combinations(char *str,int r,int index)
{
	for(int i=0;i<strlen(str);i++)
	{
		temp[index]=str[i];
		if(index==r-1)
		{
			cout<<"\t"<<temp;
			n++;
		}
		else
	    {
	    	combinations(str,r,index+1);
		}
	}
}

int main()
{
	int r;
	char str[20];
	cout<<"\nEnter the string :";
	cin>>str;
	cout<<"\nCombinations are :";
	for(r=1;r<=strlen(str);r++)
	{
		combinations(str,r,0);
	}
	cout<<"\nTotal Combinations is :"<<n;
	return 0;
}
