#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;

int isPrimeNumber(int x) {
  if(x < 2) return 1;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 1;
	return 2;
}

int main() {
	int left, right, flag {0}, appear[10001] {0};
	map<int, int> link;
	cin >> left >> right;
	for (int i = left; i <= right; i++) {
		int now_num {i};
		vector<int> road;
    int pow_sum {0};
		while (now_num != 1) {
			pow_sum = 0;
			do{
        pow_sum += pow(now_num % 10, 2);
      }while (now_num /= 10);
			now_num = pow_sum;

			if (find(road.begin(), road.end(), now_num) != road.end()) break;

			road.push_back(now_num);
      // 打标
			appear[now_num] = 1;
		}
		if (pow_sum == 1) {
      link[i] = road.size();
      flag = 1;
    }
	}
	for (auto &num : link)
		if (!appear[num.first])
			cout << num.first << " " << isPrimeNumber(num.first) * num.second << endl;

	if (!flag) cout << "SAD" << endl;

	cout << "长度为" << link.size() << endl;

	return 0;
}