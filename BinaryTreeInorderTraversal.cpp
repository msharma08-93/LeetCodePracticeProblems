// BinaryTreeInorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// val is the key or the value that
// has to be added to the data part
Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;

	// Left and right child for node
	// will be initialized to null
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printNode(struct Node* node) {
	if (node == NULL)
	{
		return;
	}

	std::cout << node->data << " ";

}

//InOrder order of printing is (Left, Root, Right)
void InOrder(struct Node* ptr) {
	if (ptr == NULL)
	{
		return;
	}

	//Recursively moving to left
	InOrder(ptr->left);

	//Printing Root
	printNode(ptr);

	//REcursively moving to the right
	InOrder(ptr->right);
}


// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
	std::vector<int> inorderTraversal(TreeNode* root) {
		std::vector<int> temp;
		inOrderT(root,temp);
		std::cout << temp.size() << "\n";
		return temp;
	}

	void inOrderT(TreeNode* root, std::vector<int> &vec) {
		if (root == NULL)
		{
			return;
		}

		inOrderT(root->left,vec);

		vec.push_back(root->val);

		inOrderT(root->right,vec);
		
	}

};


int main()
{
	//struct Node* root = newNode(1);
	//root->left = newNode(2);
	//root->right = newNode(3);
	//root->left->left = newNode(4);
	//root->left->right = newNode(5);
	//root->left->right->left = newNode(6);
	//root->left->right->right = newNode(7);

	struct TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->right->left = new TreeNode(6);
	root->left->right->right = new TreeNode(7);


	//InOrder(root);
	Solution s1;
	std::vector<int> a = s1.inorderTraversal(root);

	std::cout << a.size() << "\n";

	for (int i = 0; i < a.size(); i++)
	{	
		std::cout << a[i] << " ";
	}
	

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
