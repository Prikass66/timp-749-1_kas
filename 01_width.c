#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
    struct node * parent;
} node;

typedef struct tree
{
    struct node * root;
    int count;
} tree;

void init(tree * t)
{
    tree * new_t = malloc(sizeof new_t);
    new_t->root = NULL;
    new_t->count = 0;
    t = new_t;
}

int find(tree* t, int value, node* n)
{
    struct node * n2;
    n2 = t->root;
    if (t->root == NULL) return 1;
    while (1)
    {
        if (n2 == NULL) return 1;
        else if (n2->data == value)
        {
            n->data = n2->data;
            n->left = n2->left;
            n->right = n2->right;
            n->parent = n2->parent;
            return 0;
        }
        else if (value > n2->data) n2 = n2->right;
        else n2 = n2->left;
    }
}

int insert(tree* t, int value)
{
    struct node * n, ** nn, * last_n = NULL;
    struct node * e_n;
    e_n = malloc(sizeof * e_n);
    int err = find(t, value, e_n);
    if (err == 0) return 1;
    nn = &t->root;
    n = t->root;
    while (1){
        if (n == NULL)
        {
            n = *nn = malloc(sizeof * n);
            if (n != NULL)
            {
                n->data = value;
                n->left = NULL;
                n->right = NULL;
                n->parent = last_n;
                t->count++;
                return 0;
            }
            else return 2;
        }
        last_n = n;
        if (value > n->data)
        {
            nn = &n->right;
            n = n->right;
        }
        else
        {
            nn = &n->left;
            n = n->left;
        }
    }
}

int deepness(struct node * n, int deep)
{
    if (n == NULL) return deep;
    int d1 = deepness(n->left, deep + 1);
    int d2 = deepness(n->right, deep + 1);
    return (d1 > d2) ? d1 : d2;
}

void printNode(struct node * n, int current, int deep)
{
    if (current == deep)
    {
        if (n != NULL) printf("%d ", n->data);
    }
    else if (n != NULL)
    {
        printNode(n->left, current + 1, deep);
        printNode(n->right, current + 1, deep);
    }
    else
    {
        printNode(n, current + 1, deep);
        printNode(n, current + 1, deep);
    }
}

void printTree(struct node * n)
{
    int m = deepness(n, 0);
    int flag = 0;
    for (int i = 1; i <= m; i++)
    {
        if (flag > 0) printf("");
        else flag++;
        printNode(n, 1, i);
    }
}

int main()
{
    struct tree * t = malloc(sizeof t);
    init(t);
    int a;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &a);
        insert(t, a);
    }
    printTree(t->root);
    printf("\n");
    return 0;
}