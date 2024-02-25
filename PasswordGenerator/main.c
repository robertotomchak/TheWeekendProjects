/*
	This file generates random passwords
	rules are defined in the READ.ME
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "password.h"

#define MIN_LENGHT 4
#define RECOMMENDED_LENGHT 12

int main ()
{
	srand(time(NULL));

	unsigned int size_password, n_password;
	char is_numeric;
	struct Rules rules;

	printf("Size of password (min = %d, recommended >= %d): ", MIN_LENGHT, RECOMMENDED_LENGHT);
	scanf("%d", &size_password);
	if (size_password < MIN_LENGHT) {
		printf("ERROR: PASSWORD IS TOO SMALL!\n");
		return 1;
	}
	printf("Number of passwords: ");
	scanf("%d", &n_password);
	printf("Only numbers (y/n)? ");
	scanf("\n%c", &is_numeric);
	if (is_numeric == 'y' || is_numeric == 'Y') {
		rules.n_lower = 0;
		rules.n_upper = 0;
		rules.n_numeric = size_password;
		rules.n_special = 0;
	}
	else if (is_numeric != 'n' && is_numeric != 'N') {
		printf("ERROR: NON-VALID OPTION\n");
		return 2;
	}

	char *passwd;
	unsigned int n_lower, n_upper, n_numeric, n_special;
	for (int i = 0; i < n_password; i++) {
		if (is_numeric == 'n' || is_numeric == 'N') {
			n_upper = randint(1, size_password / 4);
			n_numeric = randint(1, size_password / 4);
			n_special = randint(1, size_password / 4);
			n_lower = size_password - (n_upper + n_numeric + n_special);		

			rules.n_lower = n_lower;
			rules.n_upper = n_upper;
			rules.n_numeric = n_numeric;
			rules.n_special = n_special;

		}
		passwd = generate_password(&rules);
		printf("%s\n", passwd);
		free(passwd);
	}
	return 0;
}
