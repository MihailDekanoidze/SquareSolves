#include "includes.h"

int InputCoefficients(struct EquationInfo* equation)
{
    printf("Enter the coefficients : \n");

    int enteredcoef = EnterCoeff(equation);

    if (!(isfinite(equation->a) && isfinite(equation->b) && isfinite(equation->c)))
        enteredcoef = 0;

    while ((enteredcoef != 3) && (enteredcoef != EOF))
    {
        printf("Please, enter the coefficients: \n");

        enteredcoef = EnterCoeff(equation);

        if (!(isfinite(equation->a) && isfinite(equation->b)  && isfinite(equation->c)))
            enteredcoef = 0;
    }

    return enteredcoef;
}

int EnterCoeff(struct EquationInfo* equation)
{
    int enteredcoef = scanf("%lg%lg%lg", &equation->a, &equation->b, &equation->c);

    ClearBuffer();

    return enteredcoef;
}
