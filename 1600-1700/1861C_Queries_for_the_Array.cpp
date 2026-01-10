#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool ok=true;
        int len=0;
        vector<int>t,f;
        if(s.length()==1){
            if(s[0]=='0'){
                cout<<"NO"<<endl;
                continue;
            }
        }
        for(int i=0;i<s.length();i++){
            char x=s[i];
            if(x=='+')len++;
            if(x=='-')len--;
            if(x=='-'){
                while(f.size() && f.back()>len){
                    f.pop_back();
                }
                int b=0;
                while(t.size() && t.back()>len){
                    t.pop_back();
                    b=1;
                }
                if(b==1){
                    if(t.size()==0 || t.back()!=len)t.push_back(len);
                }
                
            }
            if(len<=1 && x=='0'){
                ok=false;
                break;
            }
            if(x=='+'){
                //if(t.size() && t.back()==len-1)t.push_back(len);
                if(f.size() && f.back()==len-1)f.push_back(len);
            }

            if(x=='1'){
                if(f.size()!=0){
                    ok=false;
                    break;
                }
                if(t.size()==0 || t.back()!=len)t.push_back(len);
            }
            if(x=='0'){
                if(t.size() && t.back()>=len){
                    ok=false;
                    break;
                }
                
                if(f.size()==0 || f.back()!=len)f.push_back(len);
            }
           // cout<<" t" <<" "<<t.size()<<" f "<<f.size()<<endl;
        }
        if(!ok){
            cout<<"NO"<<endl;
        }else cout<<"YES"<<endl;
    }
}