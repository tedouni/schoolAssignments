//
//  main.cpp
//  predictiveTable
//
//  Tayseer Edouni, David Laosen
//


#include <string>
#include <iostream>
using namespace std;

class STACK
{
private:
    struct NODE
    {
        
        char value;
        NODE* next;
        
    };
    
    NODE* list;
    
public:
    STACK()
    {
        list = NULL;
        
    }
    
    bool isEmpty()
    {
        
        return (list == NULL) ? true : false;
        
    }
    
    char pop()
    {
        
        NODE *p = list;
        char x;
        x = p->value;
        list = list->next;
        delete p;
        return x;
    }
    
    void insert(char x)
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
    
    void display()
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
};

void testIfValid(string fromTable)  //Test if valid entry in Table, if not then word doesn't exist
{
    if(fromTable == "NULL")
    {
        cout<<" not accepted.\n";
        exit(0);
    }
}

void iterateToPush(STACK &stack , string a)
{
    for (int i =0 ; i<a.length(); ++i)
    {
        char x = a[i];
        stack.insert(x);
    }
}

void isWordAccepted(string testOne)
{
    
    string state[5][8] =
    {   // a        +            -           *           /             (          )          $
        /*E*/   { "QT"  , "NULL"    , "NULL"    , "NULL"    , "NULL"    , "QT"      , "NULL"    , "NULL"}   ,
        /*Q*/   {"NULL" , "QT+"     , "QT-"     , "NULL"    , "NULL"    , "NULL"    , "alpha"   , "alpha"}      ,
        /*T*/   {"RF"   , "NULL"    , "NULL"    , "NULL"    , "NULL"    , "RF"      , "NULL"    , "NULL"}   ,
        /*R*/   {"NULL" , "alpha"   , "alpha"   , "RF*"     , "RF/"     , "NULL"    , "alpha"   , "alpha"}      ,
        /*F*/   {"a"    , "NULL"    , "NULL"    , "NULL"    , "NULL"    , ")E("     , "NULL"    , "NULL"}
    };
    
    STACK one;
    one.insert('$');
    one.insert('E');
    bool continueToMatch = true;
    string tempString;
    cout<<"TESTING for word "<<testOne<<endl;
    for (int i =0; i<testOne.length(); ++i)   //iterate through string to get char
    {
        char tempChar = testOne[i];
        int tempCharValue = NULL;            //value associated to char to be used for table
        
        switch (tempChar)
        {
            case 'a':
                tempCharValue = 0;
                break;
            case '+':
                tempCharValue = 1;
                break;
            case '-':
                tempCharValue = 2;
                break;
            case '*':
                tempCharValue = 3;
                break;
            case '/':
                tempCharValue = 4;
                break;
            case '(':
                tempCharValue = 5;
                break;
            case ')':
                tempCharValue = 6;
                break;
            case '$':
                tempCharValue = 7;
                break;
                
            default:
                break;
        }
        
        continueToMatch = true;
        while(continueToMatch)
        {
            
            char x = one.pop();
            
            if(x == tempChar)       //Match found
            {
                cout<<"MATCH "<<x<<" = "<<tempChar<<endl;
                one.display();
                continueToMatch = false;
            }
            
            switch (x)
            {
                case 'E':
                    tempString = state[0][tempCharValue];
                    testIfValid(tempString);
                    if (tempString != "alpha")
                        iterateToPush(one,tempString);
                    
                    break;
                    
                case 'Q':
                    tempString = state[1][tempCharValue];
                    testIfValid(tempString);
                    if (tempString != "alpha")
                        iterateToPush(one,tempString);
                    break;
                    
                case 'T':
                    tempString = state[2][tempCharValue];
                    testIfValid(tempString);
                    if (tempString != "alpha")
                        iterateToPush(one,tempString);
                    break;
                    
                case 'R':
                    tempString = state[3][tempCharValue];
                    testIfValid(tempString);
                    if (tempString != "alpha")
                        iterateToPush(one,tempString);
                    break;
                    
                case 'F':
                    tempString = state[4][tempCharValue];
                    testIfValid(tempString);
                    if (tempString != "alpha")
                        iterateToPush(one,tempString);
                    break;
                    
                case '$':
                    cout<<testOne<<" is accepted\n";
                    continueToMatch = false;
                    break;
                    
                default:
                    break;
            }
            
            
        }
        
    }
    
    cout<<endl<<endl;

}

int main()
{


    
    string testOne = "(a+a)*a$";
    isWordAccepted(testOne);
    string testTwo = "a*(a-a)$";
    isWordAccepted(testTwo);
    string testThree = "a(a+a)";
    isWordAccepted(testThree);
    
    
    
   
    return 0;
}





