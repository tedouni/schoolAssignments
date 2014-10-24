//
//  Triangle.h
//  Shapes
//
//  Created by Tayseer Edouni on 2/2/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Triangle__
#define __Shapes__Triangle__

#include <iostream>
#include "Shape.h"
#include <string>

using namespace std;

class   Triangle: public Shape
{
public:
    Triangle( );                     //default constructor
    Triangle( double sideA, double sideB, double sideC ); //constructor
    Triangle ( Coord center, double sideA, double sideB, double sideC);
    
    double sideA( ) const;
    double sideB( ) const;
    double sideC( ) const;
    
    
    void sideA ( double sideA ); //mutators 
    void sideB ( double sideB );
    void sideC (double sideC  );
    
    virtual double perimeter( )  const;
    virtual double area( )       const;
    virtual double length( )     const;
    virtual double width( )      const;
    virtual string name( )       const;
    virtual bool isValid()       const;
    virtual bool operator != (const Triangle& trOther) const;
    virtual bool operator == (const Triangle& trOther) const;
    friend ostream& operator<< (ostream& os, const Triangle& tr);
    
private:
    double max(double m, double n) const ;       //returns the max of m or n
    double heron( ) const;       //heron formula to calculate
    
    //bool valid() const; //determines which two sides added together is longer than the third
    
private:
    double _sideA;
    double _sideB;
    double _sideC;
    
};


#endif /* defined(__Shapes__Triangle__) */
