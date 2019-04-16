#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Tokentype {
	Arith=0,
	Rel=1,
	key=2,
	Id=3,
	Num=4,
	Spec=5,
	String=6,
	Logic=7
};
typedef struct token{
	char* lexeme;
	int index;
	int row;
	int col;
	int type;
}Token;
typedef struct token* tokenptr;
Token tokens[1024];