#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node{
	char* lexeme;
	int row,col,type;
}Token;
int *numtoken=0;
int *l=0;
int *r=0;
typedef struct node* tokenptr;
enum Tokentype{
	Arit=0,
	Rel=1,
	Log=2,
	Num=3,
	key=4,
	Id=5,
	Spec=6,
	String=7
};

tokenptr getnexttoken(FILE *fp){
	char ch=getc(fp);
	printf("\nget next token entered");
	char keys[][256]={"int","char","if","else","switch","break","goto"};
	char cb;
	char buf[256];
	tokenptr newtk=(tokenptr)malloc(sizeof(Token));
	printf("\n token allocated");
	if(ch=='$'){
		newtk=NULL;
		return newtk;
	}
	return newtk;

}
int main(){
	char types[][256]={"Arit","Rel","Log","Num","key","Id","Spec","String"};
	FILE *fp;
	fp=fopen("input.c","r");
	char ch=getc(fp);
	printf("\nrandom character %c",ch);
	printf("\ninput taken");
	tokenptr temp;
	do{
		printf("while loop entered");
		temp=getnexttoken(fp);
		printf("Token %s   %d    %d    %s\n",temp->lexeme,temp->row,temp->col,types[temp->type]);
	}while(temp);
}


//File declared inside, not sure if the file pointer will parse properly