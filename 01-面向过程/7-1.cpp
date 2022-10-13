#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrimerNumber(int num);
bool hasNumber(int target_num, vector <int> &this_vector, int add_flag);
void addNumbers(vector <int> &vector_from, vector <int> &vector_to);
int findNum(int target_num, vector <int> this_vector);

int main(){
	// 输入范围
	int start_num, end_num;
  cin >> start_num >> end_num;

	vector <int> maybe_happiness_nums, happiness_nums, num_independence, unhappiness_nums;
  vector <vector <int>> contact_nums;

	for(int i = start_num == 1 ? 2 : start_num; i <= end_num; i++){
		int now_num = i;
		maybe_happiness_nums.clear();

		do{
      int pow_sum = 0;

			// 计算各位数平方和
      while(now_num){
        pow_sum += pow(now_num % 10, 2);
        now_num /= 10;
      }
      now_num = pow_sum;

			// 形成闭环-->退出当前while循环
			if(hasNumber(now_num, maybe_happiness_nums, 1) || hasNumber(now_num, unhappiness_nums, 0)){
				addNumbers(maybe_happiness_nums, unhappiness_nums);
				break;
			}

			// 依附的数字在该区间
			if(now_num >= start_num && now_num <= end_num){
				contact_nums.push_back({i, now_num});
			}

			// 迭代至1-->达成要求
      if(pow_sum == 1){
        happiness_nums.push_back(i);
				num_independence.push_back(0);

				// 计算独立性
        num_independence.at(num_independence.size() - 1) = maybe_happiness_nums.size();
				if(isPrimerNumber(i)){
					num_independence.at(num_independence.size() - 1) *= 2;
				}
      }
      
    }while(now_num != 1);
	}

	// 处理依附关系
	for(int j = 0, len = contact_nums.size(); j < len; j++){
		int num1 = contact_nums.at(j).at(0), num2 = contact_nums.at(j).at(1);

		// 查找在幸福数中的下标
		int num1_index = findNum(num1, happiness_nums);
		int num2_index = findNum(num2, happiness_nums);

		if(num1_index == -1 || num2_index == -1) continue;

		// cout << "比较" << num1 << "(" << num1_index << ")" << "和" << num2 << "(" << num2_index << ")" << endl;

		if(num_independence.at(num1_index) > num_independence.at(num2_index)){
			happiness_nums.erase(happiness_nums.begin() + num2_index);
			num_independence.erase(num_independence.begin() + num2_index);
		}else{
			happiness_nums.erase(happiness_nums.begin() + num1_index);
			num_independence.erase(num_independence.begin() + num1_index);
		}
	}

	if(happiness_nums.size() == 0){
		cout << "SAD" << endl;
	}else{
		for(int j = 0, len = happiness_nums.size(); j < len; j++){
			cout << happiness_nums.at(j) << " " << num_independence.at(j) << endl;
		}
		cout << "长度为" << happiness_nums.size() << endl;
	}


	return 0;
}

// 判断是否为素数
bool isPrimerNumber(int num){
	if(num <= 2){
    return 0;
  }
  for(int i = 2; i <= sqrt(num); i++){
    if(num % i == 0){
      return 0;
    }
  }
  return 1;
}

// 在 vector 中查找某数是否存在
bool hasNumber(int target_num, vector <int> &this_vector, int add_flag){
	if(find(this_vector.begin(), this_vector.end(), target_num) == this_vector.end()){
		if(add_flag){
			this_vector.push_back(target_num);
		}
		return 0;
	}
	return 1;
}

void addNumbers(vector <int> &vector_from, vector <int> &vector_to){
	for(int i = 0, len = vector_from.size(); i < len; i++){
		vector_to.push_back(vector_from.at(i));
	}
}

int findNum(int target_num, vector <int> this_vector){
	if(find(this_vector.begin(), this_vector.end(), target_num) == this_vector.end()){
		return -1;
	}
	return find(this_vector.begin(), this_vector.end(), target_num) - this_vector.begin();
}