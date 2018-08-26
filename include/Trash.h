#ifndef TRASH_H
#define TRASH_H
#include <iostream>
#include <string>
#endif

using namespace std;
class Trash
{
public:
	Trash();
	void getTypeAndValue();
	int getValue();
	string getType();
protected:

private:
	string type1;
	int value1;


};
