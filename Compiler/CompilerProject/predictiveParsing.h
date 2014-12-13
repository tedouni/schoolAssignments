//
// Tayseer Edouni
// David Laosen
//predictiveParsing.h

//
#ifndef __predictiveParsing__predictiveParsing__
#define __predictiveParsing__predictiveParsing__

#include <iostream>
#include <string>
#include "stack.h"
#include <fstream>
#include <sstream>

void testIfValid(string fromTable); ////Test if valid entry in Table, if not then word doesn't exist

void iterateToPush(STACK &stack , string a);

bool isSyntaxAccepted();

#endif /* defined(__predictiveParsing__predictiveParsing__) */
