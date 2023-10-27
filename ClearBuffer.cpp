#include "includes.h"

void ClearBuffer(void)
{
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {}
}
