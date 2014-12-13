
// Tayseer Edouni
// David Laosen
//stack.cpp


#include "stack.h"


STACK::STACK()
    {
        list = NULL;
        
    }
    
bool STACK::isEmpty()
    {
        
        return (list == NULL) ? true : false;
        
    }
    
string STACK::pop()
    {
        
        NODE *p = list;
        string x;
        x = p->value;
        list = list->next;
        delete p;
        return x;
    }
    
void STACK::insert(string x)
    {
        
        NODE *p = new NODE;
        p->value = x;
        
        if (list == NULL)
        {
            list = p;
            p->next = NULL;
        }
        
        else
        {
            
            p->next = list;
            list = p;
        }
        
        
    }
    
void STACK::display()
    {
        NODE *p = list;
        cout<<"Read left to right"<<endl;
        
        while( p != NULL)
        {
            cout<<p->value<<" ";
            p= p->next;
        }
        cout<<endl;
    }


    
