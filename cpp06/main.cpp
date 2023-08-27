#include <iostream>
using namespace std;
 
// Driver code
int main()
{
    float f = 3.5;
 
    // Implicit type case
    // float to int
    int a = f;
    cout << "The Value of a: " << a;
 
    // using static_cast for float to int
    int b = static_cast<int>(f);
    cout << "\nThe Value of b: " << b;
}