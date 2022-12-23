//Design and impelement a menu driven program for implementing insertion sort and quick sort for population of a town
#include<iostream>
using namespace std;
#define MAX 100

class popu
{
	public:
	
	void in_sort(int s[],int n)
	{
		int key,i;
		for (int j=1;j<n;j++)
		{
			key=s[j];
			i=j-1;
			while(i>=0 && s[i]>key)
			{
				s[i+1]=s[i];
				i-=1;
			}
			s[i+1]=key;
		}
		disp(s,n);
	}
	
	void disp(int s[], int n)
	{
	    for (int i=0;i<n;i++)
	    {
	    	cout<<s[i]<<" ";
		}
	    cout<<endl;
	}
	
	int part(int s[],int p,int r)
	{
		int x=s[p],cnt=0;
		int i=p;
		int k=r;
		for (int j=i+1;j<=r;j++)
		{
			if(s[j]<=x)
			{
				cnt+=1;
			}
		}
		int index=p+cnt;
		swap(s[index],s[p]);
		while(i<index && k>index)
		{
			while(s[i]<=x)
			{
				i+=1;
			}
			while(s[k]>x)
			{
				k-=1;	
			}
			if (i<index && k>index)
			{
				swap(s[i++],s[k--]);
			}
		}
		return index;
	}
	
	void qui_sort(int s[],int p,int r)
	{
		if (p>=r)
		{
			return;
		}
		else if (p<r);
		{
			int q=part(s,p,r);
			qui_sort(s,p,q-1);
			qui_sort(s,q+1,r);
		}
	}
};

int main()
{
	popu ob1,ob2;
	int ch,popul[MAX],n;
	do
	{
		cout<<"\n\tPopulation of town and literacy rate";
		cout<<"\n1.Sort using insertion sort\n2.Sort using Quick sort\n3.Exit\nEnter choice:";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter number of cities:";
				cin>>n;
				for (int i=0;i<n;i++)
				{
				    cout<<"\nEnter Population:";
				    cin>>popul[i];
				}
				cout<<"\nBefore sorting:"<<endl;
				for (int i=0;i<n;i++)
				{
					cout<<popul[i]<<" "<<endl;
				}
				cout<<"\nAfter sorting:"<<endl;
				ob1.in_sort(popul,n);
				break;
			case 2:
				cout<<"\nEnter number of cities:";
				cin>>n;
				for (int i=0;i<n;i++)
				{
				    cout<<"\nEnter Population:";
				    cin>>popul[i];
				}
				cout<<"\nBefore sorting:"<<endl;
				for (int i=0;i<n;i++)
				{
					cout<<popul[i]<<" "<<endl;
				}
				cout<<"\nAfter sorting:"<<endl;
				ob2.qui_sort(popul,0,n);
				ob2.disp(popul,n);
				break;
		}
		
	}while(ch!=3);
}
