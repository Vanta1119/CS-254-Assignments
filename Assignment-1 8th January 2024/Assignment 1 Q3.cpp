#include <bits/stdc++.h>

using namespace std;

const int V = 4;

const int MAX = 1000000;

int graph[V + 1][V + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 20, 42, 35 },
	{ 0, 20, 0, 30, 34 }, { 0, 42, 30, 0, 12 },
	{ 0, 35, 34, 12, 0 },
};

int memo[V + 1][1 << (V + 1)];

int TSP(int i, int mask){
	if (mask == ((1 << i) | 3))
		return graph[1][i];

	if (memo[i][mask] != 0)
		return memo[i][mask];

	int result = MAX;

	for (int j = 1; j <=V ; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			result = min(result, TSP(j, mask & (~(1 << i)))
									+ graph[j][i]);
	return memo[i][mask] = result;
}

int main(){
	int ans = MAX;
	for (int i = 1; i <=V ; i++)
		ans = min(ans, TSP(i, (1 << (V + 1)) - 1)
								+ graph[i][1]);

	cout << "The Answer to Traveling Salesman Problem: " << ans << endl;

	return 0;
}

