#ifndef NODE_H
#define NODE_H
#include <vector>
//node.h
class Node
{
	Node* parent;
	public:
		Node* getParent();
		Node();
		~Node();
};

class RootNode : public Node
{
	public:
	std::vector<Node*> segments;
};

class ImportNode : public Node 
{
	public:
	using Node::Node;
	std::string file;
	bool islocal;	
};
class IncludeNode : public Node
{
	public:
	using Node::Node;
	std::string file;
	bool islocal;
};

class ReturnNode : public Node
{
	public:
	using Node::Node;
	Node* expression;
};

class AddNode : public Node
{
	public:
	using Node::Node;
	Node* left;
	Node* right;
	
};
class SubtractNode : public Node
{
	public:
	using Node::Node;
	Node* left;
	Node* right;
};

class IfNode : public Node
{
	public:
	using Node::Node;
	Node* eval;
	std::vector<Node*> body;
};
#endif
