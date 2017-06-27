//
// Created by Emre on 27.06.2017.
//

#include <windef.h>
#include <iostream>
#include "../Headers/AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {

}

Node* AVLTree::insert(Node*& n, int key) {
    if (n == NULL) {
        n = new Node();
        n->key = key;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    else if (key < n->key) {
        n->left = insert(n->left, key);
        AVLTree::balance(n);
    }

    else if (key > n->key) {
        n->right = insert(n->right, key);
        AVLTree::balance(n);
    }
    return n;
}

void AVLTree::insert(int key) {
    insert(root, key);
}

int AVLTree::checkBalance(Node *n) {

    int leftHeight = getHeight(n->left);
    int rightHeight = getHeight(n->right);

    int bFactor = (leftHeight-rightHeight);
    return bFactor;
}

void AVLTree::balance(Node *&n) {
    int bFactor = checkBalance(n);
    if(bFactor>1) {
        if(checkBalance(n->left)>0) {
            AVLTree::rotateRight(n);
        }
        else {
            AVLTree::rotateLR(n);
        }
    }
    else if(bFactor < -1) {
        if (checkBalance(n->right)>0) {
            AVLTree::rotateRL(n);
        }
        else
            AVLTree::rotateLeft(n);
    }
}

int AVLTree::getHeight(Node *n) {
    if(n == NULL) {
        return 0;
    }
    else {
        return AVLTree::maxNumber(getHeight(n->left), getHeight(n->right)) + 1;
    }
}

void AVLTree::rotateRight(Node *&n) {

    Node* node1 = n->left;
    n->left = node1->right;
    node1->right = n;
    n = node1;
}

void AVLTree::rotateLeft(Node *&n) {

    Node* node1 = n->right;
    n->right = node1->left;
    node1->left = n;
    n= node1;
}
void AVLTree::rotateLR(Node *&n) {
    Node* temp = n->left;
    rotateLeftWithParent(temp, n);
    rotateRight(n);
}

void AVLTree::rotateRL(Node *&n) {
    Node* temp = n->right;
    rotateRightWithParent(temp, n);
    rotateLeft(n);
}

void AVLTree::rotateRightWithParent(Node*& n, Node*& parent){
    Node* node1 = n->left;
    n->left = node1->right;
    node1->right = n;
    n = node1;
    parent->right=n;
}

void AVLTree::rotateLeftWithParent(Node*& n, Node*& parent){
    Node* node1 = n->right;
    n->right = node1->left;
    node1->left = n;
    n = node1;
    parent->left = n;
}

int AVLTree::maxNumber(int a, int b) {
    return (a>b ? a:b);
}

void AVLTree::inOrder(Node* root) {
    if(root != NULL) {
        inOrder(root->left);
        std::cout << "Key is: " << root->key << std::endl;
        inOrder(root->right);
    }
}

void AVLTree::inOrder() {
    inOrder(root);
}

bool AVLTree::search(Node *n, int key) {
    if (n == NULL)
        return false;
    else if(n->key == key)
        return true;
    else if(key > n->key)
        search(n->right, key);
    else
        search(n->left, key);
}

bool AVLTree::search(int n) {
    return search(root, n);
}