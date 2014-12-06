#include <iostream>
#include <cstdlib>
#include <csignal>

using namespace std;


class nota{
	public:
		nota();
		void Imprime();
		nota *ponteiro();
		void print(nota*);
		void repeticao();
	private:
		int valor;
};

void nota::print(nota *x){ cout<<"\n"<<x<<endl; cout<<x->valor<<endl;}

nota::nota(){valor=5;}

void nota::Imprime(){
	nota *i;
	cout<<"Imprimindo\t"<<valor<<endl;
	cout<<"Imprimindo\t"<<this<<endl;
	i=ponteiro();
	cout<<i<<endl;
	exit(1);
	print(i);
}

void nota::repeticao(){
	char a='t';
	while(1){
		cout<<"Passei por aqui"<<endl;
		if(a==16) {break;}
		cout<<"Mas não por aqui"<<endl;
	}
}

nota *nota::ponteiro(){ return this;}

int main(){
	nota notas;
//	notas.Imprime();
	notas.repeticao();
	return 0;
}
