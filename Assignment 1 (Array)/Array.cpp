//problem statement-

//-----hardware data-----
#include<iostream>
using namespace std;

// Declaring class for data
class customer
{
	public:
		string name,addr;
		int ph_no,order_no,amount,n;		
	public:
		void write_data();
		void read_data();
		void update();
		int search(customer c[10]);
		void del();
		void insert();
		int cust_no;
};

// input of data
void customer::write_data()
{
	cout<<"\n----- ENTER THE DATA OF CUSTOMER -----\n";
	cout<<"\nEnter the name     =" ;
	cin>>name;
	cout<<"\nEnter the address  = ";
	cin>>addr;
	cout<<"\nEnter customer no  = ";
	cin>>cust_no;
	cout<<"\nEnter Phone no     = ";
	cin>>ph_no;
	cout<<"\nEnter order no     = ";
	cin>>order_no;
	cout<<"\nEnter amount       = ";
	cin>>amount;
}

// reading data of customer
void customer::read_data()
{
	cout<<"\n\n-----CUSTOMER DATA-----";
	cout<<"\nName        ="<<name;
	cout<<"\nAddress     ="<<addr;
	cout<<"\nCustomer no ="<<cust_no;
	cout<<"\nPhone no    ="<<ph_no;
	cout<<"\nOrder no    ="<<order_no;
	cout<<"\nAmount      ="<<amount;
}

// updating data of customer
void customer::update()
{
	int cho,num;
	string word;
	cout<<"\n\n-----WHAT WOULD YOU LIKE TO UPDATE-----\n";
	cout<<"\n ENTER 1 FOR NAME   ";
	cout<<"\n ENTER 2 FOR ADDRESS";
	cout<<"\n ENTER 3 FOR CUSTOMER NO ";
	cout<<"\n ENTER 4 FOR PHONE NO ";
	cout<<"\n ENTER 5 FOR ORDER NO";
	cout<<"\n ENTER 6 FOR AMOUNT";
	cout<<"\n\nENTER YOUR CHOICE=";
	cin>>cho;
	cout<<"\n\tENTER THE NEW DATA";
	switch(cho)
	{
		case 1:
			cout<<"\nENTER NAME=";
			cin>>word;
			name = word;
			cout<<"\n***DATA UPDATED SUCCUSFULLY***";
			break;
		case 2:
			cout<<"\nENTER ADDRESS=";
			cin>>word;
			addr = word;
			cout<<"\n***DATA UPDATED SUCCUSFULLY***";
			break;
		case 3:
			cout<<"\nENTER CUSTOMER NO=";
			cin>>num;
			cust_no = num;
			cout<<"\n***DATA UPDATED SUCCUSFULLY***";
			break;
		case 4:
			cout<<"\nENTER PHONE NO=";
			cin>>num;
			ph_no = num;
			cout<<"\n***DATA UPDATED SUCCUSFULLY***";
			break;
		case 5:
			cout<<"\nENTER ORDER NO=";
			cin>>num;
			order_no = num;
			cout<<"\n***DATA UPDATED SUCCUSFULLY***";
			break;
		case 6:
			cout<<"\nENTER AMOUNT=";
			cin>>num;
			amount = num;
			cout<<"\n***DATA UPDATED SUCCUSFULLY***";
			break;
							
	}
}

// search data
int customer::search(customer c[10])
{
	int a, cn, s;
	cout<<"\n\t*****SEARCHING DATA*****\n";
	cout<<"\nENTER THE CUSTOMER NO=";
	cin>>s;
	for(a=0;a<10;a++)
	{
		if(s == c[a].cust_no)
		{
			cn = a;// storing the index value
			cout<<"\n\tCUSTOMER SUCCESFULLY FOUND\n\n";
			break;
		}
	}
	return cn;		
}


int main()//           MAIN FUNCTION
{
	int a,n_1,n_2,n_3,n_4,choice,s,cn,lp,rn,index;
	customer c[10];
	do
	{
		cout<<"\n\n1--WRITE DATA \n2--DISPLAY DATA \n3--UPDATE DATA \n4--SEARCH DATA \n5--DELETE DATA \n6--INSERT DATA \n7--EXIT";
		cout<<"\nENTER THE CHOICE=";
		cin>>choice;
		if(choice==7)
		{
			cout<<"\n*****LEAVING THE PROGRAM*****";
			break;
		}
		switch(choice)
		{
			case 1://   WRITE DATA
				cout<<"\n*****WRITING THE DATA*****";
				cout<<"\nHOW MANY PERSON DATA=";
				cin>>n_1;
				for(a=0;a<n_1;a++)
		    	{
		    		c[a].write_data();	
				}
				break;
			
			case 2://   READ DATA
				cout<<"\n\t*****READING THE DATA*****\n";
				cout<<"\nHOW MANY PERSON DATA=";
				cin>>n_2;
				for(a=0;a<n_2;a++)
				{
					c[a].read_data();
				}
				break;
			
			case 3://   UPDATING
				cout<<"\n\t*****UPDATING DATA*****\n";
				cout<<"\nSEARCH NEEDED TO UPDATE DATA";
				index = c[a].search(c);
				c[index].read_data();
				c[index].update();
				cout<<"\n\nTHE NEW DATA IS=";
				c[index].read_data();
				break;
		
			case 4://   searching
				index = c[a].search(c);
				c[index].read_data();
				break;	
				
			case 5://    DELETING DATA
				cout<<"\nSEARCH NEEDED TO DELETE DATA";
				index = c[a].search(c);
				c[index].read_data();
				
				for(a=cn;a<n_1;a++)//   shifting data to over write
				{
					c[a].name = c[a+1].name;
					c[a].addr = c[a+1].addr;
					c[a].cust_no = c[a+1].cust_no;
					c[a].ph_no = c[a+1].ph_no;
					c[a].order_no = c[a+1].order_no;
					c[a].amount = c[a+1].amount;
				}
				cout<<"\nDATA DELETED";
				break;
				
			case 6:// Insert data
				cout<<"\n*****INSERTING DATA*****";
				cout<<"\n ENTER INDEX NO TO INSERT DATA=";
				cin>>n_3;
				
				for(a=n_1;a>n_3;a--)//   shifting data to over write
				{
					c[a].name = c[a-1].name;
					c[a].addr = c[a-1].addr;
					c[a].cust_no = c[a-1].cust_no;
					c[a].ph_no = c[a-1].ph_no;
					c[a].order_no = c[a-1].order_no;
					c[a].amount = c[a-1].amount;
				}
				c[n_3].write_data();
				n_1 =n_1+1;
				cout<<"\n*****DATA INSERTED SUSSFULLY*****";
				break;	  	
		}
	}while(choice<7);
	
	return 0;
}

