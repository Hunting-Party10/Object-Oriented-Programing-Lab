#include <iostream>
#include <limits>
#include<cmath>
using namespace std;

class Exception_Handling
{
private:
	double a,b;
public:
	Exception_Handling(double x,double y)
	{
		a=x;
		b=y;
	}
	double divide()
	{
		try
		{
			if(b == 0)
				throw b;
			else
			{
				return a/b;
			}
		}
		catch(double z)
		{
			cout<<"Unable to Divide";
			return numeric_limits<double>::infinity();
		}
	}
	
};

int main()
{
	Exception_Handling e(0.0,0.0);
	int choice;
	double a,b,ans;
	do
	{
		cout<<"\n\nPress 1 to Enter 2 Numbers\n";
		cout<<"Press 2 to divide\n";
		cout<<"Press 3 to Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter 1st Number:";
				cin>>a;
				cout<<"Enter 2nd Number:";
				cin>>b;
				e=Exception_Handling(a,b);
				break;
			case 2:
				cout<<"Atempting to divide\n";
				ans=e.divide();
				if(isfinite(ans))
					cout<<"Division is:"<<ans<<"\n";
				break;
			case 3:
				break;
			default:
				cout<<"Enter valid Option";
		}
	}
	while(choice!=3);
	return 0;
}