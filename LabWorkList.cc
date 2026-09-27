#include "LabWorkList.h"
LabWorkList::LabWorkList(){
this->head=nullptr;
this->tail=nullptr;

}
        
LabWorkList:: ~LabWorkList(){
    while(head!=nullptr){
        Node* temp=head;
        head=head->next;
        delete temp;//delete all nodes
    }
}

void LabWorkList::add(LabWork* labwork){
    //Add labwork to the back of the LabWorkList
    Node* labW= new Node();
    labW->data=labwork; 
    labW->next = nullptr;


    if (head == nullptr) {
        head =labW;
        tail=labW;
    }    //use tail pointer in order to add the labwork
    else{
    tail->next=labW;
    tail=labW;}
}
LabWork* LabWorkList:: getNext(){
    if (head==nullptr){
        //return nullptrotherwise
            return nullptr;
    }    //return the LabWork* data from the first location if it exists
    LabWork* labw = head->data;
   
    //Delete the Node if it exists 

    Node* temp=head;
    head=head->next;
    //update the head and tail pointers (if head is null tail also will be nullptr)
     if (head == nullptr) {
        tail = nullptr;
    }
   
    delete temp;

    return labw;


}
        
bool LabWorkList:: isEmpty() const{
    // return true if the LabWorkList is empty.
    if(head==nullptr){
        return true;
    }
    return false;

}
int LabWorkList::size() const{
    //return the number of LabWork in the LabWorkList.
    int count=0;
    Node* temp=head;
    while (temp!=nullptr){
        count++;
        temp=temp->next;

    }
    return count;

}
void LabWorkList:: print() const{
    //prints all the LabWork.
        Node* temp=head;

    while (temp!=nullptr){
        temp->data->print();
        temp=temp->next;

    }


}