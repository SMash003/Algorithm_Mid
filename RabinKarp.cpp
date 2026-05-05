#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();

    int base = 256;
    int mod = 101;

    int pHash = 0, tHash = 0, power = 1;

    for (int i = 0; i < m - 1; i++)
    {
        power = (power * base) % mod;
    }

    for (int i = 0; i < m; i++)
    {
        pHash = (pHash * base + pattern[i]) % mod;
        tHash = (tHash * base + text[i]) % mod;
    }

    cout << "Initial Pattern Hash: " << pHash << endl;

    bool found = false;

    for (int i = 0; i <= n - m; i++)
    {
        cout << "Index " << i << " -> tHash: " << tHash << endl;

        if (pHash == tHash)
        {
            if (text.substr(i, m) == pattern)
            {
                cout << "Pattern found at index: " << i << endl;
                found = true;
            }
        }

        if (i < n - m)
        {
            tHash = (tHash - text[i] * power) % mod;
            tHash = (tHash * base + text[i + m]) % mod;

            if (tHash < 0)
                tHash += mod;
        }
    }

    if (!found)
    {
        cout << "Pattern not found" << endl;
    }
}

int main()
{
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    rabinKarp(text, pattern);

    return 0;
}