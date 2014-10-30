//
//  Coord.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 2/21/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Coord.h"

Coord::Coord() :  Coord( 0, 0 )   { }
Coord::Coord( double x, double y ) :  _x( x ), _y( y )   { }
// Notice these two methods have the same name, and different return types
//    NB: this is forbidden by C++ UNLESS they differ in the const keyword
double&  Coord::x()          {  return  _x;  }
double   Coord::x() const    {  return  _x;  }

double&  Coord::y()          {  return  _y;  }
double   Coord::y() const    {  return  _y;  }

ostream&  operator<<( ostream& os, const Coord& coord )
{
    return  os << "Coord[x=" << coord._x << ",y=" << coord._y << "]";
}

bool Coord:: operator!= (const Coord& cOther) const
{
    return !(*this==cOther);
    
}
bool Coord::operator== (const Coord& cOther) const
{
    return _x==cOther._x &&
            _y==cOther._y;

}

void Coord::display(ostream& os) const
{
    cout<<"Coord [x=]"<<_x<<",y="<<_y<<"]";
}

