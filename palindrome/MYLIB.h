//
//  MYLIB.h
//  AssignmentSevenExOne
//
//  Created by Tayseer Edouni on 3/17/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

//USED FOR HOMEWORK ASSIGNMENT 7

#ifndef AssignmentSevenExOne_MYLIB_h
#define AssignmentSevenExOne_MYLIB_h

#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Queue
{
private:
    struct NODE
    {
        T info;
        NODE* next;
    };
    
    NODE *front, *rear;
    
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    
    void pushQ( T x)
    {
        NODE *p = new NODE;
        
        p->info=x;
        p->next=NULL;
        
        if (front==NULL)
        {
            front=p;
            rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }
    
    bool emptyQ()
    {
        return (front==NULL)? true : false;
        
    }

    T popQ()
    {
        NODE *p = front;
        T x;
        
        x= front->info;
        
        front=front->next;
        
        delete (p);
        
        return x;
    }
    
    
    ~Queue()
    {
        
    }
    
};

// NEW CLASS
template <class T>
class Stack
{
private:
    struct NODE
    {
        T info;
        NODE* next;
    };
    
    NODE *list;
    
public:
    Stack()
    {
        list=NULL;
    }
    
    void pushS(T x)
    {
        NODE *p = new NODE;
        p->info=x;
        
        if (list == NULL)
        {
            p->next=NULL;
            list=p;
        }
        else
        {
            p->next=list;
            list=p;
        }
    }
    
    T popS()
    {
        NODE *p = list;
        T x;
        
        x = list->info;
        
        list=list->next;
        delete p;
        
        return x;
    }
    
    bool emptyS()
    {
        return (list == NULL) ? true : false;
    }
};

// NEW CLASS

template <class T>
class Functionfx
{
private:
    struct NODE
    {
        T coeff;
        T power;
        
        NODE* next;
    };
    
    NODE *front, *rear;
    
public:
    Functionfx()
    {
        front = NULL;
        rear = NULL;
    }
    
    void pushQ( T x, T y)
    {
        NODE *p = new NODE;
        
        p->coeff=x;
        p->power=y;
        
        p->next=NULL;
        
        if (front==NULL)
        {
            front=p;
            rear=p;
        }
        else
        {
            rear->next=p;
            rear=p;
        }
    }
    
    bool emptyQ()
    {
        return (front==NULL)? true : false;
        
    }
    
    T returnCoeff()    //MUST BE CALLED FIRST
    {
        NODE *p = front;
        T x;
        
        x= front->coeff;
        
        
        return x;
    }
    
    T popPow()     //Called second. Deletes node
    {
        NODE *p=front;
        T y;
        y=front->power;
        
        front=front->next;
        
        delete p;
    }
    
    void display()
    {
        NODE *p= front;
        cout<<"F(X)=";
        while (p!=NULL)
        {
            if(p->coeff== 0 && p->power==0)
                break;
            else if (p->power==0)
                    cout<<p->coeff<<"+";
            else {
                
            cout<<p->coeff<<"X^"<<p->power<<"+";
            p=p->next;
            }
        }
        
        printf("\b \n");
    }
    
    void computeTotal( T x)
    {
        NODE *p=front;
        
        T total=0;
        
        while (p!=NULL)
        {
            total+=p->coeff*pow(x, p->power);
            p=p->next;
        }
        
        cout<<"F("<<x<<")="<<total<<endl;
    }
    
};

#endif
