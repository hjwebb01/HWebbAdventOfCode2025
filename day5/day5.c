#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int day5_part1(char** input, int input_size) {
    
    return 0;
}

int main() {
    FILE* file = fopen("day5/input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char** input = NULL;
    int input_size = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        
        // Skip empty lines
        if (strlen(line) == 0) {
            continue;
        }

        // Allocate memory for new line
        char** temp = realloc(input, (input_size + 1) * sizeof(char*));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            fclose(file);
            return 1;
        }
        input = temp;
        
        input[input_size] = malloc(strlen(line) + 1);
        if (input[input_size] == NULL) {
            printf("Memory allocation failed\n");
            fclose(file);
            return 1;
        }
        strcpy(input[input_size], line);
        input_size++;
    }

    fclose(file);

    // Pass input to helper method
    int result = day5_part1(input, input_size);
    printf("%d\n", result);

    // Free allocated memory
    for (int i = 0; i < input_size; i++) {
        free(input[i]);
    }
    free(input);

    return 0;
}