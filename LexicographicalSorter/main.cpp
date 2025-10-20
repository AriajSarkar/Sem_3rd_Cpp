#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words;
    string word;

    cout << "Enter words (one per line, empty line to stop):" << endl;
    while (getline(cin, word)) {
        if (word.empty()) break;
        words.push_back(word);
    }

    // Sort in lexicographical order
    sort(words.begin(), words.end());

    cout << "\nSorted words in lexicographical order:" << endl;
    for (const auto& w : words) {
        cout << w << endl;
    }

    return 0;
}