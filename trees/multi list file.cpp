#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct reg
{
	int index,rollno,r1,r2,courseno,c1,c2;
};
struct stud
{
	int roll;
	char name[10];
	int ind;
};
struct sub
{
	int no;
	string s;
	int credits;
	int in;
};
void cre(stud m[],int a3,int &n,int p);
void cre(stud m[],int a3,int &n,int p)
{
	int k=0;
   	for(int i=0;i<n;i++)
   		if(m[i].roll==a3)
   		k++;
   		if(k==0)
   		{`
   			cout<<"enter the name\n";
   			cin>>m[n].name;
   			m[n].roll=a3;
   			m[n].ind=p;n++;
   		}
}
void crea(sub m[],int a4,int &n,int p);
void crea(sub m[],int a4,int &n,int p)
{
	int k=0;
	for(int i=0;i<n;i++)
	if(m[i].no==a4)
	k++;
	if(k==0)
	{
		cout<<"enter the subject name\n";
		cin>>m[n].s;
		m[n].no==a4;
		cout<<"enter the no of credits \n";
		cin>>m[n].credits;
		m[n].in=p;n++;
	}
}
void shift(reg m[],int p,int q);
void shift(reg m[],int p,int q)
{
	if(m[p].r1==-1)
	{
		m[q].r2=m[p].index;
		m[p].r1=m[q].index;
	}
	else
	shift(m,m[p].r1,q);
}
void sift(reg m[],int p,int q);
void sift(reg m[],int p,int q)
{
	if(m[p].c1==-1)
	{
		m[q].c2=m[p].index;
		m[p].c1=m[q].index;
	}
	else
	shift(m,m[p].c1,q);
}
void creat(reg m[],int a3,int a4,int p);
void creat(reg m[],int a3,int a4,int p)
{
	int k=0;
	m[p].index=p;
	m[p].rollno=a3;
	m[p].r1=-1;
	m[p].r2=-1;
	m[p].courseno=a4;
	m[p].c1=-1;
	m[p].c2=-1;
	for(int i=0;i<p;i++)
	{
	  if(m[i].rollno==a3)
	  {
	  	shift(m,i,p);
	  	break;
	  }
    }
    for(int i=0;i<p;i++)
    {
    	if(m[i].courseno==a4)
    	{
    		sift(m,i,p);
    		break;
    	}
    }
} 
int main()
{
	ofstream fout1;
	fout1.open("file1.txt");
	ofstream fout2;
	fout2.open("file2.txt");
	int a;
	reg s1[100];stud s2[100];sub s3[100];
	int a1=0,a2=0,a3,a4,a5,k=0,k1=0;
	char nam[10];string s4;
	cout<<"enter the no of registrations\n";
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cout<<"enter the rollno of student\n";
		cin>>a3;
		cout<<"course number \n";
		cin>>a4;
		if(a1==0)
		{
			cout<<"enter the name \n";
			cin>>nam;
			strcpy(s2[a1].name,nam);
			s2[a1].roll=a3;s2[a1].ind=k1;a1++;
		}
		else
		cre(s2,a3,a1,i);
		if(a2==0)
		{
		    cout<<"enter the subject \n";
		    cin>>s4;
		    cout<<"enter the credits \n";
		    cin>>a5;
		    s3[a2].s=s4;s3[a2].credits=a5;s3[a2].no=a4;s3[a2].in=k1;a2++;
		}
		else
		crea(s3,a4,a2,i);
		if(k1==0)
		{
			s1[k1].index=k1;
			s1[k1].rollno=a3;
			s1[k1].r1=-1;
			s1[k1].r2=-1;
			s1[k1].courseno=a4;
			s1[k1].c1=-1;
			s1[k1].c2=-1;k1++;
	    }
	    else
	    creat(s1,a3,a4,i);
		
	}
	for(int i=0;i<a;i++)
	{
		fout2<<	s1[i].index<<"  "<<s1[i].rollno<<"  "<<s1[i].r1<<"  "<<s1[i].r2<<"  "<<s1[i].courseno<<"	"<<s1[i].c1<<" 	"<<s1[i].c2<<"\n";
		
	}
}
