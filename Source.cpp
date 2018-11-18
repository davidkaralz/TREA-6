#include <iostream>
using namespace std;

int usados[9][2] = { { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 }, { 10, 10 } };
class juego{
private:
	char matriz[3][3];
	char jugador;
	char ganador;



public:
	int k = 0, status = 0, STATUS;
	
	void mat(){
		char c = ' ';
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				matriz[i][j] = c;
			}
		}
	}

	void read(int fila, int col, char P){
		matriz[fila][col] = P;
	}

	void drawBoard(){
		system("cls");
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout <<" "<< matriz[i][j];
				if (j < 2){
					cout << " |";
				}
			}
			if (i < 2){
				cout << "\n-----------\n";
			}
		}
		cout << "\n";
	}

	int checkboard(int i, int j){
		
		
		for (int x = 0; x < 9; x++)
		{
			if ((i == usados[x][0]) && (j == usados[x][1]))
			{
				status++;
			}
		}

		if (status == 0)	{
			usados[k][0] = i;
			usados[k][1] = j;
			k++;
		}
		STATUS = status;
		status = 0;

		return STATUS;
		
	}



	int declarewinner(char P){
		int win=0;
		if ((matriz[0][0] == P) && (matriz[0][1] == P) && (matriz[0][2] == P)){//H1
			win = 1;
		}
		if ((matriz[0][0] == P) && (matriz[1][1] == P) && (matriz[2][2] == P)){//D1
			win = 1;
		}
		if ((matriz[0][1] == P) && (matriz[1][1] == P) && (matriz[2][1] == P)){//v2
			win = 1;
		}
		if ((matriz[2][0] == P) && (matriz[2][1] == P) && (matriz[2][2] == P)){//v3
			win = 1;
		}
		if ((matriz[1][0] == P) && (matriz[1][1] == P) && (matriz[1][2] == P)){//h2
			win = 1;
		}
		if ((matriz[2][0] == P) && (matriz[2][1] == P) && (matriz[2][2] == P)){//h3
			win = 1;
		}
		if ((matriz[2][0] == P) && (matriz[1][1] == P) && (matriz[0][2] == P)){//d2
			win = 1;
		}if ((matriz[0][0] == P) && (matriz[1][0] == P) && (matriz[2][0] == P)){//v1
			win = 1;
		}
		cout << "\n"<<win;
			system("pause");
		return win;
	}



	
};



int main(){
	juego turno;
	turno.mat();

	int opcion;
	char P1, P2;
	
	while (1){
		cout << "Jugador 1 elija su figura:\n1. Circulo (o)\n2.Cruz (x)\n";	
		cin >> opcion;
		if ((opcion == 1) || (opcion == 2)){
			if (opcion == 1){
				P1 = 'O';
				P2 = 'X';
			}
			else
			{
				P1 = 'X';
				P2 = 'O';
			}
			break;
		}
		else
		{
			system("cls");
			cout << "OPCION NO VALIDA\n";
		}
	}

	system("cls");
	

	int jugada = 1;
	int fila, col, disponible,ganador;
	char P;

	while (1){
		if (jugada % 2 == 0){
			P = P2;
		}
		else
		{
			P = P1;
		}

		while (1){
			cout << "Jugador " << P << " ingrese las coordenadas de la casilla en la que desea jugar (la esquina superior izquierda es [0,0]):\n";
			cin >> fila >> col;
			if ((fila>=0)&&(fila<=2)&&(col>=0)&&(col<=2))
			{
				break;
			}
			else
			{
				cout << "Jugador '" << P << "' LA JUGADA NO ES VALIDA\n";
			}
		}
		disponible = turno.checkboard(fila, col);
			
		while (disponible!=0 ){
			cout << "Jugador '" << P << "' LA JUGADA NO ES VALIDA\ningrese las coordenadas de la casilla en la que desea jugar (la esquina superior izquierda es [0,0]):\n";
			cin >> fila >> col;
			disponible = turno.checkboard(fila, col);
		}
		jugada++;
		turno.read(fila, col, P);
		turno.drawBoard();
		ganador=turno.declarewinner(P);
		
		if (ganador == 1){
			cout << "\n\nGANO EL JUGADOR: " << P<<"\n";
			break;
		}
		if (jugada == 10){
			cout << "\n\nNO HUBO GANADOR\n";
			break;
		}

	}
	
	

system("pause");
	return 0;
}

