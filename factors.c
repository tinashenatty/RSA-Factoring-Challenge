#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_factors(unsigned long number);

/**
 * main - main entry point of the program
 * @argc: count of command line arguments passed to the program
 * @argv: vector containing command line arguments passed to the program
 *
 * Return: Always 0 (EXIT_SUCCESS)
 */
int main(int argc, char **argv)
{
	ssize_t num_read;
	char *value = NULL;
	size_t line_size = 0;
	FILE *fp;
	unsigned long number;

	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		while ((num_read = getline(&value, &line_size, fp)) != -1)
		{
			value[strcspn(value, "\n")] = '\0';
			number = atol(value);
			list_factors(number);
		}
	}
	else
	{
		fprintf(stderr, "Usage: ./factor <file_name>\n");
		return (EXIT_FAILURE);
	}
	fclose(fp);
	free(value);
	return (EXIT_SUCCESS);
}

/**
 * list_factors - determines and lists the factors of a number
 * @number: number we wish to evaluate
 *
 * Return: void
 */
void list_factors(unsigned long number)
{
	unsigned long i, j, divisor;
	int is_prime = 0;

	for (i = 2; i <= number; i++)
	{
		if (number % i == 0)
		{
			is_prime = 1; /* True */
			for (j = 2; j <= i/2; j++)
			{
				if (i % j == 0)
				{
					is_prime = 0; /* False */
					break;
				}
			}
		}

		if (is_prime)
		{
			divisor = i;
			break;
		}
	}
	printf("%lu=%lu*%lu\n", number, (number / divisor), divisor);
}
