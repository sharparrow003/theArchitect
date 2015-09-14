%{
#include <stdio.h>
%}

%%
(PROGRAM|BEGIN|END|FUNCTION|READ|WRITE|IF|ELSE|FI|FOR|ROF|CONTINUE|BREAK|RETURN|INT|VOID|STRING|FLOAT)	printf("Token Type: KEYWORD\n"); printf("Value: %s\n", yytext);
(:=|\+|-|\*|\/|=|!=|<|>|\(|\)|;|,|<=|>=)							        printf("Token Type: OPERATOR\n"); printf("Value: %s\n", yytext);
[0-9]+                                                                                                  printf("Token Type: INTLITERAL\n"); printf("Value: %s\n", yytext);
[0-9]+"."[0-9]+                                                                                         printf("Token Type: FLOATLITERAL\n"); printf("Value: %s\n", yytext);
\"([^\\\"]|\\.)*\"                                                                                      printf("Token Type: STRINGLITERAL\n"); printf("Value: %s\n", yytext);
--.*\n                                                                                                  /*Comment*/
[_a-zA-Z][_a-zA-Z0-9]{0,30}                                                                             printf("Token Type: IDENTIFIER\n"); printf("Value: %s\n", yytext);
[ \t]+                                                                                                  /*Whitespace*/
\n                                                                                                      /*Newline*/
\r                                                                                                      /*Carriage*/
%%

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Error! Usage: Micro <filename>");
  }
  else
  {
    yyin = fopen(argv[1], "r");
    yylex();
    printf("\n");
  }

  return 0;
}
