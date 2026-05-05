#include<bits/stdc++.h>
using namespace std;

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int base = 256;
    int prime = 101;

    int patternHash = 0, textHash = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;

    for (int i = 0; i < m; i++) {
        patternHash = (base * patternHash + pattern[i]) % prime;
        textHash = (base * textHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < n - m) {
            textHash = (base * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }
}



int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    rabinKarp(text, pattern);

    return 0;
}