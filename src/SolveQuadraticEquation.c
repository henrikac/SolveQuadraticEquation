/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 * 
 * Refactor the original code using top-down programming style
*/

#include <stdio.h>
#include <math.h>

typedef enum { negative, positive } bool;

void solveQuadraticEquation(double a, double b, double c);
double calculate_discriminant(double a, double b, double c);
double calculate_single_root(double a, double b);
double calculate_roots(double a, double b, double discriminant, bool status);

int main(void)
{
  double a = 1.0, b = -8.0, c = 15.0,
         d = 2.0, e =  8.0, f =  2.0,
         g, h, i;

  /* First call - coefficents are values of variables */
  solveQuadraticEquation(a, b, c);  

  /* Second call - coefficents are values of expressions */
  solveQuadraticEquation(d - 1, -e, 7 * f + 1); 

  /* Third call - coefficents are entered by user outside solveQuadraticEquation */
  printf("Enter coeficients a, b, and c: ");
  scanf("%lf %lf %lf", &g, &h, &i);
  solveQuadraticEquation(g, h, i);  

  return 0;
}

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c)
{
  double discriminant, root1, root2;

  discriminant = calculate_discriminant(a, b, c);

  if (discriminant < 0)
    printf("No roots\n");
  else if (discriminant == 0)
  {
    root1 = calculate_single_root(a, b);
    printf("One root: %f\n", root1);
  }
  else
  {
    root1 = calculate_roots(a, b, discriminant, positive);
    root2 = calculate_roots(a, b, discriminant, negative);
    printf("Two roots: %f and %f\n", root1, root2);
  }
}

double calculate_discriminant(double a, double b, double c)
{
  return b * b - 4 * a * c;
}

double calculate_single_root(double a, double b)
{
  return -b / (2 * a);
}

double calculate_roots(double a, double b, double discriminant, bool status)
{
  if (status == positive)
    return (-b + sqrt(discriminant)) / (2 * a);
  else
    return (-b - sqrt(discriminant)) / (2 * a);
}