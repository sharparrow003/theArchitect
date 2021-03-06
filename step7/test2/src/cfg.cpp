#include "cfg.h"
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

cfg::cfg() {fnname = "invalid";}
cfg::cfg(string fnname){this->fnname = fnname;}
cfg::~cfg() {}

void cfg::printcfg(vector<cfg> cfglist){
	for (vector<cfg>::iterator it = cfglist.begin(); it != cfglist.end(); it++){
		cout << "CFG name: " << (*it).fnname << endl;
		vector<statement>::iterator it1 = (*it).statlist.begin();
		for(it1;it1 != (*it).statlist.end(); it1++){
			cout << "IR code: " << (*it1).code << endl;
			set<int>::iterator it2 = (*it1).successors.begin();
			cout << "Successors" << endl;
			for(it2;it2 != (*it1).successors.end(); it2++){cout << *it2 << endl;}
			set<int>::iterator it3 = (*it1).predecessors.begin();
			cout << "Predecessors" << endl;
			for(it3;it3 != (*it1).predecessors.end(); it3++){cout << *it3 << endl;}	
		}
	}	
}

map<string,vector<int> > cfg::findleaders(vector<string> myIRlist){
	map<string,vector<int> > leaders;
	int i = 0;
	for (vector<string>::iterator it2 = myIRlist.begin(); it2 != myIRlist.end(); it2++){
		//cout << (*it2) << endl;
		//capture instruction opcode;
		string opcode;
		stringstream irnode(*it2);
		irnode >> opcode;
		//cout << opcode << endl;
		if (opcode == "LE" || opcode == "GE" || opcode == "NE" || opcode == "EQ"){
			string label(irnode.str());
			size_t pos = label.find("label");
			label = label.substr(pos);
			vector<int> temp(2);
			temp[0] = i;
			leaders.insert(pair<string,vector<int> >(label,temp));
		}
		
		else if (opcode == "JUMP"){
			string label(irnode.str());
			size_t pos = label.find("label");
			label = label.substr(pos);
			if (leaders.count(label) == 1){
				leaders[label][0] = i;
			}
			else{
				vector<int> temp(2);
				temp[0] = i;
				leaders.insert(pair<string,vector<int> >(label,temp));
			}
		}
		else if (opcode == "LABEL"){
			string label(irnode.str());
			//cout << "Entered Label" << endl;
			if(i+1 != myIRlist.size()){
				if (myIRlist[i+1] != "LINK"){
				//	cout << "Wasnt a function" << endl;
					size_t pos = label.find("label");
					label = label.substr(pos);
					if (leaders.count(label) == 1){
						leaders[label][1] = i;
					}
					else{
						vector<int> temp(2);
						temp[1] = i;
						leaders.insert(pair<string,vector<int> >(label,temp));
					}
				}
			//	cout << myIRlist[i+1] << endl;
			}
			else{
				size_t pos = label.find("label");
				label = label.substr(pos);
				if (leaders.count(label) == 1){
					leaders[label][1] = i;
				}
				else{
					vector<int> temp(2);
					temp[1] = i;
					leaders.insert(pair<string,vector<int> >(label,temp));
				}		
			}
		}
		i++;
	}	

	return leaders;
}

vector<cfg> cfg::generateCFG(vector<string> myIRlist, map<string,vector<int> > leaders){
	vector<cfg> cfglist;
	vector<string>::iterator it3 = myIRlist.begin();
	cfg tempcfg(*it3);
	it3++;
	int i = 1;
	set<int> tempsucc;
	set<int> temppred;
	for (it3; it3 != myIRlist.end(); it3++){
		string opcode;
		stringstream irnode(*it3);
		irnode >> opcode;
		//	cout << (*it3) << endl;
		if (opcode == "LABEL"){
			if(i+1 != myIRlist.size()){			
				if (myIRlist[i+1] == "LINK"){
					//string functiontest;
					//functiontest = myIRlist[i+1];
					//cout << functiontest << endl;			
					tempsucc.clear();
					temppred.clear();
					statement tempstat = tempcfg.statlist.back();
					tempstat.successors.erase(i);
					tempcfg.statlist[(tempcfg.statlist.size())-1] = tempstat;
					cfglist.push_back(tempcfg);
					tempcfg = cfg(*it3);
				}
				else{			
					tempsucc.clear();
					temppred.clear();
					string label;
					statement tempstat(*it3);
					if(!(tempcfg.statlist.empty())){	
						tempsucc.insert(i+1);
						temppred.insert(i-1);
						if(myIRlist[i-1].find("JUMP") != string::npos){temppred.erase(i-1);}
						irnode >> label;
						temppred.insert(leaders[label][0]);	
					}
					else{
						tempsucc.insert(i+1);	
						temppred.insert(i-1);
						irnode >> label;
						temppred.insert(leaders[label][0]);
					}
					tempstat.successors = tempsucc;
					tempstat.predecessors = temppred;
					tempcfg.statlist.push_back(tempstat);
				}
			}
			//string functiontest;
			//functiontest = myIRlist[i+1];
			//cout << functiontest << endl;			
			/*
			tempsucc.clear();
			temppred.clear();
			statement tempstat = tempcfg.statlist.back();
			tempstat.successors.erase(i);
			tempcfg.statlist[(tempcfg.statlist.size())-1] = tempstat;
			cfglist.push_back(tempcfg);
			tempcfg = cfg(*it3);
			///
			*/
			else{
				tempsucc.clear();
				temppred.clear();
				string label;
				statement tempstat(*it3);
				if(!(tempcfg.statlist.empty())){	
					//tempsucc.insert(i+1);
					temppred.insert(i-1);
					if(myIRlist[i-1].find("JUMP") != string::npos){temppred.erase(i-1);}
					irnode >> label;
					temppred.insert(leaders[label][0]);	
				}
				else{
					//tempsucc.insert(i+1);	
					temppred.insert(i-1);
					irnode >> label;
					temppred.insert(leaders[label][0]);
				}
				tempstat.successors = tempsucc;
				tempstat.predecessors = temppred;
				tempcfg.statlist.push_back(tempstat);
			}
		}
		
		else if ((opcode.find("STORE") != string::npos) || (opcode.find("READ") != string::npos) || (opcode.find("WRITE") != string::npos)){
			tempsucc.clear();
			temppred.clear();
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){
				tempsucc.insert(i+1);
				temppred.insert(i-1);	
			}
			else{
				tempsucc.insert(i+1);	
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);			
		}	
		
		else if ((opcode.find("ADD") != string::npos) || (opcode.find("SUB") != string::npos) || (opcode.find("JSR") != string::npos)){
			tempsucc.clear();
			temppred.clear();
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){
				tempsucc.insert(i+1);
				temppred.insert(i-1);	
			}
			else{
				tempsucc.insert(i+1);	
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);
		}
		
		else if ((opcode.find("MULT") != string::npos) || (opcode.find("DIV") != string::npos)){
			tempsucc.clear();
			temppred.clear();
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){
				tempsucc.insert(i+1);
				temppred.insert(i-1);	
			}
			else{
				tempsucc.insert(i+1);	
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);
		}
		
		else if (opcode == "JUMP"){
			tempsucc.clear();
			temppred.clear();
			string label;
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){
				irnode >> label;
				tempsucc.insert(leaders[label][1]);
				temppred.insert(i-1);	
			}
			else{
				tempsucc.insert(leaders[label][1]);	
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);
	        }	
		else if (opcode == "LE" || opcode == "GE" || opcode == "EQ" || opcode == "NE"){
			tempsucc.clear();
			temppred.clear();
			string label;
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){
				irnode >> label;
				irnode >> label;
				irnode >> label;
				irnode >> label;
				tempsucc.insert(leaders[label][1]);
				tempsucc.insert(i+1);
				temppred.insert(i-1);
				//cout << label << endl;	
			}
			else{
				tempsucc.insert(leaders[label][1]);
				tempsucc.insert(i+1);	
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);
	        }
		else if (opcode == "LABEL"){
			tempsucc.clear();
			temppred.clear();
			string label;
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){	
				tempsucc.insert(i+1);
				temppred.insert(i-1);
				if(myIRlist[i-1].find("JUMP") != string::npos){temppred.erase(i-1);}
				irnode >> label;
				temppred.insert(leaders[label][0]);	
			}
			else{
				tempsucc.insert(i+1);	
				temppred.insert(i-1);
				irnode >> label;
				temppred.insert(leaders[label][0]);
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);
		}	
		else if (opcode == "RET"){
			tempsucc.clear();
			temppred.clear();
			statement tempstat(*it3);
			if(!(tempcfg.statlist.empty())){
				tempsucc.insert(i+1);
				temppred.insert(i-1);	
			}
			else{
				tempsucc.insert(i+1);	
			}
			tempstat.successors = tempsucc;
			tempstat.predecessors = temppred;
			tempcfg.statlist.push_back(tempstat);
		}	
		i++;				
	}
	if(!(tempcfg.statlist.empty())){
		statement tempstat = tempcfg.statlist.back();
		tempstat.successors.erase(i);
		tempcfg.statlist[(tempcfg.statlist.size())-1] = tempstat;
		cfglist.push_back(tempcfg);
	}
	return cfglist;
}
/*
void cfg::cfgprint(vector<cfg> cfglist){
	
}
*/
