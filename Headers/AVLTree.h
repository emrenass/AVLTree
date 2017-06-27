//
// Created by Emre on 27.06.2017.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
};

class AVLTree {

public:
    AVLTree();
    virtual ~AVLTree();
    Node* insert(Node*& node, int key);
    void insert(int key);
    void inOrder(Node* root);
    void inOrder();
    int checkBalance(Node* n);
    void balance(Node*& n);
    bool search(int n);
    bool search(Node* n, int key);
    int getHeight(Node* n);

private:
    void rotateRight(Node*& n);
    void rotateLeft(Node*& n);
    void rotateLR(Node*& n);
    void rotateRL(Node*& n);
    int maxNumber(int a, int b);
    void rotateRightWithParent(Node *&n, Node *&parent);
    void rotateLeftWithParent(Node *&n, Node *&parent);
    Node* root;
};


#endif //AVLTREE_AVLTREE_H
