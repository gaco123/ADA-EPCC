#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int M = 26;
	vector<int> b = {6,3,4,5,7};
	vector<int> p = {10,12,15,7,2};
	vector<float> bp;
	vector<float> X;
	int actWeight = 0;
	cout<<"PROBLEMA DE LA MOCHILA\n";
	cout<<"Peso M�ximo: "<<M;
	cout<<"\nVector de Pesos: ";
	for(int i=0; i<p.size(); i++){
		cout<<p[i]<<" ";
	}
	cout<<"\nVector de Beneficio: ";
	for(int i=0; i<p.size(); i++){
		cout<<b[i]<<" ";
	}
	cout<<"\nVector bi/pi: ";
	for(int i=0; i<b.size(); i++){
		bp.push_back(float(b[i])/float(p[i]));
		X.push_back(0);
		cout<<bp[i]<<" ";
	}
	int it;
	float j;
	auto it2 = bp.begin();
	auto it3 = bp.begin();
	cout<<"\n\n";
	
	while(actWeight < M){
		//it=posicion del peso con mejor promedio b1/pi??
		it = 0;
		it2 = bp.begin();
		it3 = bp.begin();
		j = bp[it];
		for(int i=0; i<bp.size(); i++){
			if(j < bp[i]){
				it = i;
				it3 = it2;
				j = bp[i];
			}
			it2++;
		}
		//imprime la posicion escojida
		cout<<"Peso: "<<p[it]<<"; bi/pi: "<<*it3<<"; Posici�n: "<<it<<"\n";
		bp.erase(it3);
		//algoritmo en s�
		if(actWeight+p[it]<=M){
			X[it]=1;
			actWeight=actWeight+p[it];
		}
		else{
			X[it]=float(M-actWeight)/float(p[it]);
			actWeight=M;
		}
		//imprime metadata
		cout<<"Peso Actual: "<<actWeight<<"\n";
		cout<<"Vector Soluci�n: ";
		for(int i=0; i<X.size(); i++){
			cout<<X[i]<<" ";
		}
		cout<<"\nVector de Pesos: ";
		for(int i=0; i<p.size(); i++){
			cout<<p[i]<<" ";
		}
		cout<<"\n\n";
	}
	
	return 0;
}

