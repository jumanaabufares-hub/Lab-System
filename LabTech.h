#ifndef LABTECH_H
#define LABTECH_H

#include "Entity.h"
#include "LabWorkList.h"

// class should publicly inherit from Entity
class LabTech : public Entity {
    public:

        LabTech(const string& name);//ctor takes string name as an argument
        
        static void resetId();

        void addLabWork(LabWork* labwork);

        void print() const override;  // override Entity::print &  it should print num of processedLabWork
        
        void printLabWork() const;


    private:
        static const char code;
        static int nextId;

        LabWorkList processedLabWork;// contain LabWork that this LabTech has processed
        



};
#endif