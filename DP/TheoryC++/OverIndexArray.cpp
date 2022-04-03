    #include <stdio.h>

    #include<iostream>

    using namespace std;

    int main ()

    {

        int array[] = {0, 2, 4, 6, 7, 5, 3};

        int n, result = 0;

        for (n = 0; n < 8; n++) 

        {

            result += array[n];

        }
        // arry from 0 to 6 but n can be 7 that means result = 0+2+4+6+7+5+4+array[7]
        // array[7] does not have hence compiler give us a gabage value
        cout << result;

        return 0;
    }

   