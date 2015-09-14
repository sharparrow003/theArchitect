%{
#include <cstdio>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s) { cerr << "Error!" << endl; }
%}
%union {
	int ival;
	float fval;
	char *sval;
	char *iden;
}

%token PROGRAM
%token KEYWORD
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <iden> IDENTIFIER

%%
micro:
	PROGRAM IDENTIFIER { cout << "found a program name!" << endl; }
	;
%%

int main(int, char**) {
	FILE *myfile = fopen("testFiles/fibonacci.micro", "r");
	if (!myfile) {
		cout << "File could not be opened" << endl;
		return -1;
	}
	yyin = myfile;
	do {
		yyparse();
	} while (!feof(yyin));
}


