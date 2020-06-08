#include<stdio.h>
#include<float.h>

int Sum(int Number);
float Avg(int Sum, int Number);

 
int main()
{
  int Number, i, sum = 0;
  float Average =0;
  
  printf("\nPlease Enter any Integer Value\n");
  scanf("%d", &Number);
  
  sum = Sum(Number);
  Average = Avg(sum, Number);
  printf("Sum of n Numbers = %d\n", sum);
  printf("Average of n Numbers =%.2f\n", Average);
  return 0;
}
 
int Sum(int Number)
{
	int i, Sum = 0;
	
	if (Number == 0)
	{
		return Number;
	}
	else
	{
		return (Number * (Number + 1) / 2);
	}}

float Avg(int sum, int Number)
{
	double result = sum/(float)Number; 
	return result;
}
	