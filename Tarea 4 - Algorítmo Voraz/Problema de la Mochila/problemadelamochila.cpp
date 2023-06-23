#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
	
	int M = 20;
	vector<int> b = {25,24,15};
	vector<int> p = {18,15,10};
	vector<float> bp;
	vector<float> X;
	int actWeight = 0;
	float actBen = 0;
	cout<<"PROBLEMA DE LA MOCHILA\n";
	cout<<"Peso Máximo: "<<M;
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
		cout<<"Peso: "<<p[it]<<"; bi/pi: "<<*it3<<"; Posición: "<<it<<"\n";
		*it3 = 0;
		//algoritmo en sí
		if(actWeight+p[it]<=M){
			X[it]=1;
			actWeight+=p[it];
			actBen+=b[it];
		}
		else{
			X[it]=float(M-actWeight)/float(p[it]);
			actWeight=M;
			actBen+=b[it]*X[it];
		}
		//imprime metadata
		cout<<"Peso Actual: "<<actWeight<<"\n";
		cout<<"Beneficio Actual: "<<actBen<<"\n";
		cout<<"Vector Solución: ";
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

