/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/* SOLUTION: DP, brute force (recursive solution)
total number of ways to nth step = total ways to ((n-1)th + (n-2)th)
because one time, the people only can climb 1 or 2 steps
then  total ways to ((n-1)th = total ways to ((n-2) + (n-3)th) and so on
until the recursion ends, when n = 0 or 1, with the values = 1
Fibonacci sequence
*/

#include <iostream>

using namespace std;

int climbStair(int n){

    int dp[n+1];
    // the cond to end the recursion
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i){
        
        dp[i] = dp[i-1] + dp[i-2];


    }
    return dp[n];
}

/*
What if the order of steps you take didn’t matter?
 {1,1,2}, {1,2,1} and {2,1,1} will be counted as one solution, 
 how will the solution change in this case?
 n = 2, {1,1} [2} ->2= 2/2 +1
 n = 3   {1,1,1} {1,2} ->2 = 3/2 +1
 n = 4   {1,1,1,1} {1,1,2} {2,2} ->3 =  4//2 +1
 n = 5   {1,1,1,1,1} {1,1,1,2} {1,2, 2} ->3 = 5//2 + 1
n = n   --> n//2 + 1;
*/
int climbStairNoMatterOrderSteps(int n){
    int ans;
    ans = n /2 +1;
    return ans

   
}

int main(){
    int n =2;
    cout << climbStair(n);

    return 0;
}


