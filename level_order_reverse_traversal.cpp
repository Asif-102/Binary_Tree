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

void level_order_reverse(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);

    stack<Node *> st;

    while (!q.empty())
    {
        Node *presentNode = q.front();
        q.pop();
        // cout << presentNode->val << " ";
        st.push(presentNode);
        
        if (presentNode->right != NULL)
            q.push(presentNode->right);

        if (presentNode->left != NULL)
            q.push(presentNode->left);
    }

    while(!st.empty())
    {
        cout << st.top()->val << " ";
        st.pop();
    }
}

int main(void)
{
    Node *root = NULL;
    inputTee(root);

    level_order_reverse(root);
}