#include <iostream>
#include "Queuecpp.h"
#include "Stackcpp.h"
using namespace std;
// Create a class for tree
template <class T>
class Tree
{
public:
    Node<T> *root;
    Tree();
    void createTree();
    void Preorder(Node<T> *p);
    void Preorder() { Preorder(root); }
    void Preorder_non_recursive(Node<T> *p);
    void Inorder(Node<T> *p);
    void Inorder() { Inorder(root); }
    void Inorder_non_recursive(Node<T> *p);
    void Postorder(Node<T> *p);
    void Postorder() { Postorder(root); }
    void Postorder_non_recursive(Node<T> *p);
    void Levelorder(Node<T> *p);
    void Levelorder() { Levelorder(root); }
    int Height(Node<T> *root);
    int count(Node<T> *root);
    int count0(Node<T> *root);
    int count1(Node<T> *root);
    int count2(Node<T> *root);
    void binarySearchTree(Node<T> *root, T key);
    void binarySearchTree_non_recursive(T key);
    void insert(T key);
    void CreateBST();
    void deleteNode(T key);
};
// Create a constructor for tree
template <class T>
Tree<T>::Tree()
{
    root = NULL;
}
// Create a function to create a tree
template <class T>
void Tree<T>::createTree()
{
    Node<T> *p, *t;
    T x;
    Queue<Node<T> *> q(100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node<T>;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
// Create a function to display the tree in preorder
template <class T>
void Tree<T>::Preorder(Node<T> *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
// Create a function to display the tree in preorder non recursively
template <class T>
void Tree<T>::Preorder_non_recursive(Node<T> *p)
{
    Stack<Node<T> *> stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            cout << p->data << " ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            p = p->rchild;
        }
    }
}
// Create a function to display the tree in inorder
template <class T>
void Tree<T>::Inorder(Node<T> *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
// Create a function to display the tree in inorder non recursively
template <class T>
void Tree<T>::Inorder_non_recursive(Node<T> *p)
{
    Stack<Node<T> *> stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}
// Create a function to display the tree in postorder
template <class T>
void Tree<T>::Postorder(Node<T> *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}
// Create a function to display the tree in postorder non recursively
template <class T>
void Tree<T>::Postorder_non_recursive(Node<T> *p)
{
    long int temp;
    Stack<long int> stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            stk.push((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = stk.pop();
            if (temp > 0)
            {
                stk.push(-temp);
                p = ((Node<T> *)temp)->rchild;
            }
            else
            {
                cout << ((Node<T> *)-temp)->data << " ";
                p = NULL;
            }
        }
    }
}
// Create a function to display the tree in levelorder
template <class T>
void Tree<T>::Levelorder(Node<T> *p)
{
    Queue<Node<T> *> q(100);
    cout << root->data << " ";
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}
// Create a function to calculate the height of the tree
template <class T>
int Tree<T>::Height(Node<T> *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
// Create a function to calculate the number of nodes in the tree
template <class T>
int Tree<T>::count(Node<T> *root)
{
    if (root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}
// Create a function to calculate the number of nodes with 0 child in the tree
template <class T>
int Tree<T>::count0(Node<T> *root)
{
    if (root)
    {
        if (root->lchild == NULL && root->rchild == NULL)
            return 1;
        else
            return count0(root->lchild) + count0(root->rchild);
    }
    return 0;
}
// Create a function to calculate the number of nodes with 1 child in the tree
template <class T>
int Tree<T>::count1(Node<T> *root)
{
    if (root)
    {
        if ((root->lchild == NULL && root->rchild != NULL) || (root->lchild != NULL && root->rchild == NULL))
            return 1;
        else
            return count1(root->lchild) + count1(root->rchild);
    }
    return 0;
}
// Create a function to calculate the number of nodes with 2 child in the tree
template <class T>
int Tree<T>::count2(Node<T> *root)
{
    if (root)
    {
        if (root->lchild != NULL && root->rchild != NULL)
            return 1;
        else
            return count2(root->lchild) + count2(root->rchild);
    }
    return 0;
}
// Create a function to search an element in the tree
template <class T>
void Tree<T>::binarySearchTree(Node<T> *p, T key)
{
    if (p == NULL)
    {
        cout << "Element not found" << endl;
        return;
    }
    if (key == p->data)
    {
        cout << "Element found" << endl;
        return;
    }
    if (key < p->data)
        binarySearchTree(p->lchild, key);
    else
        binarySearchTree(p->rchild, key);
}
// Create a function to search an element in the tree non recursively
template <class T>
void Tree<T>::binarySearchTree_non_recursive(T key)
{
    Node<T> *p = root;
    while (p != NULL)
    {
        if (key == p->data)
        {
            cout << "Element found" << endl;
            return;
        }
        else if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    cout << "Element not found" << endl;
}
// Create a function to insert an element in the tree
template <class T>
void Tree<T>::insert(T key)
{
    Node<T> *t = root;
    Node<T> *r = NULL;
    if (root == NULL)
    {
        root = new Node<T>;
        root->data = key;
        root->lchild = root->rchild = NULL;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    t = new Node<T>;
    t->data = key;
    t->lchild = t->rchild = NULL;
    if (key < r->data)
        r->lchild = t;
    else
        r->rchild = t;
}
// Create a function for creating a Binary Search Tree
template <class T>
void Tree<T>::CreateBST()
{
    int i;
    T x;
    cout << "Enter number of nodes: ";
    cin >> i;
    while (i > 0)
    {
        cout << "Enter the element to be inserted: ";
        cin >> x;
        insert(x);
        i--;
    }
}
// Create a function to delete an element from the tree
template <class T>
void Tree<T>::deleteNode(T key)
{
    Node<T> *p = root;
    Node<T> *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
            break;
        q = p;
        if (key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (p == NULL)
        return;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        else if (p == q->lchild)
            q->lchild = NULL;
        else
            q->rchild = NULL;
        delete p;
    }
    else if (p->lchild != NULL && p->rchild == NULL)
    {
        if (p == root)
            root = p->lchild;
        else if (p == q->lchild)
            q->lchild = p->lchild;
        else
            q->rchild = p->lchild;
        delete p;
    }
    else if (p->lchild == NULL && p->rchild != NULL)
    {
        if (p == root)
            root = p->rchild;
        else if (p == q->lchild)
            q->lchild = p->rchild;
        else
            q->rchild = p->rchild;
        delete p;
    }
    else
    {
        Node<T> *r = p->rchild;
        while (r->lchild)
            r = r->lchild;
        p->data = r->data;
        deleteNode(r->data);
    }
}
int main()
{
    Tree<int> t;
    t.CreateBST();
    cout << "Preorder: ";
    t.Preorder();
    cout << "Inorder: ";
    t.Inorder();
    cout << endl;

    return 0;
}