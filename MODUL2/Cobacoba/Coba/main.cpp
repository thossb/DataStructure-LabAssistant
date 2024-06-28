#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void calculateFact(long long int fact[], int N) {
    fact[0] = 1;
    for (long long int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

long long int nCr(long long int fact[], int N, int R) {
    if (R > N) {
        return 0;
    }
    long long int res = fact[N] / fact[R];
    res /= fact[N - R];
    return res;
}

int countWays(vector<int>& arr, long long int fact[]) {
    int N = arr.size();
    if (N <= 2) {
        return 1;
    }
    vector<int> leftSubTree;
    vector<int> rightSubTree;
    int root = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] < root) {
            leftSubTree.push_back(arr[i]);
        } else {
            rightSubTree.push_back(arr[i]);
        }
    }
    int N1 = leftSubTree.size();
    int N2 = rightSubTree.size();
    int countLeft = countWays(leftSubTree, fact);
    int countRight = countWays(rightSubTree, fact);
    return (int) (nCr(fact, N - 1, N1) * 1LL * countLeft % 1000000007 * countRight % 1000000007);
}

int main() {
    vector<int> arr;
    int n;
    printf("Enter the size of the array: ");
    cin >> n;
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int N = arr.size();
    long long int fact[N];
    calculateFact(fact, N);
    printf("%d\n", (countWays(arr, fact) - 1) % 1000000007);
    return 0;
}
