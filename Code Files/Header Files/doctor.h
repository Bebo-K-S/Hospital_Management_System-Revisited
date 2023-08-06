#ifndef DOCTOR_H
#define DOCTOR_H


#include <String>
using namespace std;

class Doctor
{
private:
	string _name, _id;
	int availableFrom, availableTo;

public:
	
	/* Constructors */
	Doctor();
	Doctor(string, int);

	/* Getter Functions */
	string getName();
	string getID();

	/* Setter Functions */
	void setName(string);
	void setID(int);
	void setAvailabilty(int, int);

};

#endif