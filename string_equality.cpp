#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int i, n, k; string a, b;
        cin >> n >> k >> a >> b;
        int have[27]={0};
        int need[27]={0};
        for(char c: a)
            have[c-'a']++;
        for(char c: b)
            need[c-'a']++;

        bool bad = false;
        for(i = 0; i < 26; i++) {
            // check if frequency of have[i] is less than need[i] or (have[i]-need[i]) is not divisible by k then conversion is not possible
            if(have[i] < need[i] || (have[i] -= need[i]) % k)
                bad = true;
            //Assign the remaining frequency of character to the next character
            have[i+1] += have[i];
        }
        cout << (bad? "No" : "Yes") << '\n';
    }
    return 0;
}
