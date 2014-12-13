
// Tayseer Edouni
// David Laosen
//stack.h


#ifndef __predictiveParsing__stack__
#define __predictiveParsing__stack__

#include <iostream>
#include <string>
using namespace std;

class STACK
{
private:
    struct NODE
    {
        
        string value;
        NODE* next;
        
    };
    
    
    NODE* list;
    
public:
    STACK();
    
    bool isEmpty();
    
    
    string pop();
    
    void insert(string x);
    
    void display();
    

    
};

#endif /* defined(__predictiveParsing__stack__) */
