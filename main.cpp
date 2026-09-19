#include <iomanip>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

// TODO (frequency): implement per the lesson description.

int main() {
    string line;
    map<char, int> freq;
    if (getline(cin, line)) {
        if (line.empty()) return 0;
        for (char c : line) {
            freq[c]++;
        }
        double entropy = 0.0;
        for (map<char, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            // calculate entropy
            double prob = it->second / (double)line.length();
            entropy += -prob * log2(prob);
        }
        double min_size = entropy * line.length() / 8.0;
        // print with 4 decimal places
        cout << "bytes=" << line.length() << endl;
        std::cout << "entropy=" << std::fixed << std::setprecision(4) << entropy << std::endl;
        std::cout << "min_size=" << std::fixed << std::setprecision(3) << min_size << std::endl;
    }
    // calculate entropy
    return 0;
}
