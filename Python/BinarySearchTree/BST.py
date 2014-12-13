#Tayseer Edouni
#Assignment 4 
#BST.py
#CSPSC 233P 02 Mo/We
#tedouni@csu.fullerton.edu
#taedouni@gmail.com
#http://en.wikipedia.org/wiki/Binary_search_tree
#archived CSPC 233P emails 
#https://docs.python.org/2/library/functions.html  and other links from tutorial
#handout 
import random
import sys
 
class Node: 
    __slots__ = { '_parent', '_left', '_right', '_data' }
 
    def __init__(self, parent, data):
        self._data = data
        self._parent = parent
        self._right = None
        self._left = None
 
    #####DATA#####
    @property
    def data(self):
         return self._data
    @data.setter
    def data(self, value):
         self._data = value
    @data.deleter
    def data(self):
         del self._data
    ###PARENT###
    @property
    def parent(self):
        return self._parent
    @parent.setter
    def parent(self, node):
        self._parent = node
    @parent.deleter
    def parent(self):
        del self._parent
        
    ###RIGHT###
    @property
    def right(self):
        return self._right
    @right.setter
    def right(self, node):
        self._right = node
    @right.deleter
    def right(self):
        del self._right
    
    ###LEFT### 
    @property
    def left(self):
        return self._left
    @left.setter
    def left(self, node):
        self._left = node
    @left.deleter
    def left(self):
        del self._left

   
    def __str__(self):
        node = '\t{} -> {};\n'
        null = '\t{} [shape=point];\n\t{} -> {};\n'
        s = ''
        if self.left != None:
            s += node.format(self.data, self.left.data)
        else:
            s += null.format('null', self.data, 'null')
        if self.right != None:
            s += node.format(self.data, self.right.data)
        else:
            s += null.format('null', self.data, 'null')
        return s
 
 
class Tree():
 
    __slots__ = { '_root' }
     
    def __init__(self):
        self._root = None
 
    @property
    def root(self):
        return self._root
    @root.setter
    def root(self, node):
        self._root = node
    @root.deleter
    def root(self):
        del self._root
        
    def insert(self, data):
        node = self.root
        parent = None
        while node != None:
            parent = node
            if node.data > data:
                node = node.left
            else:
                node = node.right
        newNode = Node(parent, data)
        if parent == None:
            self.root = newNode
        elif parent.data > data:
            parent.left = newNode
        else:
            parent.right = newNode
     
    def searchNode(self, node, data):
        while node != None and node.data != data:
            if data > node.data:
                node = node.right
            else:
                node = node.left
        return node
        
    def transplant(self, u, v):
        if u.parent == None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        if v != None:
            v.parent = u.parent
    def minimum(self, treeRoot):
        node = treeRoot
        while node.left != None:
            node = node.left
        return node
 
    def maximum(self, treeRoot):
        node = treeRoot
        while node.right != None:
            node = node.right
        return node
 
    #used to find node with  desired data
    def searchData(self, data):
        return self.searchNode(self.root, data)
    
    #used to remove data from tree (if it exists)
    def remove(self, data):  
        node = self.searchData(data)  #See if node exists
        if node != None:  #if node exists
            self.deleteNode(node) #delete node
            return True             #return complete
        else:
            return False            #return error
 
    
    
    #deletes node from binary tree 
    def deleteNode(self, node):
        if node.left == None:
            self.transplant(node, node.right)
        elif node.right == None:
            self.transplant(node, node.left)
        else:
            successor = self.minimum(node.right)
            if successor.parent != node:
                self.transplant(successor, successor.right)
                successor.right = node.right
                successor.right.parent = successor
            self.transplant(node, successor)
            successor.left = node.left
            successor.left.parent = successor
        del node

    def traversal(self, node, dotList):
        if node != None:
            dotList.append(str(node))
            if node.left != None:
                self.traversal(node.left, dotList)
            if node.right != None:
                self.traversal(node.right, dotList)
     
def outputString(dotList):
    string = ''
    a = 0
    for i in dotList:
        data = str(i)
        b = data.count('null')
        if b != 0:
            n1 = data.find('null') + 4
            n2 = data.find('null', n1 + 1) + 4
            end = len(data)
            a += 1
            d = data[0:n1] + str(a) + data[n1:n2] + str(a)
            if b == 2:
                data = d + data[n2:end]
            elif b == 4:
                a += 1
                c = str(a)
                n3 = data.find('null', n2 + 1) + 4
                n4 = data.find('null', n3 + 1) + 4
                data = d + data[n2:n3] + c + data[n3:n4] + c + data[n4:end]
        string += data
    return string
         
def writeTree(tree, fileName):
    fileName.write('digraph BST{\n')
    fileName.write('\tnode [fontname="Helvetica"];\n')
    dotList = []
    tree.traversal(tree.root, dotList)
    fileName.write(outputString(dotList))
    fileName.write('}')
 
def main( ):
  if len(sys.argv) < 2:
    print('Please provide the number of keys to enter.')
    sys.exit(1)
  s = int(sys.argv[1])
  parts = int(s/3)
  t = Tree( )
  r = list(range(1,s+1))

  print('Randomly inserting the numbers from 1 to {}.'.format(len(r)))

  random.shuffle(r)

  for i in r:
    print('inserted {}'.format(i))
    t.insert(i)
  f = open('a.dot', 'w')
  writeTree(t, f)
  f.flush( )
  f.close( )
  random.shuffle(r)

  for n in range(1, 3):
    m = r[(n-1) * parts : (n * parts)]
    print(len(m))
    for i in m:
      print('removed {}'.format(i))
      v = t.remove(i)
      if v:
        print('\tcompleted.')
      else:
        print('\terror.')
    c = chr(n + 97)
    filename = str(c) + '.dot'
    f = open(filename, 'w')
    writeTree(t, f)
    f.flush( )
    f.close( )
    
###############################
#############START OF PROG#####

if __name__ == '__main__':
    main()