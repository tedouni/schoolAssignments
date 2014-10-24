//
//  Triangle.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 2/2/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Triangle.h"
#include <cmath>

Triangle::Triangle():Triangle(0,0,0)
{
   /* if(!isValid())
    {
        throw invalid_argument("invalid triangle sides");
    } */
   
}




Triangle::Triangle(double sideA, double sideB, double sideC): _sideA(sideA), _sideB(sideB),_sideC(sideC)
{
    /*if(!isValid())
    {
        throw invalid_argument("invalid triangle sides");
        
    } */
    
}

Triangle::Triangle ( Coord center, double sideA, double sideB, double sideC):   Shape(center) ,_sideA(sideA), _sideB(sideB),_sideC(sideC)
{
   /* if(!isValid())
    {
        throw invalid_argument("invalid triangle sides");
    } */
}

double Triangle:: sideA() const        {return _sideA;}
void   Triangle:: sideA( double sideA ){_sideA=sideA;}

double Triangle:: sideB() const        {return _sideB;}
void   Triangle:: sideB( double sideB) { _sideB=sideB; }

double Triangle:: sideC() const        {return _sideC;}
void   Triangle:: sideC( double sideC) { _sideC=sideC;}

double Triangle:: perimeter() const
{
    return _sideA+_sideB+_sideC;
}

double Triangle:: area() const
{
    return sqrt( heron()*(heron()-_sideA)*(heron()-_sideB)*(heron()-_sideC));
}


double Triangle:: max(double m, double n) const
{
    if (m>n)
        return m;
    else return n;
        
}

double Triangle::heron( ) const
{
    return perimeter()/2;
}

bool Triangle::isValid() const
{
    return _sideA + _sideB > _sideC  &&
           _sideB + _sideC > _sideA  &&
           _sideC + _sideA > _sideB;
}

double Triangle:: length( )      const      //parallel to x axis
{
    return max(_sideC, max(_sideA,_sideB));
}

double Triangle::  width( )      const // parallel to y axis
{
    
    return 2*( area() / length() );
}

string Triangle::  name( )       const
{
    return "Triangle";
}

 bool Triangle:: operator != (const Triangle& trOther) const
{
    return !(*this ==trOther);
    
}
bool Triangle:: operator == (const Triangle& trOther) const
{
   return dynamic_cast<const Shape&>( *this ) == dynamic_cast<const Shape&>( trOther ) &&
    _sideA==trOther._sideA &&
    _sideB==trOther._sideB &&
    _sideC==trOther._sideC;
}
