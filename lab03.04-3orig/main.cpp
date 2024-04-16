#include "class.h"
#include <iostream>
#include <fstream>

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::vector<Athlete> athletes = {
		Athlete("����", 1, {12, 15, 18}),
		Athlete("�������", 2, {17, 19, 20}),
		Athlete("�������", 3, {14, 16, 17}),
		Athlete("�����", 4, {18, 19, 20}),
		Athlete("�����", 5, {15, 16, 17})
	};

	std::cout << "������ ����������� � �� ����� �����������:" << std::endl;
	for (const auto& athlete : athletes) {
		std::cout << athlete.getName() << " �" << athlete.getNumber()
			<< ": " << athlete.getTotalResult() << std::endl;
	}

	Athlete maxAthlete = *max_element(athletes.begin(), athletes.end());

	std::cout << std::endl << "������������ ����� ���������: " << maxAthlete.getTotalResult() << std::endl;

	std::ofstream outFile("C:\\Temp\\maxatl.txt");
	if (outFile.is_open()) {
		outFile << maxAthlete.getName() << " �" << maxAthlete.getNumber() << std::endl;
		outFile << "����������:";
		for (int result : maxAthlete.getResults()) {
			outFile << " " << result;
		}
		outFile.close();
	}

	return 0;
}