/**
 * @brief Inorder Traversal (Recursive & Iterative) with user input tree construction.
 * 
 * The program reads a binary tree in level-order form from standard input,
 * where `-1` denotes a NULL (no child).
 * 
 * Example Input:
 * 1 2 3 4 5 -1 -1 -1 -1 -1 -1
 * 
 * Corresponding Tree:
 *        1
 *       / \
 *      2   3
 *     / \
 *    4   5
 * 
 * Output:
 * Recursive Inorder Traversal: 4 2 5 1 3
 * Iterative Inorder Traversal: 4 2 5 1 3
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Structure representing a binary tree node.
 */
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief Builds a binary tree from level-order input.
 * 
 * Input Format:
 * Integers separated by spaces, where `-1` represents a NULL child.
 * Example: 1 2 3 4 5 -1 -1 -1 -1 -1 -1
 * 
 * @return Pointer to the root node of the constructed tree.
 */
Node* buildTreeLevelOrder() {
    cout << "Enter nodes in level order (-1 for NULL): ";
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> values;
    int val;
    while (ss >> val) values.push_back(val);

    if (values.empty() || values[0] == -1)
        return nullptr;

    Node* root = new Node(values[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)values.size()) {
        Node* current = q.front();
        q.pop();

        // Left child
        if (values[i] != -1) {
            current->left = new Node(values[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < (int)values.size() && values[i] != -1) {
            current->right = new Node(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

/**
 * @brief Performs recursive inorder traversal.
 */
void inorderRecursive(Node* root) {
    if (!root) return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

/**
 * @brief Performs iterative inorder traversal using a stack.
 */
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current || !s.empty()) {
        while (current) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";
        current = current->right;
    }
}

int main() {
    Node* root = buildTreeLevelOrder();

    cout << "\nRecursive Inorder Traversal: ";
    inorderRecursive(root);
    cout << "\n";

    cout << "Iterative Inorder Traversal: ";
    inorderIterative(root);
    cout << "\n";

    return 0;
}
