// 104. Maximum Depth of Binary Tree

#include <iostream>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

int maxDepth(TreeNode* root) {
        if(root == NULL) 
        {
            return 0;
        }
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
    }

int main()
{
    return 0;
}