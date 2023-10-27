#include "includes.h"

void SquareSolution(struct EquationInfo* equation)
{
    assert (equation != NULL);

    const double a = equation->a;
    const double b = equation->b;
    const double c = equation->c;

    if (CmpDbl(a, 0))
    {
        LinearSolution(equation);
    }
    else
    {
        const double discriminant = b * b - 4 * a * c;

        if (CmpDbl(discriminant, 0))
        {
            equation->nRoots = ONE_ROOT;
            equation->x1 = (CmpDbl(b, 0)) ? 0 : (- b / (2 * a));
            equation->x2 = NAN;
        }
        else if (discriminant < 0)
        {
            equation->nRoots = NO_ROOTS;
            equation->x1 = NAN;
            equation->x2 = NAN;
        }
        else
        {
            const double sqrt_disc = sqrt(discriminant);
            equation->nRoots = TWO_ROOTS;
            equation->x1 = (a > 0) ? (- b - sqrt_disc) / (2 * a):
                                     (- b + sqrt_disc) / (2 * a);

            equation->x2 = (a > 0) ? (- b + sqrt_disc) / (2 * a):
                                     (- b - sqrt_disc) / (2 * a);

            if (CmpDbl(equation->x1, -0))
                equation->x1 = 0;
            if (CmpDbl(equation->x2, -0))
                equation->x2 = 0;
        }
    }
}
