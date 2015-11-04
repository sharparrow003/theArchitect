%{
#include <iostream>
#include <cstdlib>
#include "Micro.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

%%
(BEGIN)                                                                                                 { return BEGIN_TOKEN; }
(PROGRAM)                                                                                               { return PROGRAM; }
(END)                                                                                                   { return END; }
(FUNCTION)                                                                                              { return FUNCTION; }
(READ)                                                                                                  { return READ; }
(WRITE)                                                                                                 { return WRITE; }
(IF)                                                                                                    { return IF; }
(ELSE)                                                                                                  { return ELSE; }
(FI)                                                                                                    { return FI; }
(FOR)                                                                                                   { return FOR; }
(ROF)                                                                                                   { return ROF; }
(CONTINUE)                                                                                              { return CONTINUE; }
(BREAK)                                                                                                 { return BREAK; }
(RETURN)                                                                                                { return RETURN; }
(INT)                                                                                                   { return INT; }
(VOID)                                                                                                  { return VOID; }
(STRING)                                                                                                { return STRING; }
(FLOAT)                                                                                                 { return FLOAT; }
(\+)                                                                                                    { return ADDOP; }
(-)                                                                                                     { return SUBOP; }
(\*)                                                                                                    { return MULOP; }
(\/)                                                                                                    { return DIVOP;}
(<) 													{ return LESSER; }
(>)  													{ return GREATER; }
(=)                              									{ return EQUALS; }
(!=)                                                                                                    { return NEQUALS; }
(<=)                                                                                                    { return LEQUALS; }
(>=)                                                                                         	   	{ return GEQUALS;}
(:=)                                                                                                    { return ASSMTOP; }
(\()                                                                                                    { return OPENPAROP; }
(\))                                                                                                    { return CLOSEPAROP; }
(;)                                                                                                     { return SCOLONOP; }
(,)                                                                                                     { return COMMAOP; }

[0-9]+                                                                                                  { yylval.ival = atoi(yytext); return INTLIT; }
[0-9]+"."[0-9]+                                                                                         { yylval.fval = atof(yytext); return FLTLIT; }
\"([^\\\"]|\\.)*\"                                                                                      { yylval.sval = strdup(yytext); return STRLIT; }
--.*\n                                                                                                  /*Comment*/
[_a-zA-Z][_a-zA-Z0-9]{0,30}                                                                             { yylval.iden = strdup(yytext); return IDENTIFIER; }
[ \t]+                                                                                                  /*Whitespace*/
\n                                                                                                      /*Newline*/
\r                                                                                                      /*Carriage*/
%%

