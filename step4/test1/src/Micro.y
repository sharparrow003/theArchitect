%{
#include <list>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct node{
	string *value;
	struct node *left;
	struct node *right;
};

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

/*Function declarations */
class ast {
	public:
		ast();
		~ast();
		node *root;
		node *newval(string);
		node *newop(node *, string);
		node *newmath(node *, string);	
		void destroy_tree();
		void addright(node *, node *);
		void inorder(node *);
		void preorder(node *);
		void postorder(node *);
	private:
		void destroy_tree(node *);
};
ast myast;
list<ast> astlist;

void yyerror(const char *s) { cout << "Not Accepted" << endl; exit(0); }
%}

%union {
	int ival;
	float fval;
	char *sval;
	char *iden;
	struct node *nval;
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
%token SUBOP
%token MULOP
%token DIVOP
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
program: PROGRAM id BEGIN_TOKEN pgm_body END 
{
}
;

id: IDENTIFIER  {$<sval>$ = $1;}
;

pgm_body: decl func_declarations    
;

decl: string_decl decl 
| var_decl decl 
{
}
| empty 
;

string_decl: STRING id ASSMTOP str SCOLONOP  
{
}
;

str: STRLIT  {$<sval>$ = $1; }
;

var_decl: var_type id_list SCOLONOP 
{
	//char * varList = strtok($<sval>2," ");
}
;

var_type: FLOAT {$<sval>$ = "FLOAT";}
| INT {$<sval>$ = "INT";
}
;

any_type: var_type {$<sval>$ = $<sval>1;}
| VOID  {$<sval>$ = $<sval>1;}
;

id_list: id id_tail {$<sval>$ = $<sval>1;}
;

id_tail: COMMAOP id id_tail 
{
	sprintf($<sval>$, "%s %s", $<sval>1, $<sval>2);
}
| empty 
;

param_decl_list: param_decl param_decl_tail
{
}
| empty   
;

param_decl: var_type id  
{
}
;

param_decl_tail: COMMAOP param_decl param_decl_tail | empty  
;

func_declarations: func_decl func_declarations | empty   
;

func_decl: FUNCTION any_type id OPENPAROP param_decl_list CLOSEPAROP BEGIN_TOKEN func_body END 

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
{
        //cout << "Started in order!" << endl;
	//myast.inorder($<nval>1); 
	//cout << "Started pre order!" << endl;
	//myast.preorder($<nval>1);
	//cout << "Started post order!" << endl;
	//myast.postorder($<nval>1);
	//cout << "HEAD-> " << *(myast.root->value) << endl;
	astlist.push_back(myast);
	myast = ast(); 	
}
;

assign_expr: id ASSMTOP expr  
{
	node *temp1;
	node *temp2;
	temp1 = myast.newval($<sval>1);
	temp2 = myast.newmath(temp1, "=");
	myast.addright(temp2,myast.root);	
	$<nval>$ = temp2;
}
//New ASSMTOP head with id as left, expr head as right
;

read_stmt: READ OPENPAROP id_list CLOSEPAROP SCOLONOP  
{	
	string s1($<sval>3);
	istringstream iss(s1);
	while(iss){
		string s2;
		iss >> s2;
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"READ");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);
			myast = ast();			 
		}
	}
}
;

write_stmt: WRITE OPENPAROP id_list CLOSEPAROP SCOLONOP  
{
	string s1($<sval>3);
	istringstream iss(s1);
	while(iss){
		string s2;
		iss >> s2;
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"WRITE");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);
			myast = ast();			 
		}
	}
}
;

return_stmt: RETURN expr SCOLONOP   
;

expr: expr_prefix factor 
{
	if($<nval>1 == 0){
		$<nval>$ = $<nval>2;
	}
	else{
		myast.addright($<nval>1, $<nval>2);
		$<nval>$ = $<nval>1;
	}
}
//If expr_prefix is null, use factor
//Else add factor to rightside of expr_prefix
;

expr_prefix: expr_prefix factor addop
{
	if ($<nval>1 != 0 && $<nval>2 != 0){
		node *temp = myast.newmath($<nval>2, $<sval>3);
		myast.addright($<nval>1,temp);
		$<nval>$ = temp;
	}
	else if ($<nval>1 == 0 && $<nval>2 != 0){
		node *temp = myast.newmath($<nval>2, $<sval>3);
		$<nval>$ = temp;
	}
	else{
		$<nval>$ = 0;
	}						
}
//If expr_prefix isn't null, make right side of expr_prefix an addop head with factor left
//Else make new addop head with factor as left node  
| empty
{$<nval>$ = 0}   
;

factor: factor_prefix postfix_expr
{
	if($<nval>1 == 0){
		$<nval>$ = $<nval>2;
	}
	else{
		myast.addright($<nval>1, $<nval>2);
		$<nval>$ = $<nval>1;
	}	
}    
//If factor_prefix is null, use postfix expr
//Else add postfixexpr to right side of factor_prefix

;

factor_prefix: factor_prefix postfix_expr mulop
{
	if ($<nval>1 != 0 && $<nval>2 != 0){
		node *temp = myast.newmath($<nval>2, $<sval>3);
		myast.addright($<nval>1,temp);
		$<nval>$ = temp;
	}
	else if ($<nval>1 == 0 && $<nval>2 != 0){
		node *temp = myast.newmath($<nval>2, $<sval>3);
		$<nval>$ = temp;
	}
	else{
		$<nval>$ = 0;
	}
}
//If factor_prefix is not null, make right side mulop head with postfix left
//Else make new mulop head with postfix_expr as left node
| empty
{$<nval>$ = 0;}
;

postfix_expr: primary 
{
	$<nval>$ = $<nval>1;
}
| call_expr   
;

call_expr: id OPENPAROP expr_list CLOSEPAROP
;

expr_list: expr expr_list_tail | empty   
;

expr_list_tail: COMMAOP expr expr_list_tail | empty   
;

primary: OPENPAROP expr CLOSEPAROP 
{
	$<nval>$ = $<nval>2;
}
| id
{
	node *temp = myast.newval($<sval>1);
	$<nval>$ = temp;
}
| INTLIT
{
	ostringstream buffer;
	buffer << $<ival>1;
	node *temp = myast.newval(buffer.str());
	$<nval>$ = temp;
} 
| FLTLIT
{
	ostringstream buffer;
	buffer << $<fval>1;
	node *temp = myast.newval(buffer.str());
	$<nval>$ = temp;
}
;

addop: ADDOP 
{$<sval>$ = "+";}
| SUBOP
{$<sval>$ = "-";}   
;

mulop: MULOP 
{$<sval>$ = "*";}
| DIVOP
{$<sval>$ = "/";}   
;

if_stmt: IF OPENPAROP cond CLOSEPAROP decl stmt_list else_part FI   
{		
}
;

else_part: ELSE decl stmt_list 
/*{
val = val + 1;
sprintf($<sval>$, "%s %s", "\nSymbol table BLOCK ", val);
}*/
{	
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
}
;

empty:    
;
%%



ast::ast() {
	root = 0;
}

ast::~ast() {
	if (root != 0){
		delete root;
	}
}

void ast::destroy_tree(node *leaf){
	if(leaf != 0){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		if (leaf->value != 0){
			delete leaf->value;
			//cout << "Deleted leaf value!" << endl;
		}
		delete leaf;
		//cout << "Deleted whole leaf!" << endl;	
	}
	root = 0;
}

void ast::destroy_tree(){
	destroy_tree(root);
}

void ast::addright(node *head, node *leaf){
	if(leaf != 0 && head != 0){
		if(root == leaf){
			//If adding root node as left, make new root the head
			root = head;
		}	
		head->right = leaf;
	}
}

void ast::inorder(node *head){
	if(head != 0){
		inorder(head->left);
		cout << *(head->value) << endl;
		inorder(head->right);
	}
}

void ast::preorder(node *head){
	if(head != 0){
		cout << *(head->value) << endl;
		preorder(head->left);
		preorder(head->right);
	}
}

void ast::postorder(node *head){
	if(head != 0){
		postorder(head->left);
		postorder(head->right);
		cout << *(head->value) << endl;
	}
}

//node *ast::new(node *value, string operation)

node *ast::newval(string key){
	node *head = new node();
	if (root == 0){root = head;}
	head->value = new string(key);
	head->left = 0;
	head->right = 0;
	return head;
}

node *ast::newop(node *value, string operation){
	node *head = new node();
	if (root == value){root = head;}
	head->value = new string(operation);
	head->left = 0;
	head->right = value;
	return head;	
}

node *ast::newmath(node *value, string operation){
	node *head = new node();
	if (root == value){root = head;}
	head->value = new string(operation);
	head->left = value;
	//cout << "HEAD: " << *(head->value) << "Left " << *(head->left->value) << endl;
	head->right = 0;
	return head;
}
	


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
    myast = ast();
    do {
      yyparse();
    } while (!feof(yyin));
    //Access astlist here like any linked list 
    
    //Access example below
    cout << "Front of the list!" << endl;
    myast.inorder((astlist.front()).root);
    cout << "Back of the list!" << endl;
    myast.inorder((astlist.back()).root);	
  }
}


