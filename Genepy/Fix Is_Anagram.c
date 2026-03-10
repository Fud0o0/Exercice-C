#include <stdlib.h>
#include <string.h>


int compare_char(const void *p1, const void *p2) {
    const unsigned char *a = (const unsigned char *)p1;
    const unsigned char *b = (const unsigned char *)p2;
    return (*a - *b);
}


static char *my_strdup(const char *s, size_t len) {
    char *new_str = malloc(len + 1);
    if (new_str == NULL)
        return NULL;
    memcpy(new_str, s, len + 1);
    return new_str;
}

int is_anagram(const char *left, const char *right) {
    if (!left || !right) return 1;

    size_t len_l = strlen(left);
    size_t len_r = strlen(right);

    
    if (len_l != len_r) return 1;

    char *left_copy = my_strdup(left, len_l);
    char *right_copy = my_strdup(right, len_r);

    if (!left_copy || !right_copy) {
        free(left_copy);
        free(right_copy);
        return 1;
    }

   
    qsort(left_copy, len_l, sizeof(char), compare_char);
    qsort(right_copy, len_r, sizeof(char), compare_char);

    int result = strcmp(left_copy, right_copy);

    free(left_copy);
    free(right_copy);

    return result;
}