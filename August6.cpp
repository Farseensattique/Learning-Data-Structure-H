#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
public:
    Node* insertNode(Node* root, Node* newNode) {
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            while (current != NULL) {
                if (newNode->data < current->data) {
                    if (current->left != NULL) {
                        current = current->left;
                    } else {
                        current->left = newNode;
                        break;
                    }
                } else if (newNode->data > current->data) {
                    if (current->right != NULL) {
                        current = current->right;
                    } else {
                        current->right = newNode;
                        break;
                    }
                } else {
                    cout << "Invalid data entry in terms of a Binary Search Tree" << endl;
                    delete newNode;
                    break;
                }
            }
        }
        return root;
    }

    void postOrderTraversal(Node* root) {
        if (root != NULL) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of nodes to insert: ";
    cin >> n;
    cout << endl;

    BinarySearchTree bst;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> data;
        Node* newNode = new Node(data);
        root = bst.insertNode(root, newNode);
    }
    cout << endl;

    cout << "Data in post-order traversal: " << endl;
    bst.postOrderTraversal(root);

    return 0;
}


