#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	//Datos
	float valor = 3.91;
	//Los tipos de moneda deben estar si o si en orden descendente!!!
	vector<float> monedas = {2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};
	vector<int> cambio(monedas.size(), 0);
	double actVal = 0;
	
	cout <<"Cambio objetivo: "<< valor << endl;
	cout<<"Tipos de monedas: ";
	for(int i=0; i<monedas.size(); i++){
		cout<<monedas[i]<<" ";
	}
	cout<<endl<<endl;
	
	double tVal = valor;
	for(int j=0; j<monedas.size(); j++){
		cambio[j] = tVal/monedas[j];
		actVal = actVal + monedas[j]*cambio[j];
		tVal =  tVal - monedas[j]*cambio[j];
		if(actVal==valor){
			break;
		}
		cout<<"Cambio actual: "<<actVal<<endl;
		cout<<"Cambio restante: "<<setprecision(2)<<fixed<<tVal<<endl;
		cout<<"Monedas usadas: ";
		for(int i=0; i<monedas.size(); i++){
			cout<<monedas[i]<<"|"<<cambio[i]<<" ";
		}
		cout<<endl<<endl;
	}
	
	return 0;
}

