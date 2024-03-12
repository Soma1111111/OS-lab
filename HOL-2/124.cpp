#include <bits/stdc++.h>
using namespace std;
bool f(vector<int>&left){
   int k=left.size();
   for(int i=1;i<k-2;i++){
     if(left[i]<0||left[i-1]<0||left[i+1]<0){   
       return false;
     }
     if(left[i-1]!=0){
        int l= left[i-1];
        left[i-1]=0;
         left[i]-=2*l;
         left[i+1]-=l;
         if((left[i]<=0||left[i+1]<=0)&&left[i-1]!=0){
          return false;
         }
     }
 }
 if(left[k-1]==left[k-3]&&left[k-2]==2*left[k-1])return true;
 return false;
}
int main() {
    // Write C++ code here
    int n;
    cin>>n;
while(n--){
   int k;
   cin>>k;
   vector<int> left(k);
   for(int i=0;i<k;i++){
       cin>>left[i];
   }
   if(f(left)==0) cout<<"NO"<<endl;
   else cout<<"YES"<<endl;
}
    return 0;
} 