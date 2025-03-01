#include <stdio.h>
#include <unistd.h>
  int main (int argc, char* argv [])
{
  if(argc > 1)
  {
    int i = 1;
    while (argc >= i)
    {
      write(1, &argv[i], 1);
      i++;
    }
  }
}