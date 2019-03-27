#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct Tnode;
struct Trienode
{
	int tag;
	union
	{
		char* s;
		Tnode* t;
	};
}*R;
struct Tnode
{
	char* c;
	Trienode** child;
};
Tnode* createTnode()
{
	Tnode* node = new Tnode;
	node -> c = new char[26];
	node -> child = new Trienode*[27];
	return node;
}
Trienode* createTrienode(int tag)
{
	Trienode* node =new Trienode;
	if (tag == 0)
	{
		node -> tag = 0;
		node -> s = new char[26];
	}
	else
	{
		node -> tag = 1;
		node -> t = createTnode();
	}
}
int distance(char c)
{
	return	(int)c-(int)('a');
}
void insert(Trienode* r, char *str)
{
	Trienode* temp = createTrienode(0);
	temp -> s = strcpy(temp->s, str);
	int len = strlen(str);
	int pos,i;
	Trienode* p = r;
	
	if(R == NULL)
	{
		R = temp;
		return;
	}
	for(i=0; i<len; i++)
	{
		pos = distance(str[i]);
		if(p->tag == 1)
		{
			if(p->t->child[pos] == NULL)
			{
				p->t->c[pos] = str[i];
				p->t->child[pos] = temp;
				return;
			}
			else 
			{
				if(i<len-1)	
				{
					p = p->t->child[pos];
				}
				else
				{
					p->t->child[26] = temp;
					return;
				}
			}
		}
		else
		{
			char* tempstr = new char[256];
			tempstr = strcpy(tempstr, p->s);
			int templen = strlen(tempstr);
			int posj, j=0;
			
			Trienode* q = createTrienode(0);
			q->s = strcpy(q->s, tempstr);
			p->tag = 1;
			p->t = createTnode();
			
			for(; i<len && j<templen; i++,j++)
			{
				posj = distance((q->s)[j]);
				pos = distance(str[i]);
				if(pos != posj)
				{
					p->t->c[posj] = (q->s)[j];
					p->t->c[pos] = str[i];
					p->t->child[posj] = q;
					p->t->child[pos] = temp;
					return;
				}
				p->t->c[pos] = str[i];
				p->t->child[pos] = createTrienode(1);
				p = p->t->child[pos];
			}
			if(i<len)
			{
				pos = distance(str[i]);
				p->t->c[pos] = str[i];
				p->t->child[pos] = temp;
				p->t->child[26] = q;
				return;
			}
			else if (j<templen)
			{
				posj = distance((q->s)[j]);
				p->t->c[posj] = (q->s)[j];
				p->t->child[posj] = q;
				p->t->child[26] = temp;
				return;
			}
		}
	}
}
int search(Trienode* TR, char* k, int i)
{
	if(i>strlen(k) || TR==NULL)
		return 0;
	if(TR->tag == 0)
	{
		if(strcmp(TR->s, k) == 0)
			return 1;
		return 0;
	}
	if(i==strlen(k) && TR->t->child[26] != NULL)
	{
		return search(TR->t->child[26], k, i);
	}
	int pos = distance(k[i]);
	return search(TR->t->child[pos], k,i+1);
}
void print(Trienode* TR)
{
	if(TR->tag == 0)
		cout <<TR->s<<endl;
	else
	{
		for(int i=0; i<26; i++)
		{
			if(TR->t->child[i] != NULL)
			{
				print(TR->t->child[i]);
			}
		}
	}
}
int main()
{

	char* ch;
	char d;
	cout << "To enter word enter Y/ N " << endl;
	cin >> d;
	while(d == 'Y' || d == 'y')
	{
		ch = new char[250];
		cout << "Enter the word"<< endl;
		cin >> ch;
		int result = search(R,ch,0);
		if(result != 1)
			insert(R,ch);
		cout << "To enter word enter Y / N " << endl;
		cin >> d;
	}
	cout << "Enter the word to be searched "<< endl;
	ch = new char[250];
	cin >> ch;
	int result = search(R,ch,0);
	if(result == 1)
		cout <<"Found"<<endl;
	else
		cout <<"Not Found"<<endl;
	cout<<"The constructed Trie is "<<endl; 
	print (R);
	return 0;
}
