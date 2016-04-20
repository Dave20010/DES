#include <stdio.h>
#include <iostream>

#include "DES.h"

int main()
{
	printf("Starting Encryption\n");
	printf("===================\n\n");

	printf("Enter an 8-byte key (using characters): ");
	char key[8];
	std::cin >> key;

	DES DESEncrypt(key);

	printf("Enter the plaintext: ");
	char *Plaintext = new char[1000];
	std::cin >> Plaintext;
	printf("\n");

	char *Ciphertext = DESEncrypt.Encrypt(Plaintext, 1);
	printf("%s\n", Ciphertext);

	return 0;
}