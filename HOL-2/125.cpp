#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 0;
    int i = 0;
    while(i < n){
        string s1 = "map";
        string s2 = "pie";
        if(s[i] == s1[0] and s[i+1] == s1[1] and s[i+2] == s1[2]){
           
              cnt++;
              i += 3;
           
        }

        else if(s[i] == s2[0] and s[i+1] == s2[1] and s[i+2] == s2[2]){
          
              cnt++;
              i += 3;
           
        }
        else i++;
     }

     cout<<cnt<<endl;
    }
}