#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findSame (vector<vector<int>> &board, vector<vector<int>> &road, int row, int column, int target, int max_rows, int max_columns);
bool hasWalk(vector<vector<int>> road, int row, int column);

int main() {
  int rows, columns;
  cin >> rows >> columns;
  vector<vector<int>> board(rows, vector<int>(columns));
  
  for(int i {0}; i < rows; i++) {
    for(int j {0}; j < columns; j++) {
      cin >> board.at(i).at(j);
    }
  }
  
  vector<vector<int>> road;
  for(int i {0}; i < rows; i++) {
    for(int j {0}; j < columns; j++) {
      int now_color = board.at(i).at(j);
      if(now_color){
        findSame(board, road, i, j, now_color, rows, columns);
        if(road.size() >= 3) {
          for(auto it : road) {
            board.at(it.at(0)).at(it.at(1)) = 0;
          }
        }
        road.clear();
      }
    }
  }

  string result {""};
  for(int i {0}; i < rows; i++) {
    for(int j {0}; j < columns; j++) {
      result += to_string(board.at(i).at(j)) + " ";
    }
    result.erase(result.find_last_not_of(" ") + 1);
    cout << result;
    if(i < rows - 1) cout << endl;
    result = "";
  }

  return 0;
}

void findSame (vector<vector<int>> &board, vector<vector<int>> &road, int row, int column, int target, int max_rows, int max_columns) {
  int now_color = board.at(row).at(column);
  if(now_color == 0) return;
  if(now_color == target){
    if(hasWalk(road, row, column)) return;
    road.push_back({row, column});
  if(row - 1 >= 0) {
    findSame(board, road, row - 1, column, target, max_rows, max_columns);
  }
  if(row + 1 < max_rows) {
    findSame(board, road, row + 1, column, target, max_rows, max_columns);
  }
  if(column - 1 >= 0) {
    findSame(board, road, row, column - 1, target, max_rows, max_columns);
  }
  if(column + 1 < max_columns) {
    findSame(board, road, row, column + 1, target, max_rows, max_columns);
  }
  }
}

bool hasWalk(vector<vector<int>> road, int row, int column) {
  for(auto it : road){
    if(it.at(1) == column && it.at(0) == row) return true;
  }
  return false;
}