#include <iomanip>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<string> split(const string& str, const char& delim) {
    std::vector<std::string> internal;
    std::stringstream ss(str);
    std::string tok;

    while (getline(ss, tok, delim)) {
        internal.push_back(tok);
    }

    return internal;
}

string encode(const string& str) {
    string encoded = "";
    int count = 1;
    for (int i = 0; i < str.length(); i++) {
        if (i + 1 < str.length() && str[i] == str[i + 1]) {
            count++;
        } else {
            encoded += to_string(count);
            if (isdigit(str[i])) encoded += " ";
            encoded += str[i];
            if (i + 1 < str.length()) encoded += " ";
            count = 1;
        }
    }
    return encoded;
}

string decode(const string& str) {
    string decoded = "";
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        int count = 0;
        while (i < str.length() && isdigit(str[i])) {
            count = count * 10 + (str[i] - '0');
            i++;
        }
        if (str[i] == ' ') i++;
        c = str[i++];
        if (count == 0) count = 1;
        decoded += string(count, c);
    }
    return decoded;
}

int main() {
    string line;
    map<char, int> freq;
    if (getline(cin, line)) {
        if (line.empty()) return 0;
        vector<string> tokens = split(line, ' ');
        if (tokens[0] == "ENCODE") {
            cout << encode(line.find("ENCODE") != string::npos ? line.substr(7) : line) << endl;
            return 0;
        }
        cout << decode(line.find("DECODE") != string::npos ? line.substr(7) : line) << endl;
        return 0;
    }
    return 0;
}
