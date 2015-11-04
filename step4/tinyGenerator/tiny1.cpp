#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <list>
#include <stdio.h>
#include <fstream>

using namespace std;

list<string> generateIRList();					//Function to generate list of IR Nodes ***NOT IMPORTANT***
void printList(list<string> strList);				//Prints out list ***NOT IMPORTANT***
list<string> generateTinyCode(list<string> IRList);		//Generates tiny code from the list of IR Nodes  ***IMPORTANT***
int getRegister(string IRReg);					//Calculates the register number from IR Node ***IMPORTANT***

int regVal = 0;

list<string> generateIRList(){
	list <string> IRList;

	string line;
	ifstream myfile ("tinyOutput.txt");
	if (myfile.is_open())
	{
	  while ( getline (myfile,line) )
	  {
		IRList.push_back(line);
	  }
	  myfile.close();
	}
		
	return IRList;
}

void printList(list<string> strList){
	while(!strList.empty()){
		string display = strList.front(); 
		cout<<display<<endl;
		strList.pop_front();
	}
}

int getRegister(string IRReg){
	int strLen = IRReg.length();
	string IRRegVal =  IRReg.substr(2, strLen-2);
	int regReturn = atoi(IRRegVal.c_str()) - 1;
	
	return regReturn;
}
	

list<string> generateTinyCode(list<string> IRList) {
	list<string> tinyCode;

	tinyCode.push_back("var a");
	tinyCode.push_back("var b");
	tinyCode.push_back("var c");	

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

int main(){
	list<string> IRList = generateIRList();
	list<string> tinyCode = generateTinyCode(IRList);
	
	printList(tinyCode);

	
	return 0;	
}
