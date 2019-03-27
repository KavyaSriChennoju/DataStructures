#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
struct snode
{
	int roll;
	char name[10];
	snode *snext;
	rnode *down;
};
struct rnode
{
	int tag1;
	int tag2;
	union 
	{
		rnode *next1;
		snode *s1next;
	}u1;
	union 
	{
		rnode *next2;
		cnode *c1next;
	}u2;
};
struct cnode
{
	int cno;
	char cname[10];
	int credits;
	cnode *cnext;
	rnode *right;
};
int main()
{
	 snode *s1;cnode c1;rnode *r1;
	 
	 
	 
}
