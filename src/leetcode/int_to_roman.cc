#include <iostream>

using namespace std;

class Solution {
public:
    void append_to_roman(int num, string &roman, char symbols[]) {
        if (num == 0) {
            return;
        }
        if (num <= 3) {
            roman.append(num, symbols[0]);
        } else if (num == 4) {
            roman.append(1, symbols[0]);
            roman.append(1, symbols[1]);
        } else if (num <= 8) {
            roman.append(1, symbols[1]);
            roman.append(num-5, symbols[0]);
        } else {
            roman.append(1, symbols[0]);
            roman.append(1, symbols[2]);
        }
    }

    string intToRoman(int num) {
        char symbol[9] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string roman = "";
        int scale = 1000;
        for (int i = 6; i >= 0; i-=2) {
            int digit = num / scale;
            append_to_roman(digit, roman, symbol + i);
            num = num % scale;
            scale /= 10;
        }
        return roman;
    }

};

int main(int argc, char *argv[])
{
    Solution ss;
    cout << ss.intToRoman(12) << "==>Expected : XII" << endl;
    cout << ss.intToRoman(123) << "==>Expected: CXXIII" << endl;    
    return 0;
}


