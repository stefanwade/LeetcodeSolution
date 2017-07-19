#include <iostream>
#include <vector>

using namespace std;

class Knapsack01{
public:
	int knapsack01(const vector<int> &w, const vector<int> &v, int C){
		int n = w.size();
		vector<vector<int>> memo(n, vector<int>(C + 1, -1));
		if(n == 0)
			return 0;
		for(int i = 0; i <= C; i++)
			memo[0][j] = (j >= w[0] ? v[0] : 0);

		for(int i = 1; i < n; i++){
			for(int j = 0; j <= C; j++){
				memo[i][j] = memo[i - 1][j];
				if(j >= w[i])
					memo[i][j] = max(memo[i][j], v[i] + memo[i - 1][j - w[i]]);
			}
		}
		return memo[n - 1][C];
		//记忆化搜索
		/*
		return n = w.size();
		memo = vector<vector<int>>(n, vector<int>(C + 1), -1);
		return bestValue(w, v, n - 1, C);
	}
private:

	vector<vector<int>> memo;
	int bestValue(const vector<int> &w, const vector<int> &v, int index, int c) {
		if(index < 0 || c <= 0)
			return 0;
		if(memo[index][c] != -1)
			return memo[index][c];
		int res = bestValue(w, v, index - 1, c);
		if(w[index] <= c)
			res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
		memo[index][c] = res;
		return res;
		*/
	}
};

int main() {

	return 0;
}

//基于空间复杂度的优化 O(2 * C)
vector<vector<int>> memo(2, vector<int>(C + 1, -1));
if(n == 0)
	return 0;
for(int i = 0; i <= C; i++)
	memo[0][j] = (j >= w[0] ? v[0] : 0);

for(int i = 1; i < n; i++){
	for(int j = 0; j <= C; j++){
		memo[i % 2][j] = memo[(i - 1) % 2][j];
		if(j >= w[i])
			memo[i % 2][j] = max(memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
	}
}
return memo[(n - 1) % 2][C];

//基于空间复杂度的优化O(C)
vector<int> memo(C + 1, -1);

for(int i = 0; i <= C; i++)
	memo[j] = (j >= w[0] ? v[0] : 0);

for(int i = 1; i < n; i++){
	for(int j = C; j >= w[i]; j--){
			memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
	}
}
return memo[C];

