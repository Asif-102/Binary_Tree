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

int traverse(Node *root, int *tilt)
{
    if(root == NULL)
        return 0;
    
    int left = traverse(root->left, tilt);
    int right = traverse(root->right, tilt);

    *tilt += abs(left - right);

    return left + right + root->val;
}

int findTilt(Node* root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}

int main(void)
{
    Node *root = NULL;
    inputTee(root);

    int result = findTilt(root);

    cout << result;
}