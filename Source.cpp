#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _node;
typedef struct _node* Pos;
typedef struct _node{
	int GeneriraniBroj;
	int RedniBroj;

	Pos Left;
	Pos Right;
}NODE;

Pos FillTree(Pos);
Pos Fill2ndTree(Pos, Pos);
Pos InsertTree(Pos, int*, int*);
Pos Insert2ndTree(Pos, int, int);
Pos CreateNode();
void PrintTree(Pos);

int main(){
	srand((unsigned)time(NULL));
	Pos Root = NULL;
	Pos Root2 = NULL;
	printf("\n");
	Root = FillTree(Root);
	PrintTree(Root);
	Root2 = Fill2ndTree(Root, Root2);
	printf("\nDrugo stablo:\n");
	PrintTree(Root2);

	getc(stdin);
	return 0;
}

Pos CreateNode(){
	Pos q = NULL;
	q = (Pos)malloc(sizeof(NODE));
	q->GeneriraniBroj=0;
	q->RedniBroj=0;
	q->Left=NULL;
	q->Right=NULL;
	return q;
}

Pos FillTree(Pos Root){
	srand(time(NULL));
	int Rand = 0;
	int NmrCount = 0;
	while(NmrCount < 20){
		Rand = rand();
		Root = InsertTree(Root, &Rand, &NmrCount);
	}
	return Root;
}

Pos InsertTree(Pos s, int* Broj, int*Count){
	if (s==NULL){
		s = CreateNode();
		s->GeneriraniBroj = *Broj;
		s->RedniBroj=++*Count;
	}
	else if(*Broj < s->GeneriraniBroj)
		s->Left = InsertTree(s->Left, Broj, Count);
	else if(*Broj > s->GeneriraniBroj)
		s->Right = InsertTree(s->Right, Broj, Count);
	else if(*Broj == s->GeneriraniBroj)
		return s;
	return s;
}

void PrintTree(Pos Root){
	if (Root->Left!=NULL)
		PrintTree(Root->Left);
	printf("%d, %d\n", Root->GeneriraniBroj, Root->RedniBroj);
	if (Root->Right!=NULL)
		PrintTree(Root->Right);
}

Pos Fill2ndTree(Pos Root, Pos Root2){
	if (Root->Left != NULL)
		Root2 = Fill2ndTree(Root->Left, Root2);
	Root2 = Insert2ndTree(Root2, Root->RedniBroj, Root->GeneriraniBroj);
	if (Root->Right != NULL)
		Root2 = Fill2ndTree(Root->Right, Root2);
	return Root2;
}

Pos Insert2ndTree(Pos s, int Redni_Broj, int Broj){
	if (s==NULL){
		s = CreateNode();
		s->GeneriraniBroj = Broj;
		s->RedniBroj = Redni_Broj;
	}
	else if (Redni_Broj > s->RedniBroj)
		s->Left = Insert2ndTree (s->Left, Redni_Broj, Broj);
	else if (Redni_Broj < s->RedniBroj)
		s->Right = Insert2ndTree (s->Right, Redni_Broj, Broj);
	return s;
}