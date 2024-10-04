#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

void interdirder(int a[], int b){
	int aux;
	for(int i=0;i<b-2;i++){
		for(int j=0;j<b-i-1;j++){
			if(a[j]>a[j+1]){
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
			}
		}
	}
}

void SeleccionDir(int A[],int b){
	for(int i=0; i<b-1 ; i++){
		int menor = A[i];
		int c=i;
		for(int j=i;j<b;j++){
			if(A[j]<menor){
				menor = A[j];
				c=j;
			}
		}
		A[c]= A[i];
		A[i]= menor;
	}
}

using namespace std;

int main(){
	int cant=0;
	srand(time(0));
	int arreglo1[500];
	int arreglo2[500];
	
	for(int i=0;i<500;i++){
		arreglo1[i]= rand() % 20001 - 10000;
		arreglo2[i]= arreglo1[i];
		cout<<"num"<<i+1<<": "<<arreglo1[i]<<" ";
		if(i%10==0 and i!=0){
			cout<<endl;
		}
	}
	
	
	cout<<endl<<endl;
	auto inicio = std::chrono::high_resolution_clock::now();
	interdirder(arreglo1, 500);
	auto fin = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> tiempoTranscurrido = fin - inicio;
	cout<<endl<<"                       "<<  tiempoTranscurrido.count();
	
	auto inicio1 = std::chrono::high_resolution_clock::now();
	SeleccionDir(arreglo2, 500);
	auto fin1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> tiempoTranscurrido1 = fin1 - inicio1;
	cout<<endl<<"                       "<<  tiempoTranscurrido1.count();
	
//	for(int j=0;j<500;j++){
//		cout<<"num"<<j+1<<": "<<arreglo[j]<<endl;
//	}
//	cout<<time(0);
	return 0;
}