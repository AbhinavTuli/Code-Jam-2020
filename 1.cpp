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
        vector<vector<int> > arr( n , vector<int> (n)); 
        vector<set<int> > rows(n);
        vector<set<int> > cols(n);
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a;
                cin>>a;
                if(i==j){
                    t+=a;
                }
                arr[i][j]=a;
                rows[i].insert(a);
                cols[j].insert(a);
            }
        }

        int ansRow=0;
        int ansCol=0;

        for(int i=0;i<n;i++){
            if(rows[i].size()!=n){
                ansRow++;
            }
            if(cols[i].size()!=n){
                ansCol++;
            }
        }
        cout<<"Case #"<<cas<<": "<<t<<" "<<ansRow<<" "<<ansCol<<endl;
    }
}