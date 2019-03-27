#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct student
{
 public:
int index;
 int rollno;
 char name[10];
 float cgpa;
}; 
struct bstnode
{
	int lchild;
	float c;
	int index1;
	int rchild;	
};
int main()
{
int n,p=0,m,d;
student temp;
ofstream fout2;
fout2.open("file2.txt");
ofstream fout;
fout.open("file1.txt");
student s[20];
bstnode b[10];
cout<<"enter the total no of students\n";
cin>>n; 
for(int i=0;i<n;i++)
{ 
s[i].index=(i+1);
fout<<s[i].index<<"  ";
cout<<"enter the details of student "<<i+1;
cout<<"enter rollno\n";
cin>>s[i].rollno;
fout<<s[i].rollno<<"  ";
cout<<"enter name\n";
cin>>s[i].name;
fout<<s[i].name<<"  ";
cout<<"enter cgpa\n";
cin>>s[i].cgpa;
fout<<s[i].cgpa<<"  ";
fout<<"$";
}
fout.close();
b[0].lchild=-1;
b[0].c=s[0].cgpa;
b[0].index1=1;
b[0].rchild=-1;
for(int i=1;i<n;i++)
{ 
	for(int j=0;j<i;j++)
		{ 
			if(s[i].cgpa<s[j].cgpa)
			{
				m=0;
				while(b[m].c!=s[j].cgpa)
				m++;
				l1:
					{
						if(b[m].lchild==-1)
						{
							b[m].lchild=s[i].index;p++;
							b[p].lchild=-1;
							b[p].rchild=-1;
							b[p].index1=s[i].index;
							b[p].c=s[i].cgpa;break;
						}
						else
						{
							d=0;
							while(b[d].index1!=b[m].lchild)
							d++;
							m=d;
						    if(b[d].c>s[i].cgpa)
						    goto l1;
						    else
						    goto l2;
						}
					}
			}
			if(s[i].cgpa>s[j].cgpa)
			{
				m=0;
				while(b[m].c!=s[j].cgpa)
				m++;
				l2:
					{
						if(b[m].rchild==-1)
						{
							b[m].rchild=s[i].index;p++;
							b[p].lchild=-1;
							b[p].rchild=-1;
							b[p].index1=s[i].index;
							b[p].c=s[i].cgpa;break;
						}
						else
						{
							d=0;
							while(b[d].index1!=b[m].rchild)
							d++;
							m=d;
						    if(b[d].c>s[i].cgpa)
						    goto l1;
						    else
						    goto l2;
						}
					}
			}
		}
	}

for(int i=0;i<n;i++)
{
cout<<b[i].lchild<<" "<<b[i].c<<" "<<b[i].index1<<" "<<b[i].rchild<<"\n";
fout2<<b[i].lchild<<" "<<b[i].c<<" "<<b[i].index1<<" "<<b[i].rchild<<"\n";
}
char ch;
ifstream fin;
fin.open("file1.txt");
cout<<"enter the record to be searched\n";
cin>>n;
for(int i=0;i<n-1;i++)
{
	while(ch!='$')
	{
		fin.get(ch);
	}
	fin.get(ch);
}
fin.get(ch);
cout<<ch;
while(ch!='$')
{
	fin.get(ch);
	if(ch!='$')
	cout<<ch;
}

}

