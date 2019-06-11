#include <string>
#include <iostream>
#include <cassert>

using namespace std;

char hex_to_bin(char hex) {
    char mod_a_to_f = 87; // mod by 87 to turn 'a'-'f' into 10-15
    char mod_0_to_9 = 48; // mod by 48 to turn '0'-'9' into 0-9

    char dec = (hex % mod_a_to_f) % mod_0_to_9; // filer out a-f, then 0-9
    return dec;
}

char bin_to_hex(char bin) {
    assert(bin >= 0 && bin < 16); // ensure that binary 

    string hex_lookup = "0123456789absdef"; // indexed lookup table of possible hex values
    return hex_lookup[bin];
}

char xor_hex_chars(char plain, char key) {
    char plain_bin = hex_to_bin(plain);
    char key_bin = hex_to_bin(key);

    char bin = (plain_bin | key_bin) & (~plain_bin | ~key_bin); // simulating an xor gate
    return bin_to_hex(bin);
}

string caesar(string plaintext, char key) {
    size_t length = plaintext.size();

    string ciphertext; // cycle through char pairs and generate hex xor
    for (size_t i = 0; i < length; i++) {
        char hex_xor = xor_hex_chars(plaintext[i], key);
        ciphertext.push_back(hex_xor);
    }

    return ciphertext;
}

int main() {
    for (char i = 0; i < 16; i++) {
        cout << caesar("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", i) << endl;
    }
}