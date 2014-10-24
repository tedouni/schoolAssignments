//
//  Circle.h
//  Shapes
//
//  Created by Tayseer Edouni on 1/18/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Circle__
#define __Shapes__Circle__

#include <iostream>
#include "Ellipse.h"


using namespace std;

class Circle: public Ellipse
{
public:
    Circle();
    Circle( double radius );
    Circle( Coord center, double radius );
    
    void radius(double value);
    double radius() const;
    
    double diameter() const;
    double circumference() const ;
    
    bool isValid() const;
    string name()  const;
    
    friend ostream& operator<< (ostream& os , const Circle& ci);

    
private:
};
#endif /* defined(__Shapes__Circle__) */
