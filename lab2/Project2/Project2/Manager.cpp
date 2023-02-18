#include "Manager.h";

using namespace std;


	Manager::Manager() {
		conSize = s.getConsoleSize();
	}
	void Manager::setArrExp(Explosion* elementExp) {
		arrExplosion.push_back(elementExp);
	}

	void Manager::enteringParam(string text, int& val) {
		cout << text << endl;
		cin >> val;
		if (val < 1 || val > 30)
			throw "Error";
	}
	void Manager::enteringParam(string text, char& val) {
		cout << text << endl;
		cin >> val;
		if (val != 'Y' && val != 'y' && val != 'N' && val != 'n')
			throw "Error";
	}
	void Manager::enteringParamExp(string text, int& val) {
		cout << text << endl;
		cin >> val;
		if (val < 1 || val > 10) {
			throw "Error";
		}
	}
	void Manager::comparisonRad(int maxRadius, int minRadius) {
		if (maxRadius < minRadius) {
			throw "Error";
		}
	}
	void Manager::enteringParamExpProb(string text, int& val) {
		cout << text << endl;
		cin >> val;
		if (val < 1 || val > 1000) {
			throw "Error";
		}
	}
	void Manager::startWorking() {
		bool flag = false;
		while (!flag) {
			flag = printParam();
		}
		linesOutput();
	}
	bool Manager::printParam() {

		s.setColor(0, 2);
		for (int i = 0; i < conSize.width; i++) {
			cout << "-";
		}
		cout << endl;
		s.gotoXY((conSize.width - 6) / 2, 1);
		cout << "Matrix" << endl;
		for (int i = 0; i < conSize.width; i++) {
			cout << "-";
		}

		try {
			enteringParam("Введите частоту появления линий (от 1 до 30)", frequencyLines);
			enteringParam("Введите скорость линий (от 1 до 30)", speedLine);
			enteringParam("Введите длину линии (от 1 до 30)", lengthLine);
			enteringParam("Режим эпилепсии вкл/выкл (Y/N)", epilepsyMode);
			enteringParamExpProb("Вероятность взрыва", probabilityExplosion);
			enteringParamExp("Минимальный радиус взрыва", minRadius);
			enteringParamExp("Максимальный радиус взрыва", maxRadius);
			comparisonRad(maxRadius, minRadius);
			system("cls");
			return true;

		}
		catch (...) {
			cout << "Ошибка ввода параметров" << endl;
			system("pause");
			system("cls");
			return false;
		}


	}

	void Manager::linesOutput() {
		vector <Figure*> figureRegistry;
		
		
		int checkingPoint = clock() + 1000;
		while (true) {
			if (clock() >= checkingPoint) {
				for (int i = 0; i < frequencyLines; i++) {
					Figure* f = new Line(lengthLine, speedLine, epilepsyMode, probabilityExplosion, maxRadius, minRadius);
					figureRegistry.push_back(f);
					
				}
				checkingPoint += 1000;
			}

			for (int i = 0; i < figureRegistry.size(); i++) {
				
				if (figureRegistry[i]->getNextStepTime() <= clock()) {
					Figure* exp = figureRegistry[i]->draw();
					
					if (figureRegistry[i]->isForDeletion()) {
						figureRegistry.erase(i + figureRegistry.begin());
					}
					if (exp != NULL) {
						figureRegistry.push_back(exp);
					}
				}

			}


		}
	}
