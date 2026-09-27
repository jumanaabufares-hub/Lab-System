#ifndef LABWORKLIST_H
#define LABWORKLIST_H

#include "LabWork.h"

class LabWorkList{
    private:
        class Node{
            public:
                LabWork* data;
                Node* next;
        };
        Node* head;
        Node* tail;
    public:
        LabWorkList();
        
        ~LabWorkList();

        void add(LabWork* labwork);
        LabWork* getNext();

        bool isEmpty() const;
        int size() const;
        void print() const;

};
#endif