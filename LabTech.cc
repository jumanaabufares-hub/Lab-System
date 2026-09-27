#include "LabTech.h"

const char LabTech:: code='T';//set this code to ’T
//first LabTech that is made should have the id number T1
int LabTech::nextId=1;
//in constructor increment next id , ex: 1st lab tech T1, 2nd T2 etc
LabTech::LabTech(const string& name):Entity(code, nextId++, name ){


}
void LabTech:: resetId(){
    nextId=1;
}

void LabTech::addLabWork(LabWork* labwork){
    //add the given pointer to the back of the LabWorkList
    processedLabWork.add(labwork);
}

void LabTech::print() const {  
    // override Entity::print &  it should print num of processedLabWork
    Entity::print();
    cout<<"number of Processed LabWork: "<<processedLabWork.size()<<endl;
}
void LabTech::printLabWork() const{
    //print the LabTech
    print();
    //print out all the LabWork in the LabWorkList
    if (processedLabWork.isEmpty()) {
        cout << "no LabWork processed in the LabWorkList." << endl;
    } else {
        processedLabWork.print();
    }

}