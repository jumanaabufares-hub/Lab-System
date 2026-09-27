#include "Entity.h"

Entity::Entity(char code, int num, const string& name) {
    this->name = name;
    
    // concatenate the character code with the first int and store in id str
    //’P’ and 23 as arguments, then id = "P23
    this->id = code +to_string(num);
}

// print Entity metadata (name and id)
void Entity::print() const {
    cout<<"Entity metadata: "<<endl;
    cout <<"name: " << name <<", id: " <<id <<endl;
}
string Entity::getName() const{
    return name;

}
string Entity::getId() const{
    return id;

}
