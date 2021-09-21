#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    map<string, string> mp;
    mp["A#"] = "Bb";
    mp["Bb"] = "A#";

    mp["C#"] = "Db";
    mp["Db"] = "C#";

    mp["D#"] = "Eb";
    mp["Eb"] = "D#";

    mp["F#"] = "Gb";
    mp["Gb"] = "F#";

    mp["G#"] = "Ab";
    mp["Ab"] = "G#";

    int i = 1;
    string key, name;
    while (cin >> key)
    {
        cin >> name;
        cout<<"Case "<<i<<": ";
        if(mp.find(key) != mp.end()){
            cout<<mp[key]<<" "<<name<<endl;
        }else{
            cout<<"UNIQUE"<<endl;
        }
        ++i;
    }

}