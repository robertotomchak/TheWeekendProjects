#include <stdlib.h>
#include <string.h>

#include "password.h"

/*
struct Rules {
	unsigned int n_lower;
	unsigned int n_upper;
	unsigned int n_numeric;
	unsigned int n_special;
}
*/

/*
randint: generates a random integer
@parameters:
	min: lower bound
	max: upper bound
@return: integer between <min> and <max> (inclusive)
*/
int randint (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

/*
generate_password: creates a random password based on given rules
@parameters:
	rules: pointer to rules of the password
@return: a string with the password
*/
char * generate_password (struct Rules *rules)
{
	unsigned int n = rules->n_lower + rules->n_upper + rules->n_numeric + rules->n_special;
	char *password = malloc(sizeof(char) * (n + 1));

	// putting lower chars
	unsigned ind = 0;
	for (unsigned int i = ind; i < rules->n_lower + ind; i++)
		password[i] = randint(MIN_LOWER, MAX_LOWER);
	ind += rules->n_lower;

	// putting upper chars
	for (unsigned int i = ind; i < rules->n_upper + ind; i++)
		password[i] = randint(MIN_UPPER, MAX_UPPER);
	ind += rules->n_upper;

	// putting numeric chars
	for (unsigned int i = ind; i < rules->n_numeric + ind; i++)
		password[i] = randint(MIN_NUMERIC, MAX_NUMERIC);
	ind += rules->n_numeric;

	// putting special chars
	for (unsigned int i = ind; i < rules->n_special + ind; i++)
		password[i] = SPECIAL_CHAR[randint(0, strlen(SPECIAL_CHAR)-1)];
	shuffle(password, sizeof(char), n);
	password[n] = '\0';
	return password;	
}

/*
shuffle: shuffles the given array
@parameters:
	array: array that will be shuffled
	size: size (in byte) of each structure in the array
	n: size of array
@return: None
*/
void shuffle (void *array, size_t size, size_t n)
{
	void *temp_mem = malloc(size);
	for (size_t i = n-1; i > 0; i--) {
		size_t ind = randint(0, i);
		memcpy(temp_mem, array + size * i, size);
		memcpy(array + size * i, array + size * ind, size);
		memcpy(array + size * ind, temp_mem, size);
	}

	free(temp_mem);
}
