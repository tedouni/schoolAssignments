//Tayseer Edouni Assignment 10
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MONTH
{
	string MonthName;
	int MonthDays;
};

struct NODE
{
	string name;
	int day;
	NODE *left, *right;
};

NODE* root;

void insert(NODE *&r, string x, int d); 
void displayInOrder(NODE *&r); //Part One (LC)(P)(RC)
void displayLeavesInOrder(NODE *&r); //Part Two
void displayParentsWithTwoChildren(NODE *&r); //Part three
void displayParentswithOneChild(NODE *&r); //Part IV
void searchForMonth(NODE *&r, string word, bool &found);

int main()
{


	root = NULL;

	MONTH a[12] = { { "January", 31 }, { "February", 28 }, { "March", 31 },
{ "April", 30 }, { "May", 31 },{ "June", 30 }, { "July", 31 },
{ "August", 31 }, { "September", 30 }, { "October", 31 }, { "November", 30 }, 
{ "December", 31 } };

	for (int i = 0; i < 12; i++)
{
	insert(root, a[i].MonthName,a[i].MonthDays);
}

	cout << left << setw(12);
	cout << "Month name" << "No. Days\n";
	cout << "------------------------\n";
	displayInOrder(root);
	cout << endl;
	cout << "Leaves of tree are: ";
	displayLeavesInOrder(root);
	cout << endl;
	cout << endl;
	cout << "Parents with two children: ";
	displayParentsWithTwoChildren(root);
	cout << endl;
	cout << endl;
	cout << "Parents with only one child: ";
	displayParentswithOneChild(root);
	cout << endl;
	cout << endl;

	char toContinue;
	do
{

		cout << "Enter a month name: ";
		string nameOfMonth;
		cin >> nameOfMonth;
		bool found = 0;
		searchForMonth(root, nameOfMonth, found);
		cout << "CONTINUE (y/n)? ";
		cin >> toContinue;
}while (toContinue !='n');
	cout << endl;

	return 0;
}

void insert(NODE *&r, string x, int d)
{
	if (r == NULL)
	{
		r = new NODE;
		r->name = x;
		r->day = d;
		r->left = r->right = NULL;
	}

	else if (x < r->name)
		insert(r->left, x,d);
	else
		insert(r->right, x,d);

}

void displayInOrder(NODE *&r)
{
	if (r != NULL)
	{
		cout << left << setw(15);
		displayInOrder(r->left);
		cout << r->name << r->day<<endl;
		cout << left << setw(15);
		displayInOrder(r->right);
	}
}

void displayLeavesInOrder(NODE *&r)
{
	if (r != NULL)
	{
		displayLeavesInOrder(r->left);
		if (r->left == NULL & r->right == NULL)
		{
			cout << r->name <<" ";
		}
		displayLeavesInOrder(r->right);
	}
}

void displayParentsWithTwoChildren(NODE *&r)
{
	if (r != NULL)
	{
		displayParentsWithTwoChildren(r->left);
		if (r->left !=NULL & r->right != NULL)
		{
			cout << r->name << " ";
		}
		displayParentsWithTwoChildren(r->right);
	}
}

void displayParentswithOneChild(NODE *&r)
{
	if (r != NULL)
	{
		displayParentswithOneChild(r->left);
		if ( (r->left!=NULL && r->right==NULL) || (r->left==NULL && r->right!=NULL))
		{
			cout << r->name << " ";
		}
		displayParentswithOneChild(r->right);
	}
}

void searchForMonth(NODE *&r, string word, bool &found)
{
	if (r == NULL) found = false;
	else if (word == r->name)
	{
		found = true;
		cout << "There are " << r->day << " days in the month of " << r->name << endl;
	}
	else if (word < r->name) searchForMonth(r->left, word, found);
	else
		searchForMonth(r->right, word, found);

	
}
