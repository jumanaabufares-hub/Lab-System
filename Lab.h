#ifndef LAB_H
#define LAB_H

#include <string>

#include "Patient.h"
#include "LabTech.h"

using namespace std;

class Lab {
public:
    Lab();
    
    ~Lab();
    
    void addLabTech(const string& name);
    
    void addPatient(const string& name, const string& medicalConditions);

    void addLabWork(const string& patientId, LabWorkCode code, double cost);
    
    void processLabWork(const string& labTechId, const string& patientId);
    
    Patient* getPatient(const string& id) const;
    LabTech* getLabTech(const string& id) const;
    
    void printLabTechs() const;
    void printPatients() const;
   
    void printLabTechLabWork(const string& id) const;
    
    void printPatientPendingLabWork(const string& id) const;
    void printPatientMedicalHistory(const string& id) const;
    
    void resetIds();

private:
    static const int MAX_PATIENTS = 1000;//large num for the array
    static const int MAX_LABTECHS = 500;
    // array list structure
    Patient* patients[MAX_PATIENTS];
    LabTech* labTechs[MAX_LABTECHS];

    //number of patiens and labtechs in the arrays
    int patientsNum;
    int labTechsNum;
    
    int extractIdNumber(const string& id) const;
};

#endif