#include <iostream>
#include "chess.h"


using namespace std;

int main() {
	std::cout << "------ START -------";


	Chess chess;
	string step;

	//	chess.step_from("c5");
	chess.print_boar();
	cout << "\n Step from: ";


	while (1) {
		cin >> step;
		system("CLS");


		if (!chess.step_from(step)) {
			chess.print_boar();
			cout << "\n Step from: ";
			continue;
		}
		chess.print_boar();
		cout << "\n Step to: ";

		cin >> step;

		system("CLS");
		chess.step_to(step);
		chess.print_boar();

		if (chess.end_fl == 'K') {
			cout << "\n White Win ";
			break;
		}
		else if (chess.end_fl == 'k') {
			cout << "\n Black Win ";
			break;
		}
		cout << "\n Step from: ";
	}
	cin >> step;
}