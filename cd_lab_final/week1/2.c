#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum TOKENTYPE{
	ARITHMETIC_OP=0,
	RELATION_OP=1;
	SPECIAL_SYMBOL=2,
	STRING_LITERAL=3,
	KEYWORD=4,
	IDENTIFIER=5,
	LOGICAL_OP=6,
	NUMERICAL_CONST=7
};

struct token{
	char lexeme[256];
	int type;
	int index;
	int row;
	int col;
}
typedef struct token Token;
typedef struct token* Tokenptr;
char keywords[][20] = {"for", "if", "else", "while", "return", "do", "int", "char", "float", "double", "NULL", "break", "continue", "enum", "typedef", "struct", "include", "switch", "case"};


TOKEN tokens[1000];
int numTokens = 0;
int rowCount = 1;
int colCount = 1;

void printToken(TOKEN token) {
	printf("< %s, ", token.lexeme);
	printf("%d, ", token.row);
	printf("%d, ", token.col);
	switch (token.type) {
		case ARITHMETIC_OP:	
			printf("arithmetic operation >\n");
			break;
		case RELATIONAL_OP:	
			printf("relational operation >\n");
			break;
		case LOGICAL_OP:	
			printf("logical operation >\n");
			break;
		case SPECIAL_SYMBOL:	
			printf("special symbol >\n");
			break;
		case KEYWORD:	
			printf("keyword >\n");
			break;
		case NUMERICAL_CONST:	
			printf("numerical constant >\n");
			break;
		case STRING_LITERAL:	
			printf("string literal >\n");
			break;
		case IDENTIFIER:	
			printf("identifier >\n");
			break;
	}
}


void printTokens(TOKEN tokens[], int size) {
	for(int i=0;i<size;i++)
		printToken(tokens[i]);
}

void insertToken(char* l, int row, int col, int type) {
	strcpy(tokens[numTokens].lexeme, l);
	tokens[numTokens].index = numTokens;
	tokens[numTokens].row = row;
	tokens[numTokens].col = col;
	tokens[numTokens].type = type;
	numTokens++;
}

FILE *fa;
int main(){
	fa
}