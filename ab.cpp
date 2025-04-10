#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    // Take the input from the user
    cin >> str;
    int len = str.length();
    // Check if the string starts with 'a' and ends with 'b'
    if(str[0] == 'a' && str[len - 1] == 'b') {
        cout << "Accepted";
    } else {
        cout << "Rejected";
    }
    return 0;
}