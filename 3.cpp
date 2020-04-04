#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<fstream>
#include<queue>
#include<unordered_map>
// #define INT_MAX 2147483647
// #define INT_MIN (-__INT_MAX__ -1)
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        int n;
        cin>>n;
        int j=0;
        int c=0;
        string ans=string(n,'0');
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(make_pair(a,b),i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i].first.first>=c){
                int d=v[i].second;
                ans[d]='C';
                c=v[i].first.second;
            }
            else if(v[i].first.first>=j){
                int d=v[i].second;
                ans[d]='J';
                j=v[i].first.second;
            }
            else{
                ans="IMPOSSIBLE";
                break;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}