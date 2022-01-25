#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int digitsize(int num)
{
    return (int) log10(num) + 1;
}

int add(int a, int b)
{
    int sum = 0;
    while(b--)
            sum += a;
    return sum;
}

void gethalfs(int num, int * first, int * last)
{
    int n, po;
    
    if (num == 0) return;
    n = digitsize(num);
    po = (int) pow(10, n/2);
    *first = num / po;
    *last  = num - *first * po;
    return;
}

int multiply(int x, int y)
{
    int a, b, c, d;
    int ac, bd, adbc;
    int n, ans;

    a = b = c = d = 0;
    ac = adbc = bd = 0;
    
    if (x<10 || y<10) return add(x, y);
    gethalfs(x, &a, &b);
    gethalfs(y, &c, &d);
    ac = multiply(a, c);
    bd = multiply(b, d);
    adbc = multiply(a+b, c+d) - (ac + bd);
    n = digitsize(x);
    ans = (pow(10, n) * ac) + (pow(10, n/2) * adbc) + bd;
    return ans;
}

int main(void)
{
    int x = 3131; //first number; first half:a, second half:b
    int y = 6969; //second number; first half:c, second half:d

    if (digitsize(x) != digitsize(y)) {
            printf("Number of digits are not equal.\n");
            exit(1);
    }

    printf("%d * %d = %d \n", x, y, multiply(x, y));

    return 0;
}
