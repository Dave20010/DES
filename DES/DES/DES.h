#ifndef _DES_H
#define _DES_H

class DES
{
private:
	char *_key;
	char *_ScheduledKeys[16];
	int _round;

	///////////////////////////////
	/// General Encryption
	///////////////////////////////

	void PrivScheduleKeys();
	char *PrivInitialPermutation(char *s);
	char *PrivFinalPermutation(char *s);

	///////////////////////////////
	/// F Function
	///////////////////////////////

	char *F(char *s);
	char *PrivExpansion(char *s);
	char *PrivXOR(char *s, char *rKey);
	char *PrivSubstitutionBox(char *s);
	char *PrivPermutation(char *s);

	///////////////////////////////
	/// Misc
	///////////////////////////////

	int GetKeyArraySize();

public:
	///////////////////////////////
	/// Constructors/Destructors
	///////////////////////////////

	DES();
	DES(const DES &d);
	DES &operator=(const DES &d);
	~DES();

	DES(char *key);

	///////////////////////////////
	/// Encryption/Decryption
	///////////////////////////////

	char *Encrypt(char *p);
	char *Decrypt(char *c);
};

#endif