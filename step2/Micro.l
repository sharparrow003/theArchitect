%{
#include <iostream>
#include <cstdlib>
#include "Micro.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

%%
PROGRAM													{ return PROGRAM; }
(BEGIN|END|FUNCTION|READ|WRITE|IF|ELSE|FI|FOR|ROF|CONTINUE|BREAK|RETURN|INT|VOID|STRING|FLOAT)		{ return KEYWORD; }
(:=|\+|-|\*|\/|=|!=|<|>|\(|\)|;|,|<=|>=)							        /*Operator*/
[0-9]+                                                                                                  { yylval.ival = atoi(yytext); return INT; }
[0-9]+"."[0-9]+                                                                                         { yylval.fval = atof(yytext); return FLOAT; }
\"([^\\\"]|\\.)*\"                                                                                      { yylval.sval = strdup(yytext); return STRING; }
--.*\n                                                                                                  /*Comment*/
[_a-zA-Z][_a-zA-Z0-9]{0,30}                                                                             { yylval.iden = strdup(yytext); return IDENTIFIER; }
[ \t]+                                                                                                  /*Whitespace*/
\n                                                                                                      /*Newline*/
\r                                                                                                      /*Carriage*/
%%

