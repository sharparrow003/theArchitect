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
%token BEGIN_TOKEN
%token END
%token FUNCTION
%token READ
%token WRITE
%token IF
%token ELSE
%token FI
%token FOR
%token ROF
%token CONTINUE
%token BREAK
%token RETURN
%token INT
%token VOID
%token STRING
%token FLOAT
%token ADDOP
%token MULOP
%token COMPOP
%token ASSMTOP
%token OPENPAROP
%token CLOSEPAROP
%token SCOLONOP
%token COMMAOP
%token <ival> INTLIT
%token <fval> FLTLIT
%token <sval> STRLIT
%token <iden> IDENTIFIER

%%
program:  PROGRAM id BEGIN_TOKEN pgm_body END    { cout<< "program" << endl; }
;
id:       IDENTIFIER   { cout<< "id" << endl; }
;
pgm_body: decl func_declarations    { cout<< "pgm_body" << endl; }
;
decl:     string_decl decl | var_decl decl | empty   { cout<< "decl" << endl; }
;

string_decl: STRING id ASSMTOP str SCOLONOP  { cout<< "string_decl" << endl; }
;
str: STRLIT  { cout<< "str" << endl; }
;

var_decl: var_type id_list SCOLONOP  { cout<< "var_decl" << endl; }
;
var_type: FLOAT | INT   { cout<< "var_type" << endl; }
;
any_type: var_type | VOID  { cout<< "any_type" << endl; }
;
id_list: id id_tail  { cout<< "id_list" << endl; }
;
id_tail: COMMAOP id id_tail | empty   { cout<< "id_tail" << endl; }
;

param_decl_list: param_decl param_decl_tail | empty   { cout<< "param_decl_list" << endl; }
;
param_decl: var_type id   { cout<< "param_decl" << endl; }
;
param_decl_tail: COMMAOP param_decl param_decl_tail | empty  { cout<< "param_decl_tail" << endl; }
;

func_declarations: func_decl func_declarations | empty   { cout<< "func_declarations" << endl; }
;
func_decl: FUNCTION any_type id OPENPAROP param_decl_list CLOSEPAROP BEGIN_TOKEN func_body END   { cout<< "func_decl" << endl; }
;
func_body: decl stmt_list   { cout<< "func_body" << endl; }
;

stmt_list: stmt stmt_list | empty   { cout<< "stmt_list" << endl; }
;
stmt: base_stmt | if_stmt | for_stmt   { cout<< "stmt" << endl; }
;
base_stmt: assign_stmt | read_stmt | write_stmt | return_stmt   { cout<< "base_stmt" << endl; }
;

assign_stmt: assign_expr SCOLONOP   { cout<< "assign_stmt" << endl; }
;
assign_expr: id ASSMTOP expr  { cout<< "assign_expr" << endl; }
;
read_stmt: READ OPENPAROP id_list CLOSEPAROP SCOLONOP  { cout<< "read_stmt" << endl; }
;
write_stmt: WRITE OPENPAROP id_list CLOSEPAROP SCOLONOP  { cout<< "write_stmt" << endl; }
;
return_stmt: RETURN expr SCOLONOP   { cout<< "return_stmt" << endl; }
;

expr: expr_prefix factor   { cout<< "expr" << endl; }
;
expr_prefix: expr_prefix factor addop | empty   { cout<< "expr_prefix" << endl; }
;
factor: factor_prefix postfix_expr    { cout<< "factor" << endl; }
;
factor_prefix: factor_prefix postfix_expr mulop | empty    { cout<< "factor_prefix" << endl; }
;
postfix_expr: primary | call_expr   { cout<< "postfix_expr" << endl; }
;
call_expr: id OPENPAROP expr_list CLOSEPAROP   { cout<< "call_expr" << endl; }
;
expr_list: expr expr_list_tail | empty   { cout<< "expr_list" << endl; }
;
expr_list_tail: COMMAOP expr expr_list_tail | empty   { cout<< "expr_list_tail" << endl; }
;
primary: OPENPAROP expr CLOSEPAROP | id | INTLIT | FLTLIT   { cout<< "primary" << endl; }
;
addop: ADDOP   { cout<< "addop" << endl; }
;
mulop: MULOP   { cout<< "mulop" << endl; }
;

if_stmt: IF OPENPAROP cond CLOSEPAROP decl stmt_list else_part FI   { cout<< "if_stmt" << endl; }
;
else_part: ELSE decl stmt_list | empty  { cout<< "else_part" << endl; }
;
cond: expr compop expr  { cout<< "cond" << endl; }
;
compop: COMPOP   { cout<< "compop" << endl; }
;

init_stmt: assign_expr | empty   { cout<< "init_stmt" << endl; }
;
incr_stmt: assign_expr | empty   { cout<< "incr_stmt" << endl; }
;

for_stmt: FOR OPENPAROP init_stmt SCOLONOP cond SCOLONOP incr_stmt CLOSEPAROP decl stmt_list ROF   { cout<< "for_stmt" << endl; }
;

empty:    { cout<< "empty" << endl; }
;



%%

int main(int argc, char *argv[]) {
  if (argc != 2)
  {
    printf("Error! Usage: Micro <filename>");
  }
  else
  {
    FILE *myfile = fopen(argv[1], "r");
    if (!myfile) {
      cout << "File could not be opened" << endl;
      return -1;
    }
    yyin = myfile;
    do {
      yyparse();
    } while (!feof(yyin));
  }
}


