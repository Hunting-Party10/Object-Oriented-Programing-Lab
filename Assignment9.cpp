#include<iostream>
#include<fstream>
#define DATA 150
using namespace std;

int main()
{
	cout<<"Enter File Name:";
	char filename[DATA];
	cin.getline(filename,DATA);
	ofstream output;
	output.open(filename);
	if(output==NULL)
	{
		cout<<"Unable to open file";
		return -1;
	}
	char data[150];
	cout<<"Enter Data you want to write\n";
	scanf("%[^\n]s",data);
	output<<data<<"\n";
	output.close();
	cout<<"Data Written\n";
	cout<<"\n\nReading data from given file\n\n";
	ifstream input;
	input.open(filename);
	if(input==NULL)
	{
		cout<<"Unable to open file";
		return -1;
	}
	input.getline(data,DATA);
	cout<<data;
	cout<<"\n";
	input.close(); 
}

