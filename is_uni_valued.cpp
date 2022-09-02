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

void inputTree(Node *&root)
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

bool is_unival(Node *root)
{
    if (root == NULL)
        return true;

    if (root->left != NULL && root->val != root->left->val)
        return false;

    if (root->right != NULL && root->val != root->right->val)
        return false;

    return is_unival(root->left) && is_unival(root->right);
}

int main(void)
{
    Node *root = NULL;
    inputTree(root);

    cout << is_unival(root);
}