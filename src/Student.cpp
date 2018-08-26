#include "Student.h"
#include "Campus.h"
#include <string>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

Student::Student()
{
    firstName = "";
    lastName = "";
    iq = 0;
}

Student::Student(string first, string last, int i)
{
    setFirst(first);
    setLast(last);
    setIQ(i);
}


void Student::go_to_campus(Campus &a){
    spot = a.addStudent();
}

void Student::setIQ(int val){
    iq = val;
}

int Student::getIQ() const{
    return iq;
}

string Student::getFirstName(){
    return firstName;
}

string Student::getLastName(){
    return lastName;
}
int Student::getCurrentXCoordinate() {
	return spot.pos_x;
}

int Student::getCurrentYCoordinate() {
	return spot.pos_y;
}
void Student::pickUpTrash() {
    cout << getFirstName() << " is picking up trash" << endl;
    Trash trash = Trash();
    trash.getTypeAndValue();

	if (pocketTrash < 10) {
		pocket[pocketTrash] = trash;
		cout << getFirstName() << " has added " << trash.getType() << " to their pocket " << endl;
		pocketTrash++;
	}
	else {
		int minimumValue = INT_MAX;
		int index;

		for (int i = 0; i < 10; i++) {
			if (pocket[i].getValue() < minimumValue) {
				minimumValue = pocket[i].getValue();
				index = i;
			}
		}
		if (minimumValue < trash.getValue()) {
			cout << "replacing a " << pocket[index].getType() << " with value " << pocket[index].getValue() << endl;
			pocket[index] = trash;
			cout << getFirstName() << " has replaced his previous trash with " << trash.getType() << " with value " << trash.getValue() << endl;
		}
		else { //else, don't keep the new trash
			cout << getFirstName() << " has no room for trash of lesser value, " << trash.getType() << "has been removed from campus " << endl;
		}
	}
}

void Student::studentMoveTeacher(Campus& a) {
		cout << getFirstName() << " is moving to the teacher" << endl;
		int newX = spot.pos_x;
		int newY = spot.pos_y;
		Position teacherCor = a.getTeacherCor();
		bool up = a.canMoveBuilding(newX, newY - 1);
		bool down = a.canMoveBuilding(newX, newY + 1);
		bool left = a.canMoveBuilding(newX - 1, newY);
		bool right = a.canMoveBuilding(newX + 1, newY);
		if (teacherCor.pos_x > spot.pos_x && right) {
			newX = newX + 1;
		}
		else if (teacherCor.pos_x < spot.pos_x && left) {
			newX = newX - 1;
		}
		else if (teacherCor.pos_y > spot.pos_y && down) {
			newY = newY + 1;
		}

		else if (teacherCor.pos_y < spot.pos_y && up) {
			newY = newY - 1;
		}

		else if ((newY + 1 == teacherCor.pos_y && newX == teacherCor.pos_x) || (newY - 1 == teacherCor.pos_y && newX == teacherCor.pos_x) ||
                 (newX + 1 == teacherCor.pos_x && newY == teacherCor.pos_y) || (newX - 1 == teacherCor.pos_x && teacherCor.pos_y)){
			cout << getFirstName() << "'s Score is " << getScore() << endl;
			cout << "with items: " << endl;
			emptyPockets();
			cout << endl;
			a.campusSpace[newX][newY] = 'B';
			a.updateNumberOfStudents();
			done = true;

		}

		else if (newX == spot.pos_x && newY == spot.pos_y) {
			cout << getFirstName() << " is blocked, and will wait a turn" << endl;
		}

		if (newX != spot.pos_x || newY != spot.pos_y){
			cout << getFirstName() << " will move to (" << newX << ", " << newY << ")" << endl;
		}


		updatePositionTeacher(a, newX, newY);

}
Position Student::studentMove(Campus &a) {
	int newX = spot.pos_x;
	int newY = spot.pos_y;
	Position closeTrash = a.findClosestTrash(newX, newY);
	bool up = a.canMove(newX, newY - 1);
	bool down = a.canMove(newX, newY + 1);
	bool left = a.canMove(newX - 1, newY);
	bool right = a.canMove(newX + 1, newY);
	if (closeTrash.pos_x > spot.pos_x && right) {
		newX = newX + 1;
	}
	else if (closeTrash.pos_x < spot.pos_x && left) {
		newX = newX - 1;
	}
	else if (closeTrash.pos_y > spot.pos_y && down) {
		newY = newY + 1;
	}

	else if (closeTrash.pos_y < spot.pos_y && up) {
		newY = newY - 1;
	}
	if (newX == spot.pos_x && newY == spot.pos_y) {
		cout << getFirstName() << " is blocked, and will wait a turn" << endl;
	}

	else {
		cout << getFirstName() << " will move to (" << newX << ", " << newY << ")" << endl;
	}
	if (a.campusSpace[newX][newY] == 'T') {
		cout << getFirstName() << " stepped on trash" << endl;
		pickUpTrash();

	}
	updatePosition(a, newX, newY);
}
void Student::studentMoveDoor(Campus& a) {
	cout << getFirstName() << " is moving to the door" << endl;
	int newX = spot.pos_x;
	int newY = spot.pos_y;
	Position doorCor = a.getDoorCor();
	bool up = a.canMove(newX, newY - 1);
	bool down = a.canMove(newX, newY + 1);
	bool left = a.canMove(newX - 1, newY);
	bool right = a.canMove(newX + 1, newY);
	if (doorCor.pos_x > spot.pos_x && right) {
		newX = newX + 1;
	}
	else if (doorCor.pos_x< spot.pos_x && left) {
		newX = newX - 1;
	}
	else if (doorCor.pos_x > spot.pos_y && down) {
		newY = newY + 1;
	}

	else if (doorCor.pos_y < spot.pos_y && up) {
		newY = newY - 1;
	}
	if (newX == spot.pos_x && newY == spot.pos_y) {
		cout << getFirstName() << " is blocked, and will wait a turn" << endl;
	}

	else {
		cout << getFirstName() << " will move to (" << newX << ", " << newY << ")" << endl;
		updatePosition(a, newX, newY);
	}
	if (newX == doorCor.pos_x && newY == doorCor.pos_y) {
		door = false;
	}
    updatePosition(a, newX, newY);
}
int Student::getScore() {
	score = 0;
	for (int i = 0; i < trashInPocket; i++) {
		score = score + pocket[i].getValue();
	}
	return score;

}

void Student::updatePosition(Campus &a, int x, int y) {
	a.campusSpace[x][y] = 'S';
	if (spot.pos_x == a.getDoorCor().pos_x && spot.pos_y == a.getDoorCor().pos_y) {
		a.campusSpace[spot.pos_x][spot.pos_y] = 'D';
	}
	else {
		a.campusSpace[spot.pos_x][spot.pos_y] = ' ';
	}
	spot.pos_x = x;
    spot.pos_y = y;

}

void Student::updatePositionTeacher(Campus& a, int x, int y) {
	a.campusSpace[x][y] = 'S';
	if (spot.pos_x == a.building_size - 1 && spot.pos_y == a.building_size - 1) {
		a.campusSpace[spot.pos_x][spot.pos_y] = 'D';
	}
	else {
		a.campusSpace[spot.pos_x][spot.pos_y] = 'B';
	}
	spot.pos_x = x;
	spot.pos_y = y;
}

bool Student::isGoingToDoor(){
	return door;
}



void Student::emptyPockets(){
	cout << getFirstName() << "'s items are: " << endl;
	for (int i = 0; i < trashInPocket; i++) {
		cout << "Item " << i + 1 << " is " << pocket[i].getType() << ", with value: " << pocket[i].getValue() << endl;
	}
}

bool Student::isDone() {
	return done;
}

