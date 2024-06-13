#include <iostream>
#include <fstream>
#include <string>

class Worker {
private:
    std::string firstName;
    std::string lastName;
    int experience;
    double hourlySalary;
    int hoursWorked;

public:
    void setData(std::string fName, std::string lName, int exp, double hSalary, int hours) {
        firstName = fName;
        lastName = lName;
        experience = exp;
        hourlySalary = hSalary;
        hoursWorked = hours;
    }

    double calculateSalary() {
        double bonus = 0.0;
        if (experience <= 1) {
            bonus = 0.0;
        }
        else if (experience <= 3) {
            bonus = 0.05;
        }
        else if (experience <= 5) {
            bonus = 0.08;
        }
        else {
            bonus = 0.15;
        }
        return (hourlySalary * hoursWorked) * (1 + bonus);
    }

    void displayInfo() {
        std::cout << "���: " << firstName << " " << lastName << std::endl;
        std::cout << "����: " << experience << " years" << std::endl;
        std::cout << "�������� � ���: " << hourlySalary << std::endl;
        std::cout << "���� ������: " << hoursWorked << std::endl;
        std::cout << "����� ��������: " << calculateSalary() << std::endl;
    }

    void writeToFile() {
        std::ofstream file("���������� � ����������.txt", std::ios::app);
        if (file.is_open()) {
            file << "���: " << firstName << " " << lastName << "\n";
            file << "����: " << experience << " ���\n";
            file << "�������� � ���: " << hourlySalary << "\n";
            file << "���� ������: " << hoursWorked << "\n";
            file << "����� ��������: " << calculateSalary() << "\n\n";
            file.close();
        }
        else {
            std::cerr << "Error." << std::endl;
        }
    }
};

int main() {
    Worker worker1, worker2, worker3;
    setlocale(LC_ALL, "RU");

    worker1.setData("���������", "����������", 2, 25.0, 40);
    worker2.setData("�������", "��������", 4, 30.0, 45);
    worker3.setData("������", "����������", 6, 35.0, 50);

    worker1.displayInfo();
    worker2.displayInfo();
    worker3.displayInfo();

    worker1.writeToFile();
    worker2.writeToFile();
    worker3.writeToFile();


    std::ifstream file("���������� � ����������.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "�rror." << std::endl;
    }

    return 0;
}


		
