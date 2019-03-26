/*
Nama Program : Exercise Strukdat 5
Nama         : Aprischa Nauva
NPM          : 140810180063
Tanggal Buat : 26 Maret 2019
Deskripsi    : Program ini untuk memenuhi exercise strukdat 5
*/

#include<iostream>

using namespace std;

struct Pembalap {
	int nomor;
	char nama;
	int waktu;
	Pembalap* next;
	Pembalap* prev;
};

void createNode(Pembalap* &p, int nomor, char nama){
	p=new Pembalap;
	p->nama=nama;
	p->nomor=nomor;
	cout << " -> Masukkan waktu : ";
	cin >> p->waktu;
	p->next=NULL;
	p->prev=NULL;
}

void insertFirst(Pembalap* &head, Pembalap* node){
	if (head==NULL)
		head = node;
	else{
		node->next = head;
		node->prev = node;
		head = node;
	}
}

void insertBefore(Pembalap* &head, int nomorKey, Pembalap* node){
	Pembalap* pCari;
	if(pCari->next==NULL)
		pCari->next=node;
	else{
		node->next=pCari;
		node->prev=pCari->prev;
		pCari->prev->next=node;
		pCari->prev=node;
	}
}

void deleteByKey(Pembalap* &head, int nomorKey, Pembalap* &deletedNode);
void search(Pembalap* &firstNode, int nomorKey, Pembalap* &pToUpdate){
	pToUpdate=firstNode;
	while(pToUpdate->nomor!=nomorKey){
		pToUpdate=pToUpdate->next;
		}
}

void traversal(Pembalap* head){
	Pembalap* help;
	if (head==NULL){
		cout << "***LIST KOSONG***";
	}
	else {
		help=head;
		while(help!=NULL){
			cout << "Nomor : " << help->nomor << endl;
			cout << "Nama : " << help->nama << endl;
			cout << "Waktu : " << help->waktu << endl;
			cout << endl;
			help=help->next;
		}
	}
}

void sortingByNomor(Pembalap* &head);
void update(Pembalap* firstNode, int nomorKey);

int main() {
	Pembalap* head = NULL;
	Pembalap* pBaru = NULL;
	Pembalap* pToUpdate = NULL;
	char nama = 'a';

	for (int i = 0; i < 4; i++) {
		createNode(pBaru, i+1, nama++);
		insertFirst(head, pBaru);
	}
	cout << " -> List" << endl;
	traversal(head);

	int keyNomor = 2;

	cout << " -> Insert Before nomor" << keyNomor << endl;
	createNode(pBaru, 99, 'z');
	insertBefore(head, keyNomor, pBaru);
	traversal(head);
}
