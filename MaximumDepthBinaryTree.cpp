 // MaximumDepthBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* NewNode(int data) {
    TreeNode* temp = new TreeNode();
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return fun(root, 1);
    }

    int fun(TreeNode* root, int a) {
        int l = (root->left != NULL ? fun(root->left, a + 1) : a);
        int r = (root->right != NULL ? fun(root->right, a + 1) : a);
        return std::max(l,r);
    }
};

int main()
{
    TreeNode* root = NewNode(-1);
    root->left = NewNode(2);
    root->right = NewNode(2);
    //root->left->left = NewNode(3);
    root->right->right = NewNode(3);
    //root->left->right = NewNode(4);
    root->right->left = NewNode(4);
    root->right->left->right = NewNode(5);
    root->right->left->right->left = NewNode(6);


    Solution s;
    std::cout << s.maxDepth(root);
}