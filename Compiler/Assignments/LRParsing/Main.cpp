// Tayseer Edouni & David Laosen - Group # 15
// CS 323
// Assignment 9 - LRParser

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class STACK{
private:
	struct NODE	{ char value; NODE* next; };
	NODE* list;

public:
	STACK() { list = NULL; }

	bool isEmpty() { return (list == NULL) ? true : false; }

	char pop() {
		NODE *p = list;
		char x;
		x = p->value;
		list = list->next;
		delete p;
		return x;
	}

	void insert(char x) {
		NODE *p = new NODE;
		p->value = x;
		if (list == NULL) {
			list = p;
			p->next = NULL;
		} else {
			p->next = list;
			list = p;
		}
	}

	void display() {
		NODE *p = list;
		cout << "Read left to right" << endl;
		while (p != NULL) {
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}
};

void testIfValid(string fromTable, string word)  {//Test if valid entry in Table, if not then word doesn't exist
	if (fromTable == "NULL") {
		cout << "\n" << word << " is not accepted.\n\n";
		exit(0);
	}
	if (fromTable == "acc") {
		cout << "\n" << word << " is accepted.\n\n";
		exit(0);
	}
}

void iterateToPush(STACK &stack, string a) {
	for (int i = 0; i<a.length(); ++i) {
		char x = a[i];
		stack.insert(x);
	}
}

void pushPopS(STACK &one, char x, char tempChar, string tempString, bool &continueToMatch){
	one.insert(x);
	one.insert(tempChar);
	iterateToPush(one, tempString.substr(1));
	one.display();
	continueToMatch = false;
}

void pushPopR(STACK &one, char x, char &tempChar, string tempString, bool &continueToMatch, int &tempCharValue){
	int r[8] = { 6, 6, 2, 6, 6, 2, 6, 2 };

	one.insert(x);
	one.display();
	string b = tempString.substr(1);
	int c = stoi(b);
	c--;
	for (int i = 0; i < r[c]; i++)
		x = one.pop();
	switch (c){
	case 0:	tempChar = 'E'; tempCharValue = 8; break;
	case 1: tempChar = 'E'; tempCharValue = 8; break;
	case 2: tempChar = 'E'; tempCharValue = 8; break;
	case 3: tempChar = 'T'; tempCharValue = 9; break;
	case 4: tempChar = 'T'; tempCharValue = 9; break;
	case 5: tempChar = 'T'; tempCharValue = 9; break;
	case 6: tempChar = 'F'; tempCharValue = 10; break;
	case 7: tempChar = 'F'; tempCharValue = 10; break;
	default: break;
	}
}

void pushPop(STACK &one, char x, char &tempChar, int &tempCharValue, string tempString, char tempCharBackup, int charValueBackup){
	one.insert(x);
	one.insert(tempChar);
	iterateToPush(one, tempString);
	one.display();
	tempChar = tempCharBackup;
	tempCharValue = charValueBackup;
}

void choices(STACK &one, string tempString, string word, char x, char tempChar, char tempCharBackup, int &tempCharValue, int charValueBackup, bool &continueToMatch){
	testIfValid(tempString, word);
	if (tempString.at(0) == 's'){
		pushPopS(one, x, tempChar, tempString, continueToMatch);
	}
	else if (tempString.at(0) == 'r'){
		pushPopR(one, x, tempChar, tempString, continueToMatch, tempCharValue);
	}
	else {
		pushPop(one, x, tempChar, tempCharValue, tempString, tempCharBackup, charValueBackup);
	}
}

void isWordAccepted(string word) {
	string parseTable[16][11] =
	{// i  +  -  *  /  (  )  $  E  T  F
	{ "s5", "NULL", "NULL", "NULL", "NULL", "s4", "NULL", "NULL", "1", "2", "3" }, //0
	{ "NULL", "s6", "s7", "NULL", "NULL", "NULL", "NULL", "acc", "NULL", "NULL", "NULL" }, //1
	{ "NULL", "r3", "r3", "s8", "s9", "NULL", "r3", "r3", "NULL", "NULL", "NULL" }, //2
	{ "NULL", "r6", "r6", "r6", "r6", "NULL", "r6", "r6", "NULL", "NULL", "NULL" }, //3
	{ "s5", "NULL", "NULL", "NULL", "NULL", "s4", "NULL", "NULL", "a", "2", "3" }, //4
	{ "NULL", "r8", "r8", "r8", "r8", "NULL", "r8", "r8", "NULL", "NULL", "NULL" }, //5
	{ "s5", "NULL", "NULL", "NULL", "NULL", "s4", "NULL", "NULL", "NULL", "b", "3" }, //6
	{ "s5", "NULL", "NULL", "NULL", "NULL", "s4", "NULL", "NULL", "NULL", "c", "3" }, //7
	{ "s5", "NULL", "NULL", "NULL", "NULL", "s4", "NULL", "NULL", "NULL", "NULL", "d" }, //8
	{ "s5", "NULL", "NULL", "NULL", "NULL", "s4", "NULL", "NULL", "NULL", "NULL", "e" }, //9
	{ "NULL", "s6", "s7", "NULL", "NULL", "NULL", "sf", "NULL", "NULL", "NULL", "NULL" }, //a
	{ "NULL", "r1", "r", "s6", "s9", "NULL", "r1", "r2", "NULL", "NULL", "NULL" }, //b
	{ "NULL", "r2", "r2", "s8", "s9", "NULL", "r2", "r2", "NULL", "NULL", "NULL" }, //c
	{ "NULL", "r4", "r4", "r4", "r4", "NULL", "r4", "r4", "NULL", "NULL", "NULL" }, //d
	{ "NULL", "r5", "r5", "r5", "r5", "NULL", "r5", "r5", "NULL", "NULL", "NULL" }, //e
	{ "NULL", "r7", "r7", "r7", "r7", "NULL", "r7", "r7", "NULL", "NULL", "NULL" } }; //f

	STACK one;
	one.insert('0');
	bool continueToMatch = true;
	string tempString;
	cout << "TESTING for word " << word << endl;
	for (int i = 0; i<word.length(); ++i) { //iterate through string to get char
		char tempChar = word[i];
		char tempCharBackup = word[i];
		int tempCharValue = NULL;           //value associated to char to be used for table
		int charValueBackup = NULL;
		switch (tempChar) {
		case 'i': tempCharValue = 0; charValueBackup = 0; break;
		case '+': tempCharValue = 1; charValueBackup = 1; break;
		case '-': tempCharValue = 2; charValueBackup = 2; break;
		case '*': tempCharValue = 3; charValueBackup = 3; break;
		case '/': tempCharValue = 4; charValueBackup = 4; break;
		case '(': tempCharValue = 5; charValueBackup = 5; break;
		case ')': tempCharValue = 6; charValueBackup = 6; break;
		case '$': tempCharValue = 7; charValueBackup = 7; break;
		case 'E': tempCharValue = 8; charValueBackup = 8; break;		
		case 'T': tempCharValue = 9; charValueBackup = 9; break;		
		case 'F': tempCharValue = 10; charValueBackup = 10; break;
		default: break;
		}

		continueToMatch = true;
		while (continueToMatch)	{
			char x = one.pop();
			switch (x) {
			case '0':
				tempString = parseTable[0][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '1':
				tempString = parseTable[1][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '2':
				tempString = parseTable[2][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '3':
				tempString = parseTable[3][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '4':
				tempString = parseTable[4][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '5':
				tempString = parseTable[5][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '6':
				tempString = parseTable[6][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '7':
				tempString = parseTable[7][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '8':
				tempString = parseTable[8][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case '9':
				tempString = parseTable[9][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case 'a':
				tempString = parseTable[10][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case 'b':
				tempString = parseTable[11][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case 'c':
				tempString = parseTable[12][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case 'd':
				tempString = parseTable[13][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case 'e':
				tempString = parseTable[14][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;

			case 'f':
				tempString = parseTable[15][tempCharValue];
				choices(one, tempString, word, x, tempChar, tempCharBackup, tempCharValue, charValueBackup, continueToMatch);
				break;
			}
		}
	}
	cout << endl << endl;
}

int main(int argc, const char * argv[]) {
	string testOne = "(i+i)*i$";	//accepted
	string testTwo = "i*(i-i)$";	//accpeted
	string testThree = "i(i+i)$";	//rejected

	// run one test at a time
	isWordAccepted(testTwo);

	return 0;
}