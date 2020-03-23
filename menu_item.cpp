#include "menu_item.h"

MenuItem::MenuItem() {
    title = "Undefined";
}

MenuItem::MenuItem(std::string initTitle, int initIndex) {
    // Set title
    title = initTitle;
    
    // Set index
    index = initIndex;
}

MenuItem::MenuItem(std::string initTitle, void(*initFuncPtr)(), int initIndex) {
    // Set title
    title = initTitle;
    
    // Set function pointer
    funcPtr = initFuncPtr;
    
    // Set index
    index = initIndex;
}

int MenuItem::getIndex() {
    // Return index
    return index;
}

std::string MenuItem::getTitle() {
    return title;
}

void MenuItem::performCallback() {
    // Perform callback if one supplied
    if (funcPtr != nullptr) funcPtr();
}
