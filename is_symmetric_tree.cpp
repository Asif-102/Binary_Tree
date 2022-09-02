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

bool isMirror(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if(root1 != NULL && root2 != NULL && root1->val == root2->val)
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);

    return false;
}

bool isSymmetric(Node *root)
{
    return isMirror(root, root);
}

int main(void)
{
    Node *root = NULL;
    inputTee(root);

    cout << isSymmetric(root);
}