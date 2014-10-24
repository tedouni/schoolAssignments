//
//  Circle.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 1/18/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include "Circle.h"
#include <cmath>

using namespace std;

const double PI=3.14159265359 ; //from Google


Circle::Circle() : Circle(0){}

Circle::Circle(double radius):Ellipse(radius,radius) { }
Circle::Circle(Coord center, double radius) : Ellipse(center, radius, radius){}

double Circle::radius() const
{
    
        return radius();
    
        
}

void Circle::radius(double radius)
{
    semimajor(radius);
    semiminor(radius);
    
}

double Circle::diameter()   const{return radius()*2;}
double Circle::circumference() const {return 2*PI*radius();}

string  Circle::name()    const{ return "Circle";}

bool Circle::isValid() const { return true;}

ostream& operator<< (ostream& os , const Circle& ci)
{
    return os<<"Circle["<< dynamic_cast<const Ellipse&> (ci)<<"]";
}
    

