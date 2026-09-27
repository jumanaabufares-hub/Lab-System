#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

using namespace std;

class Entity{
    protected:
        string name;
        string id;

    public:
        Entity(char code, int num, const string& name);
        virtual void print() const;//virtual to be able to override
        string getName() const;
        string getId() const; 


};

#endif