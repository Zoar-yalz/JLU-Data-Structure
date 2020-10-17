#include<iostream>
#include<string>
using namespace std;
#define scanf_s scanf
class BinaryTree
{
public:
	class Node//嵌套节点类
	{
	public:
		Node();
		Node(int v);//含参构造
		int value;
		Node* left;
		Node* right;
	};
	void inputTree(BinaryTree::Node** node);//根据带空节点的先序遍历构造树
	BinaryTree();
	BinaryTree(int v);
	~BinaryTree();//析构函数
	void del(Node* node);//删除以某节点为根的所有子树
	void del(int value);//删除值为v的结点及其所有子树
	Node* root;
private:
	void NodeSearch(BinaryTree::Node* node, int v, int* ans);
	void Search_del(BinaryTree::Node* node);
	int cmp_value;
	Node* cmp_result;
};
void InorderTraversal(BinaryTree::Node* root);
BinaryTree::Node::Node()
{
	value = 0;
	left = nullptr;
	right = nullptr;
}
BinaryTree::Node::Node(int v)
{
	value = v;
	left = nullptr;
	right = nullptr;
}
void BinaryTree::NodeSearch(BinaryTree::Node* node, int v, int* ans)
{
	if (node == nullptr || *ans != 0)
	{
		return;
	}
	if ((node->left != nullptr && node->left->value == v) || (node->right != nullptr && node->right->value == v))
	{
		*ans = node->value;
		return;
	}
	NodeSearch(node->left, v, ans);
	NodeSearch(node->right, v, ans);
}
BinaryTree::BinaryTree()
{
	root = nullptr;
	cmp_result = nullptr;
	cmp_value = 0;
}
BinaryTree::BinaryTree(int v)
{
	Node* p = new Node(v);
	root = p;
	cmp_result = nullptr;
	cmp_value = 0;
}

BinaryTree::~BinaryTree()
{
	del(root);
}

void BinaryTree::del(Node* node)
{
	if (node == nullptr) return;
	del(node->left);
	del(node->right);
	delete node;
}
void BinaryTree::del(int value)
{
	cmp_result = nullptr;
	cmp_value = value;
	Search_del(root);
	if (cmp_result == nullptr)
	{
		cout << 0 <<"\n";
	}
	else
	{
		InorderTraversal(root);
		cout << "\n";
	}
}
void BinaryTree::Search_del(BinaryTree::Node* node)
{

	if (node == nullptr || cmp_result != nullptr )
	{
		return;
	}
	if (node->left != nullptr && node->left->value == cmp_value)
	{
		cmp_result = node;
		del(node->left);
		node->left = nullptr;
		return;
	}
	else if (node->right != nullptr && node->right->value == cmp_value)
	{
		cmp_result = node;
		del(node->right);
		node->right = nullptr;
		return;
	}
	Search_del(node->left);
	Search_del(node->right);
}
int main()
{
	BinaryTree* tree = new BinaryTree();
	tree->inputTree(&(tree->root));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		tree->del(temp);
	}
}
void InorderTraversal(BinaryTree::Node* root)
{
	if (root != nullptr)
	{
		InorderTraversal(root->left);
		printf("%d ", root->value);
		InorderTraversal(root->right);
	}
}
void BinaryTree::inputTree(BinaryTree::Node** node)
{
	int temp;
	scanf_s("%d", &temp);
	if (temp == 0)
	{
		*node = nullptr;//空指针的构造
		return;
	}
	else
	{
		*node = new Node(temp);//非空指针
	}
	inputTree(&((*node)->left));//先根构造
	inputTree(&((*node)->right));
}
