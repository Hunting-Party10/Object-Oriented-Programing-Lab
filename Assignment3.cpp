#include<iostream>
#include<string.h>
using namespace std;
class Complex
{
	private:
		float x;
		float y;

	public:
			Complex()
			{
				x=0;
				y=0;
			}
		void accept(int,int);
		void display();
		Complex operator *(Complex);
		Complex operator /(Complex);
		friend Complex operator +(Complex,Complex);
		friend Complex operator -(Complex,Complex);
		void conjugate();
};

void Complex::display()
{
	
	if(y>0)
	{
		cout<<x<<"+i"<<y<<"\n";
	}
	if(y<0)
	{
		cout<<x<<"-i"<<-1*y<<"\n";
	}
	if(y==0)
	{
		cout<<x<<"+i0"<<"\n";
	}

}

void Complex::conjugate()
{
		y=-1*y;
}

void Complex::accept(int real,int complex)
{
	x=real;
	y=complex;
}

Complex Complex::operator *(Complex C)
{
	Complex Answer;
	
	if((C.y==(-1*y))&&(C.x==x))
	{
		Answer.x=x*x+y*y;
		Answer.y=0;
	}
	else
	{
		Answer.x=x*C.x-y*C.y;
		Answer.y=C.x*y+C.y*x;
	}
	return Answer;
}

Complex Complex::operator /(Complex C)
{
	Complex Answer;
	Complex Conj=C;
	Conj.conjugate();
	Complex Temp2;
	Temp2.x=x;
	Temp2.y=y;
	Complex d=C*Conj;
	Complex n=Temp2*Conj;
	Answer.x=n.x/d.x;
	Answer.y=n.y/d.x;
	return Answer;
}

Complex operator +(Complex A,Complex B)
{
	Complex Answer;
	Answer.x=A.x+B.x;
	Answer.y=A.y+B.y;
	return Answer;
}

Complex operator -(Complex A,Complex B)
{
	Complex Answer;
	Answer.x=A.x-B.x;
	Answer.y=A.y-B.y;
	return Answer;
}

int main()
{
	Complex A,B,Answer;
	int choice,real,complex,c=0;
	do
	{
		cout<<"\nComplex Calculator\n";
		cout<<"Press 1 to Enter new values for Complex number\n";
		cout<<"Press 2 to display Entered values\n";
		cout<<"Press 3 to do addition\n";
		cout<<"Press 4 to do subtraction\n";
		cout<<"Press 5 to do multiplication\n";
		cout<<"Press 6 to do division\n";
		cout<<"Press 7 to Exit\n";
		cin>>choice;
		cout<<"\n";
		switch(choice)
		{
			case 1:
				{
					int ch=1;
					if(c!=0)
					{
						cout<<"A:";
						A.display();
						cout<<"B:";
						B.display();
						int flag;
						do
						{
							cout<<"Do you want to enter new values?\n(1:Yes,2:No)\n-";
							cin>>ch;
							if((ch==1)||(ch==2))
							{
								
								flag=0;
							}
							else
							{
								cout<<"Invalid Option Please enter again\n";
								flag=1;
							}
						}
						while(flag==1);
					}
					else
					{
						cout<<"No Default Values Exist\n";
					}
					if(ch==1)
					{
						cout<<"Enter Real Value of A:";
						cin>>real;
						cout<<"Enter Complex value of A:";
						cin>>complex;
						A.accept(real,complex);
						cout<<"Enter Real Value of B:";
						cin>>real;
						cout<<"Enter Complex value of B:";
						cin>>complex;
						B.accept(real,complex);
						c++;
					}
					else
					{
						cout<<"Aborted\n";
					}
				}
				break;
				
			case 2:
				if(c==0)
				{
					cout<<"Enter Values First Please\n";
				}
				else
				{
					cout<<"A:";
					A.display();
					cout<<"B:";
					B.display();
				}
				break;
			
			case 3:
				if(c==0)
				{
					cout<<"Enter Values First Please\n";
				}
				else
				{
					cout<<"A:";
					A.display();
					cout<<"B:";
					B.display();
					Answer=A+B;
					cout<<"A+B is:";
					Answer.display();					
				}
				break;
				
			
			case 4:
				if(c==0)
				{
					cout<<"Enter Values First Please\n";
				}
				else
				{
					cout<<"A:";
					A.display();
					cout<<"B:";
					B.display();
					cout<<"A-B is:";
					Answer=A-B;
					Answer.display();
					cout<<"B-A is:";		
					Answer=B-A;
					Answer.display();
				}				
				break;
			
			case 5:
				if(c==0)
				{
					cout<<"Enter Values First Please\n";
				}
				else
				{
					cout<<"A:";
					A.display();
					cout<<"B:";
					B.display();
					cout<<"A*B is:";
					Answer=A*B;
					Answer.display();
					cout<<"B*A is:";
					Answer=B*A;
					Answer.display();
				}
				break;
			
			case 6:
				if(c==0)
				{
					cout<<"Enter Values First Please\n";
				}
				else
				{
					cout<<"A:";
					A.display();
					cout<<"B:";
					B.display();
					cout<<"A/B is:";
					Answer=A/B;
					Answer.display();
					cout<<"B/A is:";
					Answer=B/A;
					Answer.display();
				}		
				break;
			
			case 7:
				cout<<"Exiting\n";
				break;
			
			default:
				cout<<"Enter valid option\n";
		}	
	}
	while(choice!=7);
	return 0;
}









