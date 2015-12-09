#ifndef CFG_H
#define CFG_H
#include <string>
#include <map>
#include <vector>
#include "stat.h"

class cfg {
	public:
		cfg();
		cfg(std::string);
		~cfg();
		std::string fnname;
		std::vector<statement> statlist;
		static void printcfg(std::vector<cfg>);
		static std::map<std::string,std::vector<int> > findleaders(std::vector<std::string>);
		static std::vector<cfg>	generateCFG(std::vector<std::string>, std::map<std::string,std::vector<int> >);
		//void addstat(statement);
};

#endif

