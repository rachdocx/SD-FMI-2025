//480 inorder successor BST techie delight

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

    void search(Node* root, int key, Node* &lastLeft){
        if(root == NULL)
            return;
        if(root->data == key)
            return;
        if(root->data > key){
            lastLeft = root;
            search(root->left, key, lastLeft);
        }
        else {
            search(root->right, key, lastLeft);
        }
    }

    Node* findInorderSuccessor(Node* root, Node* x)
    {
        if(root == NULL || x == NULL)
            return nullptr;
        if(x->right != NULL){
            Node* currentNode = x->right;
            while(currentNode->left != NULL)
                currentNode = currentNode->left;
            return currentNode;
        }
        Node* lastLeft = nullptr;
        search(root, x->data, lastLeft);
        return lastLeft;
    }
};
