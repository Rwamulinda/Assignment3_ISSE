#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void strip_chars(char *str, const char *remove_chars) {
    int write_pos = 0;
    
    // Loop through each character in the original string
    for (int read_pos = 0; str[read_pos] != '\0'; read_pos++) {
        bool found = false;
        
        // Check if the current character is in the remove_chars array
        for (int i = 0; remove_chars[i] != '\0'; i++) {
            if (str[read_pos] == remove_chars[i]) {
                found = true;  // Mark the character for removal
                break;
            }
        }
        
        // If the character isn't found in remove_chars, keep it in the string
        if (!found) {
            str[write_pos++] = str[read_pos];
        }
    }
    
    // Null-terminate the modified string
    str[write_pos] = '\0';
}

// Function to test the strip_chars function
void test_strip_chars(const char *input, const char *remove_chars, const char *expected) {
    char str[100];
    strcpy(str, input);  // Copy input to a modifiable string
    
    strip_chars(str, remove_chars);  // Call the function
    
    printf("Input: \"%s\", Remove: \"%s\", Output: \"%s\", Expected: \"%s\"\n",
           input, remove_chars, str, expected);
    
    if (strcmp(str, expected) == 0) {
        printf("Test passed!\n");
    } else {
        printf("Test failed.\n");
    }
}

int main() {
    // Test cases
    test_strip_chars("Carnegie Mellon", "l ", "CarnegieMeon");
    test_strip_chars("Test Case", "s", "Tet Cae");
    
    return 0;
}
