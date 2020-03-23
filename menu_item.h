#ifndef menu_item_h
#define menu_item_h

#include <stdio.h>
#include <string>

class MenuItem {
  
public:
    //Constructor & Destructor
    MenuItem();
    MenuItem(std::string initTitle, int initIndex);
    MenuItem(std::string initTitle, void(*initFuncPtr)(), int initIndex);
    
    // Get title
    std::string getTitle();
    
    // Get index
    int getIndex();
    
    // Perform callback
    void performCallback();
private:
    // Menu Item Title
    std::string title;
    
    // Menu Item Index
    int index = 0;
    
    // Callback pointer
    void(*funcPtr)() = nullptr;
};

#endif /* menu_item_hpp */
