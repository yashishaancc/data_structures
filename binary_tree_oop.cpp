#include<iostream>
#include<string>
using namespace std;
typedef struct node{
	int val;
	int l, r;
	struct node* parent;
	struct node* left;
	struct node* right;
}Node;
Node* getNewNode(int in){
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = in;
	node->l = 0;
	node->r = 0;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}
class BST{
	Node* root;
private:
	void decrement(Node* node){
		Node* tmp=node;
		while(tmp->parent != NULL){
			if(tmp->parent->left == tmp){
				tmp->parent->l--;
			}
			if(tmp->parent->right == tmp){
				tmp->parent->r--;
			}
			tmp = tmp->parent;
		}
	}
public:
	BST(){
		root = NULL;
	}
	Node* _insert(Node* root, int in){
		if(root == NULL){
			Node* node = getNewNode(in);
			root = node;
			return root;
		}
		if(in == root->val){
			decrement(root);
			return root;
		}
		if(in <= root->val){
			root->left = _insert(root->left, in);
			root->left->parent = root;
			root->l += 1;
		}
		else if(in >= root->val){
			root->right = _insert(root->right, in);
			root->right->parent = root;
			root->r += 1;
		}
		return root;
	}
	void insert(int in){
		root = _insert(root, in);
	}
	Node* _findval(Node* root, int x){
		if(root == NULL) return NULL;
		if(root->val == x) return root;
		if(x <= root->val) return _findval(root->left, x);
		if(x >= root->val) return _findval(root->right, x);
		return NULL;
	}
	bool findval(int x){
		Node* node = _findval(root, x);
		if(node == NULL)return false;
		else return true;
	}
	Node* _Delete(Node* root, int x){
		cout << "In Delete: " << root->val << endl;
		Node* Root = root;
		if(root == NULL)return root;
		if(root->val == x){
			// no child case
			if(root->left == NULL && root->right == NULL){
				decrement(root);
				if(root->parent == NULL){
					free(root);
					return NULL;
				}
				if(root->parent->left == root){
					root->parent->left = NULL;
					free(root);
					return Root;
				}
				if(root->parent->right == root){
					root->parent->right = NULL;
					free(root);
					return Root;
				}
			}
			//one child case
			if(root->right == NULL){
				decrement(root);
				if(root->parent == NULL){
					Root = root->left;
					root->left->parent = NULL;
					free(root);
					return Root;
				}
				if(root->parent->left != NULL && root->parent->left == root)
					root->parent->left = root->left;
				if(root->parent->right != NULL && root->parent->right == root)
					root->parent->right = root->left;
				root->left->parent = root->parent;
				free(root);
				return Root;
			}
			if(root->left == NULL){
				decrement(root);
				if(root->parent == NULL){
					Root = root->right;
					root->right->parent = NULL;
					free(root);
					return Root;
				}
				if(root->parent->left != NULL && root->parent->left == root)
					root->parent->left = root->right;
				if(root->parent->right != NULL && root->parent->right == root)
					root->parent->right = root->right;
				root->right->parent = root->parent;
				free(root);
				return Root;
			}
			//two child case
			Node* right = root->right;
			while(right->left!=NULL){
				right=right->left;
			}
			root->val = right->val;
			_Delete(right, right->val);
			if(root->parent == NULL)return root;
			return Root;
		}
		if(root->left == NULL && root->right == NULL)return root;
		if(root->left != NULL && x <= root->val){
			_Delete(root->left, x);
			return Root;
		}
		if(root->right != NULL && x >= root->val){
			_Delete(root->right, x);
			return Root;
		}
		return Root;
	}
	void Delete(int x){
		root = _Delete(root, x);
	}
	void _printInOrderTraversal(Node* root){
		if(root->left != NULL)_printInOrderTraversal(root->left);
		if(root != NULL)cout << " " << root->val << endl;
		if(root->right != NULL)_printInOrderTraversal(root->right);
	}
	void printInOrderTraversal(){
		cout << "Printing Inorder Traversal : \n";
		_printInOrderTraversal(root);
	}
	void _printPreOrderTraversal(Node* root){
		if(root != NULL)cout << " " << root->val << endl;
		if(root->left != NULL)_printPreOrderTraversal(root->left);
		if(root->right != NULL)_printPreOrderTraversal(root->right);
	}
	void printPreOrderTraversal(){
		cout << "Printing Preorder Traversal : \n";
		_printPreOrderTraversal(root);
	}
	void _printPostOrderTraversal(Node* root){
		if(root->left != NULL)_printPostOrderTraversal(root->left);
		if(root->right != NULL)_printPostOrderTraversal(root->right);
		if(root != NULL)cout << " " << root->val << endl;
	}
	void printPostOrderTraversal(){
		cout << "Printing Postorder Traversal : \n";
		_printPostOrderTraversal(root);
	}
	int _findRank(Node* root, int x){
		if(root == NULL)return 0;
		if(root->val == x)
			return 1+root->l;
		if(x > root->val)
			return 1+root->l+_findRank(root->right, x);
		if(x < root->val)
			return _findRank(root->left, x);
		return 0;
	}
	int findRank(int x){
		if(!findval(x)) return -1;
		return _findRank(root, x);
	}
	int max(int a, int b){
		return (a > b) ? a : b;
	}
	int _height(Node* root){
		if(root == NULL)return 0;
		return 1+max(_height(root->left), _height(root->right));
	}
	int height(){
		return _height(root);
	}
	void _printCurrentLevel(Node* root, int d){
		if(root == NULL)return;
		if(d == 1)cout << root->val << "  ";
		if(d > 1){
			_printCurrentLevel(root->left, d-1);
			_printCurrentLevel(root->right, d-1);
		}
	}
	void printCurrentLevel(int d){
		_printCurrentLevel(root, d);
	}
	void printLevelOrderTraversal(){
		cout << "Printing Levelorder Traversal : \n";
		for (int d = 1; d <= height(); d++){
			printCurrentLevel(d);
			cout << endl;
		}
	}
private:
	void _printBST(Node* root){
		if(root != NULL){
			cout << root->val << " : ";
			if(root->left != NULL)
				cout << "l:" << root->left->val;
			else cout << "    ";
			if(root->right != NULL)
				cout << " r:" << root->right->val;
			else cout << "     ";
			cout << "(" << root->l << "," << root->r << ")";
			cout << endl;
		}
		else return;
		_printBST(root->left);
		_printBST(root->right);
	}
public:
	void printBST(){
		cout << "Printing BST:" << endl;
		_printBST(root);
		printPreOrderTraversal();
		printInOrderTraversal();
		printPostOrderTraversal();
		printLevelOrderTraversal();
	}
};
int main(){
	int i, n, q;
	cout << "Enter size and number of queries: ";
	cin >> n >> q;
	BST b1;
	cout << "Enter numbers: ";
	for(i = 0; i < n; i++){
		int in;
		cin >> in;
		b1.insert(in);
	}
	b1.printBST();
	for(i = 0; i < q; i++){
		int x, y;
		string str;
		cout << "\x1b[33mPossible commands are: find x, add x, "
			 << "del x, rank x\x1b[0m\n";
		cin >> str;
		if(str == "find"){
			cin >> x;
			cout << boolalpha << b1.findval(x) << endl;
		}
		if(str == "add"){
			cin >> x;
			b1.insert(x);
			b1.printBST();
		}
		if(str == "del"){
			cin >> x;
			b1.Delete(x);
			b1.printBST();
		}
		if(str == "rank"){
			cin >> x;
			int rank = b1.findRank(x);
			cout << "Rank of " << x << " : " << rank << endl;
		}
	}
	b1.printBST();
	return 0;
}
// 9 100     30 50 20 60 40 10 80 70 90
/*              30
			   /  \
			  20  50
			 /   /  \
			10  40  60 
					  \
					  80 
					 /  \
					70  90
*/