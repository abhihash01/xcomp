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
	Arit=0;
	Rel=1;
	Log=2;
	Num=3;
	key=4;
	Id=5;
	Spec=6;
	String=7;
};

tokenptr getnexttoken(FILE *fp){
	char keys[][256]={"int","char","if","else","switch","break","goto"};
	char ch,cb;
	char buf[256];
	tokenptr newtk=(tokenptr)malloc(sizeof(Token));
	ch=getc(fp);
	*l=*l+1;
	if(ch==EOF){
		newtk=NULL;
		return newtk;
	}
	if(ch=='/'){
		ch=getc(fp);
		*l=*l+1;
		if(ch=='/'){
			while(ch!='\n'){
				ch=getc(fp);
				*l=*l+1;
			}
			*r=*r+1;
			*c=0;
			

		}
		else if(ch=='*'){
			cb=getc(fp);
			do{
				fseek(fp,-1,SEEK_CUR);
				ch=getc(fp);
				*l=*l+1;
				if(ch=='\n'){
					*l=0;
					*r=*r+1;
				}
				cb=getc(fp);
			}while(ch=='*'&& cb=='/');
			return getnexttoken();

		}

	}

}
int main(){
	char types[][256]={"Arit","Rel","Log","Num","key","Id","Spec","String",}
	FILE *fp;
	fp=fopen("input.c","r");
	tokenptr temp;
	do{
		temp=getnexttoken(fp);
		printf("Token %s   %d    %d    %s\n",temp->lexeme,temp->row,temp->col,types[temp->tpe]);
	}while(temp);
}


//File declared inside, not sure if the file pointer will parse properly