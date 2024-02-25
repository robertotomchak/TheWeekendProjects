#ifndef PASSWORD_H
#define PASSWORD_H
/*
	creates a (pseudo) random password, following certain rules
	these rules define which char types will be on the password
	types: special characters, upper, lower, numeric
*/


/*
rules: defines how many of each char type will be on the password
	n_lower: lower characters (a..z)
	n_upper: upper characters (A..Z)
	n_numeric: numeric characters (0..9)
	n_special: special characters (!?#...)
obs: the size of the password is equal to the sum of these values
*/
struct Rules {
	unsigned int n_lower;
	unsigned int n_upper;
	unsigned int n_numeric;
	unsigned int n_special;
};

/*
possible characters for each type
special characters are within a range in the ascii table, so it requires a string with them
*/
#define SPECIAL_CHAR "!#$%&()[]{}*+-:;<=>^~?@/|"

#define MIN_LOWER 97
#define MAX_LOWER 122

#define MIN_UPPER 65
#define MAX_UPPER 90

#define MIN_NUMERIC 48
#define MAX_NUMERIC 57

/*
randint: generates a random integer
@parameters:
	min: lower bound
	max: upper bound
@return: integer between <min> and <max> (inclusive)
*/
int randint (int min, int max);

/*
generate_password: creates a random password based on given rules
@parameters:
	rules: pointer to rules of the password
@return: a string with the password
*/
char * generate_password (struct Rules *rules);

/*
shuffle: shuffles the given array
@parameters:
	array: array that will be shuffled
	size: size (in byte) of each structure in the array
	n: size of array
@return: None
*/
void shuffle (void *array, size_t size, size_t n);

#endif
