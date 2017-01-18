#include <iostream>
#include <vector>
using namespace std;

vector<int> getPatternPi(string p) {
	int m = (int) p.size();
	int j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]){
			j = pi[j - 1];
		}

		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int> kmp(string str, string patt) {
	vector<int> arr;
	vector<int> pi = getPatternPi(patt);
	int n = (int) str.size();
	int m = (int) patt.size();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && str[i] != patt[j]){
			j = pi[j - 1];
		}

		if (str[i] == patt[j]) {
			if (j == m - 1) {
				arr.push_back(i - m + 1 + 1);
				j = pi[j];
			} else {
				j++;
			}
		}
	}
	return arr;
}

int main() {
	string str, patt;
	getline(cin, str);
	getline(cin, patt);

	vector<int> arr = kmp(str, patt);

	printf("%d\n", (int) arr.size());
	for (int i : arr)
		printf("%d ", i);

	return 0;
}
