
// Tayseer Edouni
// David Laosen
//main.cpp


#include "stack.h"
#include "predictiveParsing.h"
#include "format.h"
#include "translateLanguage.h"



int main()
{
    formatTextFile();       //Format finalv1.txt into finalv2.txt

    bool okayToTranslate = isSyntaxAccepted();
    
    if (okayToTranslate)
    {
        cout<<"\n\n\nSYNTAX ACCEPTED\n";
        translateProgram();
    }
    else
    {
        cout<<"\n\n\nSYNTAX NOT ACCEPTED\n";
  
    }


    
    
}