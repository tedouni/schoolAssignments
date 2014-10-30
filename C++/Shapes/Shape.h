//
//  Shape.h
//  Shapes
//
//  Created by Tayseer Edouni on 1/25/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Shape__
#define __Shapes__Shape__

#include <iostream>
#include <string>
#include "Coord.h"
using namespace std;

class Shape
{
    
public:
    Shape();
    Shape(Coord center);
    void center( Coord center);

    Coord center() const;
    
    virtual double area() const = 0; //Virtual (will call appropiate subclass at runtime)
    virtual double perimeter() const=0;
    virtual double length() const =0;
    virtual double width() const=0;
    virtual string name() const =0;
    virtual bool isValid() const =0;
    virtual bool operator == (const Shape& shOther) const;
    virtual bool operator != (const Shape& shOther) const;
    friend  ostream& operator<< (ostream& os, const Shape& sh);
    
    
    
private:
      Coord  _center;
};

#endif /* defined(__Shapes__Shape__) */
