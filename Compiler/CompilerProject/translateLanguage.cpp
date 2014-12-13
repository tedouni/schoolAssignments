
// Tayseer Edouni
// David Laosen
//


#include "translateLanguage.h"


void translateProgram(){
    ifstream inFile;
    ofstream outFile;
    
    string a, b, c, d;
    
    inFile.open("finalv2.txt");
    outFile.open("translate.txt");
    
    if (!inFile){
        cout << "finalv2.txt not found\n" << endl;
    } else {
        cout << "translate.txt file created\n" << endl;
        while (!inFile.eof()){								//while file has not ended
            while (inFile >> a){							//read line by line
                copy(a.begin(), a.end(), back_inserter(b));
                b += " ";
            }
            
            size_t Beg = b.find("PROGRAM");					//write beginning of file
            b.erase(Beg, (b.find(";", Beg) - Beg) + 2);
            c += "#include <iostream>\n";
            c += "using namespace std;\n";
            c += "int main()\n";
            c += "{\n";
            
            Beg = b.find("VAR");							//write variables up to beginning
            b.erase(Beg, (b.find("R", Beg) - Beg) + 2);
            c += " ";
            Beg = b.find(":");
            a.clear();
            d.clear();
            a = b;
            a.erase(a.begin(), a.begin() + Beg + 2);
            copy(a.begin(), a.begin() + 7, back_inserter(d));
            if (d == "INTEGER"){
                c += "int ";
            }
            copy(b.begin(), b.begin() + Beg, back_inserter(c));
            c += ";";
            Beg = b.find("BEGIN");
            c += "\n";
            b.erase(0, Beg);
            
            Beg = b.find("BEGIN");							//write beginning up to write
            b.erase(Beg, (b.find("N", Beg) - Beg) + 2);
            c += " ";
            Beg = b.find("WRITE");
            d.clear();
            copy(b.begin(), b.begin() + Beg, back_inserter(d));
            stringstream ss(d);
            while (ss.good()){
                a.clear();
                ss >> a;
                if (a == "=" || a == "+" || a == "-" || a == "*" || a == "/"){
                    c += " ";
                    c += a;
                    c += " ";
                } else if (a == ";"){
                    c += " ";
                    c += a;
                    c += "\n ";
                } else if (a == "("){
                    c += a;
                    c += " ";
                } else if (a == ")"){
                    c += " ";
                    c += a;
                } else {
                    c += a;
                }
            }
            b.erase(0, Beg);
            
            b.erase(0, 7);									//use write of what's between parenthesis
            c += "cout<<";
            Beg = b.find(")");
            copy(b.begin(), b.begin() + Beg - 1, back_inserter(c));
            b.erase(0, (b.find(";") + 2));
            c += "<<endl\n";
            
            
            Beg = b.find("END");							//write ending of file
            b.erase(Beg, (b.find(".", Beg) - Beg) + 2);
            c += " return 0;\n";
            c += "}\n";
            
            outFile << c << endl;
        }
    }
    
    inFile.close();
    outFile.close();
}
