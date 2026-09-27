#ifndef LIST_H
#define LIST_H
#include <string>

#include "Student.h"

class List{

    class Node {

        public:
            Student* data;
            Node*    next;
    };

    public:
        List();
        
        // Any data left in the List gets destroyed
        ~List();
        //we have unlimited size, so add always succeeds
        void add(Student*);
        //return false if name not found
        Student* get(const string& name);
        //double pointer for a return parameter of a pointer

        Student* remove(const string& name);

        void print() const;  //not modify this List object

    private:
        Node* head;

};


#endif

