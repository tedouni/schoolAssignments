//
//  main.cpp
//  Shapes
//
//  Created by Tayseer Edouni on 1/18/14.
//  Copyright (c) 2014 Tayseer Edouni. All rights reserved.
//

#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Triangle.h"
#include "Parallelogram.h"
#include "Coord.h"


 void  nameInvalid( string msg, double (Shape::*fp)() const, const Shape& sh )  {
    cout << "the " + msg + " of sh is: ";
    if (sh.isValid())  {  cout << (sh.*fp)();  }
    else               {  cout << sh.name() << " is invalid";  }
    cout << endl;
}
 
void  displayShape( const Shape& sh )  {
    cout << "sh is a(n): " << sh.name() << endl;
    cout << "center: " << sh.center() << endl;
    nameInvalid( "area     ", &Shape::area,      sh );
    nameInvalid( "perimeter", &Shape::perimeter, sh );
    nameInvalid( "length   ", &Shape::length, sh);
    nameInvalid( "width    ", &Shape::width,sh );
    cout << endl;
}


using namespace std;

int main(int argc, const char * argv[])
{
    /*
    const Shape& c = Circle();
    const Shape& d = Circle( 3 );
    const Shape& e = Circle( Coord( 1, 2 ), 3 );
    displayShape( c );
    displayShape( d );
    displayShape( e );
    const Shape&  e1 = Ellipse();
    const Shape&  e2 = Ellipse( 4, 2 );
    const Shape&  e3 = Ellipse( Coord( -2, -2 ), 4, 2 );
    displayShape( e1 );
    displayShape( e2 );
    displayShape( e3 );
    const Shape&  sq1 = Square();
    const Shape&  sq2 = Square( 10 );
    const Shape&  sq3 = Square( Coord( 5, 10 ), 10 );
    displayShape( sq1 );
    displayShape( sq2 );
    displayShape( sq3 );
    const Shape&  rect1 = Rectangle();
    const Shape&  rect2 = Rectangle( 10, 5 );
    const Shape&  rect3 = Rectangle( Coord( -2, 4 ), 10, 5 );
    displayShape( rect1 );
    displayShape( rect2 );
    displayShape( rect3 );
    const Shape&  tri1 = Triangle();
    const Shape&  tri2 = Triangle( 3, 4, 5 );
    const Shape&  tri3 = Triangle( Coord( 1, 1 ), 3, 4, 15 );
    displayShape( tri1 );
    displayShape( tri2 );
    displayShape( tri3 );
    const Shape&  par1 = Parallelogram();
    const Shape&  par2 = Parallelogram( 10, 4, 30 );
    const Shape&  par3 = Parallelogram( Coord( 3, 3 ), 10, 4, 30 );
    displayShape( par1 );
    displayShape( par2 );
    displayShape( par3 );
    Coord  c1;
    Coord  c2( 12, -3 );
    cout << "c1 is: " << c1 << endl;
    cout << "c2 is: " << c2 << endl;
    cout << "...done." << endl;  */
    
    Circle c;
    Circle d( 3 );
    Circle e( Coord( 1, 2 ), 3 );
    const Shape& she = e;
    const Ellipse& ee = e;
    const Circle& ce = e;
    cout << "displaying them all as shapes..." << endl;
    displayShape( she );
    displayShape( ee );
    displayShape( ce );
    cout << "now displaying them directly to cout... " << endl;
    cout << "as a Shape...    " << she << endl;
    cout << "as an Ellipse... " << ee  << endl;
    cout << "as a Circle...   " << ce  << endl;
    Square  sq( Coord( 5, 10 ), 10 );
    const Shape&          shsq = sq;
    const Parallelogram&  psq  = sq;
    const Rectangle&      rsq  = sq;
    const Square&         sqsq = sq;
    cout << endl << "displaying them all as shapes..." << endl;
    displayShape( shsq );
    displayShape( psq );
    displayShape( rsq );
    displayShape( sqsq );
    cout << "now displaying them directly to cout... " << endl;
    cout << shsq << endl;
    cout << psq  << endl;
    cout << rsq  << endl;
    cout << sqsq << endl;
    cout << "...done." << endl;
    
    return 0;
}
