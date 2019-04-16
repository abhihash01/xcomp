#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct token{
	char* lexeme;
	int row, col;
	int type;
}Token;
int numtokens;
int c;
int r;
typedef struct token* tokenptr;
tokenptr getnexttoken(FILE *fp){
	tokenptr newtk=(tokenptr)malloc(sizeof(Token));
	
	char ch,buf[256],cb;
	printf("reached here 1\n");
	ch=getc(fp);
	printf("reached here 2a \n");
	c+=1;
	printf("reached here 5 \n");
	if(ch==EOF){
		newtk=NULL;
		return newtk;
	}
	printf("reached here 4 \n");
	if(ch=='/'){
		ch=getc(fp);
		printf("reached here 3 \n");
		c+=1;
		if(ch=='/'){
			printf("// area reached \n");
			while(ch!='\n'){
				ch=getc(fp);
			}
			c=0;
			r+=1;
		}
		else if(ch=='*'){
			printf("/* area reached\n");
			cb=getc(fp);
			c+=1;
			while((ch!='*')&&(cb!='/')){
	
				
				if(ch=='\n'){
					c=0;
					r=r+1;
				}
				ch=cb;
				cb=getc(fa);
				c++;
				c+=1;
				printf("here final \n");
			}
		}
		return getnexttoken(fp);
		
	}
	else if(ca=='+'||ca=='-'||ca=='*'||ca== '/'){
		cb=getc(fa);
		if(ca=='+'&&cb=='+'){
			newtk->name[0]=ca;
			newtk->name[1]=cb;
			newtk->name[2]='\0';
		}
	}
	
	
	

}
int main(){
	FILE *fa;
	tokenptr temp;
	fa=fopen("input.c","r");
	do{
		temp=getnexttoken(fa);
		if(temp!=NULL){
		printf("\nToken  %s %d %d %d",temp->lexeme,temp->row,temp->col,temp->type);
	}
	}while(temp!=NULL);
	return 0;
}