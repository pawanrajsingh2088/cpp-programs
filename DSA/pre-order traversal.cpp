#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Structure for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief Builds a binary tree level-wise from user input.
 * 
 * Input format: integers separated by spaces, -1 for null.
 * Example: 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
 * 
 * @return Pointer to the root of the tree.
 */
TreeNode* buildTreeLevelOrder() {
    cout << "Enter nodes in level order (-1 for NULL):\n";
    string line;
    getline(cin, line);
    if (line.empty()) getline(cin, line);  // handle leftover newline

    stringstream ss(line);
    vector<int> values;
    int x;
    while (ss >> x) values.push_back(x);

    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < (int)values.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < values.size() && values[i] != -1) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < values.size() && values[i] != -1) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

/**
 * @brief Recursive preorder traversal.
 */
void preorderRecursive(TreeNode* root, vector<int> &result) {
    if (!root) return;
    result.push_back(root->val);
    preorderRecursive(root->left, result);
    preorderRecursive(root->right, result);
}

/**
 * @brief Iterative preorder traversal using stack.
 */
vector<int> preorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}

/**
 * @brief Utility function to print traversal.
 */
void printTraversal(const vector<int> &res) {
    for (int val : res) cout << val << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = buildTreeLevelOrder();

    if (!root) {
        cout << "Tree is empty.\n";
        return 0;
    }

    vector<int> preorderRes;
    preorderRecursive(root, preorderRes);
    cout << "\nPreorder (Recursive): ";
    printTraversal(preorderRes);

    vector<int> iterativeRes = preorderIterative(root);
    cout << "Preorder (Iterative): ";
    printTraversal(iterativeRes);

    return 0;
}
