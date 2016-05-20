/*
Program sprawdza twoje wyniki badan morfologicznych.
Jako kolejne paramety programu wprowadz:
1) Monocyty w G/l ( 0,1-0.4 )
2) Hemoglobina w g/dl ( 13.5-17.5 )
3) Erytrocyty w M/ul ( 4,5-6,5 )
4) Hematokryt w %	( 42-52  )
5) Leukocyty w K//ul ( 4,1-10,9 )
6) Limfocyty w tys./ul ( 2.5-4.5 )
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
	for(int i=0; i<argcount; i++ )
		T[i]=atof(args[i]);
	cout<<"Parametry:";
	for(int i=1; i<argcount;i++ )
		cout<<endl<<T[i];
	cout<<endl; 
		
	
	if( T[1]<0.1 or T[1]>0.4 or T[2]<13.5 or T[2]>17.5 or T[3]<4.5 or T[3]>6.5 or T[4]<42 or T[4]>52 or T[5]<4.1 or T[5]>10.9 or T[6]<2.5 or T[6]>4.5){  
		cout<<"Zdrowy!";	
	}else
		cout<<"Wyniki badania nie mieszcza sie w normiach.";
	
	
	return 0;
}
