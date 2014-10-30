//
//  Ellipse.h
//  Shapes
//
//  Created by Tayseer Edouni on 1/30/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Ellipse__
#define __Shapes__Ellipse__

#include <iostream>
#include <string>

#include "Shape.h"

using namespace std;

class Ellipse: public Shape
{
public:
    Ellipse();
    Ellipse( double radius );
    Ellipse (double semimajor, double semiminor);
    Ellipse( Coord center, double semimajor, double semiminor );
    
    void semimajor(double semimajor);
    double semimajor()  const;
    
    void semiminor(double semiminor);
    double semiminor() const;
    
    
    virtual double area() const;
    virtual double perimeter() const;
    virtual double length() const;
    virtual double width() const;
    virtual string name() const;
    
    double eccentricity() const;
    double focus() const;
    
    virtual bool isValid() const;
    
    virtual bool operator != (const Ellipse& eOther) const;
    virtual bool operator == (const Ellipse& eOther) const;
    friend ostream& operator<<( ostream& os, const Ellipse& e);
    
private:
    double _semimajor;
    double _semiminor;
    
};
#endif /* defined(__Shapes__Ellipse__) */
