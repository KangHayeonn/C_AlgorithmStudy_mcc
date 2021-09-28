#include<stdio.h>
#include<stdlib.h>

struct binarytree{       //여기서 데이터 타입만 수정하면 됨
    int data;
    struct binarytree *left;
    struct binarytree *right;
}typedef binarytree;

typedef struct {
    binarytree *root;
}Root;


void createtree(Root *R , int data){
    R->root = (binarytree*)malloc(sizeof(binarytree));
    R->root->data = data;
    R->root->left = NULL;
    R->root->right = NULL;
}


void inputtree(binarytree *T , int data){
    if (data<T->data){   
        if(T->left!=NULL){
            inputtree(T->left,data);
        }else{
             binarytree *temp = (binarytree*)malloc(sizeof(binarytree));
            temp->data = data;
            temp->left  =NULL;
            temp->right =NULL;
            T->left = temp;
        }
    }
    else if (data>T->data){   
        if(T->right!=NULL){
            inputtree(T->right,data);
        }else{
            binarytree *temp = (binarytree*)malloc(sizeof(binarytree));
            temp->data = data;
            temp->left  =NULL;
            temp->right =NULL;
            T->right = temp;
        }
    }
}



void printpostorder(binarytree *T){
    if (T==NULL){
        return ;
    }
    else{
        printpostorder(T->left);
        printpostorder(T->right);
        printf("%d\n",T->data);
    }

}


// 
void freetree(binarytree **T){
    if (T==NULL){
        return ;
    }
    else{
        freetree(&T[0]->left);
        freetree(&T[0]->right);
        free(T[0]);
    }
}

int main(){

    int temp;

    Root *R = (Root*)malloc(sizeof(Root));
    scanf("%d",&temp);
    createtree(R,temp);



    while (scanf("%d", &temp)!= EOF) {
        inputtree(R->root,temp);
    }

    
    printpostorder(R->root);


    /*	do {
		

	} while (getc(stdin) == ' ');*/



    free(R);
}
