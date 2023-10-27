#include "includes.h"

int TestInput(struct EquationInfo* equation, FILE* test);

int TestCheck(const struct EquationInfo* equation, FILE * test);

int main()
{
    FILE* test = fopen("test", "r");

    struct EquationInfo equation = {.a = 0,
                        .b = 0,
                        .c = 0,
                        .nRoots = 0,
                        .x1 = NAN,
                        .x2 = NAN};

    printf("Testing:\n");

    int CountTests = 0;

    if (fscanf(test, "%d", &CountTests) != EOF)
    {

        for (int i = 0; i < CountTests; i++)
        {
            printf("Test %d\n", i + 1);
            int errors = 0;
            errors += TestInput(&equation, test);
            SquareSolution(&equation);
            errors += TestCheck(&equation, test);

            if (errors != 0)
            {
                printf("Program finished with errors\n");
                return 1;
            }

            equation.a = 0;
            equation.b = 0;
            equation.c = 0;
            equation.nRoots = 0;
            equation.x1 = NAN;
            equation.x2 = NAN;
        }

        fclose(test);

        return 0;
    }
}

int TestCheck(const struct EquationInfo* equation, FILE * test)
{
    int TruenRoots = 0;
    double truex1 = 0;
    double truex2 = 0;

    if (fscanf(test, "%d", &TruenRoots) == EOF)
        return 1;
    if (fscanf(test, "%lg", &truex1) == EOF)
        return 1;
    if (fscanf(test, "%lg", &truex2) == EOF)
        return 1;

    int CmpnRoots = TruenRoots == equation->nRoots;
    int Cmpx1 = (CmpDbl(truex1, equation->x1)) || (isnan(equation->x1) && (CmpDbl(truex1, 0)));
    int Cmpx2 = (CmpDbl(truex2, equation->x2)) || (isnan(equation->x2) && (CmpDbl(truex2, 0)));

    if (CmpnRoots && Cmpx1 && Cmpx2)
        printf("Success!\n");
    else
        printf("Failed\n");

    printf("Entered coefficients:\n");
    printf("a = %lg\nb = %lg\nc = %lg\n", equation->a, equation->b, equation->c);
    printf("nRoots = %d / TruenRoots = %d\n", equation->nRoots, TruenRoots);
    printf("x1 = %lg / truex1 = %lg\n", equation->x1, truex1);
    printf("x2 = %lg / truex2 = %lg\n", equation->x2, truex2);
    printf("\n");

    return 0;
}

int TestInput(struct EquationInfo* equation, FILE* test)
{
    if (fscanf(test, "%lg", &equation->a) == EOF)
        return 1;
    if (fscanf(test, "%lg", &equation->b) == EOF)
        return 1;
    if (fscanf(test, "%lg", &equation->c) == EOF)
        return 1;

    return 0;
}
