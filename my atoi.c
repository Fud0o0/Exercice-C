int my_atoi(const char *s) {
    int res = 0;
    int sign = 1;
    int i = 0;

    // 1. Check for sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // 2. Process digits only
    for (; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            res = res * 10 + (s[i] - '0');
        }
    }

    // 3. Apply the sign
    return res * sign;
}