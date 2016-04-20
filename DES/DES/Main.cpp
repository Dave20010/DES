#include <stdio.h>
#include <iostream>

#include "DES.h"

int ConvertCharToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'a' && c <= 'f')
	{
		return c - 'a' + 10;
	}
	else
	{
		printf("INPUT ERROR: NOT A HEX DIGIT\n");
		return 0;
	}
}

char *ConvertCharToBinary(const char *input)
{
	char *binary = new char[8];
	for (unsigned int i = 0; i < strlen(input); i += 2)
	{
		char left = input[i];
		char right = input[i + 1];
		int iLeft = ConvertCharToInt(left);
		int iRight = ConvertCharToInt(right);
		binary[i / 2] = (char)(iLeft * 16 + iRight);
	}
	return binary;
}

char BinaryXOR(char byteA, char byteB)
{
	return byteA ^ byteB;
}

char BinaryAND(char byteA, char byteB)
{
	return byteA & byteB;
}

char BinaryOR(char byteA, char byteB)
{
	return byteA | byteB;
}

char BinaryNOT(char byteA)
{
	return ~byteA;
}

int main()
{
	printf("Starting Encryption\n");
	printf("===================\n\n");

	printf("Enter an 16 character hex string: ");
	char *HexInput = new char[16];
	std::cin >> HexInput;

	char *BinaryKey = ConvertCharToBinary(HexInput);

	//PRINT KEY AS BINARY
	/*printf("Key as binary: \n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d", (BinaryKey[i] >> j) & 1);

			if (j % 4 == 0)
			{
				printf(" ");
			}
		}
		//printf("\n");
	}
	printf("\n");*/

	DES *DESEncrypt = new DES(BinaryKey);

	printf("Enter the plaintext: ");
	char *Plaintext = new char[1000];
	std::cin >> Plaintext;
	printf("\n");

	char *Ciphertext = DESEncrypt->Encrypt(Plaintext, 1);
	printf("%s\n", Ciphertext);

	delete[] HexInput;
	delete[] BinaryKey;
	delete DESEncrypt;
	delete[] Plaintext;

	return 0;
}