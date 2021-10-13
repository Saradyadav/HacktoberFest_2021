/*
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) 
In-Place. The left and right pointers in nodes are to be used as 
previous and next pointers respectively in converted DLL. 
The order of nodes in DLL must be same as Inorder of the given Binary Tree.
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 

*/


// This function should return head to the DLL
class Solution
{
    Node* head = NULL, *tail = NULL;
    queue < Node*> store;
    void Inorder(Node* root) {
        if (!root) return;
        bToDLL(root->left);
        store.push(root);
        bToDLL(root->right);
    }
public:
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Inorder(root);
        while (store.size() != 0) {
            Node *temp = store.front();
            store.pop();
            temp->left = NULL;
            temp->right = NULL;
            if (!head)
                head = tail = temp;
            else {
                temp->left = tail;
                tail->right = temp;
                tail = temp;
            }
        }
        return head;
    }
};
