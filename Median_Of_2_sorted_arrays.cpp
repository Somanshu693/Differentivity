#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);
class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
         if(array2.size()<array1.size()){
             return MedianOfArrays(array2,array1);
         }
        int m=array1.size();
        int n =array2.size();
       
    int low=0, high=m;
    while(low<=high){
        int cut1=low+(high-low)/2;
        int cut2=(m+n)/2-cut1;
        int l1=cut1==0?INT_MIN:array1[cut1-1];
        int l2=cut2==0?INT_MIN:array2[cut2-1];
        int r1=cut1==m?INT_MAX:array1[cut1];
        int r2=cut2==n?INT_MAX:array2[cut2];
        if(l1<=r2 && l2<=r1){
            if((m+n)%2==0)
         return (double)((max(l1,l2)+min(r1,r2))/2.0);
          else
          return (double)(min(r1,r2));
        }
        else if(l1>r2) high=cut1-1;
         else low =cut1+1;
    }
    return 0.0;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
    }