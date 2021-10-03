//CyclicRotation
#include <iostream>
#include <vector>
using std::cout;
using std: endl;

vector<int> solution(vector<int> &A, int K){
    vector <int> shift;
    if (A.empty() or K == A.size()) // check if A is empty array or ...
        return A;
    if (K > A.size()) // len(A)
        K = K % A.size()
    if (K < A.size())
        K = K - A.size()
    for (int i  = K; i < A.size(, i++))
        {
            shift.push_back(A[i]);

        }
    for (int  i = 0, i< K; i++)
        {
            shift.push_back(A[i])                

        }
    return shift;

}


int main() {




return 0;

}



