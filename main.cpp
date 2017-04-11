#include <iostream>
#include "Database.h"
int main(){
    Database d;
    d.load();
    // d.print();
    d.save("./data/student2","./data/teacher2", "./data/lesson2");
    return 0;
     
    
}
