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

void zigzag_order(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    currentLevel.push(root);

    bool left_to_right = true;

    while (!currentLevel.empty())
    {
        Node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp != NULL)
        {
            cout << temp->val << " ";

            if (left_to_right == true)
            {
                if (temp->left != NULL)
                    nextLevel.push(temp->left);

                if (temp->right != NULL)
                    nextLevel.push(temp->right);
            }
            else
            {
                if (temp->right != NULL)
                    nextLevel.push(temp->right);

                if (temp->left != NULL)
                    nextLevel.push(temp->left);
            }
        }

        if (currentLevel.empty())
        {
            left_to_right = !left_to_right;
            swap(currentLevel, nextLevel);
        }
    }
}

int main(void)
{
    Node *root = NULL;
    inputTee(root);

    zigzag_order(root);
}