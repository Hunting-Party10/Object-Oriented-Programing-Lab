#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class lib
{
	private:
		char *author;
		char *name;
		char *publisher;
		float *price;
		int *stock;
		static int records;
		static int bill;


	public:
		lib()
		{
			author=new char[50];
			name=new char[50];
			publisher=new char[50];
			price=new float;
			stock=new int;
		}

		lib(char nm[50],char athr[50],char pblshr[50],float prc,int stck)
		{
			author=new char[50];
			name=new char[50];
			publisher=new char[50];
			price=new float;
			stock=new int;
			strcpy(author,athr);
			strcpy(name,nm);
			strcpy(publisher,pblshr);
			*price=prc;
			*stock=stck;
		}
		void purchase();
		void delete_data();
		void newEntry(lib *l[50],int c);
		void display();
		void reset();
		void update(lib *l[50],int index);
		int search(lib *l[50],int c,char query[50]);
		void tablehead();
		void tabletail();
};

int lib::records;
int lib::bill;

void lib::newEntry(lib *l[50],int t)
{
	char a[50],b[50],c[50];
	float d;
	int e;
	cout<<"Enter Book Name:";
	cin>>a;
	cout<<"Enter Author Name:";
	cin>>b;
	cout<<"Enter Publisher:";
	cin>>c;
	cout<<"Enter Price:";
	cin>>d;
	cout<<"Enter Stock:";
	cin>>e;
	*l[t]=lib(a,b,c,d,e);
}

void lib::update(lib *l[50],int index)
{
	cout<<"Enter New Price:";
	cin>>*l[index]->price;
	cout<<"Enter New Stock:";
	cin>>*l[index]->stock;
}


int lib::search(lib *l[50],int c,char query[50])
{
	int i;
	for(i=0;i<c;i++)
	{
		if(strcmp(l[i]->name,query)==0)
		{
			return i;
		}
	}
	return -1;
}

void lib::display()
{
	cout<<"|"<<setw(15)<<std::left<<author<<"|"<<setw(15)<<std::left<<name<<"|"<<setw(10)<<std::left<<*price<<"|"<<setw(8)<<std::left<<*stock<<"|\n";
	tabletail();
}

void lib::purchase()
{
	if(*stock!=0)
	{
		*stock-=1;
		records++;
		bill+=*price;
		cout<<"You have purchased :"<<records<<" books\n"<<"Your total bill is:Rs"<<bill<<"\n";
	}
	else
	{
		cout<<"No stock available,Unable to purchase book\n";
	}
}

void lib::reset()
{
	records=0;
	bill=0;
}

void lib::delete_data()
{
	delete(author);
	delete(name);
	delete(publisher);
	delete(price);
	delete(stock);
}

void lib::tablehead()
{
	tabletail();
	cout<<"|Author         |Book Name      |Price     |Stock   |\n";
	tabletail();
}

void lib::tabletail()
{
	int i;
	for(i=1;i<=53;i++)
		cout<<"-";
	cout<<"\n";
}

int main()
{
	int ch=0,i;
	int c=0;
	lib *l[50],*dummy=new lib;
	char query[50];
	int index;
	int delete_counter=0;
	int delete_index[50];
	dummy->reset();
	do
	{
		cout<<"\n\nBook Store\n\n";
		cout<<"Press 1 to Enter Data\n";
		cout<<"Press 2 to Display data\n";
		cout<<"Press 3 to Search data\n";
		cout<<"Press 4 to Update Book\n";
		cout<<"Press 5 to Purchase\n";
		cout<<"Press 6 to Delete\n";
		cout<<"Press 7 to Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				if(delete_counter==0)
				{
					l[c]=new lib;
					dummy->newEntry(l,c);
					c++;
				}
				else
				{
					int d=delete_index[delete_counter-1];
					l[d]=new lib;
					dummy->newEntry(l,d);
					delete_counter--;
				}
				break;

			case 2:
				int j;
				if(delete_counter==0)
				{
					dummy->tablehead();
					for(i=0;i<c;i++)
					{

						l[i]->display();
					}
				}
				else
				{
					dummy->tablehead();
					for(i=0;i<c;i++)
					{
						int flag=0;
						for(j=0;j<delete_counter;j++)
						{
							if(i==delete_index[j])
							{
								flag=1;
							}
							if(flag==0)
							{

								l[i]->display();
							}
						}
					}
				}

				break;

			case 3:
				cout<<"Enter Title of the book you want to search:";
				cin>>query;
				index=dummy->search(l,c,query);
				if(index!=-1)
				{
					dummy->update(l,index);
				}
				else
				{
					cout<<"Record Not found\n";
				}
				break;

			case 4:
				cout<<"Enter Title of the book you want to search:";
				cin>>query;
				index=dummy->search(l,c,query);
				if(index!=-1)
				{
					dummy->update(l,index);
				}
				else
				{
					cout<<"Record Not found\n";
					break;
				}
				break;
			case 5:
				cout<<"Enter Title of the book you want to search:";
				cin>>query;
				index=dummy->search(l,c,query);
				if(index!=-1)
				{
					cout<<"Book Found\n";
					l[index]->display();
					cout<<"\nPress 1 to purchase\nPress 2 to Exit\n";
					int ch;
					cin>>ch;
					if(ch==1)
					{
						l[index]->purchase();
					}
					else
					{
						cout<<"Purchase Canceled\n";
					}
				}
				else
				{
					cout<<"Record Not found\n";

				}
				break;

			case 6:
				cout<<"Enter Title of the book you want to search:";
				cin>>query;
				index=dummy->search(l,c,query);
				if(index!=-1)
				{
					cout<<"Book Found\n";
					l[index]->display();
					cout<<"\nPress 1 to Delete\nPress 2 to Exit\n";
					cin>>ch;
					if(ch==1)
					{
						delete_index[delete_counter]=index;
						delete_counter++;
						l[index]->delete_data();
						delete(l[index]);

					}

				}
				else
				{
					cout<<"Record Not found\n";

				}
				break;

			case 7:
				break;

			default:
				cout<<"Enter Valid Option\n";
		}
	}
	while(ch!=7);
}

