//
//  OrderedLinkedList.h
//  AssignmentSixExThree
//
//  Created by Tayseer Edouni on 3/11/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __AssignmentSixExThree__OrderedLinkedList__
#define __AssignmentSixExThree__OrderedLinkedList__

#include <iostream>
using namespace std;
class OrderedLinkedList
{
private:
    struct node
    {
        int info;
        node *next;
    };
    node *list;
    
public:
    OrderedLinkedList();
    void insert(int x);
    void display();
    
};

#endif /* defined(__AssignmentSixExThree__OrderedLinkedList__) */
