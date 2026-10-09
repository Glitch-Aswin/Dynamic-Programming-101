/*
Write a function `canSum(targetSum, numbers)` that takes in a targetSum and an
array of numbers as arguments

The function should be able to predict correctly whether it would be possible 
to generate the TargetSum using the numbers from the array and return the
corresponding boolean value.

You may use the elements of the array as many times as you need


You may assume that all input numbers are non negative

*/


#include <bits/stdc++.h>

using namespace std;

/*
    Solution without memoization

    bool canSum(int targetSum,vector<int> numbers){

    if(targetSum<0){
        return false;
    }
    if(targetSum==0){
        return true;
    }

    for(int num : numbers){
        int rem = targetSum - num;
        if(canSum(rem,numbers)){
            return true;
        }
    }

    return false;
}
*/

unordered_map<int,bool> dp;

bool canSum(int targetSum,vector<int> numbers){

    if(dp.find(targetSum) != dp.end()){
        return dp[targetSum];
    }
    if(targetSum<0){
        return false;
    }
    if(targetSum==0){
        return true;
    }

    for(int num : numbers){
        int rem = targetSum - num;
        dp[rem] = canSum(rem,numbers);
        if(dp[rem]){
            return true;
        }
    }

    return false;
}


int main(){
    cout<<"Enter a number:";
    int target;
    scanf("%d",&target);

    vector<int> vec = {7,14};
    if(canSum(target,vec)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }

}