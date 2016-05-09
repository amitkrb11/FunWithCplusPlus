#include <iostream>
using namespace std;
typedef struct node{
	int data;
	struct node *left, *right;
} tree;
tree *createNode(int data) {
	tree *root = (tree *)(malloc)(sizeof(tree *));
	root->data = data;
	root->left = root->right = NULL;
	return root;
}
void inorder(tree *root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
void preorder(tree *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(tree *root) {
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
tree *insert(int data, tree *root) {
	if (root == NULL)
		return createNode(data);
	if ( (root->data) > data)
		root->left = insert(data, root->left);
	else
		root->right = insert(data, root->right);
	return root;
}
bool search(int data, tree *root) {
	if (root == NULL) return false;
	if (root->data == data) return true;
	if (root->data > data)
		return search(data, root->left);
	return search(data, root->right);
}
int findMax(tree *root) {
	while (root->right != NULL)
		root = root->right;
	return root->data;
}
node *deleteNode(int data, tree *root) {
	if (root == NULL) return NULL;
	if ( (root->data) > data)
		root->left = deleteNode(data, root->left);
	else if ( (root->data) < data)
		root->right = deleteNode(data, root->right);
	else {
		if ( (root->left) == NULL) {
			node *tmp = root->right;
			free(root);
			return tmp;
		}
		else if ( (root->right) == NULL) {
			node *tmp = root->left;
			free(root);
			return tmp;
		}
		else {
			root->data = findMax(root->left);
			root->left = deleteNode(root->data, root->left);
		}
	}
	return root;
}
int main() {
	tree *root = createNode(4);
	insert(2, root); insert(1, root);
	insert(3, root); insert(6, root);
	insert(5, root); insert(8, root);
	insert(7, root); insert(10, root); insert(9, root);
	inorder(root); cout << endl;
	preorder(root); cout << endl;
	postorder(root); cout << endl;
	cout << search(5, root) << endl;
	cout << search(4, root) << endl;
	cout << search(12, root) << endl;
	cout << search(10, root) << endl;
	cout << search(-1, root) << endl;
	root = deleteNode(10, root);
	root = deleteNode(4, root);
	root = deleteNode(5, root);
	root = deleteNode(-1, root);
	inorder(root); cout << endl;
	preorder(root); cout << endl;
	postorder(root); cout << endl;
}