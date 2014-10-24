//
//  Parallelogram.h
//  Shapes
//
//  Created by Tayseer Edouni on 2/14/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Parallelogram__
#define __Shapes__Parallelogram__

#include <iostream>
#include "Shape.h"
#include <string>
#include <cmath>

class Parallelogram : public Shape
{
private:
    double _sideA;
    double _sideB;
    double _theta; //radians

public:
    Parallelogram( );                     //default constructor
    Parallelogram( double sideB, double sideA, double theta );
    Parallelogram( Coord center, double sideB, double sideA, double theta );
    double sideA( ) const;
    double sideB( ) const;
    double theta( ) const;
    
    
    void sideA ( double sideA ); //mutators
    void sideB ( double sideB );
    void theta (double theta  );
    
    virtual double perimeter( )  const;
    virtual double area( )       const;
    virtual double length( )     const;
    virtual double width( )      const;
    virtual string name( )       const;
    virtual bool isValid()       const;
    virtual bool operator != (const Parallelogram& pOther) const;
    virtual bool operator == (const Parallelogram& pOther) const;
    friend ostream& operator<<( ostream& os, const Parallelogram& p);
    


    
};

#endif /* defined(__Shapes__Parallelogram__) */
