int my_atoi(const char *s) {
    int res = 0;
    int sign = 1;
    int i = 0;

    
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    
    for (; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
        }
    }

    
    return res * sign;
}