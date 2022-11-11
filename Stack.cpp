#include <windows.h> //MEMBUAT TAMPILAN
#include <iostream> //digunakan untuk input / output
#include <conio.h> //MENGGUNAKAN GETCH()
#include <stdlib.h> //digunakan untuk oprasi perbandingan
#include <limits> // Only Integer
#define MAKS 5
using namespace std;

struct Node {
   int data[MAKS];
   int petunjuk;
}tumpukan;


void gotoxy(int x, int y)
{
   	COORD k = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void init(){
    tumpukan.petunjuk=-1;
}

bool isEmpty(){
    return tumpukan.petunjuk==-1;
}

bool isFull(){
    return tumpukan.petunjuk==MAKS-1;
}

void push() {
    if(isFull()){
        cout<<"Data Sudah Penuh";
    }
    else{
        tumpukan.petunjuk++;
        cout<<"Masukan Data Kedalam Stack : ";
        cin>>tumpukan.data[tumpukan.petunjuk];
    }
}

void pop() {
    if(isEmpty()){
        cout<<"Data Masih Kosong";
    }
    else{
        cout<<"Data Yang diambil adalah : "<<tumpukan.data[tumpukan.petunjuk];
        tumpukan.petunjuk--;
    }
}

void display() {
    if(isEmpty()){
        cout<<"Tumpukan Kosong"<<endl;
    }
    else{
        cout<<"Tumpukan : ";
        for(int i = tumpukan.petunjuk; i>=0; i--){
            cout<<tumpukan.data[i]<<((i==0) ? "" : ",");
        }
    }
}

menu(){
    int choose, data;
    init();
    do{
            system("cls");
            gotoxy(0,0);cout<< "Implementasi stack dengan linkedlist"<<endl;
            gotoxy(0,1);cout<<"1. Menambah Data              "<<endl;
            gotoxy(0,2);cout<<"2. Menghapus Data             "<<endl;
            gotoxy(0,3);cout<<"3. Exit                       "<<endl;
            gotoxy(0,4);cout<<"====================================="<<endl;
            gotoxy(0,5);cout<<"Pilih (1-3) = ";
            while(!(cin>>choose)){
                system("cls");
                cin.clear();   
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                gotoxy(0,1);cout << "Invalid input...";
                gotoxy(0,3);cout << "Tekan Tombol Apapun Untuk Melanjutkan...";
                getch();
                return menu();
            }
            if(choose == 1){
                push();
            }
            else if(choose == 2){
                pop();
            }
            else if(choose == 3){
                gotoxy(0,13);cout<<"TERIMAKASIH";	
                return 0;
            }
            else{
                system("cls");
                gotoxy(0,1);cout << "Masukan anda salah ! \n"<< endl;
                getch();
                return menu();

            }
            getch();
        }
        while(choose!=3);
}


int main(){
    system("cls");
    menu();


}
