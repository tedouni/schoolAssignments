


#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class GradeBook
{
private:
    
    struct Student
    {
        string name;
        double assignments[5];			//Holds all assignments , 5 which pertain to 20% of the total grade
		double totalGrade = 0 ;				//in percent
    };
    
    string nameOfCourse;
    int numberOfStudents = 10;				//Fixed number of students in class
    
    Student classOfStudents[10];			//Constructed Struct of 10 students
    
public:
    GradeBook(string courseName)
    {
        nameOfCourse = courseName;
    }
    
    void collectClassData()
    {
		cout << "\nCollecting class data from class.txt file\n";
        fstream inputFile;
        inputFile.open("/Users/tedouni/Dropbox/Fall2014/CPSC254/AssignmentTwo/CPSC254_AssignmentTwo/GradeBookProject/GradeBookProject/class.txt", ios::in);   //opens file
        int i = 0;
        
		while (!inputFile.eof())
		{
            
			inputFile >> classOfStudents[i].name >> classOfStudents[i].assignments[0] >> classOfStudents[i].assignments[1] >> classOfStudents[i].assignments[2] >> classOfStudents[i].assignments[3] >> classOfStudents[i].assignments[4];
			
			for (int j = 0; j < 5; ++j)
			{
				classOfStudents[i].totalGrade += classOfStudents[i].assignments[j] * 0.20;
			}
            
			sort(classOfStudents[i].assignments, classOfStudents[i].assignments + 5);
			++i;
        }
        
        inputFile.close();
    }
    
	
    void dropLowestGrade()	//Since assignment array is sorted, just have to change index 0 to 100
    {
		cout << endl;
		cout << "Lowest grade has been dropped for all students\n";
		
		for (int i = 0; i < 10; i++)
		{
			classOfStudents[i].totalGrade -= classOfStudents[i].assignments[0] * 0.20;
			classOfStudents[i].assignments[0] = 100;
			classOfStudents[i].totalGrade += classOfStudents[i].assignments[0] * 0.20;
		}
    }
    
    void addExtraCredit()
    {
		cout << "How many percent points would you like to reward the class in extra credit to their total grade: ";
		double extraCredit;
		cin >> extraCredit;
		cout << extraCredit << " % has been awarded to each student\n";
		for (int i = 0; i < 10; i++)
		{
			classOfStudents[i].totalGrade += extraCredit;
		}
    }
    
    void curveAllGrades()
    {
        double allTotalScore = 0;
		double avgTotalGrade = 0;
		double increaseTotalGrade = 0;
        
		const double CURV = 75;
        
		for (int i = 0; i < 10; i++)
		{
            allTotalScore += classOfStudents[i].totalGrade;
		}
        
		avgTotalGrade = allTotalScore / 10;
		cout<<"Average grade in class is: "<<avgTotalGrade<<endl;
        
		if (avgTotalGrade < CURV)
		{
			increaseTotalGrade = CURV - avgTotalGrade;
            cout<<"All grades increased by "<<increaseTotalGrade<<" %"<<endl;
            for (int i = 0; i<10; ++i)
            {
                classOfStudents[i].totalGrade +=increaseTotalGrade;
            }
            cout<<"New average grade is: "<<CURV<<endl;
 		}
        
        else
            cout<<"Grades were not increased\n";
        
    }
    
    void reportPassFail()
    {
		cout << endl;
		cout << "Course Name: " << nameOfCourse;
		cout << endl << endl;
        
        for (int i = 0; i<10; ++i)
        {
            if(classOfStudents[i].totalGrade < 60)
            {
				cout << classOfStudents[i].name << " has earned an F ( " << classOfStudents[i].totalGrade << "%)\n";
            }
            else if( classOfStudents[i].totalGrade < 70 && classOfStudents[i].totalGrade > 60)
            {
                cout << classOfStudents[i].name << " has earned a D ( " << classOfStudents[i].totalGrade << "%)\n";
            }
            else if( classOfStudents[i].totalGrade < 80 && classOfStudents[i].totalGrade > 70)
            {
                cout << classOfStudents[i].name << " has earned a C ( " << classOfStudents[i].totalGrade << "%)\n";
            }
            else if( classOfStudents[i].totalGrade < 90 && classOfStudents[i].totalGrade > 80)
            {
                cout << classOfStudents[i].name << " has earned a B ( " << classOfStudents[i].totalGrade << "%)\n";
            }
            else if( classOfStudents[i].totalGrade > 90)
            {
                cout << classOfStudents[i].name << " has earned an A ( " << classOfStudents[i].totalGrade << "%)\n";
            }
        }
		cout << endl;
    }
    
    
};





int main()
{
	char option, cont;
	cout << "What is the name of this course: ";
	string nameOfCourse;
	cin >> nameOfCourse;
    
	GradeBook myGradeBook(nameOfCourse);
	myGradeBook.collectClassData();
	cout << endl;
	do
	{
		cout << "A: Show Pass/Fail results" << endl;
		cout << "B: Drop Lowest Grade" << endl;
		cout << "C: Curve Grades" << endl;
		cout << "D: Add Extra Credit" << endl;
        cout << "Please select an option: " << endl;

		cin >> option;
		option = toupper(option);
		switch (option)
		{
            case 'A':
                myGradeBook.reportPassFail();
                break;
            case 'B':
                myGradeBook.dropLowestGrade();
                break;
            case 'C':
                myGradeBook.curveAllGrades();
                break;
            case 'D':
                myGradeBook.addExtraCredit();
                break;
            default:
                cout << "ERROR: Please enter a valid option." << endl;
                break;
		}
		cout << "Continue making changes? (Y/N): ";
		cin >> cont;
		cont = toupper(cont);
		cout << endl;
	} while (cont != 'N');
    
	
    return 0;
}
