/*
SAPER
kolumny i wersze numerowane od zera
Uwaga! 
W grze znajduje sie kilka podwójnych bomb ( dodaje ona do sasiednich pol wartosc 2, a nie 1 jak zwykla bomba)
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define N 10 //rozmiar planszy NxN
#define wid 1	//szerokosc pol
struct box{
	int val;
	bool visible;
};
void makeboard(int l, box P[][N]){
	for(int w=0 ;w<l; w++){
		for(int k=0; k<l;k++){
			P[w][k].val=0;
			P[w][k].visible=false;
		}
	}
}

void visboard(int l,box P[][N]){
		for(int w=0 ;w<l; w++){
		for(int k=0; k<l;k++){
			P[w][k].visible=true;
		}
	}
}

void showboard(int l, box P[][N]){
	
	cout<<"  ";
	for(int i=0;i<N;i++){
		cout.width(wid);
		cout<<i;
	}
	cout<<endl<<"  ";
	for(int i=0;i<N;i++){
		cout.width(wid);	
		cout<<"-";
	}
	cout<<endl;
	for(int w=0 ;w<l; w++){
		cout.width(wid);
		cout<<w<<"|";
		for(int k=0; k<l;k++){
			if( P[w][k].visible==true ){
				if(P[w][k].val==0){
					cout.width(wid);
					cout<<" ";
				}
				else if(P[w][k].val==9){
					cout.width(wid);
					//cout<<"B";
					cout<<(char)15; //znak bomby
				}
					else{
					cout.width(wid);
					cout<<P[w][k].val;
				}
			}else{
				cout.width(wid);
			//	cout<<"#";
				cout<<(char)127; //znak nieodkrytego pola
			}
		}
		cout<<"|"<<endl;
	}
	cout<<"  ";
	for(int i=0;i<N;i++){
		cout.width(wid);
		cout<<"-";
	}
	cout<<endl;
}

void setbomb(int w,int k, box P[][N]){ //wiersz/kolumna
	
		P[w][k].val=9;
		
		for(int i=-1 ;i<2; i++){
			for(int j=-1;j<2; j++){
				if( (w+i)<0 or (k+j)<0)	continue;
				if( (w+i)>N-1 or (k+j)>N-1)	continue;
			
				if(i==0 and j==0)	continue;
				
				P[w+i][k+j].val++;
				if(P[w+i][k+j].val>=9)
					P[w+i][k+j].val=9;
			}
		}
	
}

void randbombs(int amount,int secondamount,int size, box P[][N],int start_w,int start_k){
	int x,y;
	while(amount>0){
		x=rand()%size;
		y=rand()%size;
		if(x==start_w or y==start_k or P[x][y].val==9){
			continue;
		}
			
		setbomb(x,y,P);
		amount--;
	}
	while(secondamount>0){
		x=rand()%size;
		y=rand()%size;
		if(x==start_w or y==start_k){
			continue;
		}
		if(P[x][y].val==9){
			setbomb(x,y,P);
			secondamount--;
		}
	}
}

void getnext(int &w, int &k){
	cout<<endl<<"Podaj wiersz i kolumne : ";

	while(true){
		cin>>w;
		cin>>k;
		if(w<N and w>=0 and k<N and k>=0){
			break;
		}
		cout<<"Wprowadz poprawne wspolrzedne : ";
	}
}

void reveal(int w, int k, box P[][N]){
	
	
	if(w<0 || w>=N || k<0 || k>=N ) return;
	
	if(P[w][k].visible==true) return;
	
	if(P[w][k].val!=9 && P[w][k].visible==false)
		P[w][k].visible=true;
	
	if(P[w][k].val!=0) return;
	
	reveal(w-1,k-1,P);
	reveal(w-1,k,P);
	reveal(w-1,k+1,P);
	reveal(w,k-1,P);
	reveal(w,k,P);
	reveal(w,k+1,P);
	reveal(w+1,k-1,P);
	reveal(w+1,k,P);
	reveal(w+1,k+1,P);
	
}

void firstreveal(int w,int k,box P[][N]){
	if( P[w][k].val==0 ){
		reveal(w,k,P);
	}
	else{
		if(w-1>=0 && w-1<N && k-1>=0 && k-1<N && P[w-1][k-1].val==0 ){
			reveal(w-1,k-1,P);
			return;
		}
		if(w-1>=0 && w-1<N && k>=0 && k<N && P[w-1][k].val==0 ){
			reveal(w-1,k,P);
			return;
		}
		if(w-1>=0 && w-1<N && k+1>=0 && k+1<N && P[w-1][k+1].val==0 ){
			reveal(w-1,k+1,P);
			return;
		}
			
		if(w>=0 && w<N && k-1>=0 && k-1<N && P[w][k-1].val==0 ){
			reveal(w,k-1,P);
			return;
		}
		if(w>=0 && w<N && k+1>=0 && k+1<N && P[w][k+1].val==0 ){
			reveal(w,k+1,P);
			return;
		}
		
		if(w+1>=0 && w+1<N && k-1>=0 && k-1<N && P[w+1][k-1].val==0 ){
			reveal(w+1,k-1,P);
			return;
		}
		if(w+1>=0 && w+1<N && k>=0 && k<N && P[w+1][k].val==0 ){
			reveal(w+1,k,P);
			return;
		}
		if(w+1>=0 && w+1<N && k+1>=0 && k+1<N && P[w+1][k+1].val==0 ){
			reveal(w+1,k+1,P);
			return;
		}
	}			
}

int checkstatus(int w,int k, int amount,box P[][N]){
	
	if(P[w][k].val==9 )
		return -1; //przegrana
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(P[i][j].visible==false)
				amount--;
		}
	}
	if(amount==0)
		return 1;
		
	return 0;	
}

int main(){
	srand( time( NULL ) );
	cout<<"		Saper!"<<endl<<"Uwagi:"<<endl<<"1) Kolumny oraz wiersze sa numerowane od zera"<<endl<<"2) Wpisuj najpierw wiersz, a poniej kolumne pola, ktore chcesz odkryc";
	cout<<endl<<"3) W grze znajduje sie kilka podwójnych bomb (dodaje ona do sasiednich pol wartosc 2, a nie 1 jak zwykla bomba)";
	cout<<endl<<"Powodzenia!!!";
	int bombs=N;
	int doublebombs=N/4;
	int w,k;
	int status=0; // -1przegrana 0gramy dalej, 1wygrana
	box Board[N][N];
	
	makeboard(N,Board);
	
	getnext(w,k);
	
	randbombs(bombs,doublebombs,N,Board,w,k);
	
	firstreveal(w,k,Board);
	
	while(status==0){
		cout<<endl;
		showboard(N,Board);
		
		getnext(w,k);
		reveal(w,k,Board);
		
		status=checkstatus(w,k,bombs,Board);
		
		if(status==-1){
			cout<<endl<<"	Trafiles na bombe!"<<endl;
			visboard(N,Board);
			showboard(N,Board);
			break;
		}
		if(status==1){
			cout<<endl<<"	Wygrales!"<<endl;
			visboard(N,Board);
			showboard(N,Board);
			break;
		}
		cout<<endl;
	}


	return 0;
}
