#include <iostream>
#include "Student.h"
#include "Campus.h"
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
    srand (time(NULL));
	Campus campus = Campus(10,5);
	Student John = Student("John", "Smith", 100);
	Student Jane = Student("Jane", "Chow", 100);
	John.go_to_campus(campus);
	Jane.go_to_campus(campus);
	cout << "the first student's x position is " << John.getCurrentXCoordinate() << endl;
	cout << "the first student's y position is " << John.getCurrentYCoordinate() << endl;
	cout << "the second student's x position is " << Jane.getCurrentXCoordinate() << endl;
	cout << "the second student's y position is " << Jane.getCurrentYCoordinate() << endl;
	cout << campus << endl;
	int loop = 0;
	while (campus.getNumTrashItems() > 0) {
		John.studentMove(campus);
		Jane.studentMove(campus);
		loop++;
		cout << campus << endl;
	}
	while (campus.getNumberOfStudents() > 0) {
		loop++;
		if (John.isGoingToDoor()) {
			John.studentMoveDoor(campus);
			cout << campus << endl;
		}

		else if (!John.isDone()) {
			John.studentMoveTeacher(campus);
			cout << campus << endl;
		}

		if (Jane.isGoingToDoor()) {
			Jane.studentMoveDoor(campus);
			cout << campus << endl;
		}

		else if (!Jane.isDone()) {
			Jane.studentMoveTeacher(campus);
			cout << campus << endl;
		}



	}

		cout << campus << endl;

		 if (John.getScore() > Jane.getScore()) {
			cout << John.getFirstName() << " is the winner, with score " << John.getScore() << endl;
			John.emptyPockets();
			cout << endl;
		}
		if (Jane.getScore() > Jane.getScore()) {
			cout << Jane.getFirstName() << " is the winner, with score " << Jane.getScore() << endl;
			Jane.emptyPockets();
			cout << endl;
		}
		if (Jane.getScore() == John.getScore()){
			cout << "It's a tie with score " << Jane.getScore()<< endl;

		}

		cout << "took " << loop << " loops to complete" << endl;
}
