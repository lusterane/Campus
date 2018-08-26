#include "Trash.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;
Trash::Trash()
{
    ifstream trashFile("trash.txt");
	string placeholder;
	if (trashFile.is_open()) {
		getline(trashFile, placeholder);
		int trashSize = atoi(placeholder.c_str());
		int trashIndex = rand()%trashSize+1;
		for (int i = 0; i <= trashIndex; i++) {
			getline(trashFile, placeholder);
			int spaceIndex = placeholder.find(" ");
			string type = placeholder.substr(0, spaceIndex);
			string stringValue = placeholder.substr(spaceIndex + 1);
			int value = atoi(stringValue.c_str());

			value1 = value;
			type1 = type;
		}
	}
	else {
		cout << "Error: could not open trash file" << endl;
	}
	trashFile.close();
}

void Trash::getTypeAndValue() {
	cout << "Trash is type " << type1 << " with a value of " << value1 << endl;
}

int Trash::getValue() {
	return value1;
}

string Trash::getType() {
	return type1;
}

