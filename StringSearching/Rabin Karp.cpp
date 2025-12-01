#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Calculate hash value for a string
int calculateHash(const string &str, int base, int length) {
    int hash = 0;
    for (int i = 0; i < length; i++) {
        hash += (str[i] - '0') * pow(base, length - i - 1);
    }
    return hash;
}

// Rabin-Karp pattern matching algorithm
void rabinKarp(const string &text, const string &pattern, int base) {
    int n = text.length();
    int m = pattern.length();
    
    // Calculate hash for pattern
    int patternHash = calculateHash(pattern, base, m);
    
    // Calculate hash for first window of text
    int textHash = calculateHash(text.substr(0, m), base, m);
    
    // Slide the window over text
    for (int i = 0; i <= n - m; i++) {
        
        // If hash values match, check actual strings
        if (textHash == patternHash) {
            if (text.substr(i, m) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        
        // Calculate hash for next window (rolling hash)
        if (i < n - m) {
            textHash = (textHash - (text[i] - '0') * pow(base, m - 1)) * base + (text[i + m] - '0');
        }
    }
}

int main() {
    string text = "3141592653589793";
    string pattern = "26";
    int base = 10;
    
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Searching..." << endl;
    
    rabinKarp(text, pattern, base);
    
    return 0;
}
