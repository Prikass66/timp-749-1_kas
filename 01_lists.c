#include <stdio.h>
#include <stdlib.h>

struct list
{
    struct node *head;
    struct node *tail;
}list;

struct node
{
    int val;
    struct node *next;
}node;

void init(struct list* l)
{
    l->head = NULL;
    l->tail = NULL;
}

void clean(struct list* l)
{
    struct node* inter1;
    struct node* inter2;
    inter1 = l->head;
    while (inter1->next != NULL)
    {
        inter2 = inter1;
        inter1 = inter1->next;
        free(inter2);
    }
    free(inter1);
    init(l);
}
int is_empty(struct list* l)
{
    if (l->head == NULL) return 0;
    else return 1;
}

struct node* find(struct list* l, int V)
{
    struct node* inter;
    inter = l->head;
    while (inter != NULL)
    {
        if (inter->val == V) return inter;
        inter = inter->next;
    }
    return NULL;
}

int push_back(struct list* l, int V)
{
    struct node* Node;
    Node = (struct node*)malloc(sizeof(struct node));
    Node->val = V;
    Node->next = NULL;
    if (l->head == NULL)
    {
        l->head = Node;
    }
    else if (l->head->next == NULL)
    {
        l->head->next = Node;
    }
    else
    {
        l->tail->next = Node;
    }
    l->tail = Node;
    return 0;
}

int push_front(struct list* l, int V)
{
    struct node* Node;
    Node = (struct node*)malloc(sizeof(struct node));
    Node->val = V;
    if (l->head == NULL)
    {
        Node->next = NULL;
        l->tail = Node;
    }
    else
    if (l->head->next == NULL) Node->next = l->tail;
    else Node->next = l->head;
    l->head = Node;
    return 0;
}

int insert_after(struct list* l, int n, int V)
{
    int i;
    struct node* inter;
    inter = l->head;
    for (i = 1; i < n; i++)
    {
        inter = inter->next;
        if (inter->next == l->tail)
        {
            push_back(l, V);
            return 0;
        }
    }
    struct node* Node;
    Node = (struct node*)malloc(sizeof(struct node));
    Node->val = V;
    Node->next = inter->next;
    inter->next = Node;
    return 0;
}

int remove_node(struct list* l, int V)
{
    struct node* inter1;
    struct node* inter2;
    inter1 = l->head;
    while (inter1->val != V)
    {
        if (inter1 == l->tail) return 0;
        inter2 = inter1;
        inter1 = inter1->next;
    }
    if (inter1 == l->head) l->head = inter1->next;
    else if (inter1 == l->tail)
    {
        inter2->next = NULL;
        l->tail = inter2;
    }
    else inter2->next = inter1->next;
    free(inter1);
    return 0;
}

void print(struct list* l)
{
    if (is_empty(l) == 1)
    {
        struct node* inter;
        inter = l->head;
        while (inter->next != NULL)
        {
            printf("%d ", inter->val);
            inter = inter->next;
        }
        printf("%d\n", l->tail->val);
    }
}

int main()
{
    int n, x, i, k1, k2, k3;
    struct list a;
    struct node* b;
    init(&a);
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &x);
        push_back(&a, x);
    }
    print(&a);
    scanf("%d %d %d", &k1, &k2, &k3);
    b = find(&a, k1);
    if (b != NULL)
    {
        k1 = 1;
    }
    else
    {
        k1 = 0;
    }
    b = find(&a, k2);
    if (b != NULL)
    {
        k2 = 1;
    }
    else
    {
        k2 = 0;
    }
    b = find(&a, k3);
    if (b != NULL)
    {
        k3 = 1;
    }
    else
    {
        k3 = 0;
    }
    printf("%d %d %d\n", k1, k2, k3);
    scanf("%d", &x);
    push_back(&a, x);
    print(&a);
    scanf("%d", &x);
    push_front(&a, x);
    print(&a);
    scanf("%d %d", &n, &x);
    insert_after(&a, n, x);
    print(&a);
    scanf("%d", &x);
    remove_node(&a, x);
    print(&a);
    clean(&a);
    return 0;
}