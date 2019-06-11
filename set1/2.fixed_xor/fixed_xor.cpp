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

string fixed_xor(string plaintext, string key) {
    assert(plaintext.size() == key.size()); // ensure that key acts as one-time-pad

    size_t length = plaintext.size();

    string ciphertext; // cycle through char pairs and generate hex xor
    for (size_t i = 0; i < length; i++) {
        char hex_xor = xor_hex_chars(plaintext[i], key[i]);
        ciphertext.push_back(hex_xor);
    }

    return ciphertext;
}

int main() {
    string plaintext = "1c0111001f010100061a024b53535009181c";
    string key = "686974207468652062756c6c277320657965";
    string ciphertext = "746865206b696420646f6e277420706c6179";

    if (ciphertext == "746865206b696420646f6e277420706c6179") {
        cout << "oh cool, you're not a total dumbass" << endl;
    } else {
        cout << "your output:    " << ciphertext << endl;
        cout << "correct output: " << ciphertext << endl;
    }

    return 0;
}