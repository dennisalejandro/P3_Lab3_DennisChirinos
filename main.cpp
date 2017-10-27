#include <string>
#include <iostream>
#include <vector>
using namespace std;
int*** CrearMatriz(int);
void Met1();
int*** Met2(int*, int, int);
void Met3A(string, vector<string*>*);
void Met3B(vector<string*>*);
int main () {
	int op = 0;
	int op3 = 0;
	int gradoMax = 0;
	vector <string*>* vFechas = new vector<string*>();
	while (op != 4) {
		cout << "Ingrese numero del ejercicio, salir con 4" << "\n";
		cin >> op;
		switch(op) {
			case 1: {
				
			} break;
			case 2: {
				int grado;
				int div;
				cout << "Ingrese grado mas alto del polinomio: ";
				cin >> gradoMax;
				int* poly = new int[gradoMax];
				for (int i = 0;i<=gradoMax;i++) {
					cout << "Ingrese el polinomio x^" << (gradoMax-i) << ": ";
					cin >> grado;
					poly[i] = grado;
				}
				cout << "Ingrese el divisor x+";
				cin >> div;
				Met2(poly, (div*-1), gradoMax);
				delete[] poly;
			} break;
			case 3: {
				cout << "Ingrese opcion: \n";
				cout << "1) Ingresar codigo \n";
				cout << "2) Imprimir fechas \n";
				cin >> op3;
				switch (op3) {
					case 1: {
						cout << "Ingrese nueva Fecha \n";
						string NewDate;
						cin >> NewDate;
						Met3A(NewDate, vFechas);
					} break;
					case 2: {
						Met3B(vFechas);
					} break;
				}
			} break;
		}
	}
	return 0;
}
int*** CrearMatriz(int size) {
	int*** matriz = new int**[size];
	for (int i = 0;i<size;i++) {
		matriz[i] = new int*[3];
	}
	for (int i = 0;i<size;i++) {
		for (int j = 0;j<3;j++) {
			matriz[i][j] = new int[size];
		}
	}	
	return matriz;
}
void Met1() {

}
int*** Met2(int* poly, int div, int size) {
	int* resp = new int[size];
	int* res = new int[size];
	int*** ret = new int**[size];
	resp[0] = 1;
	res[0] = 0;
	for (int i = 1;i<=size;i++) {
		int** mat = new int*[3];
		int a = resp[i-1]*div;
		res[i-1] = a; 
		resp[i] = a + poly[i];
		for (int y = 0;y<=size;y++) {
			cout << poly[y] << " ";
		}
		cout << "\n";
		for (int y = 0;y<i;y++) {
			cout << res[y] << " ";
		}
		cout << "\n";
		cout << "---------";
		cout << "\n";
		for (int y = 0;y<i;y++) {
			cout << resp[y] << " ";
		}
		mat[0] = poly;
		mat[1] = res;
		mat[2] = resp;
		ret[i-1] = mat;
		cout << "\n \n";
	}
	cout << "el cociente es: \n";
    for (int i = 0;i<=size;i++) {
    	cout << resp[i] << "x^" <<  (size-1)<<"+";
    }
	cout << "\n";
	return ret;
}
void Met3A(string Code, vector<string*>* vFechas) {
	cout << "Size: ";
	cout << Code.size();
	string Ano;
	string Mes;
	string Dia;
	if (Code.size() == 8) {
		for (int i = 0;i<=3;i++) {
			Ano += Code.at(i);
		}
		if (stoi(Mes)<=12) {
			for (int i = 4;i<=5;i++) {
				Mes += Code.at(i);	
			}
		} else {
			Mes += "00";
		}
		if (stoi(Dia)<=31) {
			for (int i = 6; i <= 7; i++) {
				Dia += Code.at(i);
			}
		} else {
			Dia += "00";
		}
		string* Date = new string[3];
		Date[0]  = Ano;
		Date[1]  = Mes;
		Date[2]  = Dia;
		vFechas->push_back(Date);
	}
}
void Met3B(vector<string*>* vFechas) {
	int op;
	int Ano = 0;
	int Mes;
	int Dia;
	cout << "Imprimir por mes, año, o dia de la semana? \n";
	cout << "1) Todos \n";
	cout << "2) Mes \n";
	cout << "3) año \n";
	cin >> op;
	switch (op) {
		case 1: {
			for (int i = 0;i<vFechas->size();i++) {
				cout << vFechas->at(i)[0] << "/";
				cout << vFechas->at(i)[1] << "/";
				cout << vFechas->at(i)[2] << "\n";		
			}
		} break;
		case 2: {
			cout << "Ingrese Numero del Mes \n";
			cin >> Mes;
			for (int i = 0;i<vFechas->size();i++) {
				if (stoi(vFechas->at(i)[1])==Mes) {
					cout << vFechas->at(i)[0] << "/";
					cout << vFechas->at(i)[1] << "/";
					cout << vFechas->at(i)[2] << "\n";
				}
			}
		} break;
		case 3: {
			cout << "Ingrese numero del Año \n";
			cin >> Ano;
            for (int i = 0;i<vFechas->size();i++) {
                if (stoi(vFechas->at(i)[0])==Ano) {
                    cout << vFechas->at(i)[0] << "/";
                    cout << vFechas->at(i)[1] << "/";
                    cout << vFechas->at(i)[2] << "\n";
                }
            }

		} break;
	}
} 
