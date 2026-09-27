#include "Patient.h"

const char Patient::code = 'P';

int Patient::nextId = 1;


Patient::Patient(const string& name, const string& medicalConditions):Entity('P', nextId++, name){
  this->medicalConditions=medicalConditions;
}
    
void Patient::resetId(){
  nextId=1;
}
    
void Patient::addLabWork(LabWork* labWork){// Add ptr to the back of the pending LabWork list
  pendingLabWork.add(labWork);

}
LabWork* Patient:: processLabWork(){
  //Remove the LabWork from the front of the pending LabWork list
    //check if its empty:
  if (pendingLabWork.isEmpty()) {
    return nullptr;
  }
  LabWork* labwork=pendingLabWork.getNext();

  // Add it to the processed LabWork list, and also return it.
  processedLabWork.add(labwork);
  return labwork;


}
void Patient::print() const {
  Entity::print();
  cout<<"pending Labworks: "<<pendingLabWork.size()<<endl;
  cout<<"conditions: "<<medicalConditions<<endl;
  cout<<"Medical History: : "<<processedLabWork.size()<<endl;



}

bool Patient::hasPendingLabWork() const{
  //true if there is any LabWork in the pending LabWork list
  if (!pendingLabWork.isEmpty()){ 
    return true;}
  else{
    return false;
  }

}

void Patient::printMedicalHistory() const{
  if (processedLabWork.isEmpty()) {
    cout << "  No medical history available" << endl;
    return;
  }else{
    cout<<"medical history of:";
    Entity::print(); //name:, id:\n

    processedLabWork.print();


  }
  
  
}

void Patient::printPendingLabWork() const{
  if (pendingLabWork.isEmpty()) {
    cout << "  No pending Labwork available" << endl;
    return;
  }else{
    cout<<"pending Labwork of:";
    Entity::print();
    pendingLabWork.print();


  }
  

}