//
//  Square.h
//  Shapes
//
//  Created by Tayseer Edouni on 1/25/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Square__
#define __Shapes__Square__

#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;

class Square: public Rectangle
{
public:
    Square();
    Square(double side);
    Square( Coord center, double side);
    
    double side() const;
    void side(double side);
    string name() const;
    bool isValid() const;
    
    friend ostream& operator<< (ostream& os , const Square& sq);
    
private:
    double _side;
    
};


#endif /* defined(__Shapes__Square__) */
