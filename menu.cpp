#include "menu.h"
#include <stdio.h>
#include <iostream>

Menu::Menu() {
    
}

Menu::Menu(std::string initHeader) {
    
    // Set header and header flag
    hasHeader = true;
    header = initHeader;
    
}

Menu::Menu(std::string initHeader, void (*initCallback)(int)) {
    
    // Set header and header flag
    hasHeader = true;
    header = initHeader;
    
    // Set global callback
    globalCallbackPtr = initCallback;
    
}

Menu::Menu(void (*initCallback)(int)) {
    
    // Set global callback
    globalCallbackPtr = initCallback;
    
}

void Menu::addItem(std::string title) {
    // Create menu item and add to list
    menuItems.push_back(new MenuItem(title, count));
    
    // Increment count
    count++;
}

void Menu::addItem(std::string title,void(*funcPtr)()) {
    // Create menu item and add to list
    menuItems.push_back(new MenuItem(title, funcPtr, count));
    
    // Increment count
    count++;
}


// Print menu and allow for selection
void Menu::printMenu() {
    
    // Initialize option
    int option = 0;
    
    // Print menu header if supplied
    if (hasHeader) std::cout << header << "\n" << std::endl;
    
    // Enumerate in print options
    for (int i = 0; i < menuItems.size(); i++) std::cout << i << ".) " << menuItems[i]->getTitle() << std::endl;

    
    // Prompt user for selection
    std::cout << "\nSelect option: ";
    std::cin >> option;
    
    // Check if selection is valid
    if (option < 0 && option >= menuItems.size()) {
        // Print selection invalid and print menu again
        std::cout << "Not a valid selection.  Please try again." << std::endl;
        printMenu();
    } else {
        // Call menu item's callback
        menuItems[option]->performCallback();
        
        // If global callback supplied, call that with index as parameter
        if (globalCallbackPtr != nullptr) globalCallbackPtr(option);
    }
    
}
