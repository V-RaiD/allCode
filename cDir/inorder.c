#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode tnode;

void inorder(tnode* tn);

int main(){
	tnode* tree;
	//create tree
	/////////////

	//print dfs
	inorder(tree);
		
	return 0;
}

void inorder(tnode* tn){
	if(!tn->left && !tn->right){
		printf("%d\n",tn->data);
		return;
	}
	if(tn->left){
		inorder(tn->left);
	}
	printf("%d\n",tn->data);
	if(tn->right){
		inorder(tn->right);
	}
	return;	
}
