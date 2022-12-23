
#include<iostream>
using namespace std;
#include<conio.h>
#include<stdlib.h>
#define MAX 100

class Sparse
{
	
		
	int a[MAX][MAX],s[MAX][MAX],r,c,n;

	public : 
	 void read();
	 void convert(); 
	 void display();
	 Sparse addition(Sparse S2); 
	 Sparse transpose();
	 Sparse multiply(Sparse S2); 
};

void Sparse :: read()
{    
    int i,j;
	cout<<"Enter rows and columns of matrix :\n";
	cin>>r>>c;
	cout<<"\nEnter "<<r*c<<" elements for matrix :\n";
	
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
};

void Sparse :: convert()
{ 
int i,j;
n=0;
s[0][0]=r;
s[0][1]=c;

for (i=0;i<r;i++)
{
	for(j=0;j<c;j++) 
	{
		if (a[i][j]!=0)
		{
			
			s[n+1][0]=i;
			s[n+1][1]=j;
			s[n+1][2]=a[i][j];
			
			n++;
		}
	}
}
s[0][2]=n;

};

void Sparse :: display()
{
	int i,j;
	cout<<"\nrows\tcol\tnon zero\n";
	
	for(i=0;i<=s[0][2];i++)
	{
		for(j=0;j<3;j++)
		{
		  cout<<s[i][j]<<"\t";
	    }
		cout<<"\n";
	}
	
};


Sparse Sparse :: addition(Sparse S2)
{
	Sparse S3;
	int i=1,j=1,k=1;
	S3.s[0][0]=s[0][0];
	S3.s[0][1]=s[0][1];
	
	if(s[0][0]!=S2.s[0][0] || s[0][1]!=S2.s[0][1] ) // (r1 and r2) or (c1 and c2) of two sparse matrix (Sparse and S2) are not equal  
	{
		cout<<"\nAddition is not possible";
		return S3;
	}
	
	while(i<=n && j<=S2.n)  // n is non zero elements 
	{
		if (s[i][0]==S2.s[j][0] && s[i][1]==S2.s[j][1]) //respective no of row and column is equal of two sparse matrices then addition happens
		{
			S3.s[k][0]=s[i][0];
			S3.s[k][1]=s[i][1];
			S3.s[k][2]=s[i][2]+S2.s[j][2];
			i++;
			j++;
			k++;
		}
		
		else if(s[i][0]==S2.s[j][0]) // respective row is equal of two sparse matrix  
		{                             // two conditions arrived 
			if (s[i][1]<S2.s[j][1])   // if respective col of 1st matrix is less than other, then copy 1st col in 3rd sparse matrix
			{
				S3.s[k][0]=s[i][0];
				S3.s[k][1]=s[i][1];
				S3.s[k][2]=s[i][2];  
				i++;
				k++;    // ***** all talks about Col size (big or small)
			}
			
			else
			{                           // 1st sparse matrix col is greater than 2nd  s[i][1]>S2.s[j][1]
				S3.s[k][0]=S2.s[j][0];
				S3.s[k][1]=S2.s[j][1];  // above conditions gets false then copy col of 2nd sparse matrix
				S3.s[k][2]=S2.s[j][2];
				
				j++;
				k++;
			}
		
		}
		
		else
		{
			if (s[i][0]<S2.s[j][0])        // if respective row of 1st matrix is less than other, then copy 1st row in 3rd sparse matrix 
			{
		  	  S3.s[k][0]=s[i][0];
		 	  S3.s[k][1]=s[i][1];
		  	  S3.s[k][2]=s[i][2];     
				i++;
				k++;                // ***** all talks about row size (big or small)
			}
		
		   else
		   {  
		      S3.s[k][0]=S2.s[j][0];
			  S3.s[k][1]=S2.s[j][1];         // 1st sparse matrix row is greater than 2nd  s[i][0]>S2.s[j][0]
			  S3.s[k][2]=S2.s[j][2];
				
			  j++;
			  k++;
		   	
		   }
		
		}

	} //While loop ended
	
	
	while (i<=n && j>=n)
	{
		S3.s[k][0]=s[i][0];
		S3.s[k][1]=s[i][1];
		S3.s[k][2]=s[i][2];   // If both are same
		
		i++;
		k++;
	}
	
	while (j<=n && i<=n)
	{
		S3.s[k][0]=S2.s[j][0];
		S3.s[k][1]=S2.s[j][1];
		S3.s[k][2]=S2.s[j][2];
		
		j++;
		k++;
	}
	
	S3.s[0][2]=k-1;
	
	
}//Sparse Sparse ended


Sparse Sparse :: transpose()
{
	int i,j,k=1;
	Sparse S3;

	S3.s[0][0] = s[0][1];
	S3.s[0][1] = s[0][0];
	S3.s[0][2] = s[0][2];
	
	for(i=0;i<s[0][1];i++)
	{
		for(j=1;j<=s[0][2];j++)
		{
			if (s[j][1]==i)
			{
				S3.s[k][0]=s[j][1];
				S3.s[k][1]=s[j][0];
				S3.s[k][2]=s[j][2];
				k++;
			}
		}
	}
	return S3;
 }
 
 Sparse Sparse :: multiply(Sparse S2)
{
	Sparse S3;
	int i,j,t1,t2,t3=1,sum;
	S2=S2.transpose();

	S3.s[0][0] = s[0][0];
	S3.s[0][1] = S2.s[0][0];


if(s[0][1]!=S2.s[0][1])
{
 cout<<"\nMultiplication is not possible";
 return S3; 
}
 
else
{
  	for(i=0;i<s[0][0];i++)
	{
		for(j=0;j<S2.s[0][0];j++)
		{ 
			int flag1 =0,flag2=0;
		    t1=1;
		    t2=1;
		    sum=0;

				while(t1<=s[0][2])
				{
					if (s[t1][0] == i)
					{
						flag1 = 1;
						break;
					}
					t1++;
				}
				
				while(t2<=S2.s[0][2])
				{
					if(S2.s[t2][0] == j)
					{
						flag2 = 1;
						break;
					}
					t2++;
				}
				
				if(flag1 == 1 && flag2 == 1)
				{
					while(s[t1][0]==i && S2.s[t2][0]==j) //row are same
					{
						if (s[t1][1] == S2.s[t2][1])   //col are same
						{
							sum=sum+s[t1][2]*S2.s[t2][2];
							t1++;
							t2++;						
						}
						else if(s[t1][1]<S2.s[t2][1]) //row no. is less than col. no. of 2nd matrix
						{
							t1++;
						}
						else //s[t1][1]>S2.s[t2][1]
						{
						   t2++;
						} 
					}
				  if(sum>0)
					 {
					 	S3.s[t3][0]=i;
					 	S3.s[t3][1]=j;
					 	S3.s[t3][2]=sum; 
						t3++;
				     }
				}
					
				 
		}
		
			
	}
S3.s[0][2]=t3-1;
return S3;
	
 }

}


int main()
{
	Sparse S,S2,S3;
	int p;
do
{
	
	cout<<"\n1.Read\n2.Convert\n3.Display\n4.Addition\n5.Transpose\n6.Multiplication\n7.Exit\n\nEnter your choice :";
	cin>>p;
	
	switch(p)
	{
	   case 1:
	   	 cout<<"\nFirst Matrix\n";
	     S.read();
	     cout<<"\nSecond Matrix\n";
	     S2.read();
	     break;
		 
	   case 2:
	   	 cout<<"1st converting done";
	     S.convert();
	     cout<<"\n2nd converting done\n"; 
	     S2.convert();
		 break;
		 
	   case 3:
	   	 cout<<"1st triplet is....\n";
	     S.display();
	     cout<<"\n2nd triplet is.....\n"; 
	     S2.display();
		 break;
		
	   case 4:
	 	 S3=S.addition(S2);
	   	 S3.display();
         break;
         
	   case 5:
	   	 //cout<<"First matrix transpose is";
	     //S3=S.transpose();
	     //S3.display();
	     //cout<<"\n";
	     cout<<"Second matrix transpose is";
	     S3=S2.transpose();
	     S3.display();
		 break;	 

	 case 6:
		 
		 S3=S.multiply(S2);
		 S3.display();
		 break;
					 
	   case 7:
	   	 cout<<"Exiting.......";
	     exit(0);
		  	
	   default:
	   	 cout<<"Invalid choice!! Try again";
		
	}
}
while(p!=6);
}
