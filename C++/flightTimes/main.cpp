//
//  main.cpp
//  ProjectEightExThree
//
//  Created by Tayseer Edouni on 3/24/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include <iostream>
using namespace std;


void getInfo(int& index, string& name);
//e.g. Enter PH with index set to 0,
//returns Phoenix with index 3

int main(int argc, const char * argv[])
{
    //construct adjacency list 4x4 array of floats

    float flightList[4][4]={ {0,1,2.5,4.5}, {3.5,0,1.5,3.5},
        {2,3.5,0,2}, {2.10,1.5,3,0} };
    
    char choice;
    do
    {
        cout<<"LA Los Angeles, VEG Las Vegas, SAN San Diego, PH, Phoenix\n";
        cout<<"Enter the name of two cities to see the flight time\n";

        
        string start, end;
        cin>>start>>end;
        
        int citya=0, cityb=0;
        getInfo(citya, start);
        getInfo(cityb, end);
        
        cout<<"It takes "<<flightList[citya][cityb]<<" hours from "<<start<<" to "<<end<<endl;

    
        

        
        cout<<"CONTINUE (y/n)? ";
        cin>>choice;
    } while (choice=='y' || choice == 'Y');
    
        cout<<"Program ended!\n";

        return 0;
}

void getInfo(int& index, string& name)
{
    if (name == "LA")
    {index=0; name="Los Angeles";}
    else if(name == "VEG")
    {index = 1; name="Las Vegas";}
    else if(name == "SAN")
    {index =2; name="San Diego";}
    else if(name =="PH")
    {index =3; name="Phoenix";}
    else{cout<<"ERROR"; exit(0);}
   }
