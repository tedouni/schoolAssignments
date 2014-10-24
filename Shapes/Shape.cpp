//
//  Shape.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 1/25/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Shape.h"
Shape::Shape(): Shape (Coord(0,0)){}
Shape::Shape(Coord center):_center(center)  {}

void Shape::center( Coord center)
{
    center=_center;
}

Coord Shape::center() const
{
    return _center;
}


bool Shape:: operator == (const Shape& shOther) const
{
    return _center == shOther._center;
}

bool Shape:: operator != (const Shape& shOther) const
{
    return !(*this == shOther);
}
             
ostream& operator<< (ostream& os, const Shape& sh)
{
    return os<<"Shape[center="<<sh._center<<"]";
}