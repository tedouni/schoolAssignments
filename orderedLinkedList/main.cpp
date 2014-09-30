//
//  main.cpp
//  AssignmentSixExThree
//
//  Created by Tayseer Edouni on 3/11/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include <iostream>
#include "OrderedLinkedList.h"
#include <ctime>

int main(int argc, const char * argv[])
{
    OrderedLinkedList ol;

    for (int i=0; i<6; ++i)
    {
        int x= rand()%100;
        
        ol.insert(x);
    }
   
    //PART 1,2 & 3  see display() member function in cpp file
    ol.display();
    
    return 0;
}

