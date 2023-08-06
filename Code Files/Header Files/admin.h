#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "doctor.h"
#include "nurse.h""
#include "receptionist.h"

class Admin
{
private:
	vector<Doctor> _doctorDB;
	vector<Nurse> _nurseDB;
	vector<Receptionist> _receptionistDB;
	
public:

	/* Doctor Functions */
	bool findDoctorName(string name);
	bool findDoctorID(string id);

	void addDoctorToDB(string name, int id);

	/* Nurse Functions */
	bool findNurseName(string name);
	bool findNurseID(string id);

	void addNurseToDB(string name, int id);

	/* Receptionist Functions */
	bool findReceptionistName(string name);
	bool findReceptionistID(string id);

	void addReceptionistToDB(string name, int id);

};

#endif