
#include "LabWork.h"

const string LabWork::LABTESTS[NUM_LABTESTS] = {
    "Blood Test",
    "Urine Test",
    "X-Ray",
    "MRI",
    "CT Scan",
    "Ultrasound",
    "Biopsy",
    "Genetic Test",
    "Allergy Test",
    "COVID-19 Test"
};


const string LabWork:: NOTCOMPLETE="not complete";


LabWork::LabWork (LabWorkCode labWorkCode, double cost){
    this->labWorkCode=labWorkCode;
    this->cost=cost;
    this->labTechId=NOTCOMPLETE;// initial value of labTechId 
}
bool LabWork:: isComplete() const{
    if(labTechId==NOTCOMPLETE){
        return false;
    } return true;
}
void LabWork:: completeLabWork(const string& labTechId){
    this->labTechId = labTechId;// set the labTechId member variable to this argument

}
void LabWork::print()const{
    cout<<"LabWork description: "<<LABTESTS[labWorkCode]<<endl;//labworkCode as an index into LABTESTS[]
    cout<< "cost: "<<cost<<endl;
    cout<<"labTechId: "<<labTechId<<endl;
}

