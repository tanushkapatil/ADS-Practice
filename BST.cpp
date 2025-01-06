#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;            // Data of the node
    TreeNode* left;       // Pointer to the left child
    TreeNode* right;      // Pointer to the right child

    // Constructor to initialize the node
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary search tree
void insertNode(TreeNode*& root, int value) {
    TreeNode* temp = root;

    // Create the new node
    TreeNode* newNode = new TreeNode(value);

    // If the tree is empty, set root to the new node
    if (root == nullptr) {
        root = newNode;
        return;
    }

    // Traverse the tree to find the correct position for the new node
    while (temp != nullptr) {
        if (value < temp->data) { // Go to the left subtree
            if (temp->left == nullptr) {
                temp->left = newNode; // Insert the new node
                break;
            } else {
                temp = temp->left; // Move to the left child
            }
        } else { // Go to the right subtree
            if (temp->right == nullptr) {
                temp->right = newNode; // Insert the new node
                break;
            } else {
                temp = temp->right; // Move to the right child
            }
        }
    }
}

// Function to print the tree in-order (for testing)
void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    int choice, value;

    do {
        cout << "\nMenu:";
        cout << "\n1. Insert a node";
        cout << "\n2. Display in-order traversal";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                insertNode(root, value);
                cout << "Node inserted.\n";
                break;
            case 2:
                cout << "In-order traversal of the tree: ";
                inOrderTraversal(root);
                cout << "\n";
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

