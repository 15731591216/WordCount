#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    char *mode = argv[1];  
    char *filename = argv[2];  
  
    FILE *file = fopen(filename, "r");  
    if (file == NULL) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    int ch, is_word = 0, char_count = 0, word_count = 0;  
  
    while ((ch = fgetc(file)) != EOF) {  
        char_count++; // Count all characters  
  
        if (isspace(ch) || ch == ',') {  
            if (is_word) {  
                word_count++;  
                is_word = 0;  
            }  
        } else {  
            is_word = 1;  
        }  
    }  
  
    if (is_word) { // Check for last word  
        word_count++;  
    }  
  
    if (strcmp(mode, "-c") == 0) {  
        printf("字符数：%d\n", char_count);  
    } else if (strcmp(mode, "-w") == 0) {  
        printf("单词数：%d\n", word_count);  
    } else {  
        fprintf(stderr, "Invalid mode: %s\n", mode);  
        fclose(file);  
        return 1;  
    }  
  
    fclose(file);  
    return 0;  
}