//
//  OrderedLinkedList.cpp
//  AssignmentSixExThree
//
//  Created by Tayseer Edouni on 3/11/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "OrderedLinkedList.h"


OrderedLinkedList::OrderedLinkedList()
{
    list=NULL;
}

void OrderedLinkedList:: insert(int x)
{
    node* p=list, *q=list, *r;
    
    r=new node;
    r->info=x;
    r->next=NULL;
    
    while (p!=NULL && p->info<x)
    {
        q=p;
        p=p->next;
        
    }
    
    if (p==list)
    {
        list=r;
        r->next=p;
    }else if(p==NULL)
    {
        q->next=r;
    } else
    {
        r->next=p;
        q->next=r;
    }
    
}
void OrderedLinkedList:: display()
{
    node *p=list;
    int odd,even,total;
    odd=even=total=0;
    
    
    cout<<"OList-->";
    while (p!=NULL)
    {
        total+=p->info;
        if(p->info %2 ==0 )
            even++;
        else odd++;
        
        cout<<p->info<<"-->";
        p=p->next;
    }
    cout<<"NULL\n\n";
    
    cout<<"There are "<<even<<" even nodes and "<<odd<<" odd nodes in this OList\n\n";
    
    cout<<"The average of all of the numbers in this OList is : "<<total/6<<endl;
}