//476 Techie Delight
/*

Given the root of a binary search tree (BST) and a key, search for the node with that key in the BST.

For example, consider the following BST.

		  15
		/	 \
	   /	  \
	  /		   \
	 10		   20
	/  \	  /  \
   /	\	 /	  \
  8		12	16	  25

Input: key = 25
Output: true

Input: key = 5
Output: false

*/

class Solution
{
public:

	/*
		A BST node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/

	bool search(Node* root, int key)
	{
		if( root -> data == NULL)
			return false;
		if(root->data == key)
			return true;
		if(root-> data > key)
			return search(root->left, key);
		else
			return search(root->right, key);
		
	}
};
