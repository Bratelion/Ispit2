#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node;
typedef struct node *Pos;
typedef struct node
{
	int el;
	Pos left;
	Pos right;
	int rb;
}_node;

Pos node();
Pos Place(int x, int i, Pos B);
void print(Pos B);

int main(int argc, char* argv[])
{
	srand(time(NULL));
	rand();
	int i=0, x=0;
	Pos stablo=NULL;
	while(i<20)
	{
		i++;
		x=rand();
		printf("%d) %d\n", i, x);
		stablo=Place(x, i, stablo);
	}
	printf("Binarno stablo:\n");
	print(stablo);

	return 0;
}

Pos node()
{
	Pos q=NULL;
	q=(Pos)malloc(sizeof(_node));
	if(q==NULL) printf("nema memorije!\n");
	else
	{
		q->el=0;
		q->left=NULL;
		q->right=NULL;
		q->rb=0;
	}
	return q;
}

Pos Place(int x, int i, Pos B)
{
	if(B==NULL)
	{
		Pos q=node();
		q->el=x;
		q->rb=i;
		B=q;
	}
	else if(x < B->el)
		B->left=Place(x, i, B->left);
	else if(x > B->el)
		B->right=Place(x, i, B->right);
	return B;
}
		
void print(Pos B)
{
	if(B->left!=NULL)
		print(B->left);
	printf("%d) %d\n", B->rb, B->el);
	if(B->right!=NULL)
		print(B->right);
}