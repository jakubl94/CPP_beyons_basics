#include "Resource.h"
#include <iostream>
#include <vector>
#include <stdexcept>
using std::vector;
using std::cout;
using std::endl;

int main()
{
§    vector<int> numbers{1, 2, 3};
    numbers.push_back(4);
    numbers[0] = 15;
    int num = numbers[3];

    for(int i : numbers)
    {
        cout << i << endl;
    }

    Resource r("local");
    {// just add scope with curly brackets
        cout << "------scope start---------" << endl;
        vector<Resource> resources;
        resources.push_back(r);
        cout << "--------------------------" << endl;
        resources.push_back(Resource("first"));
        cout << "--------------------------" << endl;
        resources.push_back(Resource("second"));
        cout << "-------scope ending-------" << endl;
    }
    return 0;

}