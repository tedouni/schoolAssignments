//
//  Rectangle.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 1/25/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Rectangle.h"


Rectangle::Rectangle(): Rectangle(0,0) {}

Rectangle::Rectangle(double length, double width): Rectangle(Coord (0,0), length, width){}
Rectangle::Rectangle(Coord center,double length,double width): Parallelogram(center, length, width, 90){ }

void Rectangle::width(double width)
{width;}

void Rectangle::length(double length)
{length;}


string Rectangle::name() const {return "Rectangle";}

bool Rectangle:: isValid() const
{return true;}

ostream& operator<< (ostream& os , const Rectangle& r)
{
    return os<<"Rectangle[" << dynamic_cast<const Parallelogram&>(r)<<"]";
}