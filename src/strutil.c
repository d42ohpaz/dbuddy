#include <string.h>

#include "strutil.h"

void trim(char * str) {
    ltrim(str);

    if (strlen(str) == 0)
        return;

    rtrim(str);
}

void ltrim(char * str) {
    int i = 0, l = 0;

    while (str[l] == '\0' || str[l] == '\t' || str[l] == '\n' || str[l] == '\r' || str[l] == '\v' || str[l] == ' ')
        l++;

    if (strlen(str) > l) {
        while (str[i + l] != '\0') {
            str[i] = str[i + l];
            i++;
        }
    }

    str[i] = '\0';
}

void rtrim(char * str) {
    size_t l = strlen(str);

    while (str[l] == '\0' || str[l] == '\t' || str[l] == '\n' || str[l] == '\r' || str[l] == '\v' || str[l] == ' ')
        l--;

    str[l + 1] = '\0';
}
