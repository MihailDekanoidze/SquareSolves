#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

enum NROOTS{
     NO_ROOTS = 0,
     ONE_ROOT = 1,
     TWO_ROOTS = 2,
     INFINITE_ROOTS = -1
};

struct EquationInfo
{
    double a;
    double b;
    double c;
    int nRoots;
    double x1;
    double x2;
};

#include "ExtraFunctions.h"
#include "Interface.h"
#include "SquareSolution.h"
