#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

void WordInvert(char * start, char * end)
{
  char temp;
  while (start != NULL && end != NULL && start < end)
  {
    temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}

void PhraseInvert(char * str)
{
  char * start;
  char * end;
  char * ptr = str;
  int len = strlen(str) - 1;
  while(*str++ != '\0')
  {
    if (*str != ' ')
    {
      {
        start = str;
        end = str;
      }
      while(*end != ' '&& *end != '\0')
      {
        end++;
      }
      WordInvert(start, end - 1);
      str = end;
    }
  }
  WordInvert(ptr, ptr + len);
}

int main(int argc, char** argv)
{
  char str[] = " I    am    wd student! ";
  PhraseInvert(str);
  std::cout << str << std::endl;
}
