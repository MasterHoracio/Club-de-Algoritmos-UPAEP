#include <bits/stdc++.h>

using namespace std;

typedef struct tree{
    char ch;
    struct tree *left;
    struct tree *right;
}BinaryTree, *BinaryTreePtr;

BinaryTreePtr buildBinaryTree(){
    BinaryTreePtr subtree = new BinaryTree;
    char ch;
    if(cin >> ch){
        if(ch == '@')
            return NULL;
        subtree->ch = ch;
        subtree->left = buildBinaryTree();
        subtree->right = buildBinaryTree();
    }
    return subtree;
}

void visit(BinaryTreePtr node){
    cout << node->ch << " ";
}

void preOrder(BinaryTreePtr node){
    if(node != NULL){
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(BinaryTreePtr node){
    if(node != NULL){
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

void postOrder(BinaryTreePtr node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

int main(){
    freopen("input.txt", "r", stdin);

    BinaryTreePtr bt;
    bt = buildBinaryTree();

    cout << "pre-order -> ";
    preOrder(bt);
    cout << endl;
    cout << "in-order -> ";
    inOrder(bt);
    cout << endl;
    cout << "post-order -> ";
    postOrder(bt);
    cout << endl;

    fclose(stdin);
    return 0;
}