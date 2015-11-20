%{
#include <list>
#include <stack>
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;
//push list on to stack after every DECL, whenever you see a rule, push to other stack
//This way first rules seen are put at the bottom and the last rule seen will be on top
//Stack will be strings, so every time you see func or conditional rule, push the string i.e. SYMBOL TABLE
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;

void yyerror(const char *s) { cerr << "Not Accepted" << endl; exit(0); }
static int val = 0;
static int scope = 0;
static list<stack<vector<string> *> *> empire;
static stack<vector<string> *> currkingdom;
static vector<string> currfief;
%}

%union {
	int ival;
	float fval;
	char *sval;
	char *iden;
	void *fief;
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
{
	while(!empire.empty()){
		stack<vector<string> *> *kingdomptr = empire.front();
		empire.pop_front();
		while(!(*kingdomptr).empty()){
			//cout << "Pre Acknowledge Level 2" << endl;
			vector<string> *fiefptr = (*kingdomptr).top();
			(*kingdomptr).pop();
			//cout << "Fief Pointer: " << fiefptr << endl;
			//cout << "Acknowledge Level 2" << endl;
			if(!(*fiefptr).empty()){	
				//cout << "Above Fief Pointer is not empty" << endl;
				
				for (vector<string>::iterator it = (*fiefptr).begin(); it != (*fiefptr).end(); it++){
					//cout << "Pre Acknowledge Level 3" << endl;
					if (*it == "Symbol table IF" || *it == "Symbol table FOR" || *it == "Symbol table ELSE"){
						val = val + 1;
						cout << endl << "Symbol table BLOCK " << val << endl;
					}
					else{cout<<*it<<endl;}
					//cout << "Acknowledge Level 3" << endl;
				}
				(*fiefptr).clear();
			}
			delete fiefptr;
		}
		delete kingdomptr;
	}
}
;
id:       IDENTIFIER  {
	$<sval>$ = $1;
}
;
pgm_body: decl func_declarations    
;
decl:     string_decl decl
{
	if (scope == 0){
		if(!currfief.empty()){
			vector<string> *newfief = new vector<string>;
			*newfief = currfief;
			currkingdom.push(newfief);
			
			//cout << "First element: " << currfief.front() << endl;			
			//for (vector<string>::iterator it = currfief.begin(); it != currfief.end(); it++){
			//	cout << scope << endl;
			//	cout << *it << endl;
			//} 
			
			currfief.clear();
			stack<vector<string> *> *newkingdom = new stack<vector<string> *>;
			*newkingdom = currkingdom;
			empire.push_back(newkingdom);
			currkingdom.pop();
		}
		$<fief>$ = 0;
		scope = 1;
	}
	else{
		if(!currfief.empty()){
			vector<string> *newfief = new vector<string>;
			*newfief = currfief;	
			$<fief>$ = newfief;
			currfief.clear();
		}
	}			    
}   
| var_decl decl 
{ 	
	if (scope == 0){
		if(!currfief.empty()){
			/*
			while(currfief.size() > 9){
				vector<string> *newfief = new list<string>;
				while((*newfief).size() < 10 && !currfief.empty()){
					(*newfief).push_back(currfief.front());
					currfief.pop_front();
				}
				currkingdom.push(newfief);
				newfief = 0;
			}
			*/
			vector<string> *newfief = new vector<string>;
			*newfief = currfief;
			currkingdom.push(newfief);
			
			//cout << "First element: " << currfief.front() << endl;			
			//for (vector<string>::iterator it = currfief.begin(); it != currfief.end(); it++){
			//	cout << scope << endl;
			//	cout << *it << endl;
			//} 
			
			currfief.clear();
			stack<vector<string> *> *newkingdom = new stack<vector<string> *>;
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
			vector<string> *newfief = new vector<string>;
			*newfief = currfief;	
			$<fief>$ = newfief;
			currfief.clear();
		}
	}						    
}
| empty {
	if (currfief.empty() && scope == 0){scope = 1;}
	$<fief>$ = 0;	
}	 
;

string_decl: STRING id ASSMTOP str SCOLONOP {
	string s1($<sval>2);
	string s2($<sval>4);
	string s3("name " + s1 + " type STRING value " + s2);
	currfief.push_back(s3); 
}
;
str: STRLIT  {$<sval>$ = $1; }
;

var_decl: var_type id_list SCOLONOP {	
	string s1($<sval>2);
	stringstream ss(s1);
	string s2($<sval>1);
	string s3;
	string s4;
	while(ss >> s3){
		s4 = "name " + s3 + " type " + s2;
		if (s3 != ""){
			//cout << s3 << endl;
			currfief.push_back(s4);
		}
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
id_list: id id_tail {
	if($<sval>2 != 0){
		string s1;
		string s2($<sval>2);
		stringstream ss;
		ss << $<sval>1 << " " << $<sval>2;
		s1 = ss.str();
		//cout << s1 << endl;
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
		//free($<sval>2);
		//cout << s1 << endl;
		const char *temp = s1.c_str();
		$<sval>$ = (char*)temp;
	}
	else{
		ss << $<sval>2 << " " << $<sval>3;
		s1 = ss.str();
		//cout << s1 << endl;
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
	vector<string> *fiefptr = new vector<string>;
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
	string s3("name " + s2 + " type " + s1);
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
	
	ostringstream oss;
	oss << endl << "Symbol table " << $<sval>3;	
	vector<string> *fnname = new vector<string>;
	(*fnname).push_back(oss.str());
	
	//dynamically allocate new stack to copy current scope (kingdom) into;
	stack<vector<string> *> *newkingdom = new stack<vector<string> *>;
	if (!currkingdom.empty()){
		*newkingdom = currkingdom;
	}
	//push param declarations and function name
	if ($<fief>5 != 0){	
		(*newkingdom).push((vector<string>*)$<fief>5);
	}
	(*newkingdom).push(fnname);
	
	//After pushing function name, add the function stack to list of functions
	empire.push_back(newkingdom);
	while(!currkingdom.empty()){
		//vector<string> *temp = currkingdom.top();
		currkingdom.pop();
		//
		//if(!(*temp).empty()){	
		//	for (vector<string>::iterator it = (*temp).begin(); it != (*temp).end(); it++){
		//		cout<<*it<<endl;
		//	}
		//}
	}	
}
;
func_body: decl stmt_list {
	if($<fief>1 != 0){	
		if(!(*((vector<string>*)$<fief>1)).empty()){
			currkingdom.push((vector<string>*)$<fief>1);
		}
	}
}
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
	if($<fief>5 != 0){	
		string s1("Symbol table IF");
		//fief has to be void in order to be transferrable in C union
		vector<string> *vectorptr = (vector<string>*)$<fief>5;	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table IF");
		vector<string> *newfief = new vector<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}	
}
;
else_part: ELSE decl stmt_list 
/*{
val = val + 1;
sprintf($<sval>$, "%s %s", "\nSymbol table BLOCK ", val);
}*/
{
	if($<fief>2 != 0){	
		string s1("Symbol table ELSE");
		//fief has to be void in order to be transferrable in C union
		vector<string> *vectorptr = (vector<string>*)$<fief>2;	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table ELSE");
		vector<string> *newfief = new vector<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
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
	if($<fief>9 != 0){		
		string s1("Symbol table FOR");	
		//fief has to be void in order to be transferrable in C union
		vector<string> *vectorptr = (vector<string>*)$<fief>9;	
		(*vectorptr).insert((*vectorptr).begin(),s1);
		if(!(*vectorptr).empty()){
			currkingdom.push(vectorptr);
		}
	}
	else{
		string s1("Symbol table FOR");
		vector<string> *newfief = new vector<string>;
		(*newfief).push_back(s1);
		currkingdom.push(newfief);
	}
}
;

empty:    
;

%%


/*
class Fntable {
	public:
		list parameters;	
		list variables;
		vector<vector<string>> innervars;
		Fntable();
		Fntable(list,list,vector<vector<string>>);
}
Fntable::Fntable(){
	parameters;
	vars;	
}

Fntable::Fntable(list params, list vars, vector<vector<string>> newvars){
	parameters = params;
	variables = vars;
	innervars = newvars; 
}

~Fntable::Fntable(){
	while(parameters.size()){
		String * temp = parameters.front();
		parameters.pop_front();
		if(temp){
			delete(temp);
		}
	}
	while(variables.size()){
		String * temp = variables.front();
		variables.pop_front();
		if(temp){
			delete(temp);
		}
	}
	vector<vector<string>>().swap(innervars);
}
*/



int main(int argc, char *argv[]) {
  if (argc != 2)
  {
    cout<<"Error! Usage: Micro <filename>"<< endl;
  }
  else
  {
    FILE *myfile = fopen(argv[1], "r");
    if (!myfile) {
      cout << "File could not be opened" << endl;
      return -1;
    }
    yyin = myfile;
    cout << "Symbol table GLOBAL" << endl;
    do {
      yyparse();
    } while (!feof(yyin));
  }
}


