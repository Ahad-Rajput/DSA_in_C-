/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector<int>v = {2,7,11,15};
    // vector<int>v = {3,2,4};
    vector<int>v = {3,3};
    // int target = 9;
    int target = 6;
    bool found = false;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[i] + v[j] == target)
            {
                cout << "{" << i << " , " << j << "}" << endl;
                found = true;
            }
        }
    }
    if(found != true){
        cout << target << " is not present in array.\n";
    }

    return 0;
}