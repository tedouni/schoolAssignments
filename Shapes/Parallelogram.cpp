//
//  Parallelogram.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 2/14/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Parallelogram.h"
const double PI= 3.1415926589;


Parallelogram::Parallelogram():Parallelogram(0,0,0){}

Parallelogram::Parallelogram( double sideB, double sideA, double theta ): _sideB(sideB), _sideA(sideA), _theta(theta )  {} //constructor

Parallelogram::Parallelogram( Coord center, double sideB, double sideA, double theta): Shape(center) ,_sideB(sideB), _sideA(sideA), _theta(theta ) {}

double Parallelogram:: sideA( ) const
{
    return _sideA;
    
}

void Parallelogram::sideA ( double sideA )
{
    _sideA=sideA;
}

double Parallelogram::sideB( ) const
{
    return _sideB;
}
void Parallelogram::sideB ( double sideB )
{
    _sideB=sideB;
}

double Parallelogram::theta( ) const
{
    return _theta;
}
void Parallelogram::theta (double theta  )
{
    _theta= theta ;
}



 double Parallelogram::perimeter( )  const
{
    return _sideA*2+_sideB*2;
}
 double Parallelogram::area( )       const
{
    return _sideB * _sideA * sin( _theta * (PI/180)) ;
}
 double Parallelogram::length( )     const
{
    return _sideB +  _sideA * cos( _theta * (PI/180));
}
 double Parallelogram::width( )      const
{
    return _sideA * sin( _theta * (PI/180)) ;
}
 string Parallelogram:: name( )       const
{
    return "Parallelogram ";
}

bool Parallelogram:: isValid() const
{return true;}

bool Parallelogram::operator != (const Parallelogram& pOther) const
{
    return !(*this == pOther);
}

bool Parallelogram::operator == (const Parallelogram& pOther) const
{
    return dynamic_cast<const Shape&>(*this) == dynamic_cast<const Shape&>(pOther) &&
    _sideA == pOther._sideA &&
    _sideB == pOther._sideB &&
    _theta == pOther._theta;
}

ostream& operator<<( ostream& os, const Parallelogram& p)
{
    return os <<"Parallelogram[sideB="<<p._sideB<<",sideA="<<p._sideA<<","<<p._theta<<","<<dynamic_cast<const Shape&>(p)<<"]";
}
