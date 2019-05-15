/*	
	Nama program	: Case 2
	Nama			: Gede Bagus Darmagita
	NPM				: 140810180068
	Tanggal buat	: 15 Mei 2019
    Deskripai       : tugas 2 pada praktikum strukdat ke-11
*/

#include<iostream>
using namespace std;

struct Simpul{          // binary tree
    int data;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul (pointer& pBaru){
    pBaru = new Simpul;
    cout << "Masukan 1 angka: ";
    cin >> pBaru->data;
    pBaru->left = NULL;
	pBaru->right = NULL;
}

void insertBST (Tree& Root, pointer pBaru){
	if (Root == NULL){ 
		Root = pBaru;
    }
	else if (pBaru->data < Root->data){
		insertBST(Root->left, pBaru);
    }
	else if (pBaru->data >= Root->data){
		insertBST(Root->right, pBaru);
    }
	else{
		cout << "Sudah ada." << endl;
    }
}

void preOrder(Tree Root){
	if (Root != NULL)
	{
		cout << Root->data << " ";
		preOrder(Root->left);
		preOrder(Root->right);
	}
}

void inOrder(Tree Root){
	if (Root != NULL)
	{
		preOrder(Root->left);
		cout << Root->data << " ";
		preOrder(Root->right);
	}
}

void postOrder(Tree Root){
	if (Root != NULL)
	{
		preOrder(Root->left);
		preOrder(Root->right);
		cout << Root->data << " ";
	}
}

void givenLevel(Tree Root, int level){
	if (Root == NULL){
        return;
    }
	if (level == 1) {
        cout << Root->data << " ";
    }
	else if (level > 1){
		givenLevel(Root->left,level-1);
		givenLevel(Root->right,level-1);
	}
}

int height(Tree Root){
	if (Root == NULL){
        return 0;
    }
	else{
		int lHeight=height(Root->left);
		int rHeight=height(Root->right);
		
		if (lHeight>rHeight){
            return (lHeight+1);
        }
		else {
            return (rHeight+1);
        }
	}
}

void levelOrder(Tree Root){
	int h = height(Root);
	for (int i = 1; i <= h; i++){
		cout << i << ": ";
		givenLevel(Root,i);
		cout << endl;
	} 
}

void depthOrder (Tree Root){
	int h = height(Root);
	for (int i = 1; i <= h; i++){
		cout << i-1 << ": ";
		givenLevel(Root,i);
		cout << endl;
	} 
}

Tree searchFather(Tree Root, int key){
	if (Root == 0 || Root->data == key) {
        return Root;
    }
	else if (Root->data<key) {
        return searchFather(Root->left,key);
    }
	else {
        return searchFather(Root->right,key);
    }
}

int main(){
	Tree Bdhz = NULL;
	pointer X;
    int menu,N,key;
    char pil;
	
    do{
		system("cls");
        cout << "Main Menu: "
             << "\n1. Insert BST"
             << "\t\t\t2. Cetak PreOrder Traversal"
             << "\n3. Cetak InOrder Traversal"
             << "\t4. Cetak PostOrder Traversal"
             << "\n5. Cetak Depth and Node(s)"
             << "\t6. Cetak Level and Node(s)"
             << "\n7. Cetak Father and Child(ren)"
             << "\t8. Exit"
			 << "\nOption: ";
        cin >> menu;

        switch(menu){
            case 1: cout << "Jumlah data yang ingin di Input: "; cin >> N;
                    for (int i=0; i<N; i++){
                        createSimpul(X);
	                    insertBST(Bdhz,X);
                    }
                    break;
            case 2: cout << "Pre Order Traversal: ";
	                preOrder(Bdhz);
                    break;
            case 3: cout << "In Order Traversal: ";
	                inOrder(Bdhz);
                    break;
            case 4: cout << "Post Order Traversal: ";
	                postOrder(Bdhz);
                    break;
			case 5: cout << "Cetak Depth and Node(s):\n";
					depthOrder(Bdhz);
					break;
            case 6: cout << "Cetak Level and Node(s):\n";
	                levelOrder(Bdhz);
                    break;
			case 7: cout << "Masukan Father: "; cin >> key;
					preOrder(searchFather(Bdhz,key));
					break;
			case 8: return 0;
					break;
            default: cout << "Opsi tidak ada." << endl;
                     break;
        }   
        cout << "Ulangi? (Y/N) "; cin >> pil;
    } while (pil=='Y' || pil=='y');
}