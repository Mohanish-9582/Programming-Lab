#include<iostream>
using namespace std;
#define size 10
class deque
{
    int arr[20],front, rear;
    public:
    deque()
    {
        front = -1;
        rear = -1;
    }
    void insert_front(int);
    void display();
    void endinsert(int);
    void del_first();
    void del_end();
};
void deque::display()
{
    if (front == -1)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

void deque::endinsert(int i)
{
    if(rear>=size-1)
    {
        cout<<"\nInsertion is not possible."<<endl;
    }
    else
    {
        if(front == -1)
        {
            front++;
            rear++;
        }
        else
        {
            rear = rear+1;
        }
        arr[rear]= i;
        cout<<"Inserted element is "<<arr[rear]<<endl;
    }

}
void deque::insert_front(int i)
{
    if(front == -1)
    {
        front = 0;
        arr[++rear] = i;
        cout<<"\n Inserted element is "<<i;

    }
    else if(front!= 0)
    {
        arr[--front] = i;
        cout<<"Inserted element is "<<i;

    }
    else
    {
        cout<<"Insertiion is not possible"<<endl;

    }

}
void deque::del_first()
{
    if(front == -1)
    {
        cout<<"Deletion is not possible"<<endl;
        return;
    }
    else
    {
        cout<<"The deleted element is "<<arr[front]<<endl;
        if(front == rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            front++;
        }  
    }
}
void deque::del_end()
{
    if(front == -1)
    {
        cout<<"Deletion is not possible"<<endl;
        return;
    }
    else
    {
        cout<<"The deleted element is "<<arr[rear]<<endl;
        if(front == rear)
        {
            front = rear = -1;
            return;
        }
        else
        {
            rear--;
        }  
    }
}
int main()
{
    deque obj;
    int ch,i ;
    do
    {
        cout<<"\n1.Insert at begin\n2.Insert at End\n3.Delete At front \n4.Delete at end\n5.display\n6.Exit "<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the elemenmt to inserted "<<endl;
            cin>>i;
            obj.insert_front(i);
            break;
        case 2:
            cout<<"Enter the elemenmt to inserted "<<endl;
            cin>>i;
            obj.endinsert(i);
            break;
        case 3:
           
            obj.del_first();
            break;
        case 4:
            
            obj.del_end();
            break;
        case 5:
            obj.display();
            break;
        
        }
    } while (ch != 6);
    
}
