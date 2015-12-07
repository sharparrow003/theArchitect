%{
#include <list>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "src/ast.h"
#include "src/cfg.h"
#include "src/stat.h"

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

//Michael's Declarations
ast myast;
deque<ast> astlist;
list<string> varlist;
vector<cfg> cfglist;
//exprhead is being used as a temporary place holder for the root expression in nested parentheticals. i.e. (((x)+x)+x)
static node * exprhead = 0;
static list<stack<list<string>*> *> empire;
static stack<list<string>*> currkingdom;
static list<string>currfief;
static vector<string>myIRlist;
//ducttape list for storing exprlists in call expressions
static list<node *>ducttape;
static int val = 0;
static int scope = 0;

//Lalit's Declarations
static int registerValue = 1;
string datatype="i";
int regVal = 0;		//Values of temp variables T
int localVal = 0;	//Values of local variables L
int parVal = 0;		//Values of parameter variables P
map< string, map<string, string> > symbolTable;

int labelCount = 1;

list <string> labelStack;
list <string> activityStack;

int getRegister(string IRReg);					//Calculates the register number from IR Node ***IMPORTANT***

list<string> IRList;
list<string> IRNodeList;
list<string> astPostOrder;
list<string> generateTinyCode();				//Generates tiny code from the list of IR Nodes  ***IMPORTANT***
void printList(list<string> strList);				//Prints out list ***NOT IMPORTANT***

void yyerror(const char *s) { cout << "Not Accepted" << endl; exit(0); }
%}
%union {
	int ival;
	float fval;
	char *sval;
	char *iden;
	void *fief;
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
%token GREATER;
%token LESSER;
%token EQUALS;
%token NEQUALS;
%token LEQUALS;
%token GEQUALS;
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
	varlist.push_back("Symbol table GLOBAL");
	while(!empire.empty()){
		stack<list<string>*> *kingdomptr = empire.front();
		empire.pop_front();
		while(!(*kingdomptr).empty()){
			//cout << "Pre Ack Level 2" << endl;
			list<string>*fiefptr = (*kingdomptr).top();
			(*kingdomptr).pop();
			//cout << "Fief Pointer: " << fiefptr << endl;
		 	//cout << "Ack Level 2" << endl;
			if(!(*fiefptr).empty()){	
				//cout << "Above Fief Pointer is not empty" << endl;
				for (list<string>::iterator it = (*fiefptr).begin(); it != (*fiefptr).end(); it++){
					//cout << "Pre Ack Level 3" << endl;
					if (*it == "Symbol table IF" || *it == "Symbol table FOR" || *it == "Symbol table ELSE"){
						val = val + 1;
						//cout << endl << *it << " " << val << endl;
						stringstream ss;
						ss << *it << " " << val;
						varlist.push_back(ss.str());
					}
					else{
						//cout << *it << endl;
						varlist.push_back(*it);
					}
					//cout << "Ack Level 3" << endl;
				}
				(*fiefptr).clear();
			}
			delete fiefptr;
		}
		delete kingdomptr;
	}
}
;
id: IDENTIFIER  {$<sval>$ = $1;}
;
pgm_body: decl func_declarations    
;
decl: string_decl decl
{
	if (scope == 0){
		if(!currfief.empty()){
			list<string>*newfief = new list<string>;
			*newfief = currfief;
			currkingdom.push(newfief); 			
			currfief.clear();
			stack<list<string>*> *newkingdom = new stack<list<string>*>;
			*newkingdom = currkingdom;
			empire.push_back(newkingdom);
			currkingdom.pop();
		}
		$<fief>$ = 0;
		scope = 1;
	}
	else{
		if(!currfief.empty()){
			list<string>*newfief = new list<string>;
			*newfief = currfief;	
			$<fief>$ = newfief;
			//cout << $<fief>$ << endl;
			currfief.clear();
		}
		else if($<fief>2 != 0){
			$<fief>$ = $<fief>2;
		}		
	}
	//if ((*$<fief>$).size() > 1000){
	//	cout << "this mothafucka" << endl;
	//}
}
| var_decl decl
{
	if (scope == 0){
		//cout << "Enter here? " << endl;
		if(!currfief.empty()){
			/*
			while(currfief.size() > 9){
				list<string>*newfief = new list<string>;
				while((*newfief).size() < 10 && !currfief.empty()){
					(*newfief).push_back(currfief.front());
					currfief.pop_front();
				}
				currkingdom.push(newfief);
				newfief = 0;
			}
			*/
			list<string>*newfief = new list<string>;
			*newfief = currfief;
			currkingdom.push(newfief);
						
			//cout << "First element: " << currfief.front() << endl;		
			
			currfief.clear();
			stack<list<string>*> *newkingdom = new stack<list<string>*>;
			*newkingdom = currkingdom;
			empire.push_back(newkingdom);
			while(!currkingdom.empty()){
				currkingdom.pop();	
			}
		}
		$<fief>$ = 0;
		scope = 1;
	}
	else{
		if(!currfief.empty()){
			//cout << "Allocate new decl" << endl;
			list<string> *newfief = new list<string>;
			//cout << currfief.size();
			*newfief = currfief;	
			
			$<fief>$ = newfief;
			currfief.clear();
		}
		else if ($<fief>2 != 0){
			$<fief>$ = $<fief>2;
		}
	}
 	//cout << "Fief 1: " << $<fief>1 << endl;
	//cout << "Fief 2: " << $<fief>2 << endl;
} 
| empty
{
	if (currfief.empty() && scope == 0){scope = 1;}
	$<fief>$ = 0;
}
;

string_decl: STRING id ASSMTOP str SCOLONOP  
{
	string s1($<sval>2);
	string s2($<sval>4);
	string s3("STRING " + s1 + " " + s2);
	//cout<<s3<<endl;
	//varlist.push_back(s3);
	currfief.push_back(s3);
}
;
str: STRLIT  {$<sval>$ = $1; }
;
var_decl: var_type id_list SCOLONOP 
{
	string s1($<sval>2);
	stringstream ss(s1);
	string s2($<sval>1);
	string s3;
	while(ss >> s3){
		if(s3 != ""){
			//varlist.push_back(s2 + " " + s3);			 
			//cout << "Testing: " << s2 << " " << s3 << endl;
			currfief.push_back(s2 + " " + s3);	
		}
	}
}
;
var_type: FLOAT {$<sval>$ = "FLOAT";}
| INT {$<sval>$ = "INT";}
;
any_type: var_type {$<sval>$ = $<sval>1;}
| VOID  {$<sval>$ = $<sval>1;}
;

id_list: id id_tail {
	if($<sval>2 != 0){
		string s1;
		string s2($<sval>2);
		stringstream ss;
		ss << $<sval>1 << " " << $<sval>2;
		s1 = ss.str();
		const char *temp = s1.c_str();
		$<sval>$ = (char*)temp;
	}
	else{
		$<sval>$ = $<sval>1;
	}
}
;

id_tail: COMMAOP id id_tail {
	string s1;
	stringstream ss;
	if (!$<sval>3){
		s1 = string($<sval>2);
		const char *temp = s1.c_str();
		$<sval>$ = (char*)temp;
	}
	else{
		ss << $<sval>2 << " " << $<sval>3;
		s1 =ss.str();
		const char *temp = s1.c_str();
		$<sval>$ = (char*)temp;
	}
}
| empty 
{
	$<sval>$ = 0;
}
;

param_decl_list: param_decl param_decl_tail
{
	list<string> *fiefptr = new list<string>;
	*fiefptr = currfief;
	currfief.clear();
	$<fief>$ = fiefptr;
}
| empty
{$<fief>$ = 0;}   
;

param_decl: var_type id  
{
	string s1($<sval>1);
	string s2($<sval>2);
	string s3(s1 + " " + s2);
	currfief.push_back(s3);
}
;

param_decl_tail: COMMAOP param_decl param_decl_tail | empty  
;
func_declarations: func_decl func_declarations | empty   
;
func_decl: FUNCTION any_type id OPENPAROP param_decl_list CLOSEPAROP BEGIN_TOKEN func_body END
{
	//Push the function name on to a new list to be added to the function stack as a whole
	//cout << "Step 1 Func Decl" << endl;
	ostringstream oss;

	oss << endl << "Symbol table " << $<sval>3;	
	list<string>*fnname = new list<string>;
	(*fnname).push_back(oss.str());
	
	//cout << "Step 2 Func Decl" << endl;
	//dynamically allocate new stack to copy current scope (kingdom) into;
	stack<list<string>*> *newkingdom = new stack<list<string>*>;
	if (!currkingdom.empty()){
		*newkingdom = currkingdom;
	}
	//cout << "Step 3 Func Decl" << endl;
	//push param declarations and function name
	if ($<fief>5 != 0){	
		(*newkingdom).push((list<string>*)$<fief>5);
	}
	//cout << $<sval>3 << " " << $<fief>5 << endl;
	(*newkingdom).push(fnname);
	
	//After pushing function name, add the function stack to list of functions
	empire.push_back(newkingdom);
	while(!currkingdom.empty()){
		
		list<string>tempfief;
		tempfief = *(currkingdom.top());	
		currkingdom.pop();
	}
	
	if (!astlist.empty()){
		if ((astlist.size() + 1) >= $<ival>8){			
			stringstream ss;
			if ($<fief>5 != 0){	
				list<string> paramstorage = *((list<string>*)$<fief>5);
				ss << "Function " << $<sval>2 << " " << $<sval>3;
				for (list<string>::iterator ls = paramstorage.begin(); ls != paramstorage.end(); ls++){
					string s1(*ls);
					string s2 = s1.substr(s1.find(" ",0),string::npos);
					ss << " " << s2;	
				}	
			}
			else{ss << "Function " << $<sval>2 << " " << $<sval>3;}
			ast function = ast();
			ast functionend = ast();
			node *fnname = function.newval(ss.str());
			node *fnend = functionend.newval("FEND");			
			deque<ast>::iterator it = astlist.begin() + $<ival>8;
			astlist.insert(it,function);
			astlist.push_back(functionend);
		}
	}
} 
;

func_body: decl stmt_list
{
	//cout << $<fief>1 << endl;
	if($<fief>1 != 0){	
		if(!(*((list<string>*)$<fief>1)).empty()){
			currkingdom.push((list<string>*)$<fief>1);
		}
	}
	//test the $<ival>$ from stmtlist with this code
	//check if astlist.size < $<ival>$
	//hopefully it is the first statement in whatever function it is and i can put the function in front of its constituents
	$<ival>$ = $<ival>2;
}
;

stmt_list: stmt stmt_list   
{
	$<ival>$ = $<ival>1;
}
| empty
{
	$<ival>$ = 0;
}
;
stmt: base_stmt 
{$<ival>$ = $<ival>1;}
| if_stmt 
{$<ival>$ = $<ival>1;}
| for_stmt  
{$<ival>$ = 0;}
;

base_stmt: assign_stmt
{$<ival>$ = $<ival>1;} 
| read_stmt 
{$<ival>$ = $<ival>1;}
| write_stmt 
{$<ival>$ = $<ival>1;}
| return_stmt
{$<ival>$ = 0;}   
;

assign_stmt: assign_expr SCOLONOP   
{
	int presize = astlist.size();
	//cout << "Started post order!" << endl;
	//myast.postorder($<nval>1);	
	ast tempast;
	astlist.push_back(myast);
	//return pointer to statement's place in the list.
	if (!ducttape.empty()){
		for(list<node*>::iterator it = ducttape.begin(); it != ducttape.end(); it++){
			tempast = ast(*it);
			astlist.push_back(tempast);
		}
		tempast = ast();
		tempast.newval("CALLEND");
		astlist.push_back(tempast);
		ducttape.clear();
	}	
	myast = ast();
	//cout << (astlist.size()-1) << endl;
	$<ival>$ = presize;	
}
;

assign_expr: id ASSMTOP expr  
{
	node *temp1;
	node *temp2;
	temp1 = myast.newval($<sval>1);
	temp2 = myast.newmath(temp1, ":=");	
	//cout << "Begin Post Order" << endl;
	//myast.postorder(temp2);
	//cout << "End Post Order" << endl;
	myast.addright(temp2, $<nval>3);
	ast tempast($<nval>3);
	//cout << "Begin post order!" << endl;
	//tempast.postorder(myast.root);	
	$<nval>$ = temp2;
}
//New ASSMTOP head with id as left, expr head as right
;

read_stmt: READ OPENPAROP id_list CLOSEPAROP SCOLONOP  
{	
	int presize;
	presize = astlist.size();
	string s1($<sval>3);
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"READ");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);
			myast = ast();			 
		}
	}
	$<ival>$ = presize;
}
;

write_stmt: WRITE OPENPAROP id_list CLOSEPAROP SCOLONOP  
{
	int presize;
	presize = astlist.size();
	string s1($<sval>3);
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"WRITE");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);		 
			myast = ast();
		}
	}
	$<ival>$ = presize;
}
;

return_stmt: RETURN expr SCOLONOP
{
	int presize;
	presize = astlist.size();
	ast tempast($<nval>2);
	node *temp1 = tempast.newop($<nval>2, "RETURN");
	astlist.push_back(tempast);
	$<ival>$ = presize;
	myast = ast();
}   
;

expr: expr_prefix factor 
{
	if($<nval>1 == 0){
		$<nval>$ = $<nval>2;
		exprhead = 0;
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
		exprhead = temp;
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
{$<nval>$ = $<nval>1;}
| call_expr
{$<nval>$ = $<nval>1;} 
;

call_expr: id OPENPAROP expr_list CLOSEPAROP
{
	/*
	int presize;
	presize = astlist.size();

	string s1($<sval>3);
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		if(s2 != ""){
			node *temp1 = myast.newval(s2);
			node *temp2 = myast.newop(temp1,"READ");
			astlist.push_back(myast);
			//cout << *(myast.root->value);
			//cout << *(myast.root->right->value);
			myast = ast();			 
		}
	}
	$<ival>$ = presize;
	*/
	/*
	for (list<node*>::iterator it = ducttape.begin(); it != ducttape.end(); it++){
		cout << *((*it)->value) << endl;
	}
	*/
	myast = ast();
	//cout << "Call Expression Before" << endl;
	//myast.postorder(myast.root);
	node *temp1 = myast.newval($<sval>1);
	$<nval>$ = myast.newop(temp1, "CALL");
	//cout << "After" << endl;
	//myast.postorder(myast.root);
	
}
;
expr_list: expr expr_list_tail 
{
	ducttape.push_front($<nval>1);
}
| empty   
;
expr_list_tail: COMMAOP expr expr_list_tail
{
	ducttape.push_back($<nval>2);
} 
| empty   
;

primary: OPENPAROP expr CLOSEPAROP 
{
	if (exprhead != 0){
		$<nval>$ = exprhead;
		exprhead = 0;
	}
	else{
		$<nval>$ = $<nval>2;
	}
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
	string s1(buffer.str());
	int findings = int(s1.find("."));
	if(findings == -1) {
		s1 = s1 + ".0";
	}

	node *temp = myast.newval(s1);
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
	//AST and Control Structure code	
	node *ifptr = myast.newval("IF");
	node *fiptr = myast.newval("FI");
	myast.root = 0;
	node *condptr = $<nval>3;
	//insert a new if node right before the statement list we saved	
	deque<ast>::iterator it = astlist.begin() + $<ival>6;
	
	ast ifast = ast(ifptr);
	ast fiast = ast(fiptr);
	ast condast = ast(condptr);
	
	astlist.insert(it,condast);
	it = astlist.begin() + $<ival>6;
	astlist.insert(it,ifast);
	astlist.push_back(fiast);
	$<ival>$ = $<ival>6;

	//Symbol Table Generation code
	if($<fief>5 != 0){	
		string s1("Symbol table IF");
		//fief has to be void in order to be transferrable in C union
		list<string>*vectorptr = (list<string>*)$<fief>5;	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table IF");
		list<string>*newfief = new list<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}		
}
;

else_part: ELSE decl stmt_list 
{	
	//AST and Control Structure code	
	ast elseast;
	elseast = ast();
	node *elseptr = elseast.newval("ELSE");
	//cout << "Size of list after ELSE: " << $<ival>3 << endl;
	deque<ast>::iterator it = astlist.begin() + $<ival>3;
	//cout << *((*it).root->value) << endl;
	astlist.insert(it,elseast);

	//Symbol Table Generation code
	if($<fief>2 != 0){	
		string s1("Symbol table ELSE");
		//fief has to be void in order to be transferrable in C union
		list<string>*vectorptr = (list<string>*)$<fief>2;	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table ELSE");
		list<string>*newfief = new list<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}
}
| empty  
;

cond: expr compop expr  
{
	//make new head of the conditional statement
	node *conhead = myast.newmath($<nval>1,$<sval>2);
	myast.addright(conhead,$<nval>3);
	$<nval>$ = conhead;
	myast.root = 0;
}
;

compop: GREATER 
{$<sval>$ = ">";}
| LESSER
{$<sval>$ = "<";} 
| EQUALS 
{$<sval>$ = "=";}
| NEQUALS 
{$<sval>$ = "!=";}
| LEQUALS 
{$<sval>$ = "<=";}
| GEQUALS  
{$<sval>$ = ">=";} 
;

init_stmt: assign_expr 
{
	$<nval>$ = $<nval>1;
	myast.root = 0;
}
| empty   
{
	$<nval>$ = $<nval>1;
	myast.root = 0
}
;

incr_stmt: assign_expr   
{
	$<nval>$ = $<nval>1;
	myast.root = 0;
}
| empty
{
	$<nval>$ = $<nval>1;
	myast.root = 0;
}
;

for_stmt: FOR OPENPAROP init_stmt SCOLONOP cond SCOLONOP incr_stmt CLOSEPAROP decl stmt_list ROF   
{
	//AST and Control Structure code	
	//insert conditional ast
	ast tempast = ast($<nval>5);
	deque<ast>::iterator it = astlist.begin() + $<ival>10;
	astlist.insert(it, tempast);

	//insert FOR ast marker
	tempast = ast();
	node *ptr = tempast.newval("FOR");
	it = astlist.begin() + $<ival>10;
	astlist.insert(it, tempast);	
	
	//insert optional init ast
	if ($<nval>3 != 0){
		tempast = ast($<nval>3);
		it = astlist.begin() + $<ival>10;
		astlist.insert(it,tempast);
	}
	
	//insert ROF and increment at the end
	tempast = ast($<nval>7);
	astlist.push_back(tempast);
	tempast = ast();
	ptr = tempast.newval("ROF");
	astlist.push_back(tempast);


	//Symbol Table Generation code
	if($<fief>9 != 0){		
		string s1("Symbol table FOR");	
		//fief has to be void in order to be transferrable in C union
		list<string>*vectorptr = (list<string>*)$<fief>9;	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table FOR");
		list<string>*newfief = new list<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}
		
}
;

empty:    
;
%%

void printList(ast myast) {
	while (!astlist.empty()) {
 		myast.postorder((astlist.front()).root);
 		astlist.pop_front();
	}
}

void generateIRPostOrderList(node *head) {
	if(head != 0){
		generateIRPostOrderList(head->left);
		generateIRPostOrderList(head->right);
		astPostOrder.push_back(*(head->value));
	}
}

void checkDatatype(string var) {
	list <string> varlistTemp = varlist;
	string type;
	string varTemp;
	int flag = 0;
	while(!varlistTemp.empty()) {
	istringstream iss(varlistTemp.front());
	iss >> type;
	iss >> varTemp;
	//cout<<type<<endl;
	if(varTemp == var) {
		flag = 1;
		if(type == "INT") {
			datatype = "i";
		}
		else if(type == "FLOAT") {
			datatype = "f";
		}
		else {
			datatype = "s";
		}
	}
	varlistTemp.pop_front();
	}

	if(flag == 0) {
		if(var.find('.') != string::npos) {
			datatype = "f";
		}
		else {
			datatype = "i";
		}

	}
}

void populateSymbolTable(string functionName) {
	/*
	while(!varlistTemp.empty()) {
		istringstream iss2(varlistTemp.front());
		string variableTemp1;
		string variableTemp2;
		iss2 >> variableTemp1;
			
		if(variableTemp1 == "Symbol") {
			iss2 >> variableTemp2;
			iss2 >> variableTemp2;

			if(variableTemp2 == functionName) {
				i
				
			

		varlistTemp.pop_front();
	}*/
}

void generateIRList() {
	ast astNode = ast();
	list<string> temp;
	string op1;
	string op2;
	string result;

	string regStore,regStore1,regStore2;
	string IRDisplay;
	string label, templabel1, templabel2;
	string tempActivity;
	string funcDeclaration;
	string firstWord;
	ostringstream convert;

	string returnType;
	string functionName;
	string variableName;

	map <string, string> tempMap;
	list <string> varlistTemp;

	while (!astlist.empty()) {
		astNode = astlist.front();
		generateIRPostOrderList(astNode.root);
		astlist.pop_front();
	}

	while(!astPostOrder.empty()) {
		/*
		if (IRNodeList.front()[0] != '=' || IRNodeList.front()[0] != '+' || IRNodeList.front()[0] != '-' || IRNodeList.front()[0] != '*' || IRNodeList.front()[0] != '/' || IRNodeList.front() != "READ" || IRNodeList.front() != "WRITE") {
			temp.push_back (IRNodeList.front());
			//temp.push_back ("OP");
		}
		else {
			temp.push_back ("OP");
			
		}
		*/
		
		istringstream  iss(astPostOrder.front());
		iss >> firstWord;
		//cout<<"First Word-->"<<firstWord<<endl;
		if(astPostOrder.front() == ":=") {
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();

			op1 = temp.back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
				//cout<<op1<<endl;
			}
			if(datatype == "i") {
				IRDisplay = "STOREI "+op1+" "+regStore;
				IRNodeList.push_back(IRDisplay);
				temp.pop_back();

				op1 = temp.back();
				temp.pop_back();
				IRDisplay = "STOREI "+regStore+" "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "STOREF "+op1+" "+regStore;
				IRNodeList.push_back(IRDisplay);
				temp.pop_back();

				op1 = temp.back();
				temp.pop_back();
				IRDisplay = "STOREF "+regStore+" "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
		else if (astPostOrder.front()[0] == '+') {
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				//checkDatatype(op2);
			}
			if(datatype == "i") {
				IRDisplay = "ADDI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "ADDF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}

		else if (astPostOrder.front()[0] == '-') {
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();
			
			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				checkDatatype(op2);
			}
			if(datatype == "i") {
				IRDisplay = "SUBI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "SUBF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
		
		else if (astPostOrder.front()[0] == '*') {
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				checkDatatype(op2);
			}
			if(datatype == "i") {		
				IRDisplay = "MULTI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "MULTF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
	
		else if (astPostOrder.front()[0] == '/') {
			convert.str("");
			convert << registerValue;
			regStore = "$T"+convert.str();

			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			else if(op2[0] != '$') {
				checkDatatype(op2);
			}
			if(datatype == "i") {
				IRDisplay = "DIVI "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "DIVF "+op1+" "+op2+" "+regStore;
				IRNodeList.push_back(IRDisplay);
			}
			
			temp.push_back(regStore);
			registerValue = registerValue + 1;
			convert.str("");
		}
		
		else if(firstWord == "Function") {
			//Reset regVal (Temp), localVal (Local) and parVal (parameter) to 0
			//Label and Link
			//Generate map of local and parameter values
			regVal = 1;
			localVal = 1;
			parVal = 1;
			returnType = "";
			functionName = "";
			varlistTemp = varlist;

			iss>>returnType;
			iss>>functionName;
			
			IRDisplay = "LABEL "+functionName;
			IRNodeList.push_back(IRDisplay);
			IRDisplay = "LINK";
			IRNodeList.push_back(IRDisplay);

			tempMap.clear();
			cout<<"Function name-->"<<functionName<<endl;
			while(iss >> variableName) {
				convert.str("");
				convert << parVal;
				tempMap[variableName] = "$P"+convert.str();
				parVal++;
			}
			
			/*
			for (map<string,string>::iterator it=tempMap.begin(); it!=tempMap.end(); ++it) {
				cout<<it->first<<"-->"<<it->second<<endl;
			}
			*/
		
		}

		else if(astPostOrder.front() == "CALL") {
			//Generate activation record
		}

		else if(astPostOrder.front() == "CALLEND") {
			//Do we need this?
		}

		else if(astPostOrder.front() == "RETURN") {
			//Store the return value in $R
			//RET
			//UNLINK
		}

		else if(astPostOrder.front() == "IF") {
			activityStack.push_front("IF");

			//Else label
			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();

			labelStack.push_front(label);
			labelCount++;
			//Exit label

			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();

			labelStack.push_front(label);
			labelCount++;
		}
		else if(astPostOrder.front() == "ELSE") {
			activityStack.push_front("ELSE");
		
			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.pop_front();
			IRDisplay = "JUMP "+templabel1;
			IRNodeList.push_back(IRDisplay);
			IRDisplay = "LABEL "+templabel2;
			IRNodeList.push_back(IRDisplay);
			
			labelStack.push_front(templabel1);
		}
		else if(astPostOrder.front() == "FI") {
			tempActivity = activityStack.front();
			activityStack.pop_front();
		
			if(tempActivity == "IF") {
				//IF -- FI
				
				templabel1 = labelStack.front();
				labelStack.pop_front();
				IRDisplay = "JUMP "+templabel1;
				IRNodeList.push_back(IRDisplay);

				templabel2 = labelStack.front();
				labelStack.pop_front();				
				IRDisplay = "LABEL "+templabel2;
				IRNodeList.push_back(IRDisplay);

				IRDisplay = "LABEL "+templabel1;
				IRNodeList.push_back(IRDisplay);
			
				//labelStack.push_front(templabel1);
			}
			else {
				//IF -- ELSE -- FI
				activityStack.pop_front();
				templabel1 = labelStack.front();
				labelStack.pop_front();
				//templabel1 = labelStack.front();
				//labelStack.pop_front();
				IRDisplay = "JUMP "+templabel1;
				IRNodeList.push_back(IRDisplay);
				IRDisplay = "LABEL "+templabel1;
				IRNodeList.push_back(IRDisplay);
			
				//labelStack.push_front(templabel1);
			}
		}

		else if (astPostOrder.front() == "FOR") {
			//Out label
			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();

			labelStack.push_front(label);
			labelCount++;
			//For label

			convert.str("");
			convert << labelCount;
			label = "label"+convert.str();
			
			IRDisplay = "LABEL "+label;
			IRNodeList.push_back(IRDisplay);

			labelStack.push_front(label);
			labelCount++;
		}

		else if (astPostOrder.front() == "ROF") {
			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.pop_front();
			IRDisplay = "JUMP "+templabel1;
			IRNodeList.push_back(IRDisplay);
			IRDisplay = "LABEL "+templabel2;
			IRNodeList.push_back(IRDisplay);
			
			//labelStack.push_front(templabel1);
		}
		

		
		else if (astPostOrder.front() == "<") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "GE "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == "<=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "GT "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == ">") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "LE "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == ">=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "LT "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == "=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "NE "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}

		else if (astPostOrder.front() == "!=") {
			op2 = temp.back();
			temp.pop_back();
			op1 = temp.back();
			temp.pop_back();

			convert.str("");
			convert << registerValue;
			regStore1 = "$T"+convert.str();

			IRDisplay = "STOREI "+op2+" "+regStore1;
			IRNodeList.push_back(IRDisplay);
			
	
			registerValue = registerValue + 1;
			convert.str("");

			convert << registerValue;
			regStore2 = "$T"+convert.str();

			registerValue = registerValue + 1;

			IRDisplay = "STOREI "+op1+" "+regStore2;
			IRNodeList.push_back(IRDisplay);

			templabel1 = labelStack.front();
			labelStack.pop_front();
			templabel2 = labelStack.front();
			labelStack.push_front(templabel1);
			//labelStack.push_front(templabel2);

			IRDisplay = "EQ "+regStore2+" "+regStore1+" "+templabel2;
			IRNodeList.push_back(IRDisplay);
		}
		
		else if(astPostOrder.front() == "READ") {

			op1 = temp.back();
			
			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			
			if(datatype == "i") {
				IRDisplay = "READI "+op1;		
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "READF "+op1;		
				IRNodeList.push_back(IRDisplay);
			}
			temp.pop_back();
		}

		else if(astPostOrder.front() == "WRITE") {

			op1 = temp.back();
			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
			}
			
			if(datatype == "i") {
				IRDisplay = "WRITEI "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			else if(datatype == "f") {
				IRDisplay = "WRITEF "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			else {
				IRDisplay = "WRITES "+op1;
				IRNodeList.push_back(IRDisplay);
			}
			temp.pop_back();
		}
		else {
			temp.push_back(astPostOrder.front());
		}
		astPostOrder.pop_front();
	}

	list <string> IRNodeListDisplay = IRNodeList;
	IRList = IRNodeList;	
	list<string>::iterator it = IRNodeListDisplay.begin(); 
	for (it; it != IRNodeListDisplay.end();it++){
		//cout << *it << endl;
		myIRlist.push_back(*it);
	}
	
       	cout<<";IR code"<<endl;
	while (!IRNodeListDisplay.empty()) {
		cout<<";"<<IRNodeListDisplay.front()<<endl;
		IRNodeListDisplay.pop_front();
	}
	
}	

int getRegister(string IRReg){
	int strLen = IRReg.length();
	string IRRegVal =  IRReg.substr(2, strLen-2);
	int regReturn = atoi(IRRegVal.c_str()) - 1;
	
	return regReturn;
}
	

list<string> generateTinyCode() {
	list<string> tinyCode;
	
	

	while(!IRList.empty()){
		string stmtIR = IRList.front();
		string temp;
		string op;
		string op1;
		string op2;
		string result;
		string label;
		int regVal1;
		int regVal2;
		int regVal3;
	
		string tinyStmt;

		temp = stmtIR;

		istringstream iss(temp);

		iss>>op;
		
		//tinyCode.push_back(op);

		//ADDI op1 op2 Result
		if (op == "ADDI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addi "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addi r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//ADDF op1 op2 Result
		else if (op == "ADDF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "addr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//SUBI op1 op2 Result
		else if (op == "SUBI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subi "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subi r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//SUBF op1 op2 Result
		else if (op == "ADDF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "subr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}

		//MULTI op1 op2 Result
		else if (op == "MULTI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "muli "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "muli r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}

		//MULTF op1 op2 Result
		else if (op == "MULTF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "mulr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "mulr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}
		//DIVI op1 op2 Result
		else if (op == "DIVI") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divi "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divi r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}		

		//DIVF op1 op2 Result
		else if (op == "DIVF") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			
			if (op1[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move "+op1+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
			}
			else {
				convert.str("");
				regVal1 = getRegister(op1);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "move r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
			}
			
			if (op2[0] != '$') {
				convert.str("");
				regVal1 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divr "+op2+" r"+convert.str();
				tinyCode.push_back(tinyStmt);
				
			}

			else {
				convert.str("");
				regVal1 = getRegister(op2);
				regVal2 = getRegister(result);
				convert << regVal1;
				tinyStmt = "divr r"+convert.str()+" ";
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+" r"+convert.str()+" ";
				tinyCode.push_back(tinyStmt);
				
			}			
					
		}	

		//STOREI op1 Result
		else if (op == "STOREI") {
			iss >> op1;
			iss >> result;
			tinyStmt = "move ";
			ostringstream convert;

			if(op1[0] == '$'){
				convert.str("");
				regVal1 = getRegister(op1);
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
				
			}
			else {
				tinyStmt = tinyStmt+op1+" ";
			}

			if(result[0] == '$'){
				convert.str("");
				regVal2 = getRegister(result);
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
				
			}
			else {
				tinyStmt = tinyStmt+result+" ";
				
			}
			//regVal = regVal + 1;
			tinyCode.push_back(tinyStmt);	
				
			
		}
		//STOREF op1 Result
		else if (op == "STOREF") {
			iss >> op1;
			iss >> result;
			tinyStmt = "move ";
			ostringstream convert;

			if(op1[0] == '$'){
				convert.str("");
				regVal1 = getRegister(op1);
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
				
			}
			else {
				tinyStmt = tinyStmt+op1+" ";
			}

			if(result[0] == '$'){
				convert.str("");
				regVal2 = getRegister(result);
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
				
			}
			else {
				tinyStmt = tinyStmt+result+" ";
				
			}

			//regVal = regVal + 1;
			tinyCode.push_back(tinyStmt);	
				
			
		}
		//GT op1 op2 label
		else if (op == "GT") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jgt "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//GE op1 op2 label
		else if (op == "GE") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jge "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//LT op1 op2 label
		else if (op == "LT") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jlt "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//LE op1 op2 label
		else if (op == "LE") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jle "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//NE op1 op2 label
		else if (op == "NE") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jne "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//EQ op1 op2 label
		else if (op == "EQ") {
			iss >> op1;
			iss >> op2;
			iss >> result;
			ostringstream convert;
			tinyStmt = "cmpi ";
			
			if(op1[0] == '$') {
				regVal1 = getRegister(op1);
				convert.str("");
				convert << regVal1;
				tinyStmt = tinyStmt+"r"+convert.str()+" ";
			}
			else {
				tinyStmt = tinyStmt+" "+op1+" ";
			}
			if(op2[0] == '$') {
				regVal2 = getRegister(op2);
				convert.str("");
				convert << regVal2;
				tinyStmt = tinyStmt+"r"+convert.str();
			}
			else {
				tinyStmt = tinyStmt+" "+op2;
			}
			tinyCode.push_back(tinyStmt);
			tinyStmt = "jeq "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//JUMP label
		else if (op == "JUMP") {
			iss >> result;

			tinyStmt = "jmp "+result;
			tinyCode.push_back(tinyStmt);			
					
		}
		//LABEL label
		else if (op == "LABEL") {
			iss >> result;

			tinyStmt = "label "+result;
			tinyCode.push_back(tinyStmt);
		}		

		//READI
		else if (op == "READI") {
			iss >> result;
	
			tinyStmt = "sys readi "+result;
			tinyCode.push_back(tinyStmt);
		}
		//READF
		else if (op == "READF") {
			iss >> result;
	
			tinyStmt = "sys readr "+result;
			tinyCode.push_back(tinyStmt);
		}
		//WRITEI
		else if (op == "WRITEI") {
			iss >> result;
	
			tinyStmt = "sys writei "+result;
			tinyCode.push_back(tinyStmt);
		}
		//WRITEF
		else if (op == "WRITEF") {
			iss >> result;
	
			tinyStmt = "sys writer "+result;
			tinyCode.push_back(tinyStmt);
		}

		//WRITES
		else if (op == "WRITES") {
			iss >> result;

			tinyStmt = "sys writes "+result;
			tinyCode.push_back(tinyStmt);
		}

		IRList.pop_front();
	}
	
	tinyCode.push_back("sys halt");
	return tinyCode;
}

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf("Error! Usage: Micro <filename>");
	}
	else{
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

		//Backup IRlist from step6, dont delete this commented block
		/*	
		myIRlist.clear();
		ifstream infile("testfile");
		if(!infile){
			cerr << "File not found." << endl;
			return -1;
		}
		string line;
		while (getline(infile, line)){
			myIRlist.push_back(line);
		}
		vector<string>::iterator it1 = myIRlist.begin();
		for (it1; it1 != myIRlist.end(); it1++){
			cout << (*it1) << endl;
		}
		*/

		generateIRList();	
		
		//Michael's code
		map<string,vector<int> > leaders;
		//Vector to store GEN and KILL for each IR node
		vector<set<string> > GEN(myIRlist.size());
		vector<set<string> > KILL(myIRlist.size());
		set<string> globalGEN;
		set<string> tempGEN;
		set<string> tempKILL;
		
		list<string>::iterator it5 = varlist.begin();
		it5++;
		while((*it5).find("Symbol table") == string::npos){
			string id;
			stringstream extract(*it5);
			extract >> id;
			extract >> id;
			globalGEN.insert(id);
			it5++;
		}
		leaders = cfg::findleaders(myIRlist);
		cfglist = cfg::generateCFG(myIRlist, leaders);
		//cfg::printcfg(cfglist);	
		
		int i = 0;
		for(vector<string>::iterator it6 = myIRlist.begin(); it6 != myIRlist.end(); it6++){
			string opcode;
			stringstream irnode(*it6);
			irnode >> opcode;
			if (opcode == "STOREI"){
				int test;
				if((irnode >> test).fail()){
					irnode.str("");
					irnode.clear();
					irnode.str(*it6);
				//	cout << "Variable usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					tempGEN.insert(opcode);
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
				else{
				//	cout << "constant usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
			}
			else if (opcode == "STOREF"){
				float test;
				if((irnode >> test).fail()){
					irnode.str("");
					irnode.clear();
					irnode.str(*it6);
				//	cout << "Variable usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					tempGEN.insert(opcode);
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
				else{
				//	cout << "constant usage" << endl;
					irnode >> opcode;
					irnode >> opcode;
					irnode >> opcode;
					tempKILL.insert(opcode);
					GEN[i] = tempGEN;
					KILL[i] = tempKILL;
					tempGEN.clear();
					tempKILL.clear();
				}
			}
			else if (opcode == "ADDI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "ADDF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();			
			}
			else if (opcode == "SUBI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();	
			}
			else if (opcode == "SUBF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();

			}
			else if (opcode == "MULTI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "MULTF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "DIVI"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				int test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "DIVF"){
				string arg1;
				string arg2;
				string arg3;
				irnode >> arg1;
				irnode >> arg2;
				irnode >> arg3;
				string testvar;
				stringstream teststream(arg1);
				float test;
				if((teststream >> test).fail()){
					tempGEN.insert(arg1);	
				}
				teststream.str(arg2);
				if((teststream >> test).fail()){
					tempGEN.insert(arg2); 
				}
				tempKILL.insert(arg3);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "READI"){
				string arg1;
				irnode >> arg1;
				tempKILL.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "READF"){
				string arg1;
				irnode >> arg1;
				tempKILL.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "WRITES"){
				string arg1;
				irnode >> arg1;
				tempGEN.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "WRITEI"){
				string arg1;
				irnode >> arg1;
				tempGEN.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "WRITEF"){
				string arg1;
				irnode >> arg1;
				tempGEN.insert(arg1);			
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "PUSH"){
				string arg1;
				irnode >> arg1;
				if (arg1 == ""){;}
				else{tempGEN.insert(arg1);}
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else if (opcode == "POP"){
				string arg1;
				irnode >> arg1;
				if (arg1 == ""){;}
				else{tempKILL.insert(arg1);}
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();	
			}
			else if (opcode == "JSR"){
				GEN[i] = globalGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			else{
				GEN[i] = tempGEN;
				KILL[i] = tempKILL;
				tempGEN.clear();
				tempKILL.clear();
			}
			i++;
		}
		
		i=0;
		cout << "BEGIN DISPLAYING GEN FOR EACH IR NODE" << endl;
		vector<set<string> >::iterator it7 = GEN.begin();
		for (it7; it7 != GEN.end(); it7++){
			cout << myIRlist[i] << endl;
			set<string>::iterator it8 = (*it7).begin();
			for (it8; it8 != (*it7).end(); it8++){
				cout << *it8 << endl;
			}
			i++; 
		}
		i=0;
		cout << "BEGIN DISPLAYING KILL FOR EACH IR NODE" << endl;
		vector<set<string> >::iterator it9 = KILL.begin();
		for (it9; it9 != KILL.end(); it9++){
			cout << myIRlist[i] << endl;
			set<string>::iterator it10 = (*it9).begin();
			for (it10; it10 != (*it9).end(); it10++){
				cout << *it10 << endl;
			}
			i++; 
		}	
		//Michael's code end
		
		list<string> tinyCode = generateTinyCode();
		list<string> varlistTemp = varlist;
		list<string> varlistLoad;
		string var;
		string varTemp;
		string strName;
		string strVal;

		while(!varlistTemp.empty()) {
			//NOTE: strings in this list are actual strings not pointers
			//This is example code for iterating through the list
			//cout <<*iterator << endl;
			//i = i + 1;
			istringstream iss(varlistTemp.front());
			var = "";
			iss>>var;
			if(var == "STRING") {
				//var = "";
				iss>>strName;
				varTemp  = "str "+strName;
				//iss>>strVal;
				strVal = varlistTemp.front().erase(0,var.length()+strName.length()+2);
				varTemp = varTemp+" "+strVal;
				varlistLoad.push_front(varTemp);
				varlistTemp.pop_front();
			}
			else {
				var = "";
				iss>>var;
				varTemp = "var "+var;
				varlistLoad.push_front(varTemp);
				varlistTemp.pop_front();
			}
		}

		while(!varlistLoad.empty()) {
			tinyCode.push_front(varlistLoad.front());
			varlistLoad.pop_front();
		}
		cout<<";tiny code"<<endl;
		while (!tinyCode.empty()) {
			cout<<tinyCode.front()<<endl;
			tinyCode.pop_front();
		}
	}//END OF ELSE STATEMENT
	
}

