#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Remove all characters except alphabets
    input.erase(remove_if(input.begin(), input.end(), [](char c) {
        return !isalpha(c);
    }), input.end());

    cout << "String with only alphabets: " << input << endl;

    return 0;
}