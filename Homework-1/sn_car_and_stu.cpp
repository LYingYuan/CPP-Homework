#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// 轮胎
struct tire {
  string model;
  int size;
  int quantity;
};

// 电池参数
struct parameter {
  int voltage;
  int capacitance;
};

// 底盘
struct chassis {
  char number[9];
  string model;
  int wheelbase;
  int wheel_base;
  int min_ground_clearance;
  int min_turning_radius;
  string drive_type;
  int max_stroke;
  tire tire;
};

// AGX 套件
struct agx {
  string model;
  string ai;
  string cuda_core;
  string tensor_core;
  int video_memory;
  int storage;
  // int quantity;
};

// 双目摄像头
struct binocular_camera {
  string model;
  string camera;
  int rgb_resolution[2];
  int rgb_frame_rate;
  int fov[2];
  int depth_frame_rate;
};

// 多激光雷达
struct radar {
  string model;
  int channels_num;
  int measuring_range;
  int power_consumption;
};

// 9 轴陀螺仪
struct gyro {
  string model;
  string factory_name;
};

// 液晶显示器
struct monitor {
  string model;
  double size;
};

// 电池模块
struct battery {
  parameter parameter;
  int powered_voltage;
  int charging_time;
};

// 松灵小车
struct sn_car {
  string number;
  chassis chassis;
  agx agx;
  binocular_camera binocular_camera;
  radar radar;
  gyro gyro;
  monitor monitor;
  battery battery;
};

// 学生
struct stu {
  string id;
  string name;
};

// 学生-车
struct stu_car {
  sn_car car;
  stu student;
};

void enterStuInfo(vector<stu> &students);
void enterCarInfo(vector<sn_car> &cars, vector<stu> students, vector<stu_car> &results);
void saveInfo(vector<stu_car> results);
void printInfo(vector<stu> students);
void print(int i, vector<stu> students);

int main() {
  vector<sn_car> cars(10);
  vector<stu> students(10);
  vector<stu_car> results(10);

  enterStuInfo(students);
  enterCarInfo(cars, students, results);
  cout << "===============小车分配完成===============" << endl;
  saveInfo(results);
  printInfo(students);

  return 0;
}

// 录入学生信息
void enterStuInfo(vector<stu> &students) {
  cout << "------------开始录入10位学生的信息----------" << endl;
  for(int i = 0; i < 10; i++){
    cout << "学生" << i + 1 << "：" << endl;
    cout << "学号：";
    cin >> students[i].id;
    cout << "姓名：";
    cin >> students[i].name;
    cout << "--------------------------------------------" << endl;
  }
}

void printStuInfo(vector<stu> students) {
  for(int i {0}; i < 10; i++){
      cout << students.at(i).id << " " << students.at(i).name << endl;
    }
}

void enterCarInfo(vector<sn_car> &cars, vector<stu> students, vector<stu_car> &results) {
  sn_car car_info {
    {},
    {{}, "SCOUT MINI", 451, 490, 115, 0, "四轮四驱", 10, {"公路轮、麦克纳姆轮", 175, 4}},
    {"AGX Xavier", "32 TOPS", "512", "64", 32, 32},
    {"RealSense D435i", "D430", {1920, 1080}, 30, {87, 80}, 90},
    {"RS-Helios-16p", 16, 100, 8},
    {"CH110", "NXP"},
    {"super", 11.6},
    {{24, 15}, 24, 2}
  };

  for(int i {0}; i < 10; i++){
    cars.at(i) = car_info;
    cout << "小车" << i + 1 << "底盘编号：";
    cin.ignore();
    cin.getline(cars.at(i).chassis.number, 9);
    cars.at(i).number = "cqusn2022" + students.at(i).id.substr(1);
    results.at(i) = {
      cars.at(i),
      students.at(i)
    };
  }
}

void saveInfo(vector<stu_car> results) {
  for(auto result : results){
    sn_car car {result.car};
    chassis chassis {car.chassis};
    agx agx {car.agx};
    binocular_camera camera {car.binocular_camera};
    radar radar {car.radar};
    gyro gyro {car.gyro};
    monitor monitor {car.monitor};
    battery battery {car.battery};

    ofstream ofs;
    const string file_path = ".\\" + result.student.id + ".txt";
    ofs.open(file_path, ios::trunc);

    ofs << "1、智能小车信息：" << endl;
    ofs << " （1）编号：" << car.number << endl;
    ofs << " （2）底盘" << endl;
    ofs << "      a)编号：" << chassis.number << endl;
    ofs << "      b)型号：" << chassis.model << endl;
    ofs << "      c)轴距：" << chassis.wheelbase << "mm" << endl;
    ofs << "      d)轮距：" << chassis.wheel_base << "mm" << endl;
    ofs << "      e)最小离地间隙：" << chassis.min_ground_clearance << "mm" << endl;
    ofs << "      f)最小转弯半径：" << chassis.min_turning_radius << "m" << endl;
    ofs << "      g)驱动形式：" << chassis.drive_type << endl;
    ofs << "      h)最大行程：" << chassis.max_stroke << "KM" << endl;
    ofs << "      i)轮胎（"<< chassis.tire.quantity << "）：" << chassis.number << endl;
    ofs << "         i.型号：" << chassis.tire.model << endl;
    ofs << "        ii.尺寸：" << chassis.tire.size << "mm" << endl;
    ofs << " （3）AGX套件（1个）" << endl;
    ofs << "      a)型号：" << agx.model << endl;
    ofs << "      b)AI：" << agx.ai << endl;
    ofs << "      c)CUDA核心：" << agx.cuda_core << endl;
    ofs << "      d)Tensor CORE：" << agx.tensor_core << endl;
    ofs << "      e)显存：" << agx.video_memory << "G" << endl;
    ofs << "      f)存储：" << agx.storage << "G" << endl;
    ofs << " （4）双目摄像头（1个）" << endl;
    ofs << "      a)型号：" << camera.model << endl;
    ofs << "      b)摄像头：" << camera.camera << endl;
    ofs << "      c)RGB帧分辨率：" << camera.rgb_resolution[0] << "*" << camera.rgb_resolution[1] << endl;
    ofs << "      d)RGB帧率：" << camera.rgb_frame_rate << "Hz" << endl;
    ofs << "      e)FOV：" << camera.fov[0] << "*" << camera.fov[1] << endl;
    ofs << "      f)深度帧率：" << camera.depth_frame_rate << "Hz" << endl;
    ofs << " （5）多线激光雷达（1个）" << endl;
    ofs << "      a)型号：" << radar.model << endl;
    ofs << "      b)通道数：" << radar.channels_num << endl;
    ofs << "      c)测试范围：" << radar.measuring_range << "m" << endl;
    ofs << "      d)功耗：" << radar.power_consumption << "W"<< endl;
    ofs << " （6）9轴陀螺仪（1个）" << endl;
    ofs << "      a)型号：" << gyro.model << endl;
    ofs << "      b)厂家：" << gyro.factory_name << endl;
    ofs << " （7）液晶显示器（1个）" << endl;
    ofs << "      a)型号：" << monitor.model << endl;
    ofs << "      b)尺寸：" << monitor.size << "寸" << endl;
    ofs << " （8）电池模块（1个）" << endl;
    ofs << "      a)参数：" << battery.parameter.voltage << "V/" << battery.parameter.capacitance << "Ah" << endl;
    ofs << "      b)对外供电：" << battery.powered_voltage << "V" << endl;
    ofs << "      c)充电时长：" << battery.charging_time << "H" << endl;
    ofs << "2、学生信息：" << endl;
    ofs << " （1）学号：" << result.student.id << endl;
    ofs << " （2）姓名：" << result.student.name << endl;

    ofs.close();
  }
}

void printInfo(vector<stu> students) {
  int i {0};
  char op {' '};
  print(i, students);
  do {
    cin >> op;
    switch (op)
    {
    case 'n':
      if(i + 1 <= 9){
        i++;
        print(i, students);
      }
      
      break;
    case 'p':
      if(i - 1 >= 0){
        i--;
        print(i, students);
      }
      break;
    case 'e':
      break;
    default:
      break;
    }

  }while(op != 'e');
}

void print(int i, vector<stu> students) {
  string file_path {".\\" + students.at(i).id + ".txt"};
  ifstream ifs;
  ifs.open(file_path, ios::in);
  if (!ifs.is_open()){
    cout << "文件打开失败" << endl;
    return;
  }
  char c;
  cout << "--------------------------------------------" << endl;
  while ((c = ifs.get()) != EOF)
  {
    cout << c;
  }
  ifs.close();
  cout << "--------------------------------------------" << endl;
  cout << "请输入n（下一台）或p（上一台）显示小车，当前为第" << i + 1 << "台小车：(输入e退出)" << endl;
}