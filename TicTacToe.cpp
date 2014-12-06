#include <iostream>
#include <cstdlib>

using namespace std;
const int l=3,c=3;

class TTT{		//TicTacToe
	public:
		TTT();
		char getTabuleiro(int i, int j) { return tabuleiro[i][j];}
		void MostraTabuleiro();
		void Jogada();
		void CapturaJogada(int);
		int VerificaJogadas(int);
		void ValidaEntrada(int,int,int);
		int VerificaColunas(int);
		int VerificaDiagonais(int);
	private:
		void setTabuleiro(int,int,char);
		char tabuleiro[l][c];
};

TTT::TTT(){
	for(int i=0; i<l; i++)
		for(int j=i; j<c; j++){
			setTabuleiro(i,j,0);
			setTabuleiro(j,i,0);
		}
}

void TTT::setTabuleiro(int i, int j, char valor){tabuleiro[i][j]=valor;}	//Funcao que seta os dados no membro de dado tabuleiro

void TTT::MostraTabuleiro(){						//funcao que mostra como esta o tabuleiro do jogo atualmente
	system("clear");
	cout<<endl<<endl;
	cout<<"\t\tCol 1\tCol 2\tCol 3"<<endl<<endl;
	for(int i=0; i<l; i++){
		cout<<"Linha "<<i+1<<"\t";
		for(int j=0; j<c; j++){
			cout<<"\t"<<getTabuleiro(i,j);
		}	
		cout<<endl<<endl;
	}
	cout<<endl<<endl;
}

void TTT::Jogada(){							//funcao que chama praticamento todas as outras
	int ganhador=0,qtd=c*l;
	while(1){
		CapturaJogada(88);					//laco para chamada de leitura de jogada
		if(VerificaJogadas(88)==1 || qtd<1) break;		//teste para ver se ja ha campeao
		qtd--;
		CapturaJogada(79);
		if(VerificaJogadas(79)==1) break;
		qtd--;
	}
}

void TTT::CapturaJogada(int jogador){					//captura via teclada jogada
	int i,j;
	cout<<"Digite a sua jogada\t (linha - coluna)"<<endl;
	cin>>i>>j;
	ValidaEntrada(i-1,j-1,jogador);					//verifica se jogada válida e seta
}

int TTT::VerificaJogadas(int Jogador){
	if(VerificaColunas(Jogador)==1 || VerificaDiagonais(Jogador)==1){	//chama funcoes que verifica se ha ganhador
		if(Jogador==88) {int* jogador=new int(1);			//novo conceito de criar variavel quando necessario com ponteiro
		cout<<"O jogador "<<*jogador<<" venceu"<<endl;}
		if(Jogador==79) {int* jogador=new int(2);
		cout<<"O jogador "<<*jogador<<" venceu"<<endl;}
		return 1;						//encerra a execução de Jogada()
	}
	return 0;							//Jogada() continua executando
}

int TTT::VerificaDiagonais(int Jogador){				//Verifica se ha jagodas campeas nas diagonais
	int diagonal1=0,diagonal2=0;
	for(int i=0;i<l;i++){
		if(tabuleiro[i][i]==Jogador) diagonal1++;		//Diagonal 00,11,22,33 ...
		if(tabuleiro[i][l-i-1]==Jogador) diagonal2++;		//Diagonal inversa 03,12,21,30 
	}
	if(diagonal1==l || diagonal2==l)
		return 1;						//Caso Jogador seja campeao
	return 0;
}

int TTT::VerificaColunas(int Jogador){	int linha=0,coluna=0;		//Verifica se ha jogada campeas nas horizontais e verticais
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			if(tabuleiro[i][j]==Jogador)
				linha++;
			if(tabuleiro[j][i]==Jogador)
				coluna++;
		}
		if (linha==l || coluna==c)				//caso haja campeao retorna 1
			return 1;
		linha=coluna=0;
	}
	return 0;
}

void TTT::ValidaEntrada(int i,int j,int jogador){			//verifica se a jogada esta permitida no local digitado
	if(getTabuleiro(i,j)==0 && i<c && j<l)
		setTabuleiro(i,j,jogador);				//se posicao aceita, altera tabuleiro set()
	else{
		cout<<"Jogada Não permitida"<<endl;			//caso jogado invalida recapturar jogada para o mesmo jogador
		return CapturaJogada(jogador);
	}
	MostraTabuleiro();
}

int main(){
	TTT tab1;			//instacia objeto
	tab1.MostraTabuleiro();		//mostra o tabuleiro inicialmente
	tab1.Jogada();			//chama a funcao de execucao total do programa
	return 0;
}
