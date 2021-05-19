#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} node;

typedef struct list {
    struct node *head;
    struct node *tail;
} list;


void init(list *l)
{
    l->head = NULL;
    l->tail = NULL;
}

void clean(list *l)
{
    node* p1 = l->head;
    node* p2;
    while (p1->next != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
    free(p1);
    init(l);
}

bool is_empty(list *l)
{
    if (l->head == NULL)
        return 1;
    else
        return 0;
}

node *find(list *l, int V)
{
    node* p = l->head;
    while (p->next != NULL)
    {
        if (p->val == V) return p;
        p = p->next;
    }
    if (p->val == V) return p;
    return NULL;
}

int push_back(list *l, int V)
{
    node* Nnode;
    Nnode = (node*)malloc(sizeof(node));
    Nnode->val = V;
    Nnode->next = NULL;
    if (is_empty(l))
    {
        l->head = Nnode;
        l->tail = Nnode;
        Nnode->prev = NULL;
    }
    else
    {
        Nnode->prev = l->tail;
        l->tail->next = Nnode;
        l->tail = Nnode;
    }
    return 0;
}

int push_front(list *l, int V)
{
    node* Nnode;
    Nnode = (node*)malloc(sizeof(node));
    Nnode->val = V;
    Nnode->prev = NULL;
    if (is_empty(l))
    {
        l->head = Nnode;
        l->tail = Nnode;
        Nnode->next = NULL;
    }
    else
    {
        Nnode->next = l->head;
        l->head->prev = Nnode;
        l->head = Nnode;
    }
    return 0;
}

node *findNode(list* l, int n)
{
    int i;
    node *p = l->head;
    for (i = 1; i < n; i++)
        p = p->next;
    return p;
}

int insert_after(list *l, node *n, int V)
{
    {
        node* Nnode;
        Nnode = (node*)malloc(sizeof(node));
        Nnode->val = V;
        Nnode->prev = n;
        if (n->next == NULL){
            Nnode->next = NULL;
            n->next = Nnode;
            l->tail = Nnode;
        }
        else{
            Nnode->next = n->next;
            Nnode->next->prev = Nnode;
            n->next = Nnode;
        }
        return 0;
    }
}

int insert_before(list *l, node *n, int V)
{
    if (n->prev == NULL){
        push_front(l, V);
        return 0;
    }
    node* Nnode;
    Nnode = (node*)malloc(sizeof(node));
    Nnode->next = n;
    Nnode->prev = n->prev;
    Nnode->prev->next = Nnode;
    n->prev = Nnode;
    Nnode->val = V;
    return 0;
}

int remove_first(list *l, int V)
{
    node* p1 = l->head;
    node* p2;
    while ((p1->val != V)&&(p1->next != NULL))
    {
        p2 = p1;
        p1 = p1->next;
    }
    if ((p1->next == NULL)&&(p1->val != V)) return 1;
    else if ((p1->next == NULL)&&(p1->val == V))
    {
        p2->next = NULL;
        l->tail = p2;
    }
    else if (p1 == l->head) {
        l->head = p1->next;
        p1->next->prev = NULL;
    }
    else{
        p2->next = p1->next;
        p1->next->prev = p2;
    }
    free(p1);
    return 0;
}

int remove_last(list *l, int V)
{
    node *p1 = l->tail;
    node *p2;
    while ((p1->val != V) && (p1->prev != NULL))
    {
        p2 = p1;
        p1 = p1->prev;
    }
    if ((p1->prev == NULL) && (p1->val != V)) return 1;
    else if ((p1->prev == NULL) && (p1->val == V))
    {
        p2->prev = NULL;
        l->head = p2;
    }
    else if (p1 == l->tail)
    {
        l->tail = p1->prev;
        p1->prev->next = NULL;
    }
    else
    {
        p2->prev = p1->prev;
        p1->prev->next = p2;
    }
    free(p1);
    return 0;
}

void print(list *l)
{
    node *p = l->head;
    while (p->next != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("%d", p->val);
    printf("\n");
}

void print_invers(list *l)
{
    node *p = l->tail;
    while (p->prev != NULL)
    {
        printf("%d ", p->val);
        p = p->prev;
    }
    printf("%d", p->val);
    printf("\n");
}

int main()
{
    list l;
    node* b;
    int n, i, x, k1, k2, k3;
    init(&l);
    (void)scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        (void)scanf("%d", &x);
        push_back(&l, x);
    }
    print(&l);
    (void)scanf("%d %d %d", &k1, &k2, &k3);
    b = find(&l, k1);
    if (b != NULL) k1 = 1;
    else k1 = 0;
    b = find(&l, k2);
    if (b != NULL) k2 = 1;
    else k2 = 0;
    b = find(&l, k3);
    if (b != NULL) k3 = 1;
    else k3 = 0;
    printf("%d %d %d\n", k1, k2, k3);
    (void)scanf("%d", &x);
    push_back(&l, x);
    print_invers(&l);
    (void)scanf("%d", &x);
    push_front(&l, x);
    print(&l);
    (void)scanf("%d %d", &n, &x);
    b = findNode(&l, n);
    insert_after(&l, b, x);
    print_invers(&l);
    (void)scanf("%d %d", &n, &x);
    b = findNode(&l, n);
    insert_before(&l, b, x);
    print(&l);
    (void)scanf("%d", &x);
    remove_first(&l, x);
    print_invers(&l);
    (void)scanf("%d", &x);
    remove_last(&l, x);
    print(&l);
    clean(&l);
    return 0;
}