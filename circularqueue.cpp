/*
Nama Program : Case 1
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 8 Mei 2019
Deskripsi    : Circular Queue
*****************************************/
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

const int maxElemen=5;
struct Queue{
    int isi[maxElemen];
    int head;
    int tail;
};

void createQueue(Queue &Q);
void push(Queue &Q);
void pop(Queue &Q);
void printQueue(Queue Q);

main(){
    int b,n,pil;
    Queue Q;
    createQueue(Q);
    do{
		cout<<"Banyak Data maksimal 5 : ";
		cin>>n;
	}while(n>maxElemen);
	cout<<"Masukkan Nomor Antrian : "<<endl;
	for(int i=0; i<n; i++){
		push(Q);
	}
	cout<<"Data berhasil dibuat"<<endl;
    do{
        system("cls");
        cout<<"1. Insert Queue "<<endl;
        cout<<"2. Delete Queue "<<endl;
        cout<<"3. Print Queue "<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"Masukkan pilihan : ";
        cin>>pil;
    switch(pil){
    case 1 :
        if(Q.head!=0){
            cout<<"Masukkan Nomor Antrian : "<<endl;
        }
        push(Q);
        cout<<"Data berhasil dibuat"<<endl;
        getch();
        break;

    case 2 :
        pop(Q);
        cout<<"Data pertama berhasil dihapus"<<endl;
        getch();
        break;

    case 3 :
        printQueue(Q);
        getch();
        break;
    case 4 :
        exit(0);
        break;
    default :
        cout<<"Pilihan Anda tidak tersedia"<<endl;
        getch();
    }
}while(pil!=4);
}

void createQueue(Queue &Q){
    Q.head=-1;
    Q.tail=-1;
}

void push(Queue &Q){
    if(Q.head==-1){
		Q.head++;
		Q.tail++;
		cin>>Q.isi[Q.head];
	}else{
		if(Q.tail<maxElemen-1){
			Q.tail++;
			cin>>Q.isi[Q.tail];
		}else{
			if(Q.head==0){
				cout<<"Antrian penuh!"<<endl;
			}else{
				Q.tail=0;
				cin>>Q.isi[Q.tail];
			}
		}
	}
}

void pop(Queue &Q){
	if(Q.tail==-1){
		cout<<"Antrian kosong, tidak ada yang didelete."<<endl;
	}else if(Q.head==Q.tail){
		Q.head=-1;
		Q.tail=-1;
	}else{
		if(Q.head<maxElemen-1){
			Q.head++;
		}else{
			Q.head=0;
		}
	}
}

void printQueue(Queue Q){
	if(Q.head==-1){
		cout<<"Antrian Kosong."<<endl;
	}else{
		int i=Q.head;
		cout<<endl<<"Antrian = [";
		if(Q.head>Q.tail){
			while(i<maxElemen){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}
