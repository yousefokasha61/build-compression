#include <iostream>
#include <map>
#include <string>
using namespace std;

// TODO (frequency): implement per the lesson description.

int main() {
    string line;
    map<char, int> freq;
    if (getline(cin, line)) {
        if (line.empty()) return 0;
        for (char c : line) {
            if (isalpha(c)) {
                freq[tolower(c)]++;
            }
        }
        for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            cout << it->first << " " << it->second << endl;
        }
        freq.clear();
    }
    return 0;
}
