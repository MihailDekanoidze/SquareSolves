#include "includes.h"

void OutputSolutions(const struct EquationInfo* equation)
{
    // TODO: Add assert
    assert(equation != NULL);

    // TODO: Add consts
    const double    a = equation->a;
    const double    b = equation->b;
    const double    c = equation->c;
    const int       nRoots = equation->nRoots;
    const double    x1 = equation->x1;
    const double    x2 = equation->x2;

    printf("Equation\'s coefficients:\na = %lf\nb = %lf\nc = %lf\n", a, b, c);

    if (nRoots == TWO_ROOTS)
    {
        printf("Count of solutions: %d\n", nRoots);
        printf("x1 = %g\nx2 = %g\n", x1, x2);
    }
    else if (nRoots == ONE_ROOT)
    {
        printf("Count of solutions: %d\n", nRoots);
        printf("x1 = %g\n", x1);
    }
    else if (nRoots == NO_ROOTS)
    {
        printf("The equation hasn\'t got solutions\n");
    }
    else
    {
        printf("The equation has infinite number of solutions\n");
    }
}
