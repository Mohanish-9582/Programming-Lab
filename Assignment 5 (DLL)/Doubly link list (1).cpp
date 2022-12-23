#include<iostream>
using namespace std;

class node
{
	public:
	int roll_no;
	int marks;
	
	node *next,*prev;
	node()
	{
		next=NULL;
		prev=NULL;
	}
		
};

class marklist
{
	node *head;
	public:
		marklist()
		{
			head=NULL;
		}
		int create();
		void display();
		void sort(int count);
		void merge(marklist m1, marklist m2);
		
};

int marklist::create()
{
	char ch;
	int count=0;
	node *temp,*p;
	
	do
	{
		temp=new node();
		cout<<"enter rno & marks of Student"<<endl;
		cin>>temp->roll_no>>temp->marks;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
			temp->prev=p;
		}
		count++;
		cout<<"Do you want add more marks (y/n) :";
		cin>>ch;
		
	}while(ch!='n');
	return count;
}

void marklist::display()
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		cout<<"Roll number :"<<p->roll_no<<endl;
		cout<<"marks :"<<p->marks<<endl;
		p=p->next;
	}
	
}
void marklist::sort(int count)
{
	node *p,*q,*ptr1,*ptr2,*temp;
	int i;
	for(i=1;i<count;i++)
	{
		q=head;
		while(q->next!=NULL)
		{
			if(q->marks<q->next->marks)
			{
				ptr1=q;
				ptr2=q->next;
				temp=ptr2->next;
				if(ptr1->prev!=NULL)
				{
					ptr1->prev->next=ptr2;
				}
		        else
		        {
				head=ptr2;
	     		}
				ptr2->next=ptr1;
				ptr2->prev=ptr1->prev;
				ptr1->next=temp;
				ptr1->prev=ptr2;
				if(temp!=NULL)
				{
					temp->prev=ptr1;
				}
				q=ptr2;
			}
			q=q->next;
			
		}
	}
	
}

void marklist::merge(marklist m1, marklist m2)
{
	if(m1.head==NULL && m2.head==NULL)
	{
		head=NULL;
		return;
	}
	if(m1.head==NULL)
	{
		head=m2.head;
		return;
	}
	if(m2.head==NULL)
	{
		head=m1.head;
		return;
	}
	node *p,*q,*r;
	p=m1.head;
	q=m2.head;
	if(p->marks>=q->marks)
	{
		head=p;
		r=p;
		p=p->next;
	}
	else
	{
		head=q;
		r=q;
		q=q->next;
	}
	while(p!=NULL && q!=NULL)
	{
		if(p->marks >= q->marks)
		{
			r->next=p;
			p->prev=r;
			p=p->next;
			r=r->next;
		}
		else
		{
			r->next=q;
			q->prev=r;
			q=q->next;
			r=r->next;
		}
	}
	if(p!=NULL)
	{
		r->next=p;
	    p->prev=r;
		
	}
	if(q!=NULL)
	{
		r->next=q;
	    q->prev=r;
		
	}
}
int main()
{
	int count,count1,ch,ch1;
	marklist m1,m2,m3;
	do
	{
		cout<<"1.create marklist 1\n2.display marklist 1\n3.create marklist 2\n4.display marklist 2\n5.sort marklist 1\n6.sort marklist 2\n7.merge list "<<endl;
		cout<<"Enter your choice :"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:count=m1.create();
		           break;
			case 2:m1.display();
		           break;
			case 3:count1=m2.create();
		    	   break;
			case 4:m2.display();
		           break;
			case 5:m1.sort(count);
			       m1.display();
		           break;
			case 6:m2.sort(count1);
			       m2.display();
		           break;
		    case 7:m3.merge(m1,m2);
		           m3.display();
		}
		cout<<"Press 1 to continue  :"<<endl;
		cin>>ch1;
   }while(ch1==1);
	
}


/*OUTPUT
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
1
enter rno & marks of Student
12
345
Do you want add more marks (y/n) :y
enter rno & marks of Student
34
567
Do you want add more marks (y/n) :y
enter rno & marks of Student
23
43
Do you want add more marks (y/n) :y
enter rno & marks of Student
56
123
Do you want add more marks (y/n) :y
enter rno & marks of Student
45
65
Do you want add more marks (y/n) :n
Press 1 to continue  :
1
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
2
Roll number :12
marks :345
Roll number :34
marks :567
Roll number :23
marks :43
Roll number :56
marks :123
Roll number :45
marks :65
Press 1 to continue  :
1
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
3
enter rno & marks of Student
23
543
Do you want add more marks (y/n) :67
enter rno & marks of Student
12
Do you want add more marks (y/n) :y
enter rno & marks of Student
45
32
Do you want add more marks (y/n) :y
enter rno & marks of Student
11
87
Do you want add more marks (y/n) :y
enter rno & marks of Student
43
89
Do you want add more marks (y/n) :n
Press 1 to continue  :
1
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
4
Roll number :23
marks :543
Roll number :7
marks :12
Roll number :45
marks :32
Roll number :11
marks :87
Roll number :43
marks :89
Press 1 to continue  :
1
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
5
Roll number :34
marks :567
Roll number :12
marks :345
Roll number :56
marks :123
Roll number :45
marks :65
Roll number :23
marks :43
Press 1 to continue  :
1
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
6
Roll number :23
marks :543
Roll number :43
marks :89
Roll number :11
marks :87
Roll number :45
marks :32
Roll number :7
marks :12
Press 1 to continue  :
1
1.create marklist 1
2.display marklist 1
3.create marklist 2
4.display marklist 2
5.sort marklist 1
6.sort marklist 2
7.merge list
Enter your choice :
7
Roll number :34
marks :567
Roll number :23
marks :543
Roll number :12
marks :345
Roll number :56
marks :123
Roll number :43
marks :89
Roll number :11
marks :87
Roll number :45
marks :65
Roll number :23
marks :43
Roll number :45
marks :32
Roll number :7
marks :12
Press 1 to continue  :
2
*/
