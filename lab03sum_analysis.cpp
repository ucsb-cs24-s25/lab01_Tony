#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(const vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0){
                    vector<int> ans = {nums[i] , nums[j] , nums[k]};
                    sort(ans.begin(), ans.end());
                    bool same = false;
                    for(int m = 0; m < result.size(); m ++){
                        if(result[m] == ans){
                            same = true;
                            break;
                        }
                    }
                    if(same == false){
                        result.push_back(ans);
                    }
                }

            }
        }
    }
    return result;
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