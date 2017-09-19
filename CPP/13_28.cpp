#include<string>
using namespace std;

class TreeNode {
public:
	TreeNode(const string &s=string(),const int &i=int())
		:value(s),count(i),left(nullptr),right(nullptr),use(new size_t(1)){ }
	TreeNode(const TreeNode &node)
		:value(node.value),count(node.count),left(node.left),right(node.right),use(node.use)
	{
		++*use;
	}
	~TreeNode()
	{
		if (--*use == 0)
		{
			delete left;
			delete right;
			delete use;
		}
	}
	TreeNode& operator=(const TreeNode &rhs)
	{
		++*rhs.use;
		if (--*use == 0)
		{
			delete left;
			delete right;
			delete use;
		}
		value = rhs.value;
		count = rhs.count;
		left=rhs.left; 
		right=rhs.right; 
		use = rhs.use;
		return *this;
	}

private:
	string value;
	int count;
	TreeNode *left;
	TreeNode *right;
	size_t *use;
};

class BinStrTree {
public:
	BinStrTree(const TreeNode &tree = TreeNode()) :root(new TreeNode(tree)) {}
	BinStrTree(const BinStrTree &tree)
	{
		root = new TreeNode(*tree.root);
	}
	~BinStrTree()
	{
		delete root;
	}
	BinStrTree& operator=(const BinStrTree &rtree)
	{
		auto temp = new TreeNode(*rtree.root);
		delete root;
		root = temp;
		return *this;
	}

private:
	TreeNode *root;
};

int main() {
	BinStrTree bst, bst2;
	bst2 = bst;
	BinStrTree bst3 = bst;
	system("pause");
	return 0;
}