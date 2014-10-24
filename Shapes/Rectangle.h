//
//  Rectangle.h
//  Shapes
//
//  Created by Tayseer Edouni on 1/25/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Rectangle__
#define __Shapes__Rectangle__

#include <iostream>
using namespace std;

#include "Shape.h"
#include "Parallelogram.h"

class Rectangle : public Parallelogram
{
    
public:
    Rectangle();
    Rectangle (double length, double width);
    Rectangle (Coord center, double length, double width);
    
    void width (double width);
    void length (double length);
   
    virtual string name() const;
    virtual bool isValid() const;
    
    friend ostream& operator<< (ostream& os , const Rectangle& r);

    
private:
   // double _width, _length;
    
};

#endif /* defined(__Shapes__Rectangle__) */
