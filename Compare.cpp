#include "includes.h"

static const double EPSILON = 0.000001;

int CmpDbl (const double a, const double b)
{
    return (fabs(a - b) < EPSILON || (isnan(a) && isnan(b)));
}
