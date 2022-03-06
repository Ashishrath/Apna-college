#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {2,1,5,8,3};
    vector<int> ans;
    
    for(int i = 0; i < v.size(); i++) {
        int sum = 0;
        for(int j = i; j < v.size(); j++) {
            sum += v[j];
            ans.push_back(sum);
        }
    }

    for(int a: ans) {
        cout<<a<<" ";
    }
    return 0;
}
