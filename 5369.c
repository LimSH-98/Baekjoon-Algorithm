#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Tree {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeTreeNode(int data) {
	TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));

	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}
TreeNode* assignTree(TreeNode* tree, int data) {
	if (tree == NULL) {
		tree = makeTreeNode(data);
	}
	else if (data < tree->data) {
		tree->left = assignTree(tree->left, data);
	}
	else if (data > tree->data) {
		tree->right = assignTree(tree->right, data);
	}
	return tree;
}
void postOrder(TreeNode* tree) {
	if (tree == NULL) return;

	postOrder(tree->left);
	postOrder(tree->right);
	printf("%d\n", tree->data);
}
int main(void) {
	TreeNode *tree = NULL;
	int data;

	while (scanf("%d", &data) != EOF) {
		tree = assignTree(tree, data);
	}
	postOrder(tree);

}