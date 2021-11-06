# Patient Management System

## Overview
This system is made as part of our Data Structures assignment. **Patient Management System** is written in **C++11**.

## Building
**C++11 is required**

### CMake
You can use [CMake](https://cmake.org/) (and presumably **make**) to build the program.
```
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install
make
```

### g++
Alternatively, you can build directly with **g++**.
```
g++ src/main.cpp src/Application/*.cpp src/Module/*.cpp src/Structures/*.cpp -o PMS.exe -std=c++11
```
Statically linked variant:
```
g++ src/main.cpp src/Application/*.cpp src/Module/*.cpp src/Structures/*.cpp -o PMS.exe -static -std=c++11
```

## Functionalities/Requirements
* No Database/File Records (sadly)
* Registration List
* Active Waiting List
* Patient Lookup (Search)
* Patient Pagination

## Note(s)
* The default login(s) for the nurse(s) is:
```
Username: faizal
Password: faizal123
```
* The default login(s) for the doctor(s) is:
```
Username: hafiz
Password: hafiz123
Username: tan
Password: tan
```

## Adding Modules
### Application class
The application class controls the entire flow of the program. That being said, any modules can be omitted by commenting out the module in this constructor. Your module should be loaded in `Application.cpp`'s constructor like so:
```
modules_.InsertTail(std::make_shared<MyModule>(resource_pool_));
```
Sample constructor:
```
Application::Application()
{
    modules_.InsertTail(std::make_shared<NurseModule>(resource_pool_));
    modules_.InsertTail(std::make_shared<DoctorModule>(resource_pool_));
    modules_.InsertTail(std::make_shared<MyModule>(resource_pool_));

    Run();
}
```
This will make `MyModule` the 3rd option in the starting menu.

### Module child class
A module handles all controls of the console (i.e. `Application` will pass control to `Module` after it is selected by the user).

Here is a template `Module` child class:
```
[MyModule.h]
#ifndef PMS_MY_MODULE_H
#define PMS_MY_MODULE_H

#include "Module.h"

#include <memory>
#include <string>

namespace pms
{
    class MyModule : public Module
    {
        public MyModule(std::shared_ptr<ResourcePool> resource_pool);
        void Run();
    };
} // namespace pms

#endif // PMS_DOCTOR_MODULE_H
```
```
[MyModule.cpp]
#include "MyModule.h"

#include <memory>
#include <iostream>

namespace pms
{
    MyModule::MyModule(std::shared_ptr<ResourcePool> resource_pool)
    : Module(resource_pool)
    {
        module_option_text_ = "My Test Module";
    }
    
    void DoctorModule::Run()
    {
        std::cout << "Entered MyModule" << std::endl;
        
        std::cout << "Going back to Application" << std::endl;
    }
} // namespace pms
```

### ResourcePool class
This is a data class that defines the data that will be passed around in the program. If any other data is needed, it should be added in this class under the public access modifier.

Any hardcoded data should go into the constructor of `ResourcePool`.
