//
//  Ellipse.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 1/30/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Ellipse.h"
#include <cmath>
const double PI= 3.1415926589;

Ellipse::Ellipse() :   Ellipse ( 0, 0 ) { }
Ellipse::Ellipse(double radius):    Ellipse (radius, radius){}
Ellipse::Ellipse(double semimajor, double semiminor): Ellipse(Coord  (0,0), _semimajor,_semiminor){}
Ellipse::Ellipse( Coord center, double semimajor, double semiminor) :  Shape(center),  _semimajor(semimajor) ,_semiminor(semiminor) {}

double Ellipse::semimajor() const{ return _semimajor;}
void   Ellipse::semimajor(double semimajor) {_semimajor=semimajor;}

double Ellipse::semiminor() const { return _semiminor;}
void Ellipse::semiminor(double semiminor) { _semiminor=semiminor;}

double Ellipse:: area() const { return PI*_semimajor*_semiminor;}
double Ellipse:: perimeter() const
{
    double a=_semimajor;
    double b=_semiminor;
    return PI*(3*(a+b)-sqrt((3*a+b)*(a+3*b)));
}

double Ellipse::length() const {return 2* _semimajor;}
double Ellipse::width() const {return 2* _semiminor;}
string Ellipse::name() const {return "Ellipse";}

double Ellipse::eccentricity() const {return focus() / _semimajor;}
double Ellipse::focus() const
{
    return sqrt(pow(_semimajor,2)-pow(_semiminor,2));
    
}


bool Ellipse::  isValid() const
{return true;}

bool Ellipse:: operator != (const Ellipse& eOther) const
{
    return !(*this ==eOther);
}
bool Ellipse:: operator == (const Ellipse& eOther) const
{
    return dynamic_cast<const Shape&>( *this ) == dynamic_cast<const Shape&>( eOther ) &&
    _semimajor == eOther._semimajor &&
    _semiminor == eOther._semiminor;
}

ostream& operator<<( ostream& os, const Ellipse& e)
{
    return os<<"Ellipse[semimajor="<<e._semimajor<<", semiminor="<<e._semiminor<<"]"<<","<<dynamic_cast<const Shape&>(e)<<"]";
}

