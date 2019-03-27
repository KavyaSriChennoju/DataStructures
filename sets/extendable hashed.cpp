#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct store
{
	int rec;
	string s;
}st;
struct bucket
{
    int d1;int max;
    store st1[max];
	bucket()
	{
		int d1=0;
		int max=5;
	}
}bt;
st[50];
int main()
{
    int k,i=0,a=10;string s;
   
	do
	{
	cout<<"enter the record no\n";
	cin>>k;
	cout<<"enter name\n";
	cin>>s;
	st[i++].rec=k;st[i++].s=s;
	r=k%a;
	j=
	}
}
