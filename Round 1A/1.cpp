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
        vector<char> v(4000,'-');
        int ansf=0;
        while(n--){
            string s;
            cin>>s;
            int j=0;
            int f=0;
            int ind=0;
            while(j<s.size()){
                if(f==0){
                    if(s[j]!='*'){
                        if(v[ind]=='-' || v[ind]==s[j]){
                            v[ind]=s[j];
                        }
                        else{
                            ansf=1;
                            break;
                        }
                        j++;
                        ind++;
                    }
                    else{
                        f=1;
                        j=s.size()-1;
                        ind=v.size()-1;
                    }
                }
                else{
                    if(s[j]!='*'){
                        if(v[ind]=='-' || v[ind]==s[j]){
                            v[ind]=s[j];
                        }
                        else{
                            ansf=1;
                            break;
                        }
                        j--;
                        ind--;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        if(ansf==1){
            cout<<"Case #"<<cas<<": "<<"*"<<endl;
        }
        else{
            string ans;
            for(int i=0;i<v.size();i++){
                if(v[i]!='-'){
                    ans+=v[i];
                }
            }
            cout<<"Case #"<<cas<<": "<<ans<<endl;
        }
    }
}