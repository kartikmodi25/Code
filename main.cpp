#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#include <chrono>
using namespace std::chrono;
#define pb push_back
#define mk make_pair
// #define endl "\n"
// #define mod 1000000007
#define mod 998244353
#define int long long int
#define PI 3.1415927
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define MAXN 100005
#define N 200005
#define INF 1000000000000000000
#define LOG 18
#define LG 18
using namespace std;
auto start = high_resolution_clock::now();
// typedef long long int ll;
typedef pair<int, int> ii;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    string s;
    cin >> s;
    map<char, vector<int> > mp;
    int n = s.size();
    for(char c = 'a'; c<='z'; c++){
        mp[c].pb(0);
    }
    rep(i,0,n){
        mp[s[i]].pb(i + 1);
    }
    for(char c = 'a'; c<='z'; c++){
        mp[c].pb(n+1);
    }
    int ans = 1e9;
    for(auto x: mp){
        if(x.second.size() == 2){
            continue;
        }
        int mx = 0;
        for(int j = 1; j<x.second.size(); j++){
            int len = x.second[j] - x.second[j-1]-1;
            // cout<<len<<" ";
            int cnt = 0;
            while(len){
                cnt++;
                len>>=1;
            }
            mx = max(mx, cnt);
        }
        ans = min(ans, mx);
    }
    cout<<ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases;
    test_cases = 1;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        solve();
        // cout << endl;
        cout << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
    return 0;
}