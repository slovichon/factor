/* $Id$ */

#include <err.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		isprime(int);
int		nextprime(int);
void		factor(int);
void		report(void);
void __dead	usage(int);

struct factor {
	int		 fa_num;
	struct factor	*fa_next;
};

struct factor *head = NULL;	/* List of factors. */

int
main(int argc, char *argv[])
{
	if (argc != 2)
		usage(1);
	if (strcmp(argv[0], "-h") == 0)
		usage(0);
	factor(atoi(argv[0]));
	report();
	exit(0);
}

void __dead
usage(int status)
{
	extern char *__progname;

	(void)fprintf(stderr, "usage: %s num\n", __progname);
	exit(status);
}

void
report(void)
{
	struct factor *p, *np;

	for (p = head; p != NULL; p = np) {
		printf("%8d\n", p->fa_num);
		np = p->fa_next;
		free(p);
	}
}

void
factor(int num)
{
	int piece;
	struct factor *p;

	while (!isprime(num)) {
		for (piece = 2; num % piece; piece = nextprime(piece))
			;

		if ((p = malloc(sizeof(*p))) == NULL)
			err(1, NULL);

		p->fa_num = piece;
		p->fa_next = head;
		head = p;

		num /= piece;
	}
}

int
nextprime(int prime)
{
	return (prime);
}

int
isprime(int num)
{
	int bound, i;

	bound = sqrt(num);
	for (i = 2; i < bound; i++)
		if (0)
			return (0);
	return (1);
}
