#include<iostream>
#include<bits/stdc++.h>
#define max 5
using namespace std;
class linear_array
{
	public:
		int linear_queue[max],front=-1,rear=-1;
		void linear_enqueue()
		{
			int c,e;
			do
			{
				if(rear==max-1)
				{
					cout<<"Overflow"<<endl;
				}
				else if(front==-1 && rear==-1)
				{
					cout<<"Enter Element To Be Inserted: ";
					cin>>e;
					front=rear=0;
					linear_queue[rear]=e;
				}
				else if(front==rear)
				{
					cout<<"Enter Element To Be Inserted: ";
					cin>>e;
					rear=rear+1;
					linear_queue[rear]=e;
				}
				else
				{
					cout<<"Enter Element To Be Inserted: ";
					cin>>e;
					rear=rear+1;
					linear_queue[rear]=e;
				}
				cout<<"Do you want to continue inserting(1=Yes/0=No): ";
				cin>>c;
			}while(c!=0);
		}
		void linear_dequeue()
		{
			int val;
			if((front==-1 && rear==-1) || (front>rear))
			{
				cout<<"Underflow"<<endl;
			}
			else if(front==0 && rear==0)
			{
				val=linear_queue[front];
				front=rear=-1;
			}
			else
			{
				val=linear_queue[front];
				front=front+1;
			}
			cout<<"Deleted Value is: "<<val<<endl;
		}
		void linear_display()
		{
			int i=front;
			if(front==-1 && rear==-1)
			{
				cout<<"\nQueue is empty."<<endl;
			}
			else
			{
				while(i!=rear+1)
				{
					cout<<" "<<linear_queue[i];
					i++;
				}
			}
		}
};

class circular_array
{
	public:
		int cir_queue[max],front=-1,rear=-1,e;
		void cir_enqueue()
		{
			int c;
			do
			{
				if((rear==max-1 && front==0) || (rear==front-1))
				{
					cout<<"Overflow"<<endl;
				}
				else if(front==-1 && rear==-1)
				{
					cout<<"Enter Element To Be Inserted: ";
					cin>>e;
					front=rear=0;
					cir_queue[rear]=e;
				}
				else if((rear==max-1) && (front!=0))
				{
					cout<<"Enter Element To Be Inserted: ";
					cin>>e;
					rear=(rear+1)%max;
					cir_queue[rear]=e;
				}
				else
				{
					cout<<"Enter Element To Be Inserted: ";
					cin>>e;
					rear=(rear+1)%max;
					cir_queue[rear]=e;
				}
				cout<<"Do you want to continue inserting(1=Yes/0=No): ";
				cin>>c;
			}while(c!=0);
		}
		void cir_dequeue()
		{
			int val;
			if(front==-1 && rear==-1)
			{
				cout<<"Underflow"<<endl;
			}
			else if(front==rear)
			{
				val=cir_queue[front];
				front=rear=-1;
			}
			else if(front==max-1)
			{
				val=cir_queue[front];
				front=(front+1)%max;
			}
			else
			{
				val=cir_queue[front];
				front=(front+1)%max;
			}
			cout<<"Dequeued Value is: "<<val<<endl;
		}
		void display()
		{
			int i=front;
			if(front==-1 && rear==-1)
			{
				cout<<"\nQueue is empty."<<endl;
			}
			else
			{
				while(i!=rear+1)
				{
					cout<<" "<<cir_queue[i];
					i++;
				}
			}
		}
};

class node
{
	public:
		int data;
		node *next=NULL;
	
};
class linear_link
{
	public:
		node *front=NULL, *rear=NULL;
		void linear_enqueue()
		{
			node *p;
			p=NULL;
			int c,e;
			do
			{
				p=new(node);
				cout<<"Enter Element to be inserted: ";
				cin>>e;
				p->data=e;
				p->next=NULL;
				if(front==NULL)
				{	
				front=rear=p;
				front->next=NULL;
				rear->next=NULL;
				}
				else
				{
					rear->next=p;
					rear=p;
					rear->next=NULL;
				}
				cout<<"Do you want to continue inserting(1=Yes/0=No): ";
				cin>>c;
			}while(c!=0);
		}
		void linear_dequeue()
		{
			node *ptr;
			ptr=NULL;
			if(front==NULL)
			{
				cout<<"Underflow"<<endl;
			}
			else if(front==rear)
			{
				ptr=front;
				front==rear==NULL;
				cout<<ptr->data;
				delete(ptr);
			}
			else
			{
				ptr=front;
				front=front->next;
				cout<<ptr->data;
				delete(ptr);
			}
		}
		void linear_display()
		{
			node *temp;
			temp=front;
			cout<<"\nThe elements are:";
			if (front==NULL)
			{
				cout<<"\nQueue is Empty";
			}
			else
			{
				while(temp!=NULL)
				{
					cout<<" "<<temp->data;
					temp=temp->next;
				}
			}
		}
};

class circular_link
{
	public:
		node *front=NULL, *rear=NULL;
		void cir_enqueue()
		{
			int c,e;
			do
			{
				node *p=new node();
				cout<<"Enter Element to be inserted: ";
				cin>>e;
				p->data=e;
				p->next=NULL;
				if(rear==NULL)
				{
					front=rear=p;
					rear->next=front;
				}
				else
				{
					rear->next=p;
					rear=p;
					rear->next=front;
				}
				cout<<"Do you want to continue inserting(1=Yes/0=No): ";
				cin>>c;
			}while(c!=0);
		}
		void cir_dequeue()
		{
			node *ptr;
			ptr=front;
			if((front==NULL) && (rear==NULL))
			{
				cout<<"\nQueue is Empty";
			}
			else if (front==rear)
			{
				front==rear==NULL;
				cout<<"\nThe dequeued element is:"<<ptr->data;
				delete ptr;
			}
			else
			{
				front=front->next;
				rear->next=front;
				cout<<"\nThe dequeued element is:"<<ptr->data;
				delete ptr;
			}
		}
		void cir_display()
		{
			node *temp;
			temp=front;
			cout<<"\nThe elements are:";
			if ((front==NULL) && (rear==NULL))
			{
				cout<<"\nQueue Empty";
			}
			else
			{
				while(temp->next!=front)
				{
					cout<<" "<<temp->data;
					temp=temp->next;
				}
				cout<<" "<<temp->data;
			}
		}
};

int main(void)
{
	linear_array la;
	circular_array ca;
	linear_link ll;
	circular_link cl;
	int ch,a,b;
	do
	{
		cout<<"\nEnter Choice\n1.Linear Queue\n2.Circular Queue\n3.Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					do
					{
						cout<<"\nEnter Choice\n1.Array Representation\n2.Linked List Representation\n3Exit"<<endl;
						cin>>a;
						switch(a)
						{
							case 1:
								{
									do
									{
										cout<<"\nEnter Choice\n1.Insert(Enqueue)\n2.Delete(Dequeue)\n3.Dispaly\n4.Exit"<<endl;
										cin>>b;
										switch(b)
										{
											case 1:
												{
													la.linear_enqueue();
													break;
												}
											case 2:
												{
													la.linear_dequeue();
													break;
												}
											case 3:
												{
													la.linear_display();
													break;
												}
											default:
												{
													break;
												}
										}
									}while(b!=4);
									break;
								}
							case 2:
								{
									do
									{
										cout<<"\nEnter Choice\n1.Insert(Enqueue)\n2.Delete(Dequeue)\n3.Dispaly\n4.Exit"<<endl;
										cin>>b;
										switch(b)
										{
											case 1:
												{
													ca.cir_enqueue();
													break;
												}
											case 2:
												{
													ca.cir_dequeue();
													break;
												}
											case 3:
												{
													ca.display();
													break;
												}
											default:
												{
													break;
												}
										}
									}while(b!=4);
									break;
								}
							default:
								{
									break;
								}
						}
					}while(a!=3);
					break;
				}
			case 2:
				{
					do
					{
						cout<<"\nEnter Choice\n1.Array Representation\n2.Linked List Representation\n3Exit"<<endl;
						cin>>a;
						switch(a)
						{
							case 1:
								{
									do
									{
										cout<<"\nEnter Choice\n1.Insert(Enqueue)\n2.Delete(Dequeue)\n3.Dispaly\n4.Exit"<<endl;
										cin>>b;
										switch(b)
										{
											case 1:
												{
													ll.linear_enqueue();
													break;
												}
											case 2:
												{
													ll.linear_dequeue();
													break;
												}
											case 3:
												{
													ll.linear_display();
													break;
												}
											default:
												{
													break;
												}
										}
									}while(b!=4);
									break;
								}
							case 2:
								{
									do
									{
										cout<<"\nEnter Choice\n1.Insert(Enqueue)\n2.Delete(Dequeue)\n3.Dispaly\n4.Exit"<<endl;
										cin>>b;
										switch(b)
										{
											case 1:
												{
													cl.cir_enqueue();
													break;
												}
											case 2:
												{
													cl.cir_dequeue();
													break;
												}
											case 3:
												{
													cl.cir_display();
													break;
												}
											default:
												{
													break;
												}
										}
									}while(b!=4);
									break;
								}
							default:
								{
									break;
								}
						}
					}while(a!=3);
					break;
				}
			default:
				{
					break;
				}
		}
	}while(ch!=3);
}
