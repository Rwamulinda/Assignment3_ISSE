#include <stdio.h>
#include <stdbool.h>

// bool function to check if the string starts with a prefix
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

int main() {
    char str[] = "Carnegie Mellon";
    char prefix_1[] = "Carnegie";
    char prefix_2[] = "Mellon";
    
    if (is_prefix(prefix_1, str)) {
        printf("'%s' is a prefix of '%s'\n", prefix_1, str);
    } else {
        printf("'%s' is NOT a prefix of '%s'\n", prefix_1, str);
    }
    
    if (is_prefix(prefix_2, str)) {
        printf("'%s' is a prefix of '%s'\n", prefix_2, str);
    } else {
        printf("'%s' is NOT a prefix of '%s'\n", prefix_2, str);
    }
    
    return 0;
}
