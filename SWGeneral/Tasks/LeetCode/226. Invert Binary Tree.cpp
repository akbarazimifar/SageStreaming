/*
Given the root of a binary tree, invert the tree, and return its root.
Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {
            return NULL;
        } else {
            if(root == NULL) return root;
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
            return root;
            
            // std::cout << root->val << std::endl;
            // TreeNode *node = new TreeNode(root->val);
            // node->left = invertTree(root->right);
            // node->right = invertTree(root->left);
            // return node;
        }
    }
};

int main() {
    Solution solution;
    [4,2,7,1,3,6,9]
    std::cout << solution.invertTree() << std::endl;
}