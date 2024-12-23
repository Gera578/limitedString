#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(), s.rend());
        string newString = "";
        int count = 0;
        vector<int> freq(26, 0);
        for (char c : s) {

            freq[c - 'a']++;
        }

        int lastChar = -1;

        while (true) {
            bool added = false;

            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0 and i != lastChar) {
                    count = min(freq[i], repeatLimit);
                    newString += string(count, 'a' + i);
                    freq[i] -= count;
                    lastChar = i;
                    added = true;


                    if (freq[i] > 0) {
                        for (int j = i - 1; j > 0; j--) {

                            if (freq[j] > 0) {
                                newString += 'a' + j;
                                freq[j]--; //used if the frequency is only 1, in other words, if theres only 1 character
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (!added) break;
        }
        cout << newString << endl;
        return newString;
    }
};

int main() {
    string s = "aababab";
    
    Solution solution;
    solution.repeatLimitedString(s, 2);
}