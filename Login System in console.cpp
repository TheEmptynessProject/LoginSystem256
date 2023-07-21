#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "sha256.h"
using namespace std;

string byteToHex(uint8_t byte) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << static_cast<int>(byte);
    return ss.str();
}

int main()
{
    ofstream file("credentials.txt");

    string username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    SHA256 hash;
    hash.update(password);
    uint8_t* digest = hash.digest();

    file << "Username: " << username << "\n";
    file << "Hashed Password: ";
    for (int i = 0; i < 32; ++i) {
        file << byteToHex(digest[i]);
    }
    file << "\n";
    file.close();

    cout << "Saved.\n";

    return 0;
}
