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

void average_level(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int sum = 0, count = 0;
        queue<Node *> temp;

        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            sum += n->val;
            count++;

            if (n->left != NULL)
                temp.push(n->left);

            if (n->right != NULL)
                temp.push(n->right);
        }
        q = temp;
        cout << (sum * 1.0 / count) << " ";
    }
}

int main(void)
{
    Node *root = NULL;
    inputTree(root);

    average_level(root);
}