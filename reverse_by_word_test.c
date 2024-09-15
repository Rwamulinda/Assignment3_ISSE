#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse each word in a string
void reverse_by_word(char *str) {
    int starting = 0;
    int ending = 0;
    int length = strlen(str);
    
    while (ending <= length) {
        if (isspace(str[ending]) || str[ending] == '\0') {
            int left_side = starting;
            int right_side = ending - 1;
            
            while (left_side < right_side) {
                char temp = str[left_side];
                str[left_side] = str[right_side];
                str[right_side] = temp;
                left_side++;
                right_side--;
            }
            starting = ending + 1;
        }
        ending++;
    }
}

// Test function for reverse_by_word
void test_reverse_by_word(char *test_str, const char *expected) {
    char str[100]; // Assuming max length of 100 for simplicity
    strcpy(str, test_str);  // Copy test string to avoid modifying original
    
    printf("Original string: '%s'\n", str);
    reverse_by_word(str);
    printf("Reversed string by each word: '%s'\n", str);
    
    if (strcmp(str, expected) == 0) {
        printf("Test passed!\n\n");
    } else {
        printf("Test failed! Expected: '%s'\n\n", expected);
    }
}

int main() {
    // Test cases
    test_reverse_by_word("Carnegie Mellon University", "eigrenraC nolleM ytisrevinU");
    test_reverse_by_word("Hello World", "olleH dlroW");
    return 0;
}
