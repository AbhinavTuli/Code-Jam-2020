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
float findnbravg(vector<vector<int> > arr,int r, int c,int maxr,int maxc){
    float sum=0;
    float ct=0;
    for(int i=r-1;i>=0;i--){
        if(arr[i][c]!=0){
            sum+=arr[i][c];
            ct++;
            break;
        }
    }
    for(int i=c-1;i>=0;i--){
        if(arr[r][i]!=0){
            sum+=arr[r][i];
            ct++;
            break;
        }
    }
    for(int i=r+1;i<maxr;i++){
        if(arr[i][c]!=0){
            sum+=arr[i][c];
            ct++;
            break;
        }
    }
    for(int i=c+1;i<maxc;i++){
        if(arr[r][i]!=0){
            sum+=arr[r][i];
            ct++;
            break;
        }
    }
    //cout<<"Yo"<<sum<<" "<<ct<<endl;
    if(ct!=0){
        return sum/ct;
    }
    else{
        return -1;
    }
}
int sumboard(vector<vector<int>> v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            sum+=v[i][j];
        }
    }
    //cout<<"sum "<<sum<<endl;
    return sum;
}
int main(){
    int t;
    cin>>t;
    int ans=0;
    for(int cas=1;cas<=t;cas++){
        int r,c;
        cin>>r>>c;
        int ans=0;
        vector<vector<int> > arr( r , vector<int> (c, 0));  
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int sk;
                cin>>sk;
                arr[i][j]=sk;
            }
        }

        while(1){
            vector<pair<int,int> >s;
            int el=0;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if (arr[i][j]!=0){
                        float avg=findnbravg(arr,i,j,r,c);
                        if(avg>arr[i][j]){
                            s.push_back(make_pair(i,j));
                            el++;
                        }
                    }
                }
            }
            ans+=sumboard(arr);

            if(el==0){
                break;
            }
            for(int i=0;i<s.size();i++){
                arr[s[i].first][s[i].second]=0;
            }
        }

        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}