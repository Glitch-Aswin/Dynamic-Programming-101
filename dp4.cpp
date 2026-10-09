/*
    Write a function howSum(targetSum,numbers) that takes in a targetSum and an array
    of numbers as arguments.

    The function should return an array containing any combinations of elements of
    numbers array that adds up to targetSum exactly. If there is no combination that 
    adds up to the target return null

    If there are multiple one, you may return any single one

*/

#include <bits/stdc++.h>

using namespace std;

/*
    Brute force recursion: O(n^m) time, where m = targetSum and n = numbers.size()

optional<vector<int>> howSum(int targetSum,const vector<int>& numbers){
    if(targetSum == 0){
        return vector<int>{};
    }
    if(targetSum < 0 ){
        return nullopt;
    }

    for(int num : numbers){
        if(num <= 0) continue;
        optional<vector<int>> remRes = howSum(targetSum - num,numbers);
        if(remRes.has_value()){
            remRes->push_back(num);
            return remRes;
        }
    }
    return nullopt;
}
*/

// Memoized: O(n*m^2) time, O(m^2) space
optional<vector<int>> howSum(int targetSum,const vector<int>& numbers,map<int,optional<vector<int>>>& memo){
    if(targetSum == 0){
        return vector<int>{};
    }
    if(targetSum < 0 ){
        return nullopt;
    }
    if(memo.count(targetSum)){
        return memo[targetSum];
    }

    for(int num : numbers){
        if(num <= 0) continue;
        optional<vector<int>> remRes = howSum(targetSum - num,numbers,memo);
        if(remRes.has_value()){
            remRes->push_back(num);
            return memo[targetSum] = remRes;
        }
    }
    return memo[targetSum] = nullopt;
}

optional<vector<int>> howSum(int targetSum,const vector<int>& numbers){
    map<int,optional<vector<int>>> memo;
    return howSum(targetSum,numbers,memo);
}


int main(){

    int target;
    cout<<"Enter the target:";
    scanf("%d",&target);

    vector<int> vec;

    int n;
    cout<<"Enter the size of the input array:";
    scanf("%d",&n);


    cout<<"Enter the elements:\n";
    for(int i =0;i<n;i++){
        int a;
        scanf("%d",&a);
        vec.push_back(a);
    }

    optional<vector<int>> result = howSum(target,vec);

    if(result.has_value()){
        for(int num : *result){
            cout<<num<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO SUM FOUND"<<endl;
    }

}