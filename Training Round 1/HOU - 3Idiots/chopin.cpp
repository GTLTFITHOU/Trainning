#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void solve(int i, string s)
{
  string note = "" , cases = "";
  int j = 0;
  while(s[j]!=' '){
    note.push_back(s[j]);
    j++;
  }
  int n = s.size();
  for (j+1; j<n; j++)
    cases.pb(s[j]);
  map<string, string> cur;
  cur["A"] = "";
  cur["B"] = "";
  cur["C"] = "";
  cur["D"] = "";
  cur["E"] = "";
  cur["F"] = "";
  cur["G"] = "";
  cur["A#"] = "Bb";
  cur["C#"] = "Db";
  cur["D#"] = "Eb";
  cur["F#"] = "Gb";
  cur["G#"] = "Ab";
  cur["Bb"] = "A#";
  cur["Db"] = "C#";
  cur["Eb"] = "D#";
  cur["Gb"] = "F#";
  cur["Ab"] = "G#";
  string tmp = cur[note];
  if (cur[note]!="")
    cout << "Case " << i << ": " << tmp << cases << endl;
  else
    cout << "Case " << i << ": " << "UNIQUE" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i = 1;
    string s;
    while(getline(cin, s)){
      solve(i++, s);
    }
}
