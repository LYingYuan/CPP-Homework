#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// ��̥
struct tire {
  string model;
  int size;
  int quantity;
};

// ��ز���
struct parameter {
  int voltage;
  int capacitance;
};

// ����
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

// AGX �׼�
struct agx {
  string model;
  string ai;
  string cuda_core;
  string tensor_core;
  int video_memory;
  int storage;
  // int quantity;
};

// ˫Ŀ����ͷ
struct binocular_camera {
  string model;
  string camera;
  int rgb_resolution[2];
  int rgb_frame_rate;
  int fov[2];
  int depth_frame_rate;
};

// �༤���״�
struct radar {
  string model;
  int channels_num;
  int measuring_range;
  int power_consumption;
};

// 9 ��������
struct gyro {
  string model;
  string factory_name;
};

// Һ����ʾ��
struct monitor {
  string model;
  double size;
};

// ���ģ��
struct battery {
  parameter parameter;
  int powered_voltage;
  int charging_time;
};

// ����С��
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

// ѧ��
struct stu {
  string id;
  string name;
};

// ѧ��-��
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
  cout << "===============С���������===============" << endl;
  saveInfo(results);
  printInfo(students);

  return 0;
}

// ¼��ѧ����Ϣ
void enterStuInfo(vector<stu> &students) {
  cout << "------------��ʼ¼��10λѧ������Ϣ----------" << endl;
  for(int i = 0; i < 10; i++){
    cout << "ѧ��" << i + 1 << "��" << endl;
    cout << "ѧ�ţ�";
    cin >> students[i].id;
    cout << "������";
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
    {{}, "SCOUT MINI", 451, 490, 115, 0, "��������", 10, {"��·�֡������ķ��", 175, 4}},
    {"AGX Xavier", "32 TOPS", "512", "64", 32, 32},
    {"RealSense D435i", "D430", {1920, 1080}, 30, {87, 80}, 90},
    {"RS-Helios-16p", 16, 100, 8},
    {"CH110", "NXP"},
    {"super", 11.6},
    {{24, 15}, 24, 2}
  };

  for(int i {0}; i < 10; i++){
    cars.at(i) = car_info;
    cout << "С��" << i + 1 << "���̱�ţ�";
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

    ofs << "1������С����Ϣ��" << endl;
    ofs << " ��1����ţ�" << car.number << endl;
    ofs << " ��2������" << endl;
    ofs << "      a)��ţ�" << chassis.number << endl;
    ofs << "      b)�ͺţ�" << chassis.model << endl;
    ofs << "      c)��ࣺ" << chassis.wheelbase << "mm" << endl;
    ofs << "      d)�־ࣺ" << chassis.wheel_base << "mm" << endl;
    ofs << "      e)��С��ؼ�϶��" << chassis.min_ground_clearance << "mm" << endl;
    ofs << "      f)��Сת��뾶��" << chassis.min_turning_radius << "m" << endl;
    ofs << "      g)������ʽ��" << chassis.drive_type << endl;
    ofs << "      h)����г̣�" << chassis.max_stroke << "KM" << endl;
    ofs << "      i)��̥��"<< chassis.tire.quantity << "����" << chassis.number << endl;
    ofs << "         i.�ͺţ�" << chassis.tire.model << endl;
    ofs << "        ii.�ߴ磺" << chassis.tire.size << "mm" << endl;
    ofs << " ��3��AGX�׼���1����" << endl;
    ofs << "      a)�ͺţ�" << agx.model << endl;
    ofs << "      b)AI��" << agx.ai << endl;
    ofs << "      c)CUDA���ģ�" << agx.cuda_core << endl;
    ofs << "      d)Tensor CORE��" << agx.tensor_core << endl;
    ofs << "      e)�Դ棺" << agx.video_memory << "G" << endl;
    ofs << "      f)�洢��" << agx.storage << "G" << endl;
    ofs << " ��4��˫Ŀ����ͷ��1����" << endl;
    ofs << "      a)�ͺţ�" << camera.model << endl;
    ofs << "      b)����ͷ��" << camera.camera << endl;
    ofs << "      c)RGB֡�ֱ��ʣ�" << camera.rgb_resolution[0] << "*" << camera.rgb_resolution[1] << endl;
    ofs << "      d)RGB֡�ʣ�" << camera.rgb_frame_rate << "Hz" << endl;
    ofs << "      e)FOV��" << camera.fov[0] << "*" << camera.fov[1] << endl;
    ofs << "      f)���֡�ʣ�" << camera.depth_frame_rate << "Hz" << endl;
    ofs << " ��5�����߼����״1����" << endl;
    ofs << "      a)�ͺţ�" << radar.model << endl;
    ofs << "      b)ͨ������" << radar.channels_num << endl;
    ofs << "      c)���Է�Χ��" << radar.measuring_range << "m" << endl;
    ofs << "      d)���ģ�" << radar.power_consumption << "W"<< endl;
    ofs << " ��6��9�������ǣ�1����" << endl;
    ofs << "      a)�ͺţ�" << gyro.model << endl;
    ofs << "      b)���ң�" << gyro.factory_name << endl;
    ofs << " ��7��Һ����ʾ����1����" << endl;
    ofs << "      a)�ͺţ�" << monitor.model << endl;
    ofs << "      b)�ߴ磺" << monitor.size << "��" << endl;
    ofs << " ��8�����ģ�飨1����" << endl;
    ofs << "      a)������" << battery.parameter.voltage << "V/" << battery.parameter.capacitance << "Ah" << endl;
    ofs << "      b)���⹩�磺" << battery.powered_voltage << "V" << endl;
    ofs << "      c)���ʱ����" << battery.charging_time << "H" << endl;
    ofs << "2��ѧ����Ϣ��" << endl;
    ofs << " ��1��ѧ�ţ�" << result.student.id << endl;
    ofs << " ��2��������" << result.student.name << endl;

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
    cout << "�ļ���ʧ��" << endl;
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
  cout << "������n����һ̨����p����һ̨����ʾС������ǰΪ��" << i + 1 << "̨С����(����e�˳�)" << endl;
}