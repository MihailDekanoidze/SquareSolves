#include "includes.h"

int IsContinue(void)
{
    printf("Enter 1 to continue or 0 for exit\n");

    int completion = -1;

    while ((completion != 1) && (completion != 0))
    {
        if (scanf("%d", &completion))
        {
            ClearBuffer();

            switch (completion)
            {
                case 1 :
                        return 1;
                case 0 :
                        return 0;
                default:
                        printf("Command not recognized, please enter the command again:\n");
                        break;
            }
        }
        else
        {
            ClearBuffer();
            printf("Command not recognized, please enter the command again:\n");
        }
    }

    printf("Unexpected exit\n");
    return 1;
}
