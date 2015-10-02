%{
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

 void yyerror(const char *s) { cerr << "Not Accepted" << endl; exit(0); }
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
program:  PROGRAM id BEGIN_TOKEN pgm_body END    
;
id:       IDENTIFIER  {$<sval>$ = $1;}
;
pgm_body: decl func_declarations    
;
decl:     string_decl decl | var_decl decl | empty   
;

string_decl: STRING id ASSMTOP str SCOLONOP  {cout<<"name "<<$<sval>2<<" type STRING value "<<$<sval>4<<endl;}
;
str: STRLIT  {$<sval>$ = $1; }
;

var_decl: var_type id_list SCOLONOP //{cout<<"Type-->"<<$<sval>1<<endl;}
;
var_type: FLOAT {cout<<$<sval>1<<endl;}

| INT {cout<<$<sval>1<<endl;}
;
any_type: var_type | VOID  
;
id_list: id id_tail 
;
id_tail: COMMAOP id id_tail | empty 
;

param_decl_list: param_decl param_decl_tail | empty   
;
param_decl: var_type id   
;
param_decl_tail: COMMAOP param_decl param_decl_tail | empty  
;

func_declarations: func_decl func_declarations | empty   
;
func_decl: FUNCTION any_type id OPENPAROP param_decl_list CLOSEPAROP BEGIN_TOKEN func_body END {cout <<"\nSymbol table "<<$<sval>3<<endl; }
;
func_body: decl stmt_list   
;

stmt_list: stmt stmt_list | empty   
;
stmt: base_stmt | if_stmt | for_stmt   
;
base_stmt: assign_stmt | read_stmt | write_stmt | return_stmt   
;

assign_stmt: assign_expr SCOLONOP   
;
assign_expr: id ASSMTOP expr  
;
read_stmt: READ OPENPAROP id_list CLOSEPAROP SCOLONOP  
;
write_stmt: WRITE OPENPAROP id_list CLOSEPAROP SCOLONOP  
;
return_stmt: RETURN expr SCOLONOP   
;

expr: expr_prefix factor 
;
expr_prefix: expr_prefix factor addop | empty   
;
factor: factor_prefix postfix_expr    
;
factor_prefix: factor_prefix postfix_expr mulop | empty    
;
postfix_expr: primary | call_expr   
;
call_expr: id OPENPAROP expr_list CLOSEPAROP   
;
expr_list: expr expr_list_tail | empty   
;
expr_list_tail: COMMAOP expr expr_list_tail | empty   
;
primary: OPENPAROP expr CLOSEPAROP | id | INTLIT | FLTLIT   
;
addop: ADDOP   
;
mulop: MULOP   
;

if_stmt: IF OPENPAROP cond CLOSEPAROP decl stmt_list else_part FI   
;
else_part: ELSE decl stmt_list | empty  
;
cond: expr compop expr  
;
compop: COMPOP   
;

init_stmt: assign_expr | empty   
;
incr_stmt: assign_expr | empty   
;

for_stmt: FOR OPENPAROP init_stmt SCOLONOP cond SCOLONOP incr_stmt CLOSEPAROP decl stmt_list ROF   
;

empty:    
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
    printf("Symbol table GLOBAL\n");
    do {
      yyparse();
    } while (!feof(yyin));
  }
}


