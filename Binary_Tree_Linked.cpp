#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class BTree{
	struct BTNode{
		int val;
		BTNode *left, *right;
		BTNode(int val, BTNode *left = NULL, BTNode *right = NULL){
			this->val = val;
			this->left = left;
			this->right = right;
		}
	};
	BTNode *root;
public:
	BTArray(){		root = NULL;	}
	BTNode* insert(int value, BTNode *temp){	
		if (!temp)	return new BTNode(value);
		int randomN = rand() % 2;
		if (randomN == 0) 		temp->left = insert(value, temp->left);
		else 					temp->right = insert(value, temp->right);
		return temp;
	}
	void insert(int value){		root = insert(value, root);	}
	void generateTree(BTNode *temp, int tabs = 0){
		if (!temp)	return;
		generateTree(temp->right, tabs + 1);
		for (int i = 0 ; i < tabs ; i++)	cout << '\t';
		cout << temp->val << '\n';
		generateTree(temp->left, tabs + 1);
	}
	void generateTree(){		generateTree(root);	}
	void inorder(BTNode *temp){
		if (!temp)	return;
		inorder(temp->left);
		cout << temp -> val << ' ';
		inorder(temp->right);
	}
	void inorder(){	inorder(root);	}
	void preorder(BTNode *temp){
		if (!temp)	return;
		cout << temp -> val << ' ';
		preorder(temp->left);
		preorder(temp->right);
	}
	void preorder(){	preorder(root);	}
	int countNodes(BTNode *temp){
		if (!temp)		return 0;
		int countLeft = countNodes(temp->left);
		int countRight = countNodes(temp->right);
		return countLeft + countRight + 1;
	}
	int countNodes(){	return countNodes(root);	}	
	int height(BTNode *temp){
		if (!temp)	return 0;
		return max(height(temp->left), height(temp->right)) + 1;
	}
	int height(){	return height(root);	}
	void free(BTNode *temp){
		if (!temp){
			free(temp->left);
			free(temp->right);
			delete temp;
		}
	}
	~BTree(){
		free(root);
	}
};

int main(){
	srand(time(0));
	BTree tree;
	for (int i=0;i<15;i++)
		tree.insert(rand()%900+100);
	tree.generateTree();
	cout << "Pre Order:\t";
	tree.preorder();
	cout << '\n';
	cout << "In Order:\t";
	tree.inorder();
	cout << '\n';
	cout << "Total Nodes:" << tree.countNodes() << '\n';
	cout << "Total Height:" << tree.height() << '\n';
	return 0;
}
