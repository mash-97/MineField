#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

bool cmp(PII a, PII b){
    int ad = abs(a.first-a.second);
    int bd = abs(b.first-b.second);

    return  ad==bd?a.first < b.first : ad < bd ;
}

PII superstitiousSocks(int n, int k, int *ss){
    vector<PII> pairs;
    sort(ss, ss+n);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            pairs.push_back(PII(ss[i], ss[j]));
        }
    }
    sort(pairs.begin(), pairs.end(), cmp);
//    cout << "Sorted Pairs: \n";
//    for(auto p: pairs)
//        cout << p.first << " "<<p.second<<": "<<abs(p.second-p.first)<<endl;
    return pairs[k-1];
}
int main(){
    int n, k;
    while(1){
        scanf("%d %d", &n, &k);
        if(n==0 && k==0) break;
        int ss[n];
        for(int i=0; i<n; i++)
            scanf("%d", &ss[i]);
        PII rp = superstitiousSocks(n, k, ss);
        printf("%d %d\n", rp.first, rp.second);
    }
    return 0;
}
