#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prv, *nxt;
    Node(int _data)
    {
        data = _data;
        prv = NULL;
        nxt = NULL;
    }
};
void newNode(int pos, int data, int sz, Node *&head)
{
    Node *newNode = new Node(data);
    if (pos == 1)
    {
        newNode->nxt = head;
        head->prv = newNode;
        head = newNode;
        sz++;
        return;
    }
    if (head == NULL)
    {
        head = newNode;
        sz++;
        return;
    }
    if (pos == sz + 1)
    {
        Node *temp = head;
        while (temp->nxt != NULL)
            temp = temp->nxt;
        newNode->nxt = temp;
        temp->nxt = newNode;
        sz++;
        return;
    }
    int count = 1;
    Node *temp = head;
    while (count < pos)
    {
        temp = temp->nxt;
        count++;
    }
    newNode->nxt = temp->nxt;
    newNode->prv = temp->prv;
    newNode->nxt->prv = newNode;
    temp->nxt = newNode;
    sz++;
    return;
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    head->nxt = second;
    second->prv = head;
    second->nxt = third;
    third->prv = second;
    int size = 3;
    cout << "Linked List: ";
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->nxt;
    }
    cout << endl;
    newNode(2, 10, size, head);
    delete current;
    current = NULL;
    current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->nxt;
    }
    return 0;
}