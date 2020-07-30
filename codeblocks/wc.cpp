#include <iostream>
#include <string>
using namespace std;

int main()
{
    string msg = "hello, world";
    cout << msg << endl;
    cout << msg.length() << endl;
    cout << msg.at(1) << endl;
    cout << msg[1] << endl;
    cout << msg.empty() << endl;
    cout << msg.substr(3, 3) << endl;
    cout << msg.replace(3, 3, "why") << endl;
    cout << msg.append("end") << endl;
    cout << msg + "end" << endl;
    cout << msg.insert(3, "insert") << endl;

    string msg1;
    msg1 = msg;
    cout << msg1 << endl;

    cout << "Enter a line: ";
    getline(cin, msg);
    cout << msg << endl;
}
