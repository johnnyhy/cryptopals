#include <string>
#include <vector>
#include <iostream>

using namespace std;

char hex_to_dec(char val) {
    char mod_0_9 = 48;
    char mod_a_to_f = 49;

    cout << string(1, val) << ": " << int((val % mod_0_9) % mod_a_to_f) << endl;

    return (val % mod_0_9) % mod_a_to_f;
}

string hex_to_base64(string hex_string) {
    vector<char> bytes;

    for (auto digit = hex_string.begin(); digit < hex_string.end();  digit++) {
        char val1 = *digit++;
        char val2 = (digit == hex_string.end()) ? 0 : *digit;

        char byte_val = hex_to_dec(val1) << 4 + hex_to_dec(val2);
        bytes.push_back(byte_val);

        if (digit == hex_string.end()) {
            break;
        }
    }
}

int main() {
    hex_to_base64("");
}