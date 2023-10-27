#include "includes.h"

void LinearSolution(struct EquationInfo* equation)
{
    assert(equation != NULL);

    const double b = equation->b;
    const double c = equation->c;

    if (!CmpDbl(b, 0))
    {
        equation->nRoots = ONE_ROOT;
        equation->x1 = (CmpDbl(c, 0)) ? 0 : -c / b;
        equation->x2 = NAN;
    }
    else
    {
        equation->nRoots = (CmpDbl(c, 0)) ? INFINITE_ROOTS :
                                            NO_ROOTS;
        equation->x1 = NAN;
        equation->x2 = NAN;
    }
}
