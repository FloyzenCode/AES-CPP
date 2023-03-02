#include <iostream>
#include <cstring>
#include "aes.h"
#define _STD_ using namespace std

_STD_;

int main()
{
    const char* message = "This is a secret message.";

    const unsigned char* key = (const unsigned char*)"mysecretpassword";

    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);

    int numBlocks = strlen(message) / AES_BLOCK_SIZE + 1;
    unsigned char* encrypted = new unsigned char[numBlocks * AES_BLOCK_SIZE];

    for (int i = 0; i < numBlocks; i++) {
        unsigned char input[AES_BLOCK_SIZE];
        memset(input, 0, AES_BLOCK_SIZE);
        memcpy(input, message + i * AES_BLOCK_SIZE, AES_BLOCK_SIZE);
        AES_encrypt(input, encrypted + i * AES_BLOCK_SIZE, &aesKey);
    }

    cout << "Encrypted message: ";
    for (int i = 0; i < numBlocks * AES_BLOCK_SIZE; i++) {
        cout << hex << (int)encrypted[i];
    }
    cout << endl;

    delete[] encrypted;

    return 0;
}