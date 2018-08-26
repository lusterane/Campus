#include "Person.h"
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

Person::Person()
{
    firstName = "";
    lastName = "";
    iq = 0;
}
string Person::getFirst() const
{
    return firstName;
}

string Person::getLast() const
{
    return lastName;
}

int Person::getIQ() const
{
    return iq;
}

void Person::setFirst(string f)
{
    firstName = f;
}

void Person::setLast(string l)
{
    lastName = l;
}

void Person::setIQ(int i)
{
    iq = i;
}


