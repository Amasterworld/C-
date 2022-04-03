
/* union, the size of union  =  the size of the maximum size of the element in union = the size of the
for example in thi union exampe {
int x;
char[10];
float y;
};
 hence sizeof(exame) = 10;

 - at the run time moment, only can access one element of the union.


*/
#include <iostream>
 
union date
{
    int d;
    int m;
    int y;
};
 
int main()
{
    date dat;
 
    printf("\nSize of union: %d", sizeof(date));
    dat.d = 24;
    dat.m = 9;
    dat.y = 2014;
 
    printf("\ndate = %d", dat.d);
    printf("\nmonth = %d", dat.m);
    printf("\nyear = %d", dat.y);
 
   return 0;
 
}