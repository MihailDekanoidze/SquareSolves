#include "includes.h"

int main()
{
    int completion = -1;
    while (completion != 0)
    {
        struct EquationInfo equation = {.a = 0,
                                        .b = 0,
                                        .c = 0,
                                        .nRoots = 0,
                                        .x1 = NAN,
                                        .x2 = NAN};

        if (InputCoefficients(&equation) == EOF)
        {
            printf("Coefficients did not get\n");
            return 1;
        }

        SquareSolution(&equation);

        OutputSolutions(&equation);

        completion = IsContinue();
    }

    return 0;
}
