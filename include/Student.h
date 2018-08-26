#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Campus.h"
#include <iostream>
#include <string>
#include "Trash.h"

using namespace std;
class Student: public Person
{
    friend class Campus;
    private:
        Position spot;
        string firstName;
        string lastName;
        int iq;
        Trash pocket[10];
        void pickUpTrash();
        int trashInPocket;
        int pocketTrash = 0;
        int score = 0 ;
        void updatePosition(Campus& myCampus, int x, int y);
        void updatePositionTeacher(Campus& myCampus, int x, int y);
        bool door = true;
        bool done = false;

    public:
        Student();
        Student(string first, string last, int i);
        void go_to_campus(Campus& a);
        void setIQ(int val);
        string getFirstName();
        string getLastName();
        int getIQ() const;
        int getScore();
        void emptyPockets();
        Position studentMove(Campus &mycampus);
        friend ostream& operator << (ostream& ostream, Student& S);
        void studentMove(struct dimension *dim);
        void studentMoveDoor(Campus &myCampus);
        void studentMoveTeacher(Campus &myCampus);
        bool isDone();
        int getCurrentXCoordinate();
        int getCurrentYCoordinate();
        bool isGoingToDoor();
};

#endif // STUDENT_H
