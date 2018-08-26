#include "Campus.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <tgmath.h>
#include <string>

using namespace std;

Campus::Campus(int b, int a) {
	if (b > MAX || a >= b || b <3 || a<2) {
		cout << "Error, campus size must be between 3 and 25, and the building must be smaller than campus, but greater than 1.";
	}
	else {
		campus_size = b;
		building_size = a;
		buildCampus();
	}

}

int Campus::getCampusDimension(){
    return campus_size;
}
int Campus::getBuildingDimension(){
    return building_size;
}
char Campus::getPositionValue(int x, int y){
    return campusSpace[x][y];
}
void Campus::placeTrash() {
	int x = rand()%campus_size;
	int y;

	// if x is outside the building, the y coordinate has no bounds besides campus size -1
	if (x >= building_size) {
		y = rand()%campus_size;
	}

	// x must be within the building, so y can only be between outside the building, but inside the campus
	else {
		y = rand()% (campus_size - building_size) + building_size;
	}


	campusSpace[x][y] = 'T';
	totalTrash++;

}

void Campus::buildCampus()
{/*
    for(int i = 0; i < campus_size; i++){
        for(int j = 0; j < campus_size; j++){
            arr[i][j] = ' ';
        }
    }
    for(int i = 0; i < building_size; i++){
        for(int j = 0; j < building_size; j++){
            arr[i][j] = 'S';
        }
    }
    arr[building_size-1][building_size-1] = 'D';
    double doubCampus = (pow((double)campus_size, 2.0) - pow((double)building_size, 2.0)) * .1;
    int counter = (int)doubCampus;
    while(counter > 0){
        int randX = rand()%campus_size+1;
        int randY = rand()%campus_size+1;
        if(arr[randX][randY] == ' '){
            arr[randX][randY] = 'T';
            counter--;
        }
    }*/
	for (int i = 0; i < campus_size; i++) {
		for (int j = 0; j < campus_size; j++) {
			campusSpace[i][j] = ' ';
		}
	}

	// Make Building
	for (int i = 0; i < building_size; i++) {
		for (int j = 0; j< building_size; j++) {
			campusSpace[i][j] = 'B';
		}

	}

	// Make Door
	campusSpace[building_size - 1][building_size - 1] = 'D';

	//randomly placing a teacher in the building, but not overlapping the door
	teacherX = rand()%(building_size-1)+0;
	teacherY = rand()%(building_size-1)+0;

	//places the teacher
	campusSpace[teacherX][teacherY] = 'F';

	//Placing randomly placed trashcans for 10% of the blank space, rounded down
	int blankSpace = campus_size * campus_size - building_size * building_size;
	int numTrash = blankSpace / 10;
	for (int i = 0; i < numTrash; i++) {
		placeTrash();
	}
	cout << "the total trash on campus is " << totalTrash << endl;
}
Position Campus::getDoorCor() {
	Position doorCor = Position();
	doorCor.pos_x = building_size - 1;
	doorCor.pos_y = building_size - 1;
	return doorCor;


}
int Campus::getNumTrashItems() {
	int total = 0;
	for (int i = 0; i < campus_size; i++) {
		for (int j = 0; j < campus_size; j++) {
			if (campusSpace[i][j] == 'T') {
				total = total + 1;
			}
		}
	}
	return total;
}
int Campus::getNumberOfStudents() {
	return numberOfStudents;
}
Position Campus::getTeacherCor() {
	Position teacherCor = Position();
	teacherCor.pos_x = teacherX;
	teacherCor.pos_y = teacherY;
	return teacherCor;

}
Position Campus::addStudent()
{
	int x = campus_size+0;
	int y = campus_size+0;
	if (campusSpace[x][y] == ' ') {
		campusSpace[x][y] = 'S'; //if the proposed space is blank, put in an S
		numberOfStudents = numberOfStudents + 1; //adds a value to the counter every time a student is added
		Position returnPosition; //used to return a coordinate for this function
		returnPosition.pos_x = x;
		returnPosition.pos_y = y;

		return returnPosition;
	}
	else {
		return addStudent();
	}

}

bool Campus::canMoveBuilding(int x, int y) {
	if (x < 0 || x > building_size - 1 || y < 0 || y > building_size - 1) {
		return false;
	}
	char spot = campusSpace[x][y];
	if (spot == 'B' || spot == 'D') {
		return true;
	}
	return false;
}

void  Campus::updateNumberOfStudents() {
	numberOfStudents = numberOfStudents - 1;
}

Position Campus::findClosestTrash(int x, int y) {
	int distance;
	int minDistance = INT_MAX;
	Position nearTrash = Position();
	for (int i = 0; i < campus_size; i++) {
		for (int j = 0; j < campus_size; j++) {
			if (campusSpace[i][j] == 'T') {
				distance = abs(x - i) + abs(y - j);
				if (distance < minDistance) {
					minDistance = distance;
					nearTrash.pos_x = i;
					nearTrash.pos_y = j;
				}
			}
		}
	}
	return nearTrash;

}
bool Campus::canMove(int x, int y) {
	if (x < 0 || x > campus_size - 1 || y < 0 || y > campus_size - 1) {
		return false;
	}
	char spot = campusSpace[x][y];
	if (spot == ' ' || spot == 'D' || spot == 'T') {
		return true;
	}
	return false;
}

ostream& operator << (ostream& ostream, Campus& C){
    for(int i = 0; i < C.getCampusDimension(); i++){
        for(int j = 0; j < C.getCampusDimension(); j++){
            ostream << C.getPositionValue(i,j);
        }
        cout << endl;
    }
    return ostream;
}
