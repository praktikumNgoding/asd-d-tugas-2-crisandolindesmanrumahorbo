#include<iostream>
using namespace std;
struct Dnel{
	int data;
	Dnel *next;
};
class LinkedList{
	public:
	Dnel *Head;
	Dnel *Tail;
	
	void infirst(int x){
		Dnel *baru = new Dnel();
		Head = baru;
		Tail = baru;
		baru->data=x;
		baru->next=NULL;
	}
	void depan(int x){
		Dnel *baru = new Dnel();
		baru->data=x;
		baru->next=Head;
		Head=baru;
	}
	void belakang(int x){
		Dnel *baru = new Dnel();
		Dnel *tukar = new Dnel();
		tukar=Tail;
		baru->data=x;
		tukar->next=baru;
		baru->next=NULL;
		Tail=baru;
	}
	void set(int x,int y){
		Dnel *baru = new Dnel();
		Dnel *after = new Dnel();
		after=Head;
		baru->data=x;
		while(after->data!=y){
			after=after->next;
		}
		baru->next=after->next;
		after->next=baru;
	}
	void seb(int x,int y){
		Dnel *baru = new Dnel();
		Dnel *before = new Dnel();
		Dnel *prevbefore = new Dnel();
		before=Head;
		baru->data=x;
		while(before->data!=y){
			prevbefore=before;
			before=before->next;
		}
		prevbefore->next=baru;
		baru->next=before;
	}
	void hapusdepan(){
		Dnel *hapus = new Dnel();
		hapus = Head;
		Head = Head->next;
		delete hapus;
		}
	void hapusbelakang(){
		Dnel *hapus = new Dnel();
		Dnel *cari = new Dnel();
		hapus=Head;
		while(hapus!=Tail){
			cari=hapus;
			hapus=hapus->next;
		}
		cari->next=NULL;
		cari=Tail;
		delete hapus;
	}	
	void hapussesuatu(int x){
		Dnel *hapus = new Dnel();
		Dnel *cari = new Dnel();
		hapus = Head;
		while(hapus->data!=x){
			cari=hapus;
			hapus=hapus->next;
		}
		cari->next=hapus->next;
		delete hapus;
	}
	void print(){
		Dnel *baru = new Dnel();
		baru=Head;
		while(baru!=NULL){
			cout<<baru->data<<" -> ";
			baru=baru->next;
		}
		if(baru==NULL){
			cout<<"NULL";
		}
		cout<<endl;
	}
};
int main(){
	LinkedList list;
	list.infirst(20);
	list.print();
	list.depan(30);
	list.print();
	list.belakang(50);
	list.print();
	list.set(55,30);
	list.print();
	list.seb(22,50);
	list.print();
	list.hapusdepan();
	list.print();
	list.hapusbelakang();
	list.print();
	list.hapussesuatu(20);
	list.print();
}
