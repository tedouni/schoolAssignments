
// Tayseer Edouni
// David Laosen
// format.cpp


#include "format.h"

void formatTextFile(){
	ifstream inFile;
	ofstream outFile;

	string a, b, c;

	inFile.open("finalv1.txt");
	outFile.open("finalv2.txt");

	if (!inFile){
		cout << "finalv1.txt not found\n" << endl;
	} else {
		cout << "finalv2.txt file created\n" << endl;

		while (!inFile.eof()){										//while file has not ended
			while (getline(inFile, a)){								//read line by line
				stringstream ss(a);
				while (ss.good()){
					ss >> b;										//read word by word of each line
					bool cap = false;								//if word is a token
					for (int i = 0; i < b.size(); i++){
						if (isupper(b[i])){
							cap = true;
						} else {
							cap = false;
						}
					}

					if (cap){										//if word is a token, add space before and after
						c += " ";									//space
						copy(b.begin(), b.end(), back_inserter(c)); //token
						c += " ";									//space
					} else {
						copy(b.begin(), b.end(), back_inserter(c)); //insert word into new string
					}
					b.clear();
				}
				c += "\n";
			}

			while (c.find("(*") != std::string::npos) {				//remove comments
				size_t Beg = c.find("(*");
				c.erase(Beg, (c.find("*)", Beg) - Beg) + 2);
			}

			for (int i = 0; i < c.size(); i++){						//format	
				if (c[i] == ';' || c[i] == ':' || c[i] == '=' || c[i] == ',' || c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/'){
					outFile << " " << c[i] << " ";
				} else if (c[i] == '('){
					outFile << c[i] << " ";
				} else if (c[i] == ')'){
					outFile << " " << c[i];
				} else if (c[i] == '\n' && c[i+1] == '\n'){
					//do nothing if empty space
				} else {
					outFile << c[i];
				}
			}
		}
	}

	inFile.close();
	outFile.close();
}
