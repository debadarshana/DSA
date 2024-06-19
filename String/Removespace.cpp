
// Remove the extra space from the string
/*
str1 =      "     Geeks For     Geeks"
output =    "GeeksForGeeks" 

str1 =      "   De  b"
output =    "Deb" 

*/
#include <iostream>
#include <string.h>
using namespace std;


/*
TC : O(length(str) ^ 2)
*/
/*
string removeSpaces(string str1)
{
    int n = str1.size();
    int i = 0;
    while(i < n)
    {
        if( ' ' == str1[i])
        {
            int k = i;
            for(int j = i+1; j < n; j++)
            {
                str1[k] = str1[j];
                
                k++;
            }
            n--;
        }
        else
            i++;
        
    }

    return str1.substr(0, n);

}

*/
/*

str1 =      "   De  b"
output =    "Deb" 

TC : O(length(str)) because onle one pass
*/




string removeSpaces(string str1)
{
    int currentIndex = 0;
    int fi = 0;
    int n = str1.size();
    while( fi < n)
    {
        if(' ' != str1[fi])
        {
            str1[currentIndex++] = str1[fi];
        }
        fi++;
    }

    return str1.substr(0, currentIndex);

}

// Driver Code
int main()
{
    char str[] = "D  ebadar  shana Parida ";
    cout << "before space:"<<str<<endl;
    
    cout <<"After space: "<< removeSpaces(str);;
    return 0;
}
