/*
Program sprawdza twoje wyniki badan morfologicznych.
Jako kolejne paramety programu wprowadz:
1) Monocyty w G/l ( 0,1-0.4 )       a
2) Hemoglobina w g/dl ( 13.5-17.5 ) b
3) Erytrocyty w M/ul ( 4,5-6,5 )	c
4) Hematokryt w %	( 42-52  )		d
5) Leukocyty w K//ul ( 4,1-10,9 )	e
6) Limfocyty w tys./ul ( 2.5-4.5 )	f
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argcount, char ** args){
	
	if(argcount!=7){
		cout<<"Argumentow powinno byc 6.";
		return 0;
	}
	
	float T[argcount];
	for(int i=0; i<argcount; T[i]=atof(args[++i]) );
	
	cout<<"Parametry:";
	for(int i=1; i<argcount;i++ )
		cout<<endl<<T[i];
	cout<<endl; 
		
	
	if( T[1]>0.1 && T[1]<0.4 && T[2]>13.5 && T[2]<17.5 && T[3]>4.5 && T[3]<6.5 && T[4]>42 && T[4]<52 && T[5]>4.1 && T[5]<10.9 && T[6]>2.5 && T[6]<4.5){  
		cout<<"Zdrowy!";
		return 0; //zdrowy	
	}else
		cout<<"Wyniki badania nie mieszcza sie w normiach.";
	
	
	return 1;//zle wyniki badania
}
