//
// Created by Kylian Lee on 2021/04/07.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long int ll;

ll INF = 100000000000001;

using namespace std;

int main(){
    int n;

    cin >> n;

    ll cache[n][2];

    vector<ll> cost(n);
    for(int i =0; i < n; i++)
        cin >> cost[i];

    vector<string> words_orig(n), words_rev(n);
    for(int i = 0; i < n; i++) {
        cin >> words_orig[i];
        words_rev[i] = words_orig[i];
        reverse(words_rev[i].begin(), words_rev[i].end());
        cache[i][0] = INF; cache[i][1] = INF;
    }

    cache[0][0] = 0, cache[0][1] = cost[0];

    for(int i = 1; i < n; i++){
        if(words_orig[i] >= words_orig[i-1])
            cache[i][0] = cache[i-1][0];
        if(words_orig[i] >= words_rev[i-1])
            cache[i][0] = min(cache[i][0], cache[i-1][1]);

        if(words_rev[i] >= words_orig[i-1])
            cache[i][1] = cache[i-1][0] + cost[i];
        if(words_rev[i] >= words_rev[i-1])
            cache[i][1] = min(cache[i][1], cache[i-1][1] + cost[i]);
    }

    ll answer = min(cache[n-1][0], cache[n-1][1]);

    if(answer == INF)
        cout << -1 << endl;
    else
        cout << answer << endl;

    return 0;
}