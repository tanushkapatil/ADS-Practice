#include<iostream>
using namespace std ;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

class Tree {
    public:
        TreeNode *root ;
        Tree();
        void insert(TreeNode*& root, int value);
        void insert(int value);
        void inOrder(TreeNode* root);
        void create();
};

Tree::Tree() {
    root = NULL ;
}

void Tree::insert(TreeNode*& root, int value) {
    if(root == NULL){
        root = new TreeNode(value);
    }
    else if(value < root->data) {
        insert(root->left, value);
    }
    else{
        insert(root->right, value);
    }
}

void Tree::insert(int value) {
    insert(root, value);
}

void Tree::inOrder(TreeNode *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data << endl ;
        inOrder(root->right);
    }
}

void Tree::create() {
    int choice, value;
    do{
        cout << "0. Exit" ;
        cout << "1. Insert Multiple" ;
        cout << "2. Insert Single" ;
        cout << "3. Display Inorder" ;
        cout << "Enter Your Choice : " ;
        cin >> choice ;

        switch(choice) {
            case 0:
                cout << "Exiting program.\n";
                break;
            case 1: {
                int n;
                cout << "How many nodes to insert? ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Enter value " << (i + 1) << ": ";
                    cin >> value;
                    insert(value);
                }
                cout << "Nodes inserted successfully.\n";
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                cout << "Node inserted successfully.\n";
                break;
            case 3:
                cout << "In-order traversal: ";
                inOrder(root);
                cout << "\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            } 
            
        }
    }while (choice != 0);
}


int main() {
    Tree t;
    t.create();
    return 0;
}
