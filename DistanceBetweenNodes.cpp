/* Find the Distance between Two Nodes in a Binary Tree... The Distance between two Nodes is the minimum number of Edges Traversed
in reaching from one particular Node to another Node...*/
#include <iostream>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        if(root == NULL)   // If Tree is empty nothing to show
            return;            // Control moves out of the function
        Node* temp = root;
        ShowTree(root -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(root -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << root -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(root -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << root -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(root -> right);     // Recursive Call
    }
    Node* LowestCommonAncestor(Node* root, int n1, int n2)
    {         // Evaluating the Lowest Common Ancestor ( Parent ) of the Two Nodes
        if(root == NULL)         // If current Node is empty then we backtrack
        {
            return NULL;
        }
        if(root -> data == n1 || root -> data == n2)
        {   // If current data matches with the specified value
            return root;
        }
        Node* Left = LowestCommonAncestor(root -> left, n1, n2);     // Recursive Call for Left Subtree
        Node* Right = LowestCommonAncestor(root -> right, n1, n2);   // Recursive Call for Right Subtree
        if(Left != NULL && Right != NULL)    // If Not empty we return the Node
        {
            return root;
        }
        if(Left == NULL && Right == NULL)    // Otherwise we return empty
        {
            return NULL;
        }
        if(Left != NULL)
        {
            return LowestCommonAncestor(root -> left, n1, n2);    // If Left is not Null, then again Recursive Call
        }
        if(Right != NULL)
        {
            return LowestCommonAncestor(root -> right, n1, n2);   // If Right is not Null, then again Recursive Call
        }
    }
    int DistanceBetween(Node* root, int k, int dist)
    {            // We calculate the distance of the Left and Right Nodes separately in this function 
        if(root == NULL)
            return -1;          // If current Node is empty we return -1 such that Node distance not certain
        if(root -> data == k)
            return dist;            // Else we return the distance
        int l = DistanceBetween(root -> left, k, dist+1);   // Recursive function Call for Left
        if(l != -1)
            return l;
        return DistanceBetween(root -> right, k, dist+1);   // Recursive function Call for Right
    }
    int DistanceBetweenNodes(Node* root, int n1, int n2)
    {
        Node *Lca = LowestCommonAncestor(root, n1, n2);   // We evaluate the Lowest Common Parent of the two Nodes
        int d1 = DistanceBetween(Lca, n1, 0);     // We Recursively Evaluate the distance of Left and Right Node
        int d2 = DistanceBetween(Lca, n2, 0);     // from the Common Ancestor Recursively
        return d1 + d2;       // We return their Sum
    }
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value :";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        root = binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    binarytree.ShowTree(root);    // Displaying binary tree with Nodes
    cout << "Enter first Node value : ";
    cin >> x;
    cout << "Enter Second Node value : ";
    cin >> s;
    int d = binarytree.DistanceBetweenNodes(root, x, s);
    cout << "The Distance between the given Nodes is : " << d << endl;
    return 0;
}