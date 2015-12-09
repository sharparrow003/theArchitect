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
#include <algorithm>
using namespace std;



int main() {
	set <string> A;	
	set <string> B;
	set <string> C;

	A.insert("a");
	A.insert("b");
	A.insert("c");
	A.insert("a");

	B.insert("d");
	B.insert("e");
	B.insert("f");

	set_difference(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
	set_union(A.begin(),A.end(),B.begin(),B.end(),inserter(C,C.end()));
	
	cout<<"SETA-->"<<endl;
	for (set < string >::iterator it1=A.begin(); it1!=A.end(); ++it1) {
		cout<<*it1<<endl;
	}
	
	cout<<endl<<"SETB-->"<<endl;
	for (set < string >::iterator it2=B.begin(); it2!=B.end(); ++it2) {
		cout<<*it2<<endl;
	}

	cout<<endl<<"SETC-->"<<endl;
	for (set < string >::iterator it3=C.begin(); it3!=C.end(); ++it3) {
		cout<<*it3<<endl;
	}

	return 0;
}
