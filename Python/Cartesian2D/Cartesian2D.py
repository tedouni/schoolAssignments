#Tayseer Edouni
#Assignment 3
#Cartesian2D.py
#CPSC 323P-02 Mo/WE


# Two-dimensional Cartesian coordinate
#  class definition here

import math

######START OF CLASS#######
class Cartesian2D:
    __slot__ = ['_x','_y']

    def __init__(self,x,y):
      self._x = x
      self._y = y 

    @property 
    def x(self):
      return self._x
  
    @x.setter
    def x(self,X):
        self._x = X
    @x.deleter
    def x(self):
        del self._x
    @property
    def y(self):
        return self._y
    @y.setter
    def y(self,Y):
        self._y = Y
    @y.deleter
    def y(self):
        del self._y


    def distanceTo(self,otherPoint):
      return (self - otherPoint).length()
  
  
    def length(self):
      return math.sqrt(self.x**2 + self.y**2)

    def __sub__(self, other): 
      return Cartesian2D(self.x-other.x,self.y-other.y)
  
    def __add__(self,other):
      return Cartesian2D(self.x+other.x,self.y+other.y)
  
    def normalize(self):
      return Cartesian2D((self.x/float(math.sqrt(self.x**2 + self.y**2))),(self.y/math.sqrt(self.x**2 + self.y**2)))
    def __mul__(self,other):
      return Cartesian2D(self.x * other, self.y * other)
  
    def __str__(self):
      return '({} , {})'.format(round(self.x,2),round(self.y,2))
  
      
######END OF CLASS#######

def dot(self,other):
  return self.x*other.x + self.y*other.y
  
#####START OF MAIN FUNCTION####
def main( ):
  a = Cartesian2D(2.3, 3.4)
  b = Cartesian2D(4.5, 1.8)
  c = Cartesian2D(8.1, 0.3)
  print("The distance from a to b is {}".format(a.distanceTo(b)))
  print("The distance from b to c is {}".format(b.distanceTo(c)))
  d = a + b
  print("a + b = ({},{})".format(d.x, d.y))
  d = c - b
  print("c - b = ({}, {})".format(d.x, d.y))
  print("The length of a is {}".format(a.length()))
  print("The length of b is {}".format(b.length()))
  print("The length of c is {}".format(c.length()))
  # the normalize method returns a unit length vector
  unita = a.normalize()
  unitb = b.normalize()
  unitc = c.normalize()
  print("The length of unit a is {}".format(unita.length()))
  print("The length of unit b is {}".format(unitb.length()))
  print("The length of unit c is {}".format(unitc.length()))
  if a == b:
    print('Somehow a is equal to b?')
  else:
    print('a is not equal to b')
  s = 4
  d = unita * s
  print(d)
  print("The length of d is {}".format(d.length()))
  e = unitb * s
  f = dot(a, b)
  g = dot(unita, unitb)
  h = dot(d, e)
  print("dot(a, b) = {}".format(f))
  print("dot(unita, unitb = {}".format(g))
  print("dot(d, e) = {}".format(h))
#####END OF MAIN FUNCTION####

#START OF PROGRAM
if __name__ == "__main__":
  main( )
  
  