%{
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;
struct block 
{
	string * value;
	struct block * next;		
};

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s) { cerr << "Not Accepted" << endl; exit(0); }
static int val=0; //Determines which block is being found
static int init = 0; //Determines whether program has exited scope and thus assign head of linked list again
static int scope = 0; //Determines whether program has finished processing Global variables
static struct block * head = 0;
static struct block * curr = 0;
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
{
	if(scope == 0){scope = 1;}
}	 
;

string_decl: STRING id ASSMTOP str SCOLONOP  
{
	if(scope == 0){	
		cout<<"name "<<$<sval>2<<" type STRING value "<<$<sval>4<<endl;
	}
	else if (scope != 0 && head == 0){
		head = (block*)malloc(sizeof(block));
		stringstream temp;
		temp <<"name "<<$<sval>2<<" type STRING value "<<$<sval>4<<endl;
		head->value = new string(temp.str());
		curr = (block*)malloc(sizeof(block));
		head->next = curr;
	}
	else if (scope != 0 && head != 0){
		stringstream temp;
		temp <<"name "<<$<sval>2<<" type STRING value "<<$<sval>4<<endl;
		curr->value = new string(temp.str());
		curr->next = (block*)malloc(sizeof(block));
		curr = curr->next;
		curr->next = 0;
		curr->value = 0;
	}
}
;
str: STRLIT  {$<sval>$ = $1; }
;

var_decl: var_type id_list SCOLONOP {
char * varList = strtok($<sval>2," ");
//cout<<"name "<<$<sval>2<<" type "<<$<sval>1<<endl;
while(varList)
{	
	if(scope == 0){	
		cout<<"name "<<varList<<" type "<<$<sval>1<<endl;
	}
	else if (scope != 0 && head == 0){
		
		head = (block*)malloc(sizeof(block));
		stringstream temp;
		temp<<"name "<<varList<<" type "<<$<sval>1<<endl;
		head->value = new string(temp.str());
		curr = (block*)malloc(sizeof(block));
		head->next = curr;
	}
	else if (scope != 0 && head != 0){

		stringstream temp;
		temp<<"name "<<varList<<" type "<<$<sval>1<<endl;
		curr->value = new string(temp.str());
		curr->next = (block*)malloc(sizeof(block));
		curr = curr->next;
		curr->next = 0;
		curr->value = 0;
	}
	varList = strtok(NULL, " ");
}
}
;
var_type: FLOAT {
$<sval>$ = "FLOAT";
}

| INT {
$<sval>$ = "INT";
}
;
any_type: var_type {$<sval>$ = $<sval>1;}
| VOID  {$<sval>$ = $<sval>1;}
;
id_list: id id_tail {$<sval>$ = $<sval>1;}
;
id_tail: COMMAOP id id_tail {sprintf($<sval>$, "%s %s", $<sval>1, $<sval>2);}
| empty 
;

param_decl_list: param_decl param_decl_tail | empty   
;
param_decl: var_type id   
;
param_decl_tail: COMMAOP param_decl param_decl_tail | empty  
;

func_declarations: func_decl func_declarations | empty   
;
func_decl: FUNCTION any_type id OPENPAROP param_decl_list CLOSEPAROP BEGIN_TOKEN func_body END 
{
cout <<"\nSymbol table "<<$<sval>3<<endl;
if(head != 0){	
	while(head->value!= 0){
		cout << *head->value;
		free(head->value); //THis is where it fails
		struct block * temp = head->next;
		free(head);
		head = temp;
		//cout << head->next;
	}
}
head = 0;
curr = 0;
init = 0;
}
;
func_body: decl stmt_list
;

stmt_list: stmt stmt_list | empty  
;
stmt: base_stmt 
| if_stmt
| for_stmt  
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
{
	val = val + 1;
	if (head == 0){
		head = (block*)malloc(sizeof(block));
		stringstream temp;
		temp <<"\nSymbol table BLOCK "<<val<<endl;
		head->value = new string(temp.str());
		curr = (block*)malloc(sizeof(block));
		head->next = curr;			
	}
	else{
		stringstream temp;
		temp <<"\nSymbol table BLOCK "<<val<<endl;
		curr->value = new string(temp.str());
		curr->next = (block*)malloc(sizeof(block));
		curr = curr->next;
		curr->next = 0;
		curr->value = 0;
	}		
}
;
else_part: ELSE decl stmt_list 
/*{
val = val + 1;
sprintf($<sval>$, "%s %s", "\nSymbol table BLOCK ", val);
}*/
{
	val = val + 1;	
	if (head == 0){
		head = (block*)malloc(sizeof(block));
		stringstream temp;
		temp <<"\nSymbol table BLOCK "<<val<<endl;
		head->value = new string(temp.str());
		curr = (block*)malloc(sizeof(block));
		head->next = curr;			
	}
	else{
		stringstream temp;
		temp <<"\nSymbol table BLOCK "<<val<<endl;
		curr->value = new string(temp.str());
		curr->next = (block*)malloc(sizeof(block));
		curr = curr->next;
		curr->next = 0;
		curr->value = 0;
	}	
}
| empty  
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
{
	val = val + 1;	
	if (head == 0){
		head = (block*)malloc(sizeof(block));
		stringstream temp;
		temp <<"\nSymbol table BLOCK "<<val<<endl;
		head->value = new string(temp.str());
		curr = (block*)malloc(sizeof(block));
		head->next = curr;								
	}
	else{		
		stringstream temp;
		temp <<"\nSymbol table BLOCK "<<val<<endl;
		curr->value = new string(temp.str());
		curr->next = (block*)malloc(sizeof(block));
		curr = curr->next;
		curr->next = 0;
		curr->value = 0;
		
	}
}
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


