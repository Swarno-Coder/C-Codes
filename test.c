#include<stdio.h>

void main()
{
    typedef struct Node{
        int data;
        struct node *link;
    } node;

    node * createNode()
    {
        node *p;
        p = (node*)malloc(sizeof(struct node));
        p->link= NULL;
        printf("\n Enter the data: ");
        scanf("%d", &p->data);
        return p;
    }
    void insertatfirst(node **START)
    {
        node *P;
        p=createNode();
        if(*START==NULL)
            *START=p;
        else
        {
            p->link = *START;
            *START=p;
        }
    }
    void insertatend(node **START)
    {
        node *P,*q;
        p=createNode();
        if(*START==NULL)
            *START=p;
        else
        {
            q = *START;
            while(q->next!= NULL)
            {
                q=q->next;
            }
            q->next=p;
        }
    }
    void insertafter(node **START) 
    {
        node *P,*q,*r;
        int key;
        printf("\n Enter key: ");
        scanf("%d",&key);
        p=createNode();

        if(*START==NULL)
            *START=p;
        else
        {
            q = *START;
            while(q!=NULL && q->data!=key)
            {
                r=q;
                q=q->next;
            }
            if(p!= NULL)
            {
                p->next=q->next;
                q->next =p;
            }
            else
            {
                r->next=p;
            }
    }
    
}