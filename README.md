# CPP Menu
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=79DG973MCADQC&currency_code=USD&source=url)

Simple C++ menu creation.

Create simple menus easily.

![Example Output](https://user-images.githubusercontent.com/4554022/77284155-65686c00-6ca4-11ea-9902-6ca91e7f250f.png)

Support for individual callbacks per item *and/or* a global callback which passes back the selected index.

## Usage

**Include Menu Header**

```c++
#include "menu.h"
```

**Create Menu Instance**
Menus can be created with or without a header before the items.  Additionally supplying a pointer to a void that accepts an integer as a parameter will enable global callbacks so individual callbacks don't need to be supplied for each item. 

```c++
Menu defaultMenu;                                                         // Default menu
Menu menuWithHeader("Select one of the following options: ");             // Menu with header before items
Menu menuWithGlobalCallback(&itemSelected);                               // Menu with global callback
Menu menuWithHeaderAndCallback("Select one of the following options: ");  // Menu with global callback and header
```

**Add items**
```c++
Menu menu;
menu.addItem("My Item");                            // Item without callback
menu.addItem("My Item w/Callback", &itemCallback);  // Item with callback
```
**Print Menu**
```c++
menu.printMenu();
```

**Callbacks**
Menu item callbacks are just voids with no parameters.  The global callback takes an `int` is a parameter which is the index selected.

```c++
void menuItemCallback();
void globalCallback(int selectedIndex);
```
