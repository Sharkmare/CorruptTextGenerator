#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

char *corrupt_text(const char *text) {
    char *corrupted_text = (char *)malloc(MAX_LENGTH * sizeof(char));
    char corrupters[6][2] = {"0", "@", "&", "%", "$", "§"};
    int text_length = strlen(text);
    int corruption_count = text_length / 10;
    int i, char_index, corrupter_index;
    srand(time(NULL));
    for (i = 0; i < corruption_count; i++) {
        char_index = rand() % text_length;
        if (text[char_index] != ' ') {
            corrupter_index = rand() % 6;
            strncpy(corrupted_text, text, char_index);
            strcat(corrupted_text, corrupters[corrupter_index]);
            strcat(corrupted_text, text + char_index + 1);
            strcpy(text, corrupted_text);
        } else {
            i--;
        }
    }
    return corrupted_text;
}

int main() {
    char original_text[] = "some random string";
    char *corrupted_text = corrupt_text(original_text);
    printf("Original text: %s\n", original_text);
    printf("Corrupted text: %s\n", corrupted_text);
    free(corrupted_text);
    return 0;
}
