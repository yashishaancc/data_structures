#include<iostream>#include<string>using namespace std;typedef struct node{	int val;	int l, r;	struct node* parent;	struct node* left;	struct node* right;}Node;Node* getNewNode(int in){	Node* node = (Node*)malloc(sizeof(Node));	node->val = in;	node->l = 0;	node->r = 0;	node->parent = NULL;	node->left = NULL;	node->right = NULL;	return node;}void decrement(Node* node){	Node* tmp=node;	while(tmp->parent != NULL){		if(tmp->parent->left == tmp){			tmp->parent->l--;		}		if(tmp->parent->right == tmp){			tmp->parent->r--;		}		tmp = tmp->parent;	}}Node* insert(Node* root, int in){	if(root == NULL){		Node* node = getNewNode(in);		root = node;		return root;	}	if(in == root->val){		decrement(root);		return root;	}	if(in <= root->val){		root->left = insert(root->left, in);		root->left->parent = root;		root->l += 1;	}	else if(in >= root->val){		root->right = insert(root->right, in);		root->right->parent = root;		root->r += 1;	}	return root;}Node* _findval(Node* root, int x){	if(root==NULL) return NULL;	if(root->val == x) return root;	if(x <= root->val) return _findval(root->left, x);	if(x >= root->val) return _findval(root->right, x);	return NULL;}bool findval(Node* root, int x){	Node* node = _findval(root, x);	if(node == NULL)return false;	else return true;}Node* Delete(Node* root, int x){	cout << "In Delete: " << root->val << endl;	Node* Root = root;	if(root == NULL)return root;	if(root->val == x){		// no child case		if(root->left == NULL && root->right == NULL){			decrement(root);			if(root->parent == NULL){				free(root);				return NULL;			}			if(root->parent->left == root){				root->parent->left = NULL;				free(root);				return Root;			}			if(root->parent->right == root){				root->parent->right = NULL;				free(root);				return Root;			}		}		//one child case		if(root->right == NULL){			decrement(root);			if(root->parent == NULL){				Root = root->left;				root->left->parent = NULL;				free(root);				return Root;			}			if(root->parent->left != NULL && root->parent->left == root)				root->parent->left = root->left;			if(root->parent->right != NULL && root->parent->right == root)				root->parent->right = root->left;			root->left->parent = root->parent;			free(root);			return Root;		}		if(root->left == NULL){			decrement(root);			if(root->parent == NULL){				Root = root->right;				root->right->parent = NULL;				free(root);				return Root;			}			if(root->parent->left != NULL && root->parent->left == root)				root->parent->left = root->right;			if(root->parent->right != NULL && root->parent->right == root)				root->parent->right = root->right;			root->right->parent = root->parent;			free(root);			return Root;		}		//two child case		Node* right = root->right;		while(right->left!=NULL){			right=right->left;		}		root->val = right->val;		Delete(right, right->val);		if(root->parent == NULL)return root;		return Root;	}	if(root->left == NULL && root->right == NULL)return root;	if(root->left != NULL && x <= root->val){		Delete(root->left, x);		return Root;	}	if(root->right != NULL && x >= root->val){		Delete(root->right, x);		return Root;	}	return Root;}void _printInOrderTraversal(Node* root){	if(root->left != NULL)_printInOrderTraversal(root->left);	if(root != NULL)cout << " " << root->val << endl;	if(root->right != NULL)_printInOrderTraversal(root->right);}void printInOrderTraversal(Node* root){	cout << "Printing Inorder Traversal : \n";	_printInOrderTraversal(root);}void _printPreOrderTraversal(Node* root){	if(root != NULL)cout << " " << root->val << endl;	if(root->left != NULL)_printPreOrderTraversal(root->left);	if(root->right != NULL)_printPreOrderTraversal(root->right);}void printPreOrderTraversal(Node* root){	cout << "Printing Preorder Traversal : \n";	_printPreOrderTraversal(root);}void _printPostOrderTraversal(Node* root){	if(root->left != NULL)_printPostOrderTraversal(root->left);	if(root->right != NULL)_printPostOrderTraversal(root->right);	if(root != NULL)cout << " " << root->val << endl;}void printPostOrderTraversal(Node* root){	cout << "Printing Postorder Traversal : \n";	_printPostOrderTraversal(root);}int _findRank(Node* root, int x){	if(root == NULL)return 0;	if(root->val == x)		return 1+root->l;	if(x > root->val)		return 1+root->l+_findRank(root->right, x);	if(x < root->val)		return _findRank(root->left, x);	return 0;}int findRank(Node* root, int x){	if(!findval(root, x)) return -1;	return _findRank(root, x);}int max(int a, int b){	return (a > b) ? a : b;}int height(Node* root){	if(root == NULL)return 0;	return 1+max(height(root->left), height(root->right));}void printCurrentLevel(Node* root, int d){	if(root == NULL)return;	if(d == 1)cout << root->val << "  ";	if(d > 1){		printCurrentLevel(root->left, d-1);		printCurrentLevel(root->right, d-1);	}}void printLevelOrderTraversal(Node* root){	cout << "Printing Levelorder Traversal : \n";	for (int d = 1; d <= height(root); d++){		printCurrentLevel(root, d);		cout << endl;	}}void _printBST(Node* root){	if(root != NULL){		cout << root->val << " : ";		if(root->left != NULL)			cout << "l:" << root->left->val;		else cout << "    ";		if(root->right != NULL)			cout << " r:" << root->right->val;		else cout << "     ";		cout << "(" << root->l << "," << root->r << ")";		cout << endl;	}	else return;	_printBST(root->left);	_printBST(root->right);}void printBST(Node* root){	cout << "Printing BST:" << endl;	_printBST(root);	printPreOrderTraversal(root);	printInOrderTraversal(root);	printPostOrderTraversal(root);	printLevelOrderTraversal(root);}int main(){	Node* root = NULL;	int i, n, q;	cin >> n >> q;	for(i = 0; i < n; i++){		int in;		cin >> in;		root = insert(root, in);	}	printBST(root);	for(i = 0; i < q; i++){		int x, y;		string str;		cin >> str;		if(str == "find"){			cin >> x;			cout << findval(root, x) << endl;		}		if(str == "add"){			cin >> x;			root=insert(root, x);			printBST(root);		}		if(str == "del"){			cin >> x;			root = Delete(root, x);			printBST(root);		}		if(str == "rank"){			cin >> x;			int rank = findRank(root, x);			cout << "Rank of " << x << " : " << rank << endl;		}	}	printBST(root);	return 0;}// 9 100     30 50 20 60 40 10 80 70 90/*              30			   /  \			  20  50			 /   /  \			10  40  60 					  \					  80 					 /  \					70  90*/