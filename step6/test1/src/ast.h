#ifndef AST_H
#define AST_H
#include <string>

struct node;

class ast {
	public:
		ast();
		ast(node *);
		~ast();
		node *root;
		
		node *newval(std::string);
		node *newop(node *, std::string);
		node *newmath(node *, std::string);	
		void destroy_tree();
		void addright(node *, node *);
		void inorder(node *);
		void preorder(node *);
		void postorder(node *);
	private:
		void destroy_tree(node *);
};

#endif
