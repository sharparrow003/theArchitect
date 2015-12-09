#ifndef STAT_H
#define STAT_H
#include <list>
#include <string>
#include <set>

class statement {
	public:
		statement();
		statement(std::string);
		std::string code;
		std::set<int> successors;
		std::set<int> predecessors;
};

#endif
