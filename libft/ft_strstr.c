#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle) 
{
    size_t x;
    size_t y;

    x = 0;
    if (!*needle)
        return (char *)haystack;
    while (haystack[x]) {
        y = 0;
        while (haystack[x + y] == needle[y]) {
            if (needle[y + 1] == '\0')
                return (char *)&haystack[x];
            y++;
        }
        x++;
    }
    return (0);
}