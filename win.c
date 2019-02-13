#include "mathstic.h"

int	win_check(char **map)
{
  int res = 0;
  int i = 0;

    while (map && map[i] != NULL) {
        res += count_matches(map[i]);
        i = i + 1;
        }
    if (res == 0)
        return (0);
    else if (res > 0)
        return (res);
    else
        return (-1);
}
int	count_matches(char *line)
{
  int	i = 0 ;
  int	count = 0;

    if (line) {
        while (line[i] != '\0') {
            if (line[i] == '|')
                count = count + 1;
                i = i + 1;
        }
    }
    return (count);
}
char *my_strcpy(char *dest, char *src)
{
  int i = 0;

  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char *my_strdup(char *str)
{
  char	*s;

  if ((s = malloc(my_strlen(str))) == 0)
    {
      return (0);
    }
  my_strcpy(s, str);
  return (s);
}