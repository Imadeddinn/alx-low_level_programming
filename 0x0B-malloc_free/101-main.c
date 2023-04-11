#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* print_tab - Prints an array of string
* @tab: The array to print
*
* Return: nothing
*/
void print_tab(char **tab)
{
int i;

for (i = 0; tab[i] != NULL; ++i)
{
printf("%s\n", tab[i]);
}
}

char **strtow(const char *str)
{
char **words = NULL;
int word_count = 0;
int i, j, k;

/* count the number of words in the string */
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
{
word_count++;
}
}

/* allocate memory for the array of words */
words = malloc((word_count + 1) * sizeof(char *));
if (words == NULL)
{
return NULL;
}

/* split the string into words */
for (i = 0, j = 0; j < word_count; j++)
{
/* find the beginning of the next word */
while (str[i] == ' ')
{
i++;
}

/* find the end of the next word */
k = i;
while (str[k] != ' ' && str[k] != '\0')
{
k++;
}

/* allocate memory for the word and copy it */
words[j] = malloc((k - i + 1) * sizeof(char));
if (words[j] == NULL)
{
/* free previously allocated memory */
while (j > 0)
{
j--;
free(words[j]);
}
free(words);
return NULL;
}
strncpy(words[j], str + i, k - i);
words[j][k - i] = '\0';
i = k;
}

words[word_count] = NULL;
return words;
}

/**
* main - check the code for ALX School students.
*
* Return: 1 if an error occurred, 0 otherwise
*/
int main(void)
{
char **tab;

tab = strtow("      ALX School         #cisfun      ");
if (tab == NULL)
{
printf("Failed\n");
return (1);
}
print_tab(tab);
return (0);
}
