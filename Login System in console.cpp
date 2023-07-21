#include <iostream>
#include <fstream>
#include <sstream> // Include the <sstream> header for stringstream
#include <iomanip> // Include the <iomanip> header for setw and setfill
#include "sha256.h"
using namespace std;

string byteToHex(uint8_t byte) {
    stringstream ss;
    ss << hex << setw(2) << setfill('0') << static_cast<int>(byte);
    return ss.str();
}

int main()
{
    ofstream file("credentials.txt"); // Create file / open file

    string username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    // Hash the password using SHA-256
    SHA256 hash;
    hash.update(password);
    uint8_t* digest = hash.digest();

    // Save the hashed password to the file
    file << "Username: " << username << "\n";
    file << "Hashed Password: ";
    for (int i = 0; i < 32; ++i) {
        file << byteToHex(digest[i]);
    }
    file << "\n";
    file.close(); // Save file

    cout << "Registration successful! Your hashed password has been saved.\n";

    return 0;
}
