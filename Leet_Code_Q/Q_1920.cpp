#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>a){
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> nums = {0,2,1,5,3,4};
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = nums[nums[i]];
    }
    printArray(ans);
    return 0;
}