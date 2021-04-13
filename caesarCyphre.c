#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SEPARATORS " .,-?!/:;'-"
#define OUT    0 
#define IN    1 

void decryption_by_movement(char *string, int key);
void sort_by_length(char **prefix, int size);
void delete_all_prefixes(char *string, char **prefix, int nr_prefix);
char *strcmpL(char *a);
int start_with_prefix(char *word, char *prefix);
char *freq_word(char *string, int *max_counter);
int countWords(char *str);
void sort_alphabetically(char *vectorschar[], int nr);
int is_upper_case(char letter);
int is_lower_case(char letter);

int main(int argc, char const *argv[]) {
	unsigned int size_string = 100000;
	char *string = calloc(size_string, sizeof(char));
	long int key;
	int nr_prefix = 0;
	char **prefix = calloc(110, sizeof(char*));

	scanf("%ld", &key);
	scanf(" %[^\n]s", string);


	for (int i = 0; i < 110; i++) {
		prefix[i] = calloc(6, sizeof(char));
	}

	int i = 0;
	while (scanf(" %s", prefix[i]) != EOF) {
		i++;
		nr_prefix++;
	}

	decryption_by_movement(string, key);
	printf("%s\n", string);

	sort_by_length(prefix, nr_prefix);
	delete_all_prefixes(string, prefix, nr_prefix);

	printf("%s\n", string);

	int max_counter = 0;
	char *result = calloc(20, sizeof(char*));
	result = freq_word(string, &max_counter);

	printf("%s %d\n", result, max_counter);

	free(prefix);
	free(string);
	return 0;
}

int is_upper_case(char letter) {
	int mask = 1 << 5;

	if ((letter & mask) == ('A' & mask)) {
		return 1;
	} 

	return 0;
}

int is_lower_case(char letter) {
	int mask = 'A' ^ 'a';

	if ((letter & mask) == ('a' & mask)) {
		return 1;
	} 

	return 0;
}

void decryption_by_movement(char *string, int key) {
	while (key > 26) {
		key %= 26;
	}

	for (int i = 0; i < strlen(string); ++i) {
		if (islower(string[i])) {
			string[i] -= key;
			if (string[i] < 'a') {
				string[i] += 26;
			}
		} else if (isupper(string[i])) {
			string[i] -= key;
			if (string[i] < 'A') {
				string[i] += 26;
			}
		} 
	}
}

char *strcmpL(char *a) {
	int i = 0;
	char *b = calloc(strlen(a), sizeof(char));

	while (i < strlen(a)) {
		b[i] = a[i] | 0x20;
		i++;
	} 
	return b;
}

int start_with_prefix(char *word, char *prefix) {
	if (strlen(word) - strlen(prefix) < 2) {
		return 0;
	}
	for (int i = 0; i < strlen(prefix); ++i) {
		if (word[i] != prefix[i]) {
			return 0;
		}
	}
	return 1;
}

void delete_all_prefixes(char *string, char **prefix, int nr_prefix) {
	char *word = calloc(20, sizeof(char));
	int word_index = 0;
	
	for (int i = 0; i <= strlen(string); ++i) {
		if (isupper(string[i])) {
			word[word_index] = string[i] | 0x20;
			word_index++;
		} else if (islower(string[i])) {
			word[word_index] = string[i];
			word_index++;
		} else {
			if (word_index > 2) {
				for (int j = 0; j < nr_prefix; ++j) {
					//checking if the word start with a prefix
					if (start_with_prefix(word, prefix[j])) {
						memcpy(string + i - strlen(word),
							   string + i - strlen(word) + strlen(prefix[j]),
							   strlen(string) - i + strlen(word));
						i = i - strlen(prefix[j]);
						break;
					}
				}
			}
			memset(word, 0, word_index);
			word_index = 0;
		}

	}
}

void sort_by_length(char **prefix, int size) {
	int i, j;
	char *aux;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			aux = 0;
			if(strlen(prefix[j]) < strlen(prefix[j+1])) {
				aux = prefix[j];
				prefix[j] = prefix[j+1];
				prefix[j+1] = aux;
			}
		}
	}
}

void sort_alphabetically(char *vectorschar[], int nr) {
	int i, j;
	char *aux;

	for (i = 1; i < nr; i++) {
		aux = vectorschar[i];
		j = i - 1;
		
		while (j >= 0 && strcmp(vectorschar[j], aux) > 0) {
			vectorschar[j+1] = vectorschar[j];
			j = j - 1;
		}
		vectorschar[j + 1] = aux;
	}
}

int countWords(char *str) { 
	int state = OUT; 
	unsigned wc = 0;

	while (*str) {
		if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '.' || *str == ','||
			*str == ':' || *str == ';' || *str == '?' || *str == '!' || *str == '-') 
			state = OUT; 
		else if (state == OUT) 
		{ 
			state = IN; 
			++wc; 
		} 
		++str; 
	} 

	return wc; 
} 

char *freq_word(char *string, int *max_counter) {
	char *copy_string = calloc(strlen(string), sizeof(char));
	copy_string = strcmpL(string);
	char *word = strtok(copy_string, SEPARATORS);
	int word_nr = countWords(string);
	int frequency = 1;


	//creating an array of char
	char **split_string = malloc(word_nr * sizeof(char *));
	for (int i = 0; i < word_nr; ++i) {
		split_string[word_nr] = calloc(20, sizeof(char));
	}

	int r_index = 0;
	while (word) {
		split_string[r_index] = word;
		r_index++;
		word = strtok(NULL, SEPARATORS);
	}
	
	sort_alphabetically(split_string, word_nr);

	char *result = calloc(20, sizeof(char));
	
	for (int i = 0; i < word_nr; ++i) {
		if (!strcmp(split_string[i], split_string[i+1])) {
			frequency++;
		} else {
			frequency = 1;
		}
		if (frequency > *max_counter) {
			result = split_string[i];
			*max_counter = frequency;
		}
	}

	free(word);
	free(copy_string);

	return result;
}

