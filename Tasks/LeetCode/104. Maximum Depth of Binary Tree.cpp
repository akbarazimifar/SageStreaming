/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:
Input: root = [1,null,2]
Output: 2
Example 3:
Input: root = []
Output: 0
Example 4:
Input: root = [0]
Output: 1
Constraints:
The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

#include <iostream>
#include <unordered_map>
#include <string>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int left_h = 0, right_h = 0;
    int maxDepth(TreeNode* root) {
        if(root) {
            std::cout << root->val << " " << left_h << " " << right_h << std::endl;
            
            left_h = maxDepth(root->left);
            right_h = maxDepth(root->right);
            

            if(left_h > right_h)
                return left_h + 1;
            return right_h + 1;
            
        } else {
            return 0;
        }
    }
};

int main() {
    Solution solution;
    [3,9,20,null,null,15,7]
    std::cout << solution.maxDepth() << std::endl;
}