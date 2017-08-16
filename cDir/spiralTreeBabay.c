#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
	int data;
	char lable;
	struct TreeNode* right;
	struct TreeNode* left;
};
typedef struct TreeNode tnode;
tnode* generateSpiralTree(tnode* tNode, int height);
void printTree(tnode* tNode);
void printSpiral(tnode* tNode, tnode** tArr, int TARR_SIZE, int motion);

int main(){
	tnode* spiral;
	int height = 0;
	tnode** spArr;
	printf("\nPlease enter the height of spiral : ");
	scanf("%d",&height);
	spiral = (tnode*) malloc(sizeof(tnode));
	spiral->data = height;
	spiral->lable = 'T';
	spiral->right = NULL;
	spiral->left = NULL;

	generateSpiralTree(spiral, height-1);
	printTree(spiral);
	printf("\nNow printing Spiral of above tree\n");
	spArr = (tnode**) malloc(sizeof(tnode*));
	spArr[0] = spiral;
	printSpiral(spiral, spArr,1,0);

	return 0;
}

tnode* generateSpiralTree(tnode* tNode, int height) {
	if(height <= 0) {
		return tNode;
	}

	tNode->right = (tnode*) malloc(sizeof(tnode));
	tNode->right->data = tNode->data*10 + height;
	tNode->right->lable = 'R';
	tNode->right->right = NULL;
        tNode->right->left = NULL;
	generateSpiralTree(tNode->right, height-1);	
	
	tNode->left = (tnode*) malloc(sizeof(tnode));
        tNode->left->data = tNode->data*100 + height;
        tNode->left->lable = 'L';
        tNode->left->right = NULL;
        tNode->left->left = NULL;
	generateSpiralTree(tNode->left, height-1);

	return tNode;
}

void printTree(tnode* tNode) {
	
	printf("\n%c - %d", tNode->lable, tNode->data);
	if(tNode->right)
		printTree(tNode->right);
	if(tNode->left)
		printTree(tNode->left);
}

void printSpiral(tnode* tNode, tnode** tArr, int TARR_SIZE, int motion) {
	tnode** newArr;
	int newTarrSize = 0;
	int newMotion = (motion == 1) ? 0 : 1;
	int index = 0;
	if(TARR_SIZE <= 0) {
		return;
	}
	if(newMotion == 1) {
		//Store LR
		for(index = TARR_SIZE - 1;index >= 0; index--) {
			printf("\n%c - %d", (*(tArr[index])).lable, (*(tArr[index])).data);
			if(tArr[index]->left) {
				newArr = (tnode**) realloc(newArr,(++newTarrSize)*(sizeof(tnode*)));
				newArr[newTarrSize - 1] = (*(tArr[index])).left;
			}
			if(tArr[index]->right) {
                                newArr = (tnode**) realloc(newArr,(++newTarrSize)*(sizeof(tnode*)));
                                newArr[newTarrSize - 1] = (*(tArr[index])).right;
                        }
		}
	} else {
		//Store RL
		for(index = TARR_SIZE - 1;index >= 0; index--) {
                        printf("\n%c - %d", (*(tArr[index])).lable, (*(tArr[index])).data);
                        if(tArr[index]->right) {
                                newArr = (tnode**) realloc(newArr,(++newTarrSize)*(sizeof(tnode*)));
                                newArr[newTarrSize - 1] = (*(tArr[index])).right;
                        }
			if(tArr[index]->left) {
                                newArr = (tnode**) realloc(newArr,(++newTarrSize)*(sizeof(tnode*)));
                                newArr[newTarrSize - 1] = (*(tArr[index])).left;
                        }
                }
	}
	printSpiral(tNode,newArr,newTarrSize,newMotion);
}
