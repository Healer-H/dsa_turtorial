#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int   value;
    Node *left;
    Node *right;
};

typedef Node *Tree;

Node *createNode(int val)
{
    Node *newNode  = new Node;
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Node* insert(Tree& tree, int val) {
//     if(tree == NULL) {
//         cout << "insert sucessfully: " << val << "\n";
//         tree = createNode(val);
//         return tree;
//     }

//     if(val == tree->value)
//         return NULL;

//     if(val < tree->value) {
//         // go to left side
//         if(tree->left == NULL) {
//             tree->left = insert(tree->left, val);
//             return tree->left;
//         }
//     }
//     else {
//         // go to right side
//         if(tree->right == NULL) {
//             tree->right = insert(tree->right, val);
//             return tree->right;
//         }
//     }
// }

void insert(Tree &tree, int val)
{
    Node *newNode = createNode(val);
    Node *root    = tree;
    Node *prev    = NULL;

    while (root != NULL)
    {
        if (val == root->value)
            return;
        prev = root;
        if (val < root->value)
            root = root->left;
        else
            root = root->right;
    }

    if (prev == NULL)
    {
        tree = newNode;
    }
    else if (val < prev->value)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

Node *find(Tree tree, int val)
{
    if (tree != NULL)
    {
        if (val == tree->value)
            return tree;
        if (val < tree->value)
            return find(tree->left, val);
        else
            return find(tree->right, val);
    }
    return NULL;
}

Node *find1(Tree tree, int val)
{
    Node *root = tree;
    while (root != NULL)
    {
        if (val == root->value)
            return root;

        if (val < root->value)
            root = root->left;

        else
            root = root->right;
    }

    return NULL;
}

void LNR(Tree tree)
{
    if (tree != NULL)
    {
        LNR(tree->left);
        cout << tree->value << " ";
        LNR(tree->right);
    }
    return;
}

void substitute(Node*& to_delete, Tree& tree) {
    if(tree->left != NULL) {
        substitute(to_delete, tree->left);
    }
    else {
        to_delete->value = tree->value;
        to_delete = tree;
        tree = tree->right;
    }
}

void deleteNode(Tree &tree, int val)
{
    if (tree != NULL)
    {
        if (val < tree->value)
            deleteNode(tree->left, val);
        else if (val > tree->value)
            deleteNode(tree->right, val);
        else
        {
            Node *to_delete = tree;
            if (tree->left == NULL){
                
                tree = tree->right;
            }
            else if (tree->right == NULL) {
                tree = tree->left;
            }
            else
                substitute(to_delete, tree->right);
            delete to_delete;
        }
    }
}

int countNode(Tree tree) {
    if(tree == NULL) return 0;

    return 1 + countNode(tree->left) + countNode(tree->right);
}

int countLeafNode(Tree tree) {
    if(tree == NULL) return 0;

    if(tree->left == NULL && tree->right == NULL) return 1;

    return countLeafNode(tree->left) + countLeafNode(tree->right);
}

int calcHeight(Tree tree) {
    if(tree == NULL) return 0;
    int leftHeight = calcHeight(tree->left);
    int rightHeight = calcHeight(tree->right);
    return 1 + max(leftHeight, rightHeight);
}

int countNodeHasOneChild(Tree tree) {
    if(tree == NULL) return 0;
    int left = countNodeHasOneChild(tree->left);
    int right = countNodeHasOneChild(tree->right);

    if( (tree->left != NULL && tree->right == NULL) ||
        ((tree->left == NULL) && tree->right != NULL)
    )
        return 1 + left + right;
    return left + right;    
}

int main()
{

    Tree tree = NULL;
    int  a[]  = {10, 20, 5, 8, 2};
    int  n    = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        insert(tree, a[i]);
    }
    LNR(tree);
    cout << "\n" << countNodeHasOneChild(tree) << "\n";
    cout << "\n";
    deleteNode(tree, 10);
    deleteNode(tree, 2);
    deleteNode(tree, 9);
    LNR(tree);
    cout << "\n" << countNodeHasOneChild(tree) << "\n";


}