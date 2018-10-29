#include<iostream>
using namespace std;
class WeatherReport
{
	
	
	private:int dayofmonth;
		float hightemp;
		float lowtemp;
		float snow;
		float rain;
		static float avglowT;
		static float avgrain;
		static float avgsnow;
		static float avghighT;	
	public: void accept(WeatherReport [],int);
		void display();
		void displayavg();
		void calculate(WeatherReport T[],int c);
		void reset();
	
	
	WeatherReport()
		{
			dayofmonth=99;
			hightemp=999.0;
			lowtemp=-999.0;
			snow=0.0;
			rain=0.0;
		}
	
		WeatherReport(int d,float h,float l,float s,float r)
		{
			dayofmonth=d;
			hightemp=h;
			lowtemp=l;
			snow=s;
			rain=r;

		}		
	
};
        float WeatherReport::avglowT;
	float WeatherReport::avgrain;
	float WeatherReport::avgsnow;
	float WeatherReport::avghighT;	
void WeatherReport::accept(WeatherReport w[30],int x)
{	
	int a;
	float b,c,d,e;
	do
	{
		cout<<"Enter Day of month: ";
		cin>>a;
		if((a>30)||(a<0))
		{
			cout<<"Enter Valid amount\n";
		}
	}
	while((a>30)||(a<0));
	do
	{
	cout<<"Enter Highest Temperature: ";
	cin>>b;
	cout<<"Enter Lowest temperature: ";
	cin>>c;
	}
	while(b<c);
	do
	{
		cout<<"Enter amount of snow: ";
		cin>>d;
		if(snow<0)
		{
			cout<<"Enter valid amount\n";
		}
	}
	while(d<0);
	
	do
	{
		cout<<"Enter amount of rainfall: ";
		cin>>e;
		if(d<0)
		{
			cout<<"Enter valid amount\n";
		}
	}
	while(d<0);
	w[x]=WeatherReport(a,b,c,d,e);
}

void WeatherReport::calculate(WeatherReport T[],int c)
{	

	int i;
	for(i=0;i<c;i++)
	{
		avghighT+=T[i].hightemp;
		avglowT+=T[i].lowtemp;
		avgrain+=T[i].rain;
		avgsnow+=T[i].snow;
	}
	avghighT=avghighT/(c+1);
	avglowT=avglowT/(c+1);
	avgrain=avgrain/(c+1);
	avgsnow=avgsnow/(c+1);
}
void WeatherReport::reset()
{
	 avghighT=0;
	 avglowT=0;
	 avgrain=0;
	 avgsnow=0;
}

void WeatherReport::displayavg()
{
	cout<<hightemp;
	cout<<"Average High Temperature is :"<<avghighT<<"\n";
	cout<<"Average Low Temperature is :"<<avglowT<<"\n";
	cout<<"Average Snowfall is :"<<avgsnow<<"\n";
	cout<<"Average Rainfall is :"<<avgrain<<"\n";	
}
void WeatherReport::display()
{
	cout<<endl<<dayofmonth<<"\t\t"<<hightemp<<"\t\t"<<lowtemp<<"\t\t\t"<<rain<<"\t\t"<<snow<<endl;
}

int main()
{
	int c=0;
	int ch;
	WeatherReport w[30],d;
	cout<<"Weather Report!!\n\n\n";
	do
	{
		cout<<"Press 1 to Enter Data\n";
		cout<<"Press 2 to Calculate Data\n";
		cout<<"Press 3 to Display Average\n";
		cout<<"Press 4 to Display Table\n";
		cout<<"Press 5 to Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:	if(c<30)
				{       
					d.accept(w,c);
					c++;
					cout<<c;
				}
				else
				{
					cout<<"Cannot enter more data"; 
				}
				break;
				
			case 2:
				if(c==0)
				{
					cout<<"Cannot Calculate Please Enter Data";
					break;
				}
				d.reset();
				d.calculate(w,c);
				cout<<"Calculated\n";
				
			case 3:
				d.displayavg();
				cout<<"\n";
				break;
				
			case 4:	int i;
				cout<<"\nMonthly Weather Report :\nDay\tHigh Temperature\tLow Temperature\t\tRain\t\tSnow\n";
				for(i=0;i<30;i++)
				{
					w[i].display();
				}
				break;
			
			case 5:break;
				
			default:
				cout<<"Enter Valid data\n";
		}
	}while(ch!=5);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
