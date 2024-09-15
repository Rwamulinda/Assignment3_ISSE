#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main() {
    char str[] = "one two one three";
    char substr[] = "one ";
    
    printf("Original string: %s\n", str);
    int pos = remove_last_substr(str, substr);
    
    if (pos != -1) {
        printf("the updated  string after removing last '%s': %s\n", substr, str);
    } else {
        printf("Substring '%s' not found.\n", substr);
    }
    
    return 0;
}




// Function to check if a string starts with a given prefix
bool is_prefix(const char *prefix, const char *str) {
    while (*prefix && *str) {
        if (*prefix != *str) {
            return false;
        }
        prefix++;
        str++;
    }
    return *prefix == '\0';
}

// Function to remove the last occurrence of a substring from a string
int remove_last_substr(char *str, const char *substr) {
    int length = strlen(str);
    int sub_length = strlen(substr);
    
    if (sub_length == 0) {
        return length;
    }
    
    int last_pos = -1;
    
    for (int i = 0; i <= length - sub_length; i++) {
        if (is_prefix(substr, str + i)) {
            last_pos = i;
        }
    }
    
    if (last_pos != -1) {
        for (int i = last_pos; i <= length - sub_length; i++) {
            str[i] = str[i + sub_length];
        }
    }
    
    return last_pos;
}

