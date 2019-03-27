#include<iostream>
#include<fstream>
using namespace std;
ifstream fin1;
ifstream fin2;
ofstream fout3;
ofstream fout4;
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
	static int m1=0;
	if(m1%2==0)
	{
		fout3<<a1[0];
		cout<<a1[0];
		a1[0]=a1[1];
		a1[1]=a1[2];
	}
	else
	{
		fout4<<a1[0];
		a1[0]=a1[1];
		a1[1]=a1[2];
	}
	m1++;
}
int main()
{
int a,b,n,a1[10];
static int k2=0;
char ch,c;
ofstream fout;
fout.open("datafile.txt");
ofstream fout1;
fout1.open("A1.txt");
ofstream fout2;
fout2.open("A2.txt");
cout<<"enter the no of no's\n";
cin>>n;
for(int i=1;i<=n;i++)
{
	cout<<"enter the no "<<i<<"\n";
	cin>>a;
	fout<<a<<" ";
	
}
fout.close();
ifstream fin;
fin.open("datafile.txt");
 fin>>a;
while(!fin.eof())
{
for(int i=0,j=0;i<3;i++,j++)
{	
  	a1[j]=a;
	cout<<a1[j]<<"  ";
	 fin>>a;
}
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
	if(k2%2==0)
	{for(int i=0;i<3;i++)
	if(a1[i]!=a1[i-1])
	fout1<<a1[i];
	k2++;
    }
	else
	{for(int i=0;i<3;i++)
	if(a1[i]!=a1[i-1])
	fout2<<a1[i];
	k2++;	
	}	
}
fin.close();
fout1.close();
fout2.close();
int k=0,g=2;
while(g<3)
{
if(k%2==0)
{
fin1.open("A1.txt");
fin2.open("A2.txt");
fout3.open("B1.txt");
fout4.open("B2.txt");
}
else
{
fin1.open("B1.txt");
fin2.open("B2.txt");
fout3.open("A1.txt");
fout4.open("A2.txt");	
}
fin1>>a;
fin2>>b;int t=1,t1=1;
while(!fin1.eof() || !fin2.eof())
{
int r1=0;
if(r1==0)
{
for(int k2=0;k2<3*g-2;k2++)
 {
static int h=0;
if(h%2==0)
fin1>>c;
else{
fin2>>c;}
if(t==1)
{
a1[0]=a;a1[1]=b;a1[2]=c;t++;}
else
{a1[2]=c;
}
sort(a1);
h++;}
r1++;}
else
{int r2=0;
	for(int k2=0;k2<3*g;k2++)
 {
static int h1=0;
if(h1%2==0)
{
if(r2==0)
{
fin1>>a;}
else
fin1>>c;
}
else{
if(r2==0)
{
fin1>>b;}
fin2>>c;
}
r2++;
if(t1==1)
{
a1[0]=a;a1[1]=b;a1[2]=c;t++;}
else
{a1[2]=c;
}
sort(a1);
h1++;}
}
}
fin1.close();
fin2.close();
fout3.close();
fout4.close();
g++;
k++;
}}

