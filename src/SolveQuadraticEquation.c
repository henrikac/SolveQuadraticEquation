/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 * 
 * Coming soon...
*/

#include <stdio.h>
#include <math.h>

/* Prints roots of the quadratic equation a * x*x + b * x + c = 0 */
void solveQuadraticEquation(double a, double b, double c)
{
  double discriminant, root1, root2;

  discriminant = b * b - 4 * a * c;

  if (discriminant < 0)
    printf("No roots\n");
  else if (discriminant == 0)
  {
    root1 = -b/(2*a);
    printf("One root: %f\n", root1);
  }
  else
  {
    root1 = (-b + sqrt(discriminant))/(2*a);
    root2 = (-b - sqrt(discriminant))/(2*a);
    printf("Two roots: %f and %f\n", root1, root2);
  }
}   

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