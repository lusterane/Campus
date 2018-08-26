#ifndef CAMPUS_H
#define CAMPUS_H
#include <iostream>
#include <string>

using namespace std;
static const int MAX = 25;

struct Position{
    int pos_x;
    int pos_y;
};
class Campus
{
    public:
        friend class Student;
        char arr[MAX][MAX];
        int campus_size;
        int campusSpace[MAX][MAX];
        int building_size;
        int getCampusDimension();
        int getBuildingDimension();
        Campus(int b, int a);
        Campus();
        Position getDoorCor();
        friend ostream& operator << (ostream& os, Campus& C);
        bool canMove(int x, int y);
        int getNumTrashItems();
        int getNumberOfStudents();
        int numberOfStudents = 0;
        int teacherX;
        int teacherY;
    private:
        int totalTrash;
        void buildCampus();
        void placeTrash();
        char getPositionValue(int x, int y);
        bool canMoveBuilding(int x, int y);
        void updateNumberOfStudents();
        Position getTeacherCor();
        Position addStudent();
        Position findClosestTrash(int x, int y);
};

#endif // CAMPUS_H
