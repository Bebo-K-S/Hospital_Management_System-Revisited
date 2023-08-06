#include "nurse.h"

Nurse::Nurse()
{

}

Nurse::Nurse(string name, int id)
{
	setName(name);
	setID(id);
}

string Nurse::getName() {
	return _name;
}

string Nurse::getID() {
	return _id;
}

void Nurse::setName(string name) {
	_name = name;
}

void Nurse::setID(int id) {
	_id = "N-" + to_string(id);
}