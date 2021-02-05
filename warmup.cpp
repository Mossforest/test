#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Hello! Please give me a number\n" << endl;
    cin >> a;
    cout << "You give me " << a << ", right?\n";
    if (a == 4) {
        cout << "wow, i didnt expect that.";
    } else
        cout << "hmmmm... No problem!";
    return 0;
}