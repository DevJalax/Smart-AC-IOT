#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
        } else {
            insertHelper(root, data);
        }
    }

    void remove(int data) {
        root = removeHelper(root, data);
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

private:
    void insertHelper(Node* node, int data) {
        if (data < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(data);
            } else {
                insertHelper(node->left, data);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node(data);
            } else {
                insertHelper(node->right, data);
            }
        }
    }

    Node* removeHelper(Node* node, int data) {
        if (node == nullptr) {
            return node;
        }

        if (data < node->data) {
            node->left = removeHelper(node->left, data);
        } else if (data > node->data) {
            node->right = removeHelper(node->right, data);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            node->data = minValue(node->right);

            node->right = removeHelper(node->right, node->data);
        }

        return node;
    }

    int minValue(Node* node) {
        int minValue = node->data;

        while (node->left != nullptr) {
            minValue = node->left->data;
            node = node->left;
        }

        return minValue;
    }

    void inorderHelper(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorderHelper(node->left);
        cout << node->data << " ";
        inorderHelper(node->right);
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inorder();

    bst.remove(20);
    bst.remove(30);
    bst.remove(50);

    bst.inorder();

    return 0;
}
