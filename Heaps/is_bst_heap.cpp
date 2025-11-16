#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int countNodes(Node* root) {
    if(root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root, int index, int cnt) {
    if(root == nullptr)
        return true;
    if(index >= cnt)
        return false;
   //check if left or right node does not exceeed the bound of total nodes count
    bool left = isCBT(root->left, 2*index + 1, cnt);
    bool right = isCBT(root->right, 2*index + 2, cnt);
    return left && right;
}

bool isMaxOrder(Node* root) {
  //Leaf node
    if(root->left == nullptr && root->right == nullptr)
        return true;
  //only left node exist 
    if(root->right == nullptr)
        return root->data > root->left->data;
  //Both child exists 
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    return left && right && (root->data > root->left->data && root->data > root->right->data);
}

bool isHeap(Node* root) {
    int index = 0;
    int totalCount = countNodes(root);
    return isCBT(root, index, totalCount) && isMaxOrder(root);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    if(isHeap(root))
        cout << "The tree is a Max Heap" << endl;
    else
        cout << "The tree is not a Max Heap" << endl;

    return 0;
}
