#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include "Entity.h"
#include "LabWorkList.h"

class Patient : public Entity {
public:
    // Constructor
    Patient(const string& name, const string& medicalConditions);
    
    static void resetId();
    
    void addLabWork(LabWork* labWork);// Add ptr to the back of the pending LabWork list
    LabWork* processLabWork();
    void print() const override;
    bool hasPendingLabWork() const;
    void printMedicalHistory() const;
    void printPendingLabWork() const;
    
private:
    static const char code;      
    static int nextId;            
    
    string medicalConditions;

    LabWorkList pendingLabWork;    //all the not proccessed LabWork that this Patient has been assigned 
    LabWorkList processedLabWork;   // the medical history of the Patient
};

#endif