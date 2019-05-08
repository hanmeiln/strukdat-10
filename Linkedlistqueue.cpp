/*
Nama Program : Case 2
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 8 Mei 2019
Deskripsi    : Linked List Queue
*****************************************/
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

struct ElemenQueue{
    char info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue{
    List Head;
    List Tail;
};
Queue Q;

void createQueue(Queue& Q);
void CreateElement(pointer& pBaru);
void insertQueue(Queue& Q, pointer pBaru);
void deleteQueue(Queue& Q, pointer& pHapus);
void printQueue(Queue Q);

main(){
    Queue Q;
    pointer p;
    int pil,n=5;
    createQueue(Q);
    do{
        system("cls");
        cout<<"1. Insert Queue "<<endl;
        cout<<"2. Delete Queue "<<endl;
        cout<<"3. Print Queue "<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"Masukkan pilihan : ";
        cin>>pil;

        switch (pil){
        case 1 :
            CreateElement(p);
            insertQueue(Q,p);
            getch();
            break;
        case 2 :
            deleteQueue(Q,p);
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
            cout<<"Pilihan anda tidak tersedia"<<endl;
        }
    }while(pil!=4);
}

void createQueue(Queue& Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}

void CreateElement(pointer& pBaru){
    pBaru = new ElemenQueue;
    cout<<"Masukkan data : ";
    cin>>pBaru->info;
    pBaru->next = NULL;
}

void insertQueue(Queue& Q, pointer pBaru){
    if(Q.Head==NULL && Q.Tail==NULL){
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else{
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(Queue& Q, pointer& pHapus){
    if(Q.Head->next==NULL){
        pHapus = NULL;
        cout << "List kosong" << endl;
    }
    else if(Q.Head->next == NULL){
        pHapus = Q.Head;
        Q.Head = NULL;
        Q.Tail = NULL;
    }
    else{
        pHapus = Q.Head;
        Q.Head = Q.Head->next;
        pHapus->next = NULL;
    }
    cout<<"Data berhasil di hapus"<<endl;
}

void printQueue(Queue Q){
    pointer pBantu;
    if(Q.Head==NULL){
        cout << "Antrian Kosong";
    }
    else{
        pBantu=Q.Head;
        do{
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}
