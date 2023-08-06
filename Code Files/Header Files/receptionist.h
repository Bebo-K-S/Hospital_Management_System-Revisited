#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <String>
using namespace std;

class Receptionist
{
private:
	string _name, _id;

public:

	/* Constructors */
	Receptionist();
	Receptionist(string name, int id);

	/* Getter Functions */
	string getName();
	string getID();

	/* Setter Functions */
	void setName(string name);
	void setID(int id);

};

#endif // !RECEPTIONIST.H