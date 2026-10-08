/*
Say you are a traveller on a 2D grid. You begin in the top left corner and your goal is to reach the bottom right corner. 
You can only move down or right.

How many ways can you travel to the goal on a grid of dimension m*n?
*/        


//Write a fucntion `gridTraveller(m,n)` that caluclates this.

#include <bits/stdc++.h>

using namespace std;

/*

solution without memoization

int gridTraveller(int m,int n){
    if(m==1 && n==1){
        return 1;
    }
    if(m==0 || n == 0){
        return 0;
    }
    
    //recursively solve for down and right
    return gridTraveller(m-1,n)+gridTraveller(m,n-1);
}
*/

int dp[100][100] = {-1};

int gridTraveller(int m,int n){

    if(dp[m][n]>0){
        return dp[m][n];
    }

    if(m==1 && n==1){
        return 1;
    }
    if(m==0 || n == 0){
        return 0;
    }
    
    dp[m][n] = gridTraveller(m-1,n)+gridTraveller(m,n-1);
    return dp[m][n];

}


int main(){

    cout<<gridTraveller(2,3);
    cout<<endl;

    cout<<gridTraveller(5,5);
}
