//
//  main.cpp
//  AssignmentSevenExOne
//
//  Created by Tayseer Edouni on 3/17/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include <iostream>
#include "MYLIB.h"
#include <string>
#include <ctype.h>

using namespace std;


int main(int argc, const char * argv[])
{
    
    char choice;
    do
    {
        int counterOne=0,counterTwo=0;
        
        cout<<"Enter a phrase to see if it is a palindrome (end with '.') : ";
        char c;
        Queue<char> LeftToRight;
        Stack<char> RightToLeft;
        
        while (cin>>c && c!='.')
        {
            LeftToRight.pushQ(c);
            RightToLeft.pushS(c);
            counterOne++;
        }
        
        while ( !LeftToRight.emptyQ() && !RightToLeft.emptyS() )
        {
            char LTR = LeftToRight.popQ();
            char RTL = RightToLeft.popS();
            LTR=tolower(LTR);
            RTL=tolower(RTL);
            
            if (LTR == RTL)
            counterTwo++;
            
            
        }
        if (counterOne == counterTwo)
        cout<<"Is a PALINDROME\n";
        
        else cout<<"Not a PALINDROME\n";
        
        cout<<"Continue (y/n)? ";
        cin>>choice;
        
        
    } while (choice == 'y' || choice == 'Y' );
    return 0;
}

