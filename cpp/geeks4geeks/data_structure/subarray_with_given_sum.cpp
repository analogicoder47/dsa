// DSG on geeksforgeeks
// subarray with given sum

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        if (s == 0 || n == 0) {
            return create_res(-1);
        }

        int subarr_sum = 0;
        int left_idx   = 0;
        int right_idx  = 0;

        vector<int>::iterator iter;
        for (iter = arr.begin(); iter != arr.end(); iter++) {
            subarr_sum = subarr_sum + *iter;

            if (subarr_sum == s) {
                return create_res(left_idx+1, right_idx+1);

            } else if (subarr_sum > s) {
                break;
            }
            right_idx++;
        }

        while (right_idx < n) {
            if (subarr_sum == s) {
                return create_res(left_idx+1, right_idx+1);

            } else if (subarr_sum < s) {
                right_idx++;
                subarr_sum = subarr_sum + arr[right_idx];

            } else {
                subarr_sum = subarr_sum - arr[left_idx];
                left_idx++;   
            }
        }
        return create_res(-1);
    }

    vector<int> create_res(int left_idx, int right_idx) {
        vector<int> res;
        res.push_back(left_idx);
        res.push_back(right_idx);

        return res;
    }

    vector<int> create_res(int not_found_idx) {
        vector<int> res;
        res.push_back(not_found_idx);

        return res;
    }
};

void print_res(vector<int> res) {
    if (res.size() == 2) {
        cout << res[0] << ", " << res[1] << endl;
    } else {
        cout << res[0] << endl;
    }
}

int main(int argc, char** argv)
{
    int S = 12;
    int N = 5;
    vector<int> arr1;
    int A1[] = {1, 2, 3, 7, 5};
    for (int i = 0; i < N; i++) {
        arr1.push_back(A1[i]);
    }

    Solution sol;
    vector<int> res1 = sol.subarraySum(arr1, N, S);
    print_res(res1);

    S = 15;
    N = 10;
    vector<int> arr2;
    int A2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < N; i++) {
        arr2.push_back(A2[i]);
    }
    vector<int> res2 = sol.subarraySum(arr2, N, S);
    print_res(res2);

    S = 0;
    N = 4;
    vector<int> arr3;
    int A3[] = {1, 2, 3, 4};
    for (int i = 0; i < N; i++) {
        arr3.push_back(A3[i]);
    }
    vector<int> res3 = sol.subarraySum(arr3, N, S);
    print_res(res3);

    S = 3;
    N = 1;
    vector<int> arr4;
    int A4[] = {19};
    for (int i = 0; i < N; i++) {
        arr4.push_back(A4[i]);
    }
    vector<int> res4 = sol.subarraySum(arr4, N, S);
    print_res(res4);

    S = 23;
    vector<int> res5 = sol.subarraySum(arr4, N, S);
    print_res(res5);

    S = 19;
    vector<int> res6 = sol.subarraySum(arr4, N, S);
    print_res(res6);

    return 0;
}