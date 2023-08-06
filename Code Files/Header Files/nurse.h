#ifndef NURSE_H
#define NURSE_H

#include <String>
using namespace std;

class Nurse
{
private:
	string _name, _id;

public:

	/* Constructors */
	Nurse();
	Nurse(string name, int id);

	/* Getter Functions */
	string getName();
	string getID();

	/* Setter Functions */
	void setName(string name);
	void setID(int id);

};

#endif // !NURSE_H