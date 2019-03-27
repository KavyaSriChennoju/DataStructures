#include<iostream>
#include<fstream>
using namespace std;
ifstream fin1;
ifstream fin2;
ofstream fout3;
ofstream fout4;
int r;int m;int t2=0,t1=0;
void sort(int a1[]);
void sort(int a1[])
{
	for(int j=0;j<3;j++)
	{
		for(int k1=j+1;k1<3;k1++)
		{
			if(a1[j]>a1[k1])
			{
	        	int h;
			   	h=a1[k1];
			    a1[k1]=a1[j];
			    a1[j]=h;
			}
		}
	}


if(m==0){
         if(t1==0)
         {   t1++;
         	fout3<<a1[0]<<" ";}
        else
        {
		fin1.open("f1.txt");
		fin1>>r;
		if(a1[0]>r)
		{
		fout3<<a1[0]<<" ";}
		else
		{
		fout3<<-1<<"  ";
		m=-1;
		fout4<<r;}}}
	
	if(m==-1)
 {  if(t2==0)
     {t2++;
         	fout4<<a1[0]<<" ";}
 
 else{
 	fin2.open("f2.txt");
		fin2>>r;
  	if(a1[0]>r)
		fout4<<a1[0]<<" ";
		else
		{
		fout4<<-1<<" ";
		m=0;
		fout3<<r;
		}
	}}
		a1[0]=a1[1];
		a1[1]=a1[2];

}

int main()
{
	fout3.open("f1.txt");
fout4.open("f2.txt");
int a,n,a1[10],j=0,m=1;
	cout<<"enter the no of no's\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the number\n";
		cin>>a;
		a1[j]=a;
		j++;
		if(j==3)
		{
			sort(a1);
			j=2;
		}	
	}
	
	
}
