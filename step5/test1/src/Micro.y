%{
#include <list>
#include <deque>
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
		ast(node *);
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

//Michael's Declarations
ast myast;
deque<ast> astlist;
list<string> varlist;
//exprhead is being used as a temporary place holder for the root expression in nested parentheticals. i.e. (((x)+x)+x)
static node * exprhead = 0;

//Lalit's Declarations
static int registerValue = 1;
string datatype="i";
int regVal = 0;
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
}
;
id: IDENTIFIER  {$<sval>$ = $1;}
;
pgm_body: decl func_declarations    
;
decl: string_decl decl 
| var_decl decl 
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
	string s1($<sval>2);
	istringstream iss(s1);
	string s2;
	while(iss >> s2){
		string s3 = $<sval>1;
		if(s2 != ""){
			varlist.push_back(s3 + " " + s2);			 
		}
	}
}
;
var_type: FLOAT {$<sval>$ = "FLOAT";}
| INT {$<sval>$ = "INT";
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
{
	$<ival>$ = $<ival>1;
}
| for_stmt  
{$<ival>$ = 0;}
;

base_stmt: assign_stmt
{
	$<ival>$ = $<ival>1;
} 
| read_stmt 
{$<ival>$ = $<ival>1;}
| write_stmt 
{$<ival>$ = $<ival>1;}
| return_stmt
{$<ival>$ = 0;}   
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
	node *temp1;
	astlist.push_back(myast);
	//return pointer to statement's place in the list.
	myast = ast();
	//cout << (astlist.size()-1) << endl;
	$<ival>$ = (astlist.size()-1);	
}
;
assign_expr: id ASSMTOP expr  
{
	node *temp1;
	node *temp2;
	temp1 = myast.newval($<sval>1);
	temp2 = myast.newmath(temp1, ":=");
	myast.addright(temp2,myast.root);	
	//cout << "Begin Post Order" << endl;
	//myast.postorder(temp2);
	//cout << "End Post Order" << endl;
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
}
;
else_part: ELSE decl stmt_list 
{	
	ast elseast;
	elseast = ast();
	node *elseptr = elseast.newval("ELSE");
	//cout << "Size of list after ELSE: " << $<ival>3 << endl;
	deque<ast>::iterator it = astlist.begin() + $<ival>3;
	//cout << *((*it).root->value) << endl;
	astlist.insert(it,elseast);

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
init_stmt: assign_expr | empty   
{myast.root = 0;}
;
incr_stmt: assign_expr | empty   
{myast.root = 0;}
;
for_stmt: FOR OPENPAROP init_stmt SCOLONOP cond SCOLONOP incr_stmt CLOSEPAROP decl stmt_list ROF   
{
	
}
;
empty:    
;
%%



ast::ast() {root = 0;}
ast::ast(node *root){this->root = root;}
ast::~ast() {}

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
	
	while(!varlistTemp.empty()) {
		istringstream iss(varlistTemp.front());
		iss >> type;
		iss >> varTemp;

		if(varTemp == var) {
			if(type == "INT") {
				datatype = "i";
			}
			else {
				datatype = "f";
			}
		}
		varlistTemp.pop_front();
	}
}

void generateIRList() {
	ast astNode = ast();
	list<string> temp;
	string op1;
	string op2;
	string result;

	string regStore;
	string IRDisplay;
	ostringstream convert;
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
		
		if(astPostOrder.front()[0] == '=') {
			convert << registerValue;
			regStore = "$T"+convert.str();

			op1 = temp.back();

			if(op1[0]!='$'){
				//check for int/float. set global variable
				checkDatatype(op1);
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
			else {
				IRDisplay = "WRITEF "+op1;
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
		//GT op1 op2 Label
		/*
		else if (op == "GT") {
			iss >> op1;
			iss >> op2;
			iss >> label;

			
		}
		*/
		//GE

		//LT

		//LE

		//NE

		//EQ

		//JUMP

		//LABEL

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
    	
	//Access astlist here like any linked list 
		while (!astlist.empty()){
			ast tempast = astlist.front();
			cout << "New tree marker" << endl;
			myast.postorder(tempast.root);	
			astlist.pop_front();
		}
    	//Access example below
    	//cout << "Front of the list!" << endl;
    	//myast.inorder((astlist.front()).root);
    	//cout << "Back of the list!" << endl;
    	//myast.inorder((astlist.back()).root);
    	/*
    	
    	for (list<string>::const_iterator iterator = varlist.begin(); iterator != varlist.end(); iterator++){
		//NOTE: strings in this list are actual strings not pointers
        	//This is example code for iterating through the list
		cout << i<<" "<<*iterator << endl;
		i = i + 1;
    	}
	*/
	//LALIT UNCOMMENT THIS PART STARTING HERE<<<<<<<<<<<<<<<
	/*	
		generateIRList();
  		list<string> tinyCode = generateTinyCode();

  		list<string> varlistTemp = varlist;
		list<string> varlistLoad;
		string var;
		string varTemp;

		while(!varlistTemp.empty()) {
			//NOTE: strings in this list are actual strings not pointers
			//This is example code for iterating through the list
			//cout <<*iterator << endl;
			//i = i + 1;
			istringstream iss(varlistTemp.front());
			var = "";
			iss>>var;
			var = "";
			iss>>var;
			varTemp = "var "+var;
			varlistLoad.push_front(varTemp);
			varlistTemp.pop_front();
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
	*/
	}	
}
