/* Given a sorted array of integers A of size N and an integer B, 
where array A is rotated at some pivot unknown beforehand.

For example, the array [0, 1, 2, 4, 5, 6, 7] might become [4, 5, 6, 7, 0, 1, 2].
A = [4, 5, 6, 7, 0, 1, 2, 3]
B = 4  
0/p: 0
*/

int Solution::search(const vector<int> &A, int B) 
{
    int n = A.size();
    int lo = 0;
    int hi = n-1;
    while(lo <= hi)
    {
        int mid = lo + (hi -lo)/2;
        if( B == A[mid])
            return mid;
        else if(A[lo] < A[mid])
        {
            //sorted
            if((B >= A[lo]) && (B < A[mid]))
            {
               // cout<<"hi:"<<hi<<endl;
              //  cout<<"mid:"<<mid<<endl;
              //  cout<<"*****"<<endl;
                //the B is here
                hi = mid -1;
            }
            else
            {
                //its in the unsorted part
                lo = mid + 1;
            }
        }
        else
        {
            if(B > A[mid] && ( B <= A[hi] ))
            {
                lo = mid +1;
            }
            else
                hi = mid -1;
            //This is sorted

        }
        
    }
    return -1;
}
