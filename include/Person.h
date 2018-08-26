#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        string firstName;
        string lastName;
        int iq;
    public:
        Person();
        string getFirst() const;
        string getLast() const;
        int getIQ() const;
        void setFirst(string f);
        void setLast(string l);
        void setIQ(int i);
};


struct dimension{
    int width;
    int height;
};
struct position{
    int pos_x;
    int pos_y;
};


#endif // PERSON_H
