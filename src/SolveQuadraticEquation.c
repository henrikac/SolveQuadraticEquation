/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 * 
 * Refactor the original code using top-down programming style
*/

#include <stdio.h>
#include <math.h>

#define INVALID_INPUT -1

typedef enum { sub, add } bool;

void solveQuadraticEquation(double a, double b, double c);
double calculate_discriminant(double a, double b, double c);
double calculate_single_root(double a, double b);
double calculate_roots(double a, double b, double discriminant, bool add_or_sub);

int main(void)
{
  double a = 1.0, b = -8.0, c = 15.0,
         d = 2.0, e =  8.0, f =  2.0;

  /* First call - coefficents are values of variables */
  solveQuadraticEquation(a, b, c);  

  /* Second call - coefficents are values of expressions */
  solveQuadraticEquation(d - 1, -e, 7 * f + 1); 

  /* Third call - coefficents are entered by user outside solveQuadraticEquation */
  while (a != 0.0 || b != 0.0 || c != 0.0)
  {
    printf("Enter coeficients a, b, and c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
      printf("Invalid input");
      return INVALID_INPUT;
    }

    if (a == 0)
    {
      printf("Not a quadratic equation because a = 0\n");
      continue;
    }
    
    solveQuadraticEquation(a, b, c);    
  }  

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
    printf("One root: %f\n", calculate_single_root(a, b));
  }
  else
  {
    root1 = calculate_roots(a, b, discriminant, add);
    root2 = calculate_roots(a, b, discriminant, sub);
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

double calculate_roots(double a, double b, double discriminant, bool add_or_sub)
{
  return add_or_sub == add ? (-b + sqrt(discriminant)) / (2 * a) : (-b - sqrt(discriminant)) / (2 * a);
}