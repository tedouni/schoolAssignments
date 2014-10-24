//
//  Coord.h
//  Shapes
//
//  Created by Tayseer Edouni on 2/21/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#ifndef __Shapes__Coord__
#define __Shapes__Coord__

#include <iostream>
using namespace std;

class Coord {
public:
    Coord();
    Coord( double x, double y );
    double&  x();     // read-write reference to _x

    double   x() const;    // read-only copy of _x

    double&  y();     // read-write reference to _y

    double   y() const;     // read-only copy of _y

    
    friend ostream&  operator<<( ostream& os, const Coord& coord );
    
    bool operator!= (const Coord& cOther) const;
    bool operator== (const Coord& cOther) const;
    
    void display(ostream& os) const;
    friend ostream& operator<<(ostream& os, const Coord& c);

private:
    double  _x;
    double  _y;
};
#endif /* defined(__Shapes__Coord__) */
