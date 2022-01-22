#pragma once
#include <string>
 
class Resource
{
    private:
        std::string name;

    public:
        // Constructor
        Resource(std::string n);
        // Copy constructor
        Resource(const Resource& r);
        // Copy assignment operator
        Resource& operator=(const Resource& r);
        // Destructor
        ~Resource(void);
        std::string GetName() const {return name; }

        

};