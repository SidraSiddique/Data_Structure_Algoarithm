#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int max(const int a, const int b){
	if (a < b)	return b;
	return a;
}
class AVLTree{
	struct AVLNode{
		int val, height;
		AVLNode *left, *right;
		AVLNode(int val, AVLNode *left=NULL, AVLNode *right=NULL){
			this->val = val;
			this->left = left;
			this->right = right;
			this->height = 1;
		}
	};
	AVLNode *root;
public:
	AVLTree(){	root = NULL;	}
	AVLNode* leftRotation(AVLNode* temp){
		AVLNode* temp_right = temp->right;
		temp->right	= temp_right->left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp_right->left = temp;
		temp = temp_right;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;
	}
	AVLNode* rightRotation(AVLNode* temp){
		AVLNode* temp_left = temp->left;
		temp->left	= temp_left->right;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		temp_left->right = temp;
		temp = temp_left;
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;
	}
	int getHeight(AVLNode* t) const{
		if (!t)	return 0;
		return t->height;
	}
	int getHeight() const{
		if (!root)	return 0;
		int lh = getHeight(root->left);
		int rh = getHeight(root->right);
		return max(lh, rh) + 1;
	}
	AVLNode* doRightRotation(AVLNode* temp){
		int balance = getHeight(temp->left->left) - getHeight(temp->left->right);
		if (balance < 0) 	temp->left = leftRotation(temp->left);
		temp = rightRotation(temp);
		return temp;
	}
	AVLNode* doLeftRotation(AVLNode* temp){
		int balance = getHeight(temp->right->left) - getHeight(temp->right->right);
		if (balance > 0) 	temp->right = rightRotation(temp->right);
		temp = leftRotation(temp);
		return temp;
	}
	AVLNode* doRotation(AVLNode* temp){
		int balance = getHeight(temp->left) - getHeight(temp->right);
		if (balance > 1)			temp = doRightRotation(temp);
		else if (balance < -1)		temp = doLeftRotation(temp);
		return temp;		
	}
	AVLNode* insert(int d, AVLNode *temp){	
		if (temp==NULL)	return new AVLNode(d);
		if (temp->val>d) 			temp->left = insert(d, temp->left);
		else if (temp->val<d) 		temp->right = insert(d, temp->right);
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	void insert(int d){	
		root = insert(d, root);
	}
	AVLNode* findLeftMost(AVLNode *t){
		if (t->left == NULL)	return t;
		return findLeftMost(t->left);
	}
	AVLNode* remove(int d, AVLNode *temp, bool& isDeleted ){	
		if (temp == NULL)			return NULL;
		if (temp->val > d) 			temp->left = remove(d, temp->left, isDeleted);
		else if (temp->val < d) 	temp->right = remove(d, temp->right, isDeleted);
		else{	//this is the node to be deleted
			if (!temp->left && !temp->right){
				delete temp;	//delete leaf node and return null
				isDeleted = true;
				return NULL;
			}
			else if (temp->left == NULL && temp->right != NULL){
				AVLNode *tempR = temp->right;	//Before deletion save right child
				delete temp;					//delete current node
				isDeleted = true;
				return tempR;				//return right child to connect with grand parent
			}
			else if (temp->right == NULL){
				AVLNode *tempL = temp->left;		//Before deletion save left child
				delete temp;					//delete current node
				isDeleted = true;
				return tempL;				//return left child to connect with grand parent
			}
			else{	//node has both left and right child nodes
				AVLNode *toBeReplaced = 	findLeftMost(temp->right);//you can either find left most in right sub tree or right most in left sub tree
				temp->val = toBeReplaced->val;
				temp->right = remove(temp->val, temp->right, isDeleted);//delete the left most node having same val but single or zero child node being left most
			}		
		}
		temp = doRotation(temp);
		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
		return temp;	
	}
	bool remove(int d){	
		bool isDeleted = false;
		root = remove(d, root, isDeleted);
		return isDeleted;
	}
	void inorder(AVLNode* t){
		if (t!=NULL){
			inorder(t->left);
			cout << t->val << ' ';
			inorder(t->right);
		}
	}
	void inorder(){
		inorder(root);
		cout << '\n';
	}
	void preorder(AVLNode* t){
		if (t!=NULL){
			cout << t->val << ' ';
			preorder(t->left);
			preorder(t->right);
		}
	}
	void preorder(){
		preorder(root);
		cout << '\n';
	}
	void removeNodes(AVLNode* t){
		if (t!=NULL){
			removeNodes(t->left);
			removeNodes(t->right);
			delete t;
		}
	}
	~AVLTree(){
		removeNodes(root);
	}
	void generateTree(AVLNode *temp, int tabs){
		if (!temp)	return;
		generateTree(temp->right, tabs + 1);
		for (int i = 0 ; i < tabs ; i++)	cout << '\t';
		cout << temp->val << '\n';
		generateTree(temp->left, tabs + 1);
	}
	void generateTree(){
		generateTree(root, 0);
	}		
};

int main(){
	srand(time(0));
	AVLTree tree;
	int val;
	for (int i=0;i<30;i++){
		val = rand()%90+10;
		tree.insert(val);
	}
	tree.generateTree();
	cout << "Height: " << tree.getHeight() << '\n';
	cout << "\nPre Order:\t";
	tree.preorder();
	cout << "In Order:\t";
	tree.inorder();
	for (int i=0;i<60;i++){	//As we are generating data randomly, there is a chance that we come with an existing node, so run loop 60 times
		val = rand()%90+10;		
		if (tree.remove(val)){
			cout << val << " is deleted\n";
			tree.generateTree();
		}		
	}
	cout << "Height: " << tree.getHeight() << '\n';
	cout << "\nPre Order:\t";
	tree.preorder();
	cout << "In Order:\t";
	tree.inorder();
	return 0;
}

