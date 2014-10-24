//
//  Square.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 1/25/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Square.h"
#include <cmath>

Square::Square() : Square(0) {}
Square::Square(double side):Square( Coord(0,0),side){}
Square::Square(Coord center, double side) : Rectangle(center, side, side){}
void Square::side(double side)
{
    length(side);
    width(side);
}

double Square::side() const { return _side;}
    
string Square::name() const {return "Square";}

bool Square::isValid() const {return true;}

ostream& operator<< (ostream& os , const Square& sq)
{
    return os <<"Square["<<dynamic_cast<const Rectangle&>(sq)<<"]";
}