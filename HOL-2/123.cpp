
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>o;
        vector<int>i;
        // cout<<n;
        for(int a=0;a<n;a++){
            int l;
            cin>>l;
            o.push_back(l);
        }
        int u = m;
        while(m--){
            int p;
            cin>>p;
            i.push_back(p);
        }
        int count=0;
        for(int r=0;r<n;r++){
            for(int y=0;y<u;y++){
                if(o[r]+i[y]<=k){
                    count++;
                    // cout<<"sd";
                }
            }
        }
        // cout<<"Cds";
        cout<<count<<endl;
    }
}