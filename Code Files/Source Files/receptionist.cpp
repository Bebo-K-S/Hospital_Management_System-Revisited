#include "receptionist.h"

Receptionist::Receptionist()
{

}

Receptionist::Receptionist(string name, int id)
{
	setName(name);
	setID(id);
}

string Receptionist::getName() {
	return _name;
}

string Receptionist::getID() {
	return _id;
}

void Receptionist::setName(string name) {
	_name = name;
}

void Receptionist::setID(int id) {
	_id = "Rep-" + to_string(id);
}