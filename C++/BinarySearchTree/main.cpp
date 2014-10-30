#include <iostream>
#include <string>
#include "BSTNode.h"
#include "BSTSimple.h"	
using namespace std;
#include <string>

int main()
{
    cout<<"The bst is : \n";
    cout<<"...Preorder: \n";
    BSTSimple<char, int> treeOne;
    treeOne.put('M', 1);
    treeOne.put('G', 2);
    treeOne.put('C', 3);
    treeOne.put('I', 4);
    treeOne.put('R', 5);
    treeOne.put('O', 6);
    treeOne.put('S', 7);
    
    treeOne.print(cout, BSTNode<char, int> :: PREORDER);
    cout<<endl;
    
    cout<<"...Inorder:\n";
    treeOne.print(cout,BSTNode<char,int> :: INORDER);
    cout<<endl;

    cout<<"...Postorder:\n";
    treeOne.print(cout,BSTNode<char,int>::POSTORDER);
    cout<<endl;

    
    BSTSimple<string, int> treeTwo;
    treeTwo.put("this", 1);
    treeTwo.put("is", 2);
    treeTwo.put("fresh", 3);
    treeTwo.put("a", 10);
    treeTwo.put("barn", 11);
    treeTwo.put("in", 9);
    treeTwo.put("lacquer", 4);
    treeTwo.put("seriously", 5);
    treeTwo.put("raised", 8);
    treeTwo.put("were", 6);
    treeTwo.put("you", 7);

    cout<<"The bst is: \n";
    cout<<"...Preorder:\n";
    treeTwo.print(cout, BSTNode<string, int>::PREORDER);
    cout<<endl;
    cout<<"...Inorder:\n";
    treeTwo.print(cout,BSTNode<string, int> ::INORDER);
    cout<<endl;
    treeTwo.print(cout, BSTNode<string, int> ::POSTORDER);
    cout<<endl;
    
    BSTSimple<int, string> treeThree;
    treeThree.put(50, "fifty");
    treeThree.put(25, "twenty-five");
    treeThree.put(12, "twelve");
    treeThree.put(37, "thirty-seven");
    treeThree.put(75, "seventy-five");
    treeThree.put(62, "sixty-two");
    treeThree.put(85, "eighty-five");
    cout<<"The bst is: \n";
    cout<<"...Proder:\n";
    treeThree.print(cout, BSTNode<int, string>::PREORDER);
    cout<<endl;
    cout<<"...Inorder:\n";
    treeThree.print(cout, BSTNode<int, string>::INORDER);
    cout<<endl;
    cout<<"...Postorder:\n";
    treeThree.print(cout, BSTNode<int, string>::POSTORDER);
    cout<<endl;

    
	return 0;
}