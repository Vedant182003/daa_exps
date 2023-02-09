#include <stdio.h>
#include<math.h>

void
func1 (int n)//n^3
{
  int ans = n * n * n;
  printf("%d\t",ans);
}

void
func2 (int n)//n^logn
{
  float value= log(n);
  printf("%0.3f\t",n * value);
}

void func3 (int n)//logn^logn
{
  float value= log(n);
  float ans = pow(value,value);
  printf("%0.3f\t",ans);
}

void
func4 (int n)//2^logn
{
    float value = log(n);
  float ans = pow (2, value);
  printf("%0.3f\t",ans);
}

void
func5 (int n)//n
{
  printf("%d\t",n);
}

void
func6 (int n)//2 ^ (2logn)^0.5
{
  float ans = log(n);
  ans = 2* ans ;
  float value = pow(ans,0.5);
  ans = pow(2,value);
  printf("%.3f\t",ans);
}

void
func7 (int n)//n ^ (1/logn)
{
  float ans = log(n);
  float value = pow(ans,-1);
  ans = pow(n,value);
  printf("%.3f\t",ans);
}

void
func8 (int n)//logn
{
  float ans = log (n);
  printf("%0.3f\t",ans);
}

void
func9 (int n)//logn^2
{
  float ans = log (n);
  ans = pow (ans, 2);
  printf("%0.3f\t",ans);
}

void
func10 (int n)//(logn)^0.5
{
  float ans = log (n);
  ans = pow (ans, 0.5);
  printf("%0.3f\t",ans);
}

int
main ()
{
  for (int i = 1; i <= 100; i++)
    {
      func1 (i);
      func2 (i);
      func3 (i);
      func4 (i);
      func5 (i);
      func6 (i);
      func7 (i);
      func8 (i);
      func9 (i);
      func10 (i);
      printf ("\n");
    }
}
