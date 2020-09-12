#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
int solution(vector<int> citations) {
	int answer = 0;

	int n = citations.size();

	sort(citations.begin(), citations.end());

	int max = citations[n - 1];
	
	for (max = citations[n - 1]; max >= 0; --max) {

		int cnt = 0;
		int cnt_min = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (citations[i] >= max) {
				cnt++;
			}
			if (citations[i] <= max) {
				cnt_min++;
			}
		}

		if (cnt >= max)
			return max;
	}
	return answer;
}


int main() {

	int input[] = { 3, 0, 6, 1, 5 };

	vector<int> citations;
	int n = 5;

	for (int i = 0; i < n; i++) {
		citations.push_back(input[i]);
	}

	int res = solution(citations);

	printf("%d\n", res);


}