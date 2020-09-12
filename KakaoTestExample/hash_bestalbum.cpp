#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<string, int> genplay;//장르별 플레이 수
map<string, vector<pair<int,int>>> sorts;//장르별로 분류된 곡

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<string> list;//장르의 수

	int n = genres.size();

	//자료 세팅
	for (int i = 0; i < n; i++) {
		if (genplay[genres[i]] == 0)
			list.push_back(genres[i]);
		genplay[genres[i]] += plays[i];
		sorts[genres[i]].push_back(make_pair(i,plays[i]));
	}

	//장르 플레이수별로 정렬
	for (int i = 0; i < list.size(); i++) {
		for (int j = i; j < list.size(); j++) {
			if (genplay[list[i]] < genplay[list[j]]) {
				string tmp;
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}

	//각 장르별로 최고 플레이 곡 선택
	for (int i = 0; i < list.size(); i++) {
		int best = -1;
		int id = -1;
		int max = 0;
		vector<pair<int, int>> a = sorts[list[i]];

		for (int j = 0; j < a.size(); j++) {
			if (a[j].second > max) {//앞에서부터 보아 번호가 낮은 걸 우선으로 삼음
				max = a[j].second;
				best = j;
				id = a[j].first;
			}
		}
		answer.push_back(id);
		a[best].second = -1;
		best = -1;
		max = 0;

		//곡이 하나 이상일 때만 둘 선택
		if (a.size() > 1) {

			for (int j = 0; j < a.size(); j++) {
				if (a[j].second > max) {
					max = a[j].second;
					best = j;
					id = a[j].first;
				}
			}
			answer.push_back(id);
		}
	}


	return answer;
}


int main() {

	string input1[] = { "classic", "pop", "classic", "classic", "pop" };
	int input2[] = { 500, 600, 150, 800, 2500 };

	vector<string> genres;
	vector<int> plays;
	int n = 5;

	for (int i = 0; i < n; i++) {
		genres.push_back(input1[i]);
		plays.push_back(input2[i]);
	}

	vector<int> res = solution(genres, plays);

	for (int i = 0; i < res.size(); i++) {
		printf("%d\n", res[i]);
	}

}