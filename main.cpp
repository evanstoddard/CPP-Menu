//
//  main.cpp
//  cpp_menu
//
//  Created by Evan Stoddard on 3/22/20.
//  Copyright © 2020 Evan Stoddard. All rights reserved.
//

#include <iostream>
#include "menu.h"

void callback(int option) {
    std::cout << "Selection: " << option << std::endl;
}

int main(int argc, const char * argv[]) {
    
    Menu menu("Selection an option:", &callback);
    
    menu.addItem("Option 1");
    menu.addItem("Option 2");
    menu.addItem("Option 3");
    
    menu.printMenu();
    
    return 0;
}
