#include "DES.h"
#include <string.h>
#include <intrin.h>

///////////////////////////////
/// Encryption/Decryption
///////////////////////////////

char *DES::Encrypt(char *p)
{
	char *result = p;
	result = PrivInitialPermutation(result);
	for (int i = 0; i < 16; i++)
	{
		result = F(result);
	}
	result = PrivFinalPermutation(result);
	return result;
}

//NOT IMPLEMENTED
char *DES::Decrypt(char *c)
{
	return c;
}

///////////////////////////////
/// General Encryption
///////////////////////////////

void DES::PrivScheduleKeys()
{
	char *RoundKey = _key;
	for (int i = 0; i < 16; i++)
	{
		_ScheduledKeys[i] = (char*)_rotl8((unsigned char)RoundKey, 1);	//TO DO: MAY BE INCORRECT USE OF CASTS
		RoundKey = _ScheduledKeys[i];
	}
}

char *DES::PrivInitialPermutation(char *s)
{
	return s;
}

char *DES::PrivFinalPermutation(char *s)
{
	return s;
}

///////////////////////////////
/// F Function
///////////////////////////////

char *DES::F(char *s)
{
	char *result = s;
	result = PrivExpansion(result);
	result = PrivXOR(result, _ScheduledKeys[_round]);
	result = PrivSubstitutionBox(result);
	result = PrivPermutation(result);
	return result;
}

//NOT IMPLEMENTED
char *DES::PrivExpansion(char *s)
{
	return s;
}

//NOT IMPLEMENTED
char *DES::PrivXOR(char *s, char *rKey)
{
	rKey;
	return s;
}

//NOT IMPLEMENTED
char *DES::PrivSubstitutionBox(char *s)
{
	return s;
}

//NOT IMPLEMENTED
char *DES::PrivPermutation(char *s)
{
	return s;
}

///////////////////////////////
/// Misc
///////////////////////////////

int DES::GetKeyArraySize()
{
	return (sizeof(char) * 6 * 16);	//6-byte round keys with 16 rounds
}

///////////////////////////////
/// Constructors/Destructors
///////////////////////////////

DES::DES()
	: _key(0), _round(0)
{
	memset(_ScheduledKeys, 0, GetKeyArraySize());
}

DES::DES(const DES &d)
	: _key(d._key), _round(d._round)
{
	memcpy(_ScheduledKeys, d._ScheduledKeys, GetKeyArraySize());
}

DES &DES::operator=(const DES &d)
{
	_key = d._key;
	_round = d._round;
	memcpy(_ScheduledKeys, d._ScheduledKeys, GetKeyArraySize());
	return *this;
}

DES::DES(char *key)
	: _key(key), _round(0)
{
	memset(_ScheduledKeys, 0, GetKeyArraySize());
}

DES::~DES()
{

}