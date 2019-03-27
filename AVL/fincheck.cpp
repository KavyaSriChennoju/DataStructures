#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("datafile.txt");
	int i;
	while(!fin.eof())
	{
		fin>>i;
		cout<<i<<"  ";
	}

}
