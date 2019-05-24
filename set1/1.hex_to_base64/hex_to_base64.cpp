#include <string>
#include <vector>
#include <iostream>

using namespace std;

char hex_to_bin(char hex) {
    char mod_a_to_f = 87; // mod by 87 to turn 'a'-'f' into 10-15
    char mod_0_to_9 = 48; // mod by 48 to turn '0'-'9' into 0-9

    char dec = (hex % mod_a_to_f) % mod_0_to_9; // filer out a-f, then 0-9
    return dec;
}

string hex_to_base64(string hex_string) {
    vector<char> bytes;

    for (size_t i = 0; i < hex_string.size(); i += 2) {
        char hex1 = hex_string[i];

        // in case an odd number of hex digits was provided
        char hex2 = (i + 1 == hex_string.size()) ? 0 : hex_string[i + 1];

        char lead_bits = hex_to_bin(hex1) << 4;
        char trail_bits = hex_to_bin(hex2);

        bytes.push_back(lead_bits + trail_bits);
    }

    // ensure enough bits to construct whole base64 digits
    while (bytes.size() % 3 != 0) {
        bytes.push_back(0);
    }

    string base64_index = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string base64_encoded;

    for (size_t i = 0; i < bytes.size(); i += 3) {
        char b1 = (bytes[i] >> 2) & 0x3f;
        char b2 = ((bytes[i] << 4) + (bytes[i + 1] >> 4)) & 0x3f;
        char b3 = ((bytes[i + 1] << 2) + (bytes[i + 2] >> 6)) & 0x3f;
        char b4 = bytes[i + 2] & 0x3f;
        base64_encoded.push_back(base64_index[b1]);
        base64_encoded.push_back(base64_index[b2]);
        base64_encoded.push_back(base64_index[b3]);
        base64_encoded.push_back(base64_index[b4]);
    }

    return base64_encoded;
}

int main() {
    string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    string output = hex_to_base64(input);

    if (output == "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t") {
        cout << "yeet" << endl;
    }
    else {
        cout << "oof" << endl;
    }

    return 0;
}