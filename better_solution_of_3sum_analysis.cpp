#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> res;
    vector<int> result;
    int sum;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k){
            sum = nums[i] + nums[j] + nums[k];
            if(sum > 0){
                k-- ;
            }
            else if(sum < 0){
                j ++;
            }
            else{
                res.push_back({nums[i],nums[j],nums[k]});
                j++;
                 while(nums[j] == nums[j - 1] && j < k){
                j++;
            }
            }
        }
    }
    return res;
}

vector<int> getRandomArr(int n){
    vector<int> res(n);
    srand(static_cast<unsigned int>(time(nullptr)));
    const int range = 100000 * 2 + 1; 
    for(int i  = 0; i < n - 3; i++){
        res[i] = rand() % range - 100000;
    }
    res[n - 3] = -1;
    res[ n -2 ] = 3;
    res[n - 1] = -2;
    return res;
}

int main(){
    vector<int> n_set = {5,10,50,100,200,400,800,1600,3200,4000};
    for(int i = 0; i < n_set.size(); i++){
    auto start = chrono::high_resolution_clock::now();
    vector<vector<int>> result = threeSum(getRandomArr(n_set[i]));
    auto end = chrono::high_resolution_clock::now();
    double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    cout << " size of n: " << n_set[i] << " " << "running time: "<< time_ms << endl;
    } 
    return 0;
}