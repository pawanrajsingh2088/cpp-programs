#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Node structure for the binary tree.
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
 * Input example:
 * 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
 * (-1 means NULL)
 */
TreeNode* buildTreeLevelOrder() {
    cout << "Enter nodes in level order (-1 for NULL):"<<endl;
    string line;
    getline(cin, line);
    if (line.empty()) getline(cin, line);

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
 * @brief Recursive postorder traversal.
 */
void postorderRecursive(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postorderRecursive(root->left, result);
    postorderRecursive(root->right, result);
    result.push_back(root->val);
}

/**
 * @brief Iterative postorder traversal using two stacks.
 */
vector<int> postorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        result.push_back(s2.top()->val);
        s2.pop();
    }

    return result;
}

/**
 * @brief Utility function to print traversal results.
 */
void printTraversal(const vector<int>& traversal) {
    for (int val : traversal) cout << val << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = buildTreeLevelOrder();

    if (!root) {
        cout << "Tree is empty."<<endl;
        return 0;
    }

    // Recursive Postorder
    vector<int> recursiveResult;
    postorderRecursive(root, recursiveResult);
    cout << "\nPostorder (Recursive): ";
    printTraversal(recursiveResult);

    // Iterative Postorder
    vector<int> iterativeResult = postorderIterative(root);
    cout << "Postorder (Iterative): ";
    printTraversal(iterativeResult);

    return 0;
}
