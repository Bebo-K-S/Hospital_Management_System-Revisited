#include "doctor.h"

/* Constructors */

Doctor::Doctor()
{

}

Doctor::Doctor(string name, int id)
{
	setName(name);
	setID(id);
}

/* Getter Functions */

string Doctor::getName(){
	return _name;
}

string Doctor::getID(){
	return _id;
}

/* Setter Functions */

void Doctor::setName(string name){
	_name = name;
}

void Doctor::setID(int id){
	_id = "Dr-" + to_string(id);
}

void Doctor::setAvailabilty(int from, int to)
{
	availableFrom = from;
	availableTo = to;
}