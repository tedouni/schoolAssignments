//
//  main.cpp
//
//Tayseer Edouni
//David Laosen
/*
    Given L=aa*b+bb* 
    Write a program for the FA of the language to determine whether the following words are accepted or rejcted
    w1=aaab 
    w2=bcbbca
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{

    char cont;


    do {
        
        cout<<"Please enter a word to see if it is rejected or accept, end word with $: ";
        string word;
        cin>>word;
        int states[5][2] = { {2,1} , {4,1,}, {2,3}, {4,4} , {4,4} };
        int state = 0;
        int col = 0;
        
        for (int i =0; i<word.length(); ++i)
        {
            switch (word[i])
            {
                case 'a':
                    col = 0;
                    state = states[state][col];
                    
                    break;
                    
                case 'b':
                    col = 1;
                    state = states[state][col];
                    
                    break;
                    
                case '$':
                    if (state == 1 || state == 3)
                        cout<<word<<" is accepted\n";
                    else cout<<word<<" is rejected\n";
                    break;
                    
                    
                default:
                    break;
            }
            
        }
        
        cout<<"Would you like to continue (Y/N): ";
        cin>>cont;


    } while (cont == 'Y');
    
        return 0;
}

