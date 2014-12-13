
// Tayseer Edouni
// David Laosen
// predictiveParsing.cpp


#include "predictiveParsing.h"


/*
 prog           B
 identifier     I
 identA         A
 X              X
 dec-list       D
 dec            C
 Z              Z
 type           T
 stat-list      L
 Q              Q
 stat           S
 write          G
 assign         H
 expr           E
 exprPrime      P
 term           R
 termPrime      Y
 factor         F
 number         N
 numberB        K
 sign           W
 digit          V
 id             U
 
 */


string STATE[23][32] =
{
    //PROGRAM	VAR	BEGIN	END.	INTEGER	WRITE	(	)	=	;	,	:	*	/	+	-	a	b	c	d	e	0	1	2	3	4	5	6	7	8	9	$
    
    //prog
    {"END. L BEGIN D VAR ; I PROGRAM", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"} ,
    
    //identifier
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","A U","A U","A U","A U","A U","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //identA
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","lamda","lamda","lamda","lamda","lamda","lamda","lamda","lamda","lamda","A X","A X","A X","A X","A X","A X","A X","A X","A X","A X","A X","A X","A X","A X","A X","NULL"},
    
    //X
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","U","U","U","U","U","V","V","V","V","V","V","V","V","V","V","NULL"},
    
    //dec-list
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","; T : C","; T : C","; T : C","; T : C","; T : C","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",},
    
    //dec
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","Z I","Z I","Z I","Z I","Z I","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //Z
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","C ,", "lamda", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",},
    
    
    //type
    {"NULL","NULL","NULL","NULL","INTEGER","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //stat-list
    {"NULL","NULL","NULL","NULL","NULL","Q S","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","Q S","Q S","Q S","Q S","Q S","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //Q
    {"NULL","NULL","NULL","lamda","NULL","L","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","L","L","L","L","L","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //stat
    {"NULL","NULL","NULL","NULL","NULL","G","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","H","H","H","H","H","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",},
    
    //write
    {"NULL","NULL","NULL","NULL","NULL","; ) I ( WRITE","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //assign
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","; E = I","; E = I","; E = I","; E = I","; E = I","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //expr
    {"NULL","NULL","NULL","NULL","NULL","NULL","P R","NULL","NULL","NULL","NULL","NULL","NULL","NULL","P R","P R","P R","P R""P R","P R","P R","P R","P R","P R","P R","P R","P R","P R","P R","P R","NULL"},
    
    //exprPrime
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","lamda","NULL","lamda","NULL","NULL","NULL","NULL","P R +","P R -", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"},
    
    //term
    {"NULL","NULL","NULL","NULL","NULL","NULL","Y F","NULL","NULL","NULL","NULL","NULL","NULL","NULL","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","Y F","NULL"},
    
    //termPrime
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","lamda","NULL","lamda","NULL","NULL","Y F *","Y F /","lamda","lamda","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",},
    
    //factor
    {"NULL","NULL","NULL","NULL","NULL","NULL",") E (","NULL","NULL","NULL","NULL","NULL","NULL","NULL","N","N","I","I","I","I","I","N","N","N","N","N","N","N","N","N","N","NULL"},
    
    //number
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","K V W","K V W","NULL","NULL","NULL","NULL","NULL","K V W","K V W","K V W","K V W","K V W","K V W","K V W","K V W","K V W","K V W","NULL"},
    
    //numberB
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","lamda","NULL","lamda","NULL","NULL","lamda","lamda","lamda","lamda","NULL","NULL","NULL","NULL","NULL","K V","K V","K V","K V","K V","K V","K V","K V","K V","K V","NULL"},
    
    //sign
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","+","-","NULL","NULL","NULL","NULL","NULL","lamda","lamda","lamda","lamda","lamda","lamda","lamda","lamda","lamda","lamda","NULL"},
    
    //digit
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","0","1","2","3","4","5","6","7","8","9","NULL"},
    
    //id
    
    {"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","a","b","c","d","e","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}
};




void iterateToPush(STACK &stack , string a)
{
    
    string tempArrayOfStrings[99];
    int tempIndex = 0;
    int tempStringWordLength = 0;
    istringstream iss(a);
    
    
    do {
        string b;
        iss >> b ;
        tempArrayOfStrings[tempIndex] = b;
        tempStringWordLength++;
        tempIndex++;
    }while(iss);
    
    for (int i =0; i< tempStringWordLength; ++i)
    {
        //cout<<tempArrayOfStrings[i]<<endl;	debugging
        stack.insert(tempArrayOfStrings[i]);
    }
    
    
    
}



bool isSyntaxAccepted()
{
    //Must get data from finalv2.txt
    fstream inputFile;
    inputFile.open("finalv2.txt",ios::in);
    
    if (!inputFile)
        cout<<"Error!\nfinalv2.txt not found!\n";
    
    int numberOfLines = 1;
    string temp[100];
    int tempIndex = 0;
    
    //Get line by line string values
    while (!inputFile.eof())
    {
        
        getline(inputFile, temp[tempIndex] );
        tempIndex++;
        numberOfLines++;
        
        
    }
    
    string* linesArray = new string[numberOfLines];
    
    //store string lines from finalv2 into linesArray with line number being the index
    
    for (int i =0; i < numberOfLines; ++i)
    {
        linesArray[i] = temp[i];
    }
    
    
    //Seperate terminal and non-terminals into their own string
    int index = 0;
    string arrayForWords[100];
    int stringWordLength = 1;
    
    for (int i =0; i < numberOfLines -2; ++i)
    {
        string tempString = linesArray[i];
        istringstream iss(tempString);
        
        
        do {
            string n;
            iss >> n ;
            //If the string is a idenitifer (e.g. a2014) then break up
            if (islower(n[0]) ||n[0] == '0'|| n[0] == '1'|| n[0] == '2'|| n[0] == '3'|| n[0] == '4'|| n[0] == '5'|| n[0] == '6'|| n[0] == '7'|| n[0] == '8'|| n[0] == '9')
            {
                for (int i = 0; i < n.length(); ++i)
                {
                    arrayForWords[index] = n[i];
                    stringWordLength++;
                    index++;
                }
                
            }
            
            else
            {
                arrayForWords[index] = n;
                stringWordLength++;
                index++;
            }
        }while(iss);
        
        
    }
    
    
    STACK one;
    one.insert("$");
    one.insert("B");
    bool continueToMatch = true;
    
    //iterate through array containing string to get terminal/non-terminal
    
    for (int i =0; i<stringWordLength; ++i)
    {
        
        if (arrayForWords[i].empty())
        {
            //do nothing, checks of there are any empty strings " ", if so they will simply be skipped
        }
        
        else
        {
            string tempString = arrayForWords[i];
            
            //cout<<"MUST MATCH "<<tempString<<endl;		debugging purposes
            
            
            int tempStringValue = NULL; // value associated to string, to be used for STATE array
            
            
            if (tempString == "PROGRAM")
                tempStringValue = 0;
            else if (tempString == "VAR")
                tempStringValue = 1;
            else if (tempString == "BEGIN")
                tempStringValue = 2;
            else if (tempString == "END.")
                tempStringValue = 3;
            else if (tempString == "INTEGER")
                tempStringValue = 4;
            else if (tempString == "WRITE")
                tempStringValue = 5;
            else if (tempString == "(")
                tempStringValue = 6;
            else if (tempString == ")")
                tempStringValue = 7;
            else if (tempString == "=")
                tempStringValue = 8;
            else if (tempString == ";")
                tempStringValue = 9;
            else if (tempString == ",")
                tempStringValue = 10;
            else if (tempString == ":")
                tempStringValue = 11;
            else if (tempString == "*")
                tempStringValue = 12;
            else if (tempString == "/")
                tempStringValue = 13;
            else if (tempString == "+")
                tempStringValue = 14;
            else if (tempString == "-")
                tempStringValue = 15;
            else if (tempString == "a")
                tempStringValue = 16;
            else if (tempString == "b")
                tempStringValue = 17;
            else if (tempString == "c")
                tempStringValue = 18;
            else if (tempString == "d")
                tempStringValue = 19;
            else if (tempString == "e")
                tempStringValue = 20;
            else if (tempString == "0")
                tempStringValue = 21;
            else if (tempString == "1")
                tempStringValue = 22;
            else if (tempString == "2")
                tempStringValue = 23;
            else if (tempString == "3")
                tempStringValue = 24;
            else if (tempString == "4")
                tempStringValue = 25;
            else if (tempString == "5")
                tempStringValue = 26;
            else if (tempString == "6")
                tempStringValue = 27;
            else if (tempString == "7")
                tempStringValue = 28;
            else if (tempString == "8")
                tempStringValue = 29;
            else if (tempString == "9")
                tempStringValue = 30;
            else if (tempString == "$")
                tempStringValue = 31;
            
            continueToMatch = true;
            
            string tempStringTwo;
            
            while (continueToMatch)
            {
                string x = one.pop();
                //one.display();  debugging
                
                // MATCH
                if (x == tempString)
                {
                    cout<<"MATCH "<<x<<" == "<<tempString<<endl;
                    //one.display();
                    continueToMatch = false;
                }
                //DONE
                else if (x == "$")
                {
                    cout<<"Accepted syntax";
                    continueToMatch = false;
                }
                
                //REST
                else if (x == "B")
                {
                    tempStringTwo = STATE[0][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 0 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                else if (x == "I")
                {
                    tempStringTwo = STATE[1][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 1 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "A")
                {
                    tempStringTwo = STATE[2][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 2 "<<tempString<<endl;	//debugging
                        return false;
                    };
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "X")
                {
                    tempStringTwo = STATE[3][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 3 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "D")
                {
                    tempStringTwo = STATE[4][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 4 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "C")
                {
                    tempStringTwo = STATE[5][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 5 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "Z")
                {
                    tempStringTwo = STATE[6][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 6 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "T")
                {
                    tempStringTwo = STATE[7][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 7 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "L")
                {
                    tempStringTwo = STATE[8][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 8 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "Q")
                {
                    tempStringTwo = STATE[9][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 9 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "S")
                {
                    tempStringTwo = STATE[10][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 10 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "G")
                {
                    tempStringTwo = STATE[11][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 11 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "H")
                {
                    tempStringTwo = STATE[12][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 12 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "E")
                {
                    tempStringTwo = STATE[13][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 13 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "P")
                {
                    tempStringTwo = STATE[14][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 14 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "R")
                {
                    tempStringTwo = STATE[15][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 15 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "Y")
                {
                    tempStringTwo = STATE[16][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 16 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "F")
                {
                    tempStringTwo = STATE[17][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 17 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "N")
                {
                    tempStringTwo = STATE[18][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 18 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "K")
                {
                    tempStringTwo = STATE[19][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 19 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "W")
                {
                    tempStringTwo = STATE[20][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 20 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                else if (x == "V")
                {
                    tempStringTwo = STATE[21][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 21 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                    {   //cout<<"push: "<<tempStringTwo<<endl;		/debugging
                        iterateToPush(one, tempStringTwo);
                    }
                }
                
                else if (x == "U")
                {
                    tempStringTwo = STATE[22][tempStringValue];
                    if(tempStringTwo == "NULL")
                    {
                        cout<<" not accepted.\n";
                        cout<<"ERROR in STATE = 22 "<<tempString<<endl;	//debugging
                        return false;
                    }
                    if(tempStringTwo != "lamda")
                        iterateToPush(one, tempStringTwo);
                }
                
                
                
            }
            
        }
    }
    
    
    
    return true;
}


