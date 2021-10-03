# Đề bài
https://open.kattis.com/contests/e9659r/problems/chopin

# Tóm tát đề bài
Có 17 nốt âm trong đó có 7 nốt âm là duy nhất (UNIQUE) và các cặp nốt âm có thể thay thế cho nhau. Các nốt âm chia thành 2 loại âm sắc major và minor. Các nốt âm loại minor có thể thay thế bằng các nốt âm minor khác bằng nó (nếu tồn tại) và tương tự với major.

- Các âm duy nhất: A, B, C, D, E, G
- Các cặp âm : A# = Bb, C# = Db, D# = Eb, F# = Gb, G# = Ab

VD: A# = Bb. Nếu có A# minor xuất hiện thì thay bằng Bb và ngược lại nếu có Bb xuất hiện thay bằng A#.
=> A# major = Bb major và A# minor = Bb minor

# Yêu cầu đề bài
Nếu âm đó là duy nhất hiện ra UNIQUE, nếu tồn tại thì thay thế bằng âm tương đương.

VD:
Input:
> - Ab minor
> - D# major
> - G minor

Output:
> - Case 1: G# minor
> - Case 2: Eb major
> - Case 3: UNIQUE

# Lời giải
Tạo một `map<string,string>` với `key` là phần tử khôgn phải duy nhất (có phần tử thay thế được), `value` là phần tử thay thế.
Với mỗi input kiểm tra xem nốt âm có tồn tại trong `map<string,string>`.
- Nếu tồn tại: Hiện ra âm thay thế với âm sắ c(major hoặc minor) tương ứng.
- Nếu không tồn tại hiện ra UNIQUE.

# Code
```cpp
#include<bits/stdc++.h>
using namespace std;

map<string,string> thanham;
char doixung[15];

void sov(){
    thanham["A#"] = "Bb";
    thanham["Bb"] = "A#";
    thanham["C#"] = "Db";
    thanham["Db"] = "C#";
    thanham["D#"] = "Eb";
    thanham["Eb"] = "D#";
    thanham["F#"] = "Gb";
    thanham["Gb"] = "F#";
    thanham["G#"] = "Ab";
    thanham["Ab"] = "G#";

    string s1, s2;
    int i=1;
    while(cin >> s1 >> s2){
        cout << "Case " << i++ << ": ";

        if(thanham.find(s1) != thanham.end()){
            cout << thanham[s1] << " " << s2;
        }
        else{
            cout << "UNIQUE";
        }

        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sov();
}
```
