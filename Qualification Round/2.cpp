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


string rec(string s){
    //out<<s<<endl;
    string ans="";
    if(s.size()==0){
        return ans;
    }
    if(s.size()==1){
        int n=s[0]-'0';
        if(n==0){
            //cout<<"1 "<<s<<endl;
            return s;
        }
        string t1(n,'(');
        string t2(n,')');
        //cout<<"2 "<<t1+s+t2<<endl;
        return t1+s+t2;
    }
    int st=0;
    int ct=0;
    for(int j=0;j<s.size();j++){
        if(s[j]=='0'){
            if(ct!=0){
                string newS=s.substr(st,ct);
                ans+="(";

                for(int i=0;i<newS.size();i++){
                    if(newS[i]>='0' && newS[i]<='9'){
                        newS[i]--;
                    }
                }

                ans+=rec(newS);
                ans+=")";
            }
            ans+="0";
            ct=0;
            st=j+1;
        }
        else{
            ct++;
        }
    }

    if(ct!=0){
                string newS=s.substr(st,ct);
                ans+="(";

                for(int i=0;i<newS.size();i++){
                    if(newS[i]>='0' && newS[i]<='9'){
                        newS[i]--;
                    }
                }

                ans+=rec(newS);
                ans+=")";

            }
    //cout<<"3 "<<ans<<endl;
    return ans;
}
int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        string s;
        cin>>s;
        string ans=rec(s);
        int ct=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]>='0' && ans[i]<='9'){
                ans[i]=s[ct];
                ct++;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}