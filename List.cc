#include <iostream>
#include <string>
using namespace std;

#include "List.h"

List::List(): head(nullptr){}


List::~List(){
    Node* currNode = head;
    Node* nextNode = nullptr;

    while(currNode!=nullptr){
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }

}

//add in sorted order by name
void List::add(Student* stu){
    Node* newNode = new Node();
    newNode->data = stu;
    newNode->next = nullptr;

    Node* currNode = head;
    Node* prevNode = nullptr;

    while(currNode!=nullptr){
        if (newNode->data->lessThan(*currNode->data)){
            break;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    //insert currNode
    if (prevNode == nullptr){
        head = newNode;
    }else{
        prevNode->next = newNode;
    }
    newNode->next = currNode;

}


Student* List::remove(const string& name){
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = nullptr;

    while (currNode!=nullptr){
        if (currNode->data->getName()==name){
           break; 
        }
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == nullptr){
        return nullptr;
    }
    //currNode is not nullptr
    if (prevNode == nullptr){
        head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }
    Student *goner = currNode->data;
    delete currNode;
    return goner;
}

Student* List::get(const string& name){
    Node * currNode;

    currNode = head;

    while (currNode!=nullptr){
        if (currNode->data->getName() == name){
           return currNode->data;
        }
        currNode = currNode->next;
    }

    return nullptr
}


void List::print() const{
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    if (currNode == nullptr){
        cout <<"List empty"<<endl;
    }

    while(currNode != nullptr){
        currNode->data->print();
        currNode = currNode->next;
    }
}



