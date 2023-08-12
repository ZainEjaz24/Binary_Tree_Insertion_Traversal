#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;

    int choice;
    int number;

    while (true) {
        cout << "What Do You Want To Perform? " << endl;
        cout << "1. Insert a number" << endl;
        cout << "2. Inorder traversal" << endl;
        cout << "3. Preorder traversal" << endl;
        cout << "4. Postorder traversal" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> number;
                root = insert(root, number);
                cout << "Number inserted successfully.\n" << endl<<endl;
                break;
            case 2:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << endl<<endl;
                break;
            case 3:
                cout << "Preorder traversal: ";
                preorder(root);
                cout << endl<<endl;
                break;
            case 4:
                cout << "Postorder traversal: ";
                postorder(root);
                cout << endl<<endl;
                break;
            case 5:
                cout << "Thank You" << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
