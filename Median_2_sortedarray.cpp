/* 
Given two sorted arrays A and B of size M and N respectively, return the median of the two sorted arrays.
Round of the value to the floor integer [2.6=2, 2.2=2]
Input 1:

A = [1, 3]
B = [2]

Input 2:

A = [1, 2]
B = [3,4]


Example Output

Output 1:


3


Output 2:


3
  */

int Solution::solve(vector<int> &A, vector<int> &B) 
{
    int n1 = A.size();
    int n2 = B.size();
    int n = n1 + n2;
    if( n1 > n2)
        return solve(B,A);
    int lo = 0;
    int hi = n1;
    while( lo <= hi)
    {

        int mid1 = (lo + hi ) >> 1;
        int mid2 = (n + 1)/2 - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1) r1 = A[mid1];
        if(mid1 -1 >= 0) l1 = A[mid1-1];

        if(mid2 < n2) r2 = B[mid2];
        if(mid2 -1 >= 0) l2 = B[mid2-1];



        if( (l1 <= r2) && (l2 <= r1) )
        {

            //valid seggregation
            if(n %2 == 1) return max(l1,l2);
            else return (max(l1,l2) + min(r1,r2))/2;
        }
        else if( l1 > r2)
            hi = mid1-1;
        else
            lo = mid1 +1;
    }
    return 0;
}
