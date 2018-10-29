#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
#define name 20
#define Size 50
class Personal
{
	private:
		char Name[name];
		int age;
		long Contact_Number;
		
	public:
		Personal(int x,long y,char z[])
		{
			age=x;
			Contact_Number=y;
			strcpy(Name,z);
		}
		void getName(char Namecpy[]){
			strcpy(Namecpy,Name);
		}
		int getAge(){
			return age;
		}
		long getContact_Number(){
			return Contact_Number;
		}
};

class Academic
{
	private:
		int Grad;
		int PostGrad;
		char Course[Size];
		
	public:
		Academic(int x,int y,char z[])
		{
			Grad=x;
			PostGrad=y;
			strcpy(Course,z);
		}
		int getGrad(){
			return Grad;
		}	
		int getPostGrad(){
			return PostGrad;
		}
		void getCourse(char Coursecpy[]){
			strcpy(Coursecpy,Course);
		}
		
};

class Professional
{
	private:
		int Work_Exp;
		char Last_Place[Size];

	public:
		Professional(int x,char y[])
		{
			Work_Exp=x;
			strcpy(Last_Place,y);
		}
		int getWorkExp(){
			return Work_Exp;
		}
		
		void getName(char Last_Placecpy[]){
			strcpy(Last_Placecpy,Last_Place);
		}
				
		
		
};
		
class Driver:private Personal,private Professional,private Academic
{
	private:
		bool del;
	public:
		Driver():Personal(0,0,"NONE"),Academic(0,0,"NONE"),Professional(0,"NONE")
		{	
			del=false;
		}
		Driver(char a[],char b[],char d[],int w,int x,int y,int z,long c):Personal(w,c,a),Academic(y,z,b),Professional(x,d)
		{	
			
			del=false;
		}
		bool isDelete()
		{
			return del;
		}
		void delet()
		{
			del=true;
		}
		void display();
		void getData(Driver data[],int c);
		void tablehead();
		void tabletail();
};

void Driver::tablehead()
{
	tabletail();
	cout<<"|Name               |Age   |Contact   |Graduation-Year|Post-Grad|Course Name|Work Exp|Last Place Worked     |\n";
	tabletail();

}
void Driver::tabletail()
{
	int i;
	for(i=0;i<110;i++)
		cout<<"-";
	cout<<"\n";
	return;
}


void Driver::display()
{
	char *Str;
	Str=new char[150];
	Personal::getName(Str);
	cout<<"|"<<setw(19)<<left<<Str<<"|"<<setw(6)<<Personal::getAge()<<"|"<<setw(10)<<Personal::getContact_Number()<<"|"<<setw(15)<<Academic::getGrad()<<"|"<<setw(9)<<Academic::getPostGrad()<<"|";
	Academic::getCourse(Str);
	cout<<setw(11)<<Str<<"|"<<setw(8)<<Professional::getWorkExp()<<"|";
	Professional::getName(Str);
	cout<<setw(22)<<Str<<"|\n";
	tabletail();
	
}	

void Driver::getData(Driver data[],int c)
{
	char a[name],b[Size],d[Size];
	int w,x,y,z;
	long c1;
	
	cout<<"Enter name:";
	cin.ignore();
	cin.getline(a,name);
	
	cout<<"Enter Contact Number:";
	cin>>c1;
	cout<<"Enter Age:";
	cin>>w;
	cout<<"Enter Work Experience:";
	cin>>x;
	cout<<"Enter Year of Graduation:";
	cin>>y;
	cout<<"Enter Year of Post-Graduation:";
	cin>>z;
	cout<<"Enter Course Taken:";
	cin.ignore();
	cin.getline(b,Size);
	cout<<"Enter Last Work Place:";
	cin.getline(d,Size);
	data[c]=Driver(a,b,d,w,x,y,z,c1);
}


int main()
{
	Driver D[50],dummy;
	int c=0,n;
	int i;
	int choice;
	do
	{
		cout<<"Press 1 to Build Master Table\n";
		cout<<"Press 2 to Insert a record\n";
		cout<<"Press 3 to Display Master Table\n";
		cout<<"Press 4 to Exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				
				cout<<"Enter Number of records you want to enter\n";
				cin>>n;
				if(c==50)
				{
					cout<<"Memory Full";
					break;
				}
				if(n>50)
				{
					cout<<"Not enough Memory";
					break;
				}	
				for(i=1;i<=n;i++)
				{
					cout<<"Enter Record "<<i;
					dummy.getData(D,c);
					c++;
				}
				break;
				
			case 2:
				dummy.getData(D,c);
				c++;
				cout<<"Data Entered\n";
				break;
				
			case 3:
				dummy.tablehead();
				for(i=0;i<c;i++)
				{
					D[i].display();
				}
				break;
				
			case 4:
				break;	
		}
	}
	while(choice!=4);
}
