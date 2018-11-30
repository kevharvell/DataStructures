#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map)
{
    // FIXME: implement
    char* word;
    while((word = nextWord(file))) {
	hashMapPut(map, word, 0);
	free(word);
    }
}

int MIN3(int a, int b, int c) {
	if(a < b && a < c) {
		return a;
	} else if(b < c && b < a) {
		return b;
	} else {
		return c;
	}
}

/* The following code taken from: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance#C */

int levenshtein(char *s1, char *s2) {
    unsigned int x, y, s1len, s2len;
    s1len = strlen(s1);
    s2len = strlen(s2);
    unsigned int matrix[s2len+1][s1len+1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x-1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y-1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] = MIN3(matrix[x-1][y] + 1, matrix[x][y-1] + 1, matrix[x-1][y-1] + (s1[y-1] == s2[x-1] ? 0 : 1));

    return(matrix[s2len][s1len]);
}

/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);

    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
	// Convert to lower case
	for(int i = 0; i < strlen(inputBuffer); i++) {
		inputBuffer[i] = tolower(inputBuffer[i]);
	}
	printf("You entered: %s\n", inputBuffer);

	// If the Hash Map contains the key
	if(hashMapContainsKey(map, inputBuffer)) {
		printf("Word spelled correctly.\n");
	} 
	// The word was spelled incorrectly
	else {
		printf("Word spelled incorrectly.\n");
		printf("Did you mean...?\n");
		
		// Calculate distance and put all values in the dictionary
		struct HashLink* temp;
		for(int i = 0; i < map->capacity; i++) {
			temp = map->table[i];
			while(temp != 0) {
				temp->value = levenshtein(inputBuffer, temp->key);
				temp = temp->next;
			}
		}
		// Iterate over dictionary and put 5 smallest values in an array
		int count = 0;
		int tempDistance = 1;
		char* matchArr[5];
		while(count < 5) {
			for(int i = 0; i < map->capacity; i++) {
				temp = map->table[i];
				while(temp != 0 && count < 5) {
					if(temp->value == tempDistance) {
						matchArr[count] = temp->key;
						count++;
					}
					temp = temp->next;
				}
			}
			tempDistance++;
		}
		for(int i = 0; i < 5; i++) {
			printf("%s\n", matchArr[i]);
		}
		
	}
        
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
    }
    
    hashMapDelete(map);
    return 0;
}
