#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
