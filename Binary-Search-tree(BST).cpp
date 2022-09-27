#include <bits/stdc++.h>

using namespace std;
const int MX = 100;

/*
template< class  t>
*/
class BST {
public:
    struct node {
        int item;
        node *lift;
        node *right;
    };
    node *root;

    BST() {
        root = NULL;
    }

    bool isEmpty() {
        if (root == NULL)return true;
        return false;
    }

    void insert(int element) {
        node *NewItems = new node;
        NewItems->item = element;
        if (isEmpty()) {
            root = NewItems;
            root->lift = NULL;
            root->right = NULL;
        } else {
            node *cur = root, *prev = root;
            while (cur != NULL) {
                if (element >= cur->item) {
                    if (cur->right == NULL) break;
                    cur = cur->right;// to right
                } else {
                    if (cur->lift == NULL) break;
                    cur = cur->lift; // to lift
                }
            }
            if (cur->item <= element) {
                cur->right = NewItems;
            } else cur->lift = NewItems;
            NewItems->lift = NULL;
            NewItems->right = NULL;
        }
    }

    node *cur = root;

    void inOrder() {
        inOrderTreeWalk(root);
    }

    void inOrderTreeWalk(node *pos) {
        if (pos == NULL)return;
        inOrderTreeWalk(pos->lift);
        cout << pos->item << " ";
        inOrderTreeWalk(pos->right);
    }
    void preOrder() {
        preOrderTreeWalk(root);
    }
    void preOrderTreeWalk(node *pos)  // root , lift , right
    {
        if (pos == NULL)return;
        cout << pos->item << " ";
        inOrderTreeWalk(pos->lift);
        inOrderTreeWalk(pos->right);
    }

    void postOrder() {
        postOrderTreeWalk(root);
    }

    void postOrderTreeWalk(node *pos)  //  lift , right , root
    {
        if (pos == NULL)return;

        inOrderTreeWalk(pos->lift);
        inOrderTreeWalk(pos->right);
        cout << pos->item << " ";
    }


};

int main() {
    BST B;
    B.insert(45);
    B.insert(15);
    B.insert(79);
    B.insert(90);
    B.insert(10);
    B.insert(55);
    B.insert(12);
    B.insert(20);
    B.insert(50);
  
    B.inOrder(); // 10 12 15 20 45 50 55 79 90
    cout<<'\n' ;
    B.preOrder(); // 45 10 12 15 20 50 55 79 90
    cout<<'\n' ;
    B.postOrder(); // 10 12 15 20 50 55 79 90 45
}
 
 ### Binary-Search-tree : this algorithm is organized , as the name suggests binary tree , we can represent such a tree by linked data structure
 ## inorder tree walk :this algorithm is so named this name beacuse it print root befor subtree (element greater than root )
 ## preorder tree walk :this algorithm is so named this name beacuse it print root befor either subtree 
 ## postorder tree walk :this algorithm is so named this name beacuse it print root after either subtree 
