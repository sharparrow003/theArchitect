void symprogram (list<stack<vector<string> *> *> empire){
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
