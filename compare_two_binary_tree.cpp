#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void printTree(Node *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << endl;
    printTree(root->right);
}

void inputTee(Node *&root)
{
    int a;
    cin >> a;

    root = new Node(a);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *presentNode = q.front();
        q.pop();

        int x, y;
        cin >> x >> y;

        Node *n1 = NULL;
        Node *n2 = NULL;

        if (x != -1)
            n1 = new Node(x);
        if (y != -1)
            n2 = new Node(y);

        if (n1 != NULL)
        {
            presentNode->left = n1;
            q.push(n1);
        }
        if (n2 != NULL)
        {
            presentNode->right = n2;
            q.push(n2);
        }
    }
}

bool isSame(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    
    if(root1->val != root2->val)
        return false;
    
    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}

int main(void)
{
    Node *root1 = NULL;
    inputTee(root1);

    Node *root2 = NULL;
    inputTee(root2);

    if(isSame(root1, root2))
        cout << "These two binary trees are the same.\n";
    else
        cout << "These two binary trees are not the same\n";
}