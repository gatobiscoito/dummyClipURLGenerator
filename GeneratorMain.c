#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Dictionary.h"
#include "GeneratorMain.h"

void shuffle(int array[], int size)
{
	int i = size;
	int j, tmp;

	srand((unsigned)time(NULL));

	while (i > 1)
	{
		j = rand() % i;
		i--;
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

int main()
{
	int i;
	int j = 0;
	int numArray[WORDS_ARRAY_SIZE];
	int charaArray[CHARASET_ARRAY_SIZE];
	int rngNum;
	int urlSize = sizeof BASE_URL;
	char* fiveWords[WORDS_LENGTH] = { "" };
	char* rngChara[RNG_CHARASET_MAX] = { "" };

createFiveWords:

	for (i = 0; i < WORDS_ARRAY_SIZE; i++)
	{
		numArray[i] = i;
	}

	shuffle(numArray, WORDS_ARRAY_SIZE);

	for (i = 0; i < WORDS_LENGTH; i++)
	{
		rngNum = numArray[i];
		fiveWords[i] = words[rngNum];
		urlSize += ( int )strlen(fiveWords[i]);
	}

	if ((urlSize - RNG_CHARASET_MAX) > 60)	goto createFiveWords;

	printf("\rFive words Generate OK.     \n");

	for (i = 0; i < CHARASET_ARRAY_SIZE; i++)
	{
		charaArray[i] = i;
	}

	shuffle(charaArray, CHARASET_ARRAY_SIZE);

	for (i = 0; i < RNG_CHARASET_MAX; i++)
	{
		rngNum = charaArray[i];
		rngChara[i] = ( char* )charaset[rngNum];
	}

	printf("Random chara Generate OK.     \n");

	printf("https://clips.twitch.tv/");
	for (i = 0; i < WORDS_LENGTH; i++)
	{
		printf("%s", fiveWords[i]);
	}
	printf("-");

	for (i = 0; i < RNG_CHARASET_MAX; i++)
	{
		printf("%c", ( int )rngChara[i]);
	}

	return 0;
}
