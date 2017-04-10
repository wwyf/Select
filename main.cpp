#include <iostream>
#include "Database.h"
int main(){
    Database d;
    d.load();
    d.print();
    d.save("user2", "lesson2");
    return 0;
    
    
    
}
