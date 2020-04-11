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

vector<vector<int>> findSums(int n,int k){
    vector<vector<int>> ans;
    if(n==5){
        for(int a=1;a<=5;a++){
            for(int b=1;b<=5;b++){
                for(int c=1;c<=5;c++){
                    for(int d=1;d<=5;d++){
                        int e=k-a-b-c-d;
                        if(e>=1 && e<=n){
                            vector<int> v;
                            v.push_back(a);
                            v.push_back(b);
                            v.push_back(c);
                            v.push_back(d);
                            v.push_back(e);
                            ans.push_back(v);
                        }
                    }
                }
            }
        }
    }
    if(n==4){
        for(int a=1;a<=4;a++){
            for(int b=1;b<=4;b++){
                for(int c=1;c<=4;c++){
                    int d=k-a-b-c;
                    if(d>=1 && d<=n){
                        vector<int> v;
                        v.push_back(a);
                        v.push_back(b);
                        v.push_back(c);
                        v.push_back(d);
                        ans.push_back(v);
                    }
                }
            }
        }
    }
    
    if(n==3){
        for(int a=1;a<=3;a++){
            for(int b=1;b<=3;b++){
                int c=k-a-b;
                if(c>=1 && c<=n){
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                ans.push_back(v);
                }
            }
        }
    }
    return ans;
}

int checkCol(vector<vector<int>> &v,int num,int col){ // num to be inserted
    for(int j=0;j<v.size();j++ ){
        if(v[j][col]==num){
            return -1;
        }
    }
    return 0;
}
int checkRow(vector<vector<int>> &v,int num,int row){ // num to be inserted
    for(int j=0;j<v.size();j++ ){
        if(v[row][j]==num){
            return -1;
        }
    }
    return 0;
}
int findAns(vector<vector<int>> &v){
        //cout<<"Yo"<<endl;
    int n=v.size();
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size();j++){
            //cout<<i<<" "<<j<<endl;
            if(i==j){
                continue;
            }
            if(v[i][j]!=0){
                continue;
            }
            int ct=0;
            for(int k=1;k<=n;k++){
                //put this number
                if((checkRow(v,k,i)+checkCol(v,k,j))!=0){
                    continue;
                }
                ct++;
                v[i][j]=k;
                int x= findAns(v);
                if(x==0){
                    return 0;
                }
            }
            if(ct==0){
                return -1;
            }
        }
    }
    return 0;

}
int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        int n,k;
        cin>>n>>k;
        if(n==2){
            if(k==2){
                cout<<"Case #"<<cas<<": "<<"POSSIBLE"<<endl;
                cout<<"1 2"<<endl<<"2 1"<<endl;
            }
            else if(k==4){
                cout<<"Case #"<<cas<<": "<<"POSSIBLE"<<endl;
                cout<<"2 1"<<endl<<"1 2"<<endl;
            }
            else{
                cout<<"Case #"<<cas<<": "<<"IMPOSSIBLE"<<endl;
            }
            continue;
        }
        vector<vector<int> > sums = findSums(n,k);
        //cout<<sums.size()<<endl;
        int f=0;
        int x;
        for(int jl=0;jl<sums.size();jl++){
            vector<vector<int> > v( n , vector<int> (n,0)); 
            for(int i=0;i<n;i++){
                v[i][i]=sums[jl][i];
            }
            x=findAns(v);
            if(x!=-1){
                f=1;
                cout<<"Case #"<<cas<<": "<<"POSSIBLE"<<endl;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        cout<<v[i][j]<<" ";
                    }
                    cout<<endl;
                }
                break;
            }
            // else{
            //     cout<<"nah"<<endl;
            // }
        }
        if(f==0){
            cout<<"Case #"<<cas<<": "<<"IMPOSSIBLE"<<endl;
        }
    }
}