
#include<bits/stdc++.h>
using namespace std;


int solution(vector<int>arr){
    int ans=INT_MIN;
    int result=-1;
    vector<int>weight(arr.size(),0);
    for(int i=0;i<arr.size();i++){
        int source=i;
        int dest=arr[i];
        if(dest!=-1){
            weight[dest]+=source;
            if(ans<=weight[dest]){
                ans=max(ans,weight[dest]);
                result=dest;
            }
            
        }
    }
    if(ans!=INT_MIN)
        return result;
    return -1;
}

void solution_function()
{
    int N;
    cin >> N;
    vector<int> Edge(N);
    for (int i = 0; i < N; i++) {
        cin >> Edge[i];
    }
    int ans = solution(Edge);
    cout << ans;
}
int main() {
    solution_function();
    return 0;
}
