#include "Lab.h"
#include <iostream>

using namespace std;


Lab::Lab() : patients(), labTechs(), patientsNum(0), labTechsNum(0) {}


Lab::~Lab() {
    for (int i = 0; i < labTechsNum; i++) {
        delete labTechs[i];
    }
    
    for (int i = 0; i < patientsNum; i++) {
        delete patients[i];
    }
    
    
}

//Find and return the given Patient, or else return nullptr
Patient* Lab::getPatient(const string& id) const {
    for (int i = 0; i < patientsNum; i++) {
        if (patients[i]->getId() == id) {
            return patients[i];
        }
    }
    return nullptr;
}
//Find and return the given labTEch, or else return nullptr
LabTech* Lab::getLabTech(const string& id) const {
    for (int i = 0; i < labTechsNum; i++) {
        if (labTechs[i]->getId() == id) {
            return labTechs[i];
        }
    }
    return nullptr;
}


void Lab::addLabTech(const string& name) {

    LabTech* LTech = new LabTech(name);

    labTechs[labTechsNum] = LTech;

    labTechsNum++;

    cout << "Added LabTech: ";
    LTech->print();
}


void Lab::addPatient(const string& name, const string& medicalConditions) {

    //add a new Patient with the given parameters
    Patient* patient = new Patient(name, medicalConditions);

    patients[patientsNum] = patient;
    patientsNum++;
    
    cout << "Added Patient: ";
    patient->print();
}


void Lab::addLabWork(const string& patientId, LabWorkCode code, double cost) {
    // check if the patientexist
    Patient* patient = getPatient(patientId);
    if (patient == nullptr) {
        cout << "Error, Patient " << patientId << " does not exist" << endl;
        return;
    }
    
    //make a new LabWork and add it to that Patient
    LabWork* labWork = new LabWork(code, cost);

    patient->addLabWork(labWork);
    
    cout << "new labWork Added to the the patient (" << patientId << "): "<<endl;
    labWork->print();
}


void Lab::processLabWork(const string& labTechId, const string& patientId) {
    //check if lab tech exist
    LabTech* labtech = getLabTech(labTechId);
    if (labtech == nullptr) {
        cout << "Error, LabTech " << labTechId << "  does not exist" << endl;
        return;
    }
    //check if patient exists
    Patient* patient = getPatient(patientId);
    if (patient == nullptr) {
        cout << "Error, Patient " << patientId << " does not exist" << endl;
        return;
    }
    //if theresno labwork
    if (!patient->hasPendingLabWork()) {
        cout << "Error, Patient " << patientId << " pending LabWork does not exist" << endl;
        return;
    }
    
    //process the next LabWork from the Patient
    LabWork* labWork = patient->processLabWork();
    
    //call LabWork::completeLabWork with the LabTech id
    labWork->completeLabWork(labtech->getId());

    // and add the LabWork to the LabTech
    labtech->addLabWork(labWork);
    
    cout << "Processed LabWork: "<<endl;
    labWork->print();
    cout << " from: LabTech: " << labtech->getId() << ", Patient: " << patient->getId()  << endl;
}

void Lab::printLabTechs() const {
    cout << "Lab Techs " << endl;
    
    if (labTechsNum == 0) {
        cout << "no lab techs available." << endl;
        return;
    }
    //print all the labtechs
    for (int i = 0; i < labTechsNum; i++) {
        labTechs[i]->print();
        cout << endl;
    }
}

void Lab::printPatients() const {
    
    cout << "Patients: " << endl;
    
    if (patientsNum == 0) {
        cout << "no patients available." << endl;
        return;
    }
    //print all the Patients
    for (int i = 0; i < patientsNum; i++) {
        patients[i]->print();
        cout << endl;
    }
}


void Lab::printLabTechLabWork(const string& id) const {
    // print the given LabTech with LabWork.
    LabTech* Ltech = getLabTech(id);
    
    if (Ltech == nullptr) {
        cout << "Error, id not found." << endl;
        return;
    }
    
    cout << "LabTech with LabWork: " << endl;
    Ltech->printLabWork();
}


void Lab::printPatientPendingLabWork(const string& id) const {
    Patient* patient = getPatient(id);
    
    if (patient == nullptr) {
        cout << "Error, id not found." << endl;
        return;
    }
    
    cout << "Patient Pending LabWork: " << endl;
    patient->printPendingLabWork();
}


void Lab::printPatientMedicalHistory(const string& id) const {
    Patient* patient = getPatient(id);
    
    if (patient == nullptr) {
        cout << "Error, id not found."<< endl;
        return;
    }
        //print Patient’s processed LabWork.

    cout << "Patient Medical History: " << endl;
    patient->printMedicalHistory();
}


void Lab::resetIds() {
    //alls resetIds on the Patient and LabTech classes
    Patient::resetId();
    LabTech::resetId();
}