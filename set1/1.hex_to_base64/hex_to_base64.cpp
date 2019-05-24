#include <string>
#include <vector>
#include <iostream>

using namespace std;

char hex_to_dec(char hex) {
    char mod_a_to_f = 87; // mod by 87 to turn 'a'-'f' into 10-15
    char mod_0_to_9 = 48; // mod by 48 to turn '0'-'9' into 0-9

    char dec = (hex % mod_a_to_f) % mod_0_to_9; // filer out a-f, then 0-9
    cout << hex << ": " << int(dec) << endl;

    return dec;
}

string hex_to_base64(string hex_string) {
    vector<char> bytes;

    for (size_t i = 0; i < hex_string.size(); i += 2) {
        char hex1 = hex_string[i];
        char hex2 = (i + 1 == hex_string.size()) ? 0 : hex_string[i + 1];

        hex_to_dec(hex1);
        hex_to_dec(hex2);
    }
}

int main() {
    hex_to_base64(string("0123456789abcdef0"));
    return 0;
}