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
        
        if(n<=500){
            cout<<"Case #"<<cas<<": "<<endl;
            int j=1;
            while(n>0){
                cout<<j<<" 1"<<endl;
                j++;
                n--;
            }
        }
        else if(n>500 && n<521){
            cout<<"Case #"<<cas<<": "<<endl;
            cout<<"1 1"<<endl;
            cout<<"2 1"<<endl;
            cout<<"3 1"<<endl;
            cout<<"4 1"<<endl;
            cout<<"5 1"<<endl;
            cout<<"6 1"<<endl;
            cout<<"7 1"<<endl;
            cout<<"8 1"<<endl;
            cout<<"9 1"<<endl;
            cout<<"9 2"<<endl;
            cout<<"9 3"<<endl;
            cout<<"9 4"<<endl;
            cout<<"9 5"<<endl;
            cout<<"9 6"<<endl;
            cout<<"9 7"<<endl;
            cout<<"9 8"<<endl;
            cout<<"9 9"<<endl;
            n-=264;
            int curr=10;
            while(n>0){
                cout<<curr<<" "<<curr<<endl;
                curr+=1;
                n--;
            }
        }
        else if(n>=521){
            cout<<"Case #"<<cas<<": "<<endl;
            cout<<"1 1"<<endl;
            cout<<"2 1"<<endl;
            cout<<"3 1"<<endl;
            cout<<"4 1"<<endl;
            cout<<"5 1"<<endl;
            cout<<"6 1"<<endl;
            cout<<"7 1"<<endl;
            cout<<"8 1"<<endl;
            cout<<"9 1"<<endl;
            cout<<"10 1"<<endl;
            cout<<"10 2"<<endl;
            cout<<"10 3"<<endl;
            cout<<"10 4"<<endl;
            cout<<"10 5"<<endl;
            cout<<"10 6"<<endl;
            cout<<"10 7"<<endl;
            cout<<"10 8"<<endl;
            cout<<"10 9"<<endl;
            cout<<"10 10"<<endl;
            n-=521;
            int curr=11;
            while(n>0){
                cout<<curr<<" "<<curr<<endl;
                curr+=1;
                n--;
            }
        }
        //cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}