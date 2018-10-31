#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Base1{

	private:
		char Name[20];
		int Dob;
		char BG[3];

	public:

		void getName(char Namecpy[]){
			strcpy(Namecpy,Name);
		}
		void setName(char Namecpy[]){
			strcpy(Name,Namecpy);
		}
		int getDob(){
			return Dob;
		}
		void setDob(int dob){
			Dob=dob;
		}
		void getBG(char BGcpy[]){
			strcpy(BGcpy,BG);
		}
		void setBG(char BGcpy[]){
			strcpy(BG,BGcpy);
		}

};

class Base2
{
	private:
		int Height;
		int Weight;
	public:
		int getHeight(){
			return Height;
		}
		void setHeight(int Heightcpy){
			Height=Heightcpy;
		}
		int getWeight(){
			return Weight;
		}
		void setWeight(int Weightcpy){
			Weight=Weightcpy;
		}

};

class Base3
{
	private:
		long Insurance_Number;
		char Address[150];
		public:
		long getInsurance_Number(){
			return Insurance_Number;
		}
		void setInsurance_Number(long Insurance_Numbercpy){
			Insurance_Number=Insurance_Numbercpy;
		}
		void getAddress(char Addresscpy[150]){
			strcpy(Addresscpy,Address);
		}
		void setAddress(char Addresscpy[150]){
			strcpy(Address,Addresscpy);
		}
};

class Derived:private Base1,private Base2,private Base3
{
	private:
		long Contact_Number;
		long License_Number;
	public:
		long getContact_Number(){
			return Contact_Number;
		}
		void setContact_Number(long Contact_Numbercpy){
			Contact_Number=Contact_Numbercpy;
		}
		long getLicense_Number(){
			return License_Number;
		}
		void setLicense_Number(long License_Numbercpy){
			License_Number=License_Numbercpy;
		}

	public:
		void display();
		void getData(Derived data[],int c);
		int searchData(Derived data[50],long query,int c);
		void deleteData();
		void tablehead();
		void tabletail();
		void modify();
		int validatedelete(int delete_index,int delete_counter[]);
};

void Derived::modify()
{
	int ch;
	char *String;
	long number;
	int num;
	int t;
	do
	{
		cout<<"\nWhat do u want to modify\n1.Name\n2.Blood Group\n3.Date of Birth\n4.Height\n5.Weight\n6.Address\n7.Insurance Policy Number\n8.Telephone Number\n9.Driving License Number\n10.Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				String=new char[20];
				cout<<"Enter Name of Client:";
				cin.ignore();
				cin.getline(String,20);
				Base1::setName(String);
				delete String;
				cout<<"Modified\n";
					break;

			case 2:
				String=new char[3];
				cout<<"Enter BloodGroup of Client:";
				cin.ignore();
				cin.getline(String,3);
				setBG(String);
				delete(String);
				cout<<"Modified\n";
					break;

			case 3:
				cout<<"Enter Date of Birth\n";
				cout<<"Enter Year:";
				cin>>t;
				num=t*100;
				do
				{
					cout<<"Enter Month:";
					cin>>t;
					if((t<=0)&&(t>=13))
					{
							cout<<"Enter valid Month\n";
					}
				}
				while((t<=0)&&(t>=13));
				num+=t;
				num=num*100;
				do
				{
				cout<<"Enter Day:";
				cin>>t;
				if((t<=0)&&(t>=32))
					{
						cout<<"Enter valid Month";
					}
				}
				while((t<=0)&&(t>=32));
				num+=t;
				Base1::setDob(num);
				cout<<"Modified\n";
				break;

			case 4:
				cout<<"Enter Height:";
				cin>>num;
				Base2::setHeight(num);
				cout<<"Modified\n";
				break;

			case 5:
				cout<<"Enter Weight:";
				cin>>num;
				Base2::setWeight(num);
				cout<<"Modified\n";
				break;


			case 6:
				cout<<"Enter Address:";
				String=new char[150];
				cin.ignore();
				cin.getline(String,150);
				Base3::setAddress(String);
				delete(String);
				cout<<"Modified\n";
					break;

			case 7:
				cout<<"Enter Insurance Number";
				cin>>number;
				Base3::setInsurance_Number(number);
				cout<<"Modified\n";
					break;

			case 8:
				cout<<"Enter Contact Number:";
				cin>>number;
				Derived::setContact_Number(number);
				cout<<"Modified\n";
				break;

			case 9:
				cout<<"Enter License Number:";
				cin>>number;
				Derived::setLicense_Number(number);
				cout<<"Modified\n";
				break;

			case 10:break;

			default:cout<<"\nEnter VALID Choice..!!\n";
		}
	}while(ch!=10);

	cout<<"\nData Modified Successfully..!!\n";
}

void Derived::display()
{
	char *Str;
	Str=new char[150];
	Base1::getName(Str);
	cout<<"|"<<setw(19)<<std::left<<Str<<"|";
	int n=getDob();
	cout<<setw(2)<<n%100<<"-";
	n=n/100;
	cout<<setw(2)<<n%100<<"-";
	n=n/100;
	cout<<setw(4)<<n;
	cout<<"   |"<<setw(6)<<Base2::getHeight()<<"|"<<setw(6)<<Base2::getWeight()<<"|";
	Base1::getBG(Str);
	cout<<setw(11)<<Str<<"|"<<setw(9)<<getContact_Number()<<"|"<<setw(11)<<getLicense_Number()<<"|"<<setw(13)<<Base3::getInsurance_Number()<<"|";
	Base3::getAddress(Str);
	cout<<setw(22)<<Str<<"|\n";
	tabletail();

}
int Derived::searchData(Derived data[50],long query,int c)
{
	int i;
	for(i=0;i<c;i++)
	{
		if(data[i].getInsurance_Number()==query)
			{
				return i;
			}
	}
	return-1;
}

void Derived::deleteData()
{
	return;
}
void Derived::tablehead()
{
	tabletail();
	cout<<"|Name               |Date of Birth|Height|Weight|Blood Group|Contact  |License No.|Insurance No.|Address               |\n";
	tabletail();

}
void Derived::tabletail()
{
	int i;
	for(i=0;i<120;i++)
		cout<<"-";
	cout<<"\n";
	return;
}
void Derived::getData(Derived data[],int c)
{
	char *String;
	long number;
	int num;
	int t;
	String=new char[20];
	cout<<"Enter Name of Client:";
	cin.ignore();
	cin.getline(String,20);
	Base1::setName(String);
	delete String;
	cout<<"Enter Date of Birth\n";
	cout<<"Enter Year:";
	cin>>t;
	num=t*100;
	do
	{
	cout<<"Enter Month:";
	cin>>t;
	if((t<=0)&&(t>=13))
		{
			cout<<"Enter valid Month\n";
		}
	}
	while((t<=0)&&(t>=13));
	num+=t;
	num=num*100;
	do
	{
	cout<<"Enter Day:";
	cin>>t;
	if((t<=0)&&(t>=32))
		{
			cout<<"Enter valid Month";
		}
	}
	while((t<=0)&&(t>=32));
	num+=t;
	Base1::setDob(num);
	String=new char[3];
	cout<<"Enter BloodGroup of Client:";
	cin.ignore();
	cin.getline(String,3);
	setBG(String);
	delete(String);
	cout<<"Enter Height:";
	cin>>num;
	Base2::setHeight(num);
	cout<<"Enter Weight:";
	cin>>num;
	Base2::setWeight(num);
	cout<<"Enter Contact Number:";
	cin>>number;
	Derived::setContact_Number(number);
	cout<<"Enter License Number:";
	cin>>number;
	Derived::setLicense_Number(number);
	do
	{
		cout<<"Enter Insurance Number:";
		cin>>number;
		t=Derived::searchData(data,number,c);
		if(t!=-1)
			cout<<"Cannot have same Insurance Number Please Re-Enter data\n";
	}
	while(t!=-1);
	Base3::setInsurance_Number(number);
	cout<<"Enter Address:";
	String=new char[150];
	cin.ignore();
	cin.getline(String,150);
	Base3::setAddress(String);
	delete(String);
}

int validatedelete(int delete_index[],int delete_counter,int query)
{
	int i;
	for(i=0;i<delete_counter;i++)
	{
		if(delete_index[i]==query)
			return -1;
	}
	return query;
}

int main()
{
	Derived dummy;
	Derived data[50];
	int delete_index[50];
	int delete_counter=0;
	int c=0;
	int ch;
	do
	{
		cout<<"\n\nInsurance Pvt.Ltd\n\n";
		cout<<"Press 1 to Display Database\n";
		cout<<"Press 2 to Add data\n";
		cout<<"Press 3 to Search data\n";
		cout<<"Press 4 to Update database\n";
		cout<<"Press 5 to Delete\n";
		cout<<"Press 6 to Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(c==0)
				{
					cout<<"Database Empty\n";
				}
				else
				{
					if(delete_counter==0)
						dummy.tablehead();
					int i,j;
					int z=0;
					for(i=0;i<c;i++)
					{
						int flag=0;
						for(j=0;j<delete_counter;j++)
						{
							if(i==delete_index[j])
							{
								flag=1;
								break;
							}
							z++;
						}
						if(flag==0)
						{
							if(z==1)
								dummy.tablehead();
							data[i].display();
						}
					}
				}
				break;

			case 2:
				if(delete_counter==0)
				{
					data[c].getData(data,c);
					c++;
				}
				else
				{
					data[delete_index[delete_counter-1]].getData(data,c);
					delete_counter--;
				}
				cout<<"\nData Added\n";
				break;

			case 3:
				if(c==0)
				{
					cout<<"Database Empty\n";
				}
				else
				{
					cout<<"Enter Insurance Number you want to search:";
					long query;
					cin>>query;
					int index=dummy.searchData(data,query,c);
					index=validatedelete(delete_index,delete_counter,index);
					if(index!=-1)
					{
						dummy.tablehead();
						data[index].display();
					}
					else
					{
						cout<<"Record Not Found\n";
					}

				}
				break;

			case 4:
				if(c==0)
				{
					cout<<"Database Empty\n";
				}
				else
				{
					cout<<"Enter Insurance Number you want to search:";
					long query;
					cin>>query;
					int index=dummy.searchData(data,query,c);
					index=validatedelete(delete_index,delete_counter,index);
					if(index!=-1)
					{
						int choice;
						cout<<"Record Found\n";
						dummy.tablehead();
						data[index].display();
						do
						{
							cout<<"Do you want to Modify(1-Yes,2-No)";
							cin>>choice;
							if(choice==1)
							{

								data[index].modify();
								break;
							}
							if(choice==2)
							{
								cout<<"Aborted\n";
								break;
							}
							cout<<"Enter Valid Option\n";
						}
						while(choice!=1||choice!=2);

					}
					else
					{
						cout<<"Record Not Found\n";
					}
				}
				break;

			case 5:
				if(c==0)
				{
					cout<<"Database Empty\n";
				}
				else
				{
					cout<<"Enter Insurance Number you want to search:";
					long query;
					cin>>query;
					int index=dummy.searchData(data,query,c);
					index=validatedelete(delete_index,delete_counter,index);
					if(index!=-1)
					{
						int choice;
						cout<<"Record Found\n";
						dummy.tablehead();
						data[index].display();
						do
						{
							cout<<"Do you want to delete(1-Yes,2-No)";
							cin>>choice;
							if(choice==1)
							{
								delete_index[delete_counter]=index;
								cout<<"Record Deleted\n";
								delete_counter++;
								break;
							}
							if(choice==2)
							{
								cout<<"Aborted\n";
								break;
							}
							cout<<"Enter Valid Option\n";
						}
						while(choice!=1||choice!=2);
					}
					else
					{
						cout<<"Record Not Found\n";
					}
				}
				break;

			case 6:
				break;
			default:
				cout<<"Enter Valid Option\n";
		}
	}
	while(ch!=6);
	return 1;
}
