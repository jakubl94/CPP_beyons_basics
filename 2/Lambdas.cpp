
#include <vector>
using std::vector;
using std::begin;
using std::end;
#include <algorithm>
using std::for_each;
#include <string>
using std::string;
#include <memory>
using std::unique_ptr;
using std::make_unique;

int main()
{
    // Defining lambda
    // Capture clause []
    // Paremeters ()
    // Body {}
    auto isOdd = [](int candidate) {return candidate % 2 != 0;};

    // Executing lambda
    bool is3Odd = isOdd(3);
    bool is123594Odd = isOdd(123594);
    bool is4Odd = isOdd(4);

    vector nums {2 ,3 , 4, 5, 0, 2, 1};

    // Created lambda passed into another function
    // Counts number of odds
    int odds = std::count_if(begin(nums), end(nums), isOdd);
    
    // Lambda is not hold in a variable but is created just in calling place
    // Counts even numbers
    int evens = std::count_if(begin(nums), end(nums), [](int candidate) {return candidate % 2 == 0;});

    int x = 3;
    int y = 7;


    string message = "elements between ";
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";
    //capturing by value and reference explicitly  [x,y,&message]
    for_each(begin(nums), end(nums),
        [x, y, &message](int n)
        {
            if (n >= x && n <= y) message += " " + std::to_string(n);
        });

    //x by value, rest by ref - x wont be change by for loop since it is passed by value (copy will be created)
    x = y = 0;
    std::for_each(begin(nums), end(nums),
        [&, x](int element) mutable { // mutable allows to change variable of the class
            x += element;
            y += element;
        });

}