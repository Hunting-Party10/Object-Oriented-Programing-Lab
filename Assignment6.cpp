#include <iostream>
using namespace std;

class Shape
{
private:
	double a;
	double b;
public:
	Shape()
	{
		a=0;
		b=0;
	}
	virtual double compute_area()=0;
};

class Rectangle:public Shape
{
private:
	double a;
	double b;
public:
	Rectangle(double x,double y)
	{
		a=x;
		b=y;
	}
	double compute_area()
	{
		return  a*b;
	}
	
};

class Triangle:public Shape
{
private:
	double a;
	double b;
public:
	Triangle(double x,double y)
	{
		a=x;
		b=y;
	}
	double compute_area()
	{
		return  0.5*a*b;
	}
};

int main()
{
	Shape *s;
	int choice;
	Rectangle r(0,0);
	Triangle t(0,0);
	double x,y,ans;
	do
	{
		cout<<"\n\nPress 1 to Calculate Area for Rectangle\n";
		cout<<"Press 2 to calculate Area for Triangle\n";
		cout<<"Press 3 to Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter Length of the Rectangle : ";
				cin>>x;
				cout<<"Enter Breadth of the Rectangle :";
				cin>>y;
				r=Rectangle(x,y);
				s=&r;
				ans=s->compute_area();
				cout<<"Length of Rectangle is :"<<x<<"cm\n";
				cout<<"Breadth of Rectangle is :"<<y<<"cm\n";
				cout<<"Area is :"<<ans<<"cm2";
				break;

			case 2:
				cout<<"Enter Base of the Triangle : ";
				cin>>x;
				cout<<"Enter Heigth of the Rectangle :";
				cin>>y;
				t=Triangle(x,y);
				s=&t;
				ans=s->compute_area();
				cout<<"Base of Triangle is :"<<x<<"cm\n";
				cout<<"Height of Triangle is :"<<y<<"cm\n";
				cout<<"Area is :"<<ans<<"cm2";
				break;
			case 3:
				break;
		}

	}
	while(choice!=3);
	
}
