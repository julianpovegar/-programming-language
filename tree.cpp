//JULIAN AUGUSTO POVEDA GARCIA ПОВЕДА ГАРСИЯ ХУЛИАН АУГУСТО Б8119-10.03.01-КЗОИН

//дерево

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct hola_tree
{

	int data;
	hola_tree* left;  
	hola_tree* right;
	hola_tree* father;
};
 


class tree1
{
	int fatherRaiz = 0;
public:
	hola_tree* Tree;
	hola_tree* createTree(int, hola_tree*);
	void insert(hola_tree *&, int, hola_tree* );
	bool find(hola_tree*, int, string);

	//show
    void print_tree(hola_tree*, int);
	void print_pre_order(hola_tree*);
	void print_in_order(hola_tree*);
	void print_post_order(hola_tree*);
	
	//delete
    void remove_element(hola_tree*, int);
	void AUX_dlt(hola_tree*&, int);
	hola_tree* minimum3(hola_tree*);
	
private:

};

hola_tree* tree1::createTree(int n, hola_tree*father)
{
	hola_tree* nuevo_hola = new hola_tree();
	nuevo_hola->data = n;
	nuevo_hola->left = NULL;
	nuevo_hola->right = NULL;
	/*nuevo_hola->father = father;*/

	if (fatherRaiz == 0) { //Se da cuando el árbol está vacio
		nuevo_hola->father = nuevo_hola;
		fatherRaiz = 1;
	}
	else if (fatherRaiz == 1) {//para agregar hijos a la raíz u otros nodos
		nuevo_hola->father = father;
	}

	return nuevo_hola;
}

void tree1::insert(hola_tree*&tree, int n, hola_tree*father)
{
	if (tree == NULL)
	{
		hola_tree* nuevo_hola = createTree(n, father);
		tree = nuevo_hola;
	}
	else
	{
		int valuehead = tree->data;
		if (n < valuehead)
		{
			insert(tree->left, n, tree);
		}
		else
		{
			insert(tree->right, n, tree);
		}
	}
}
void tree1::print_tree(hola_tree*tree, int cont=NULL)
{
	if (tree == nullptr)
	{
		return;
	}
	else
	{
		print_tree(tree->right, cont + 1);
		for (int i = 0; i < cont; i++)
		{
			cout << "   ";
		}
		
		cout << tree->data << endl;
		print_tree(tree->left, cont + 1);
	}
}

bool tree1::find(hola_tree* tree, int n, string flag )
{

		if (tree == NULL)
		{
			cout << "the element:" << n << " has not found in the tree";
			return false;
		}
		else if (tree->data == n)
		{
			if (flag == "0")
			{
				AUX_dlt(tree, n);
			}
				cout << "the element:" << n << " has found in the tree";
			return true;
		}
		else if (n < tree->data)
		{
			
			return find(tree->left, n, flag);

		}
		else
		{
			
		    return find(tree->right, n, flag);
		}

}

void tree1::print_pre_order(hola_tree*tree)
{

	if (tree == NULL)
	{
		return;
	}
	else
	{
		cout << tree->data << " - ";
		print_pre_order(tree->left);
		print_pre_order(tree->right);
	
	}
}

void tree1::print_in_order(hola_tree*tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		print_in_order(tree->left);
		cout << tree->data << " - ";
		print_in_order(tree->right);
	}
}

void tree1::print_post_order(hola_tree* tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		print_post_order(tree->left);
		print_post_order(tree->right);
		cout << tree->data << " - ";
	}
}

hola_tree* tree1::minimum3(hola_tree*tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	else if (tree->left)  //si tiene hijo izq
	{
		return minimum3(tree->left); //busca la parte mas left posible
	}
	else 
	{
		return tree;
	}
}

void tree1::AUX_dlt(hola_tree*& tree, int n)
{

	if (tree->data == tree->father->data)//Significa que se refiere a la raíz
	{

		if (tree->left != NULL && tree->right != NULL) //Caso (A) Raíz con dos hijos 
		{
		
			if (tree->right->right != NULL && tree->right->left == NULL)
			{

				hola_tree* der = new hola_tree();

				der = tree->right;

				tree->data = der->data;

				tree->right = der->right;
				der->right->father = tree;
				der->father = NULL;


				delete der;
			}
			else if (tree->right->right == NULL && tree->right->left == NULL) 
			{
				//A2:Hijo der sin hijos 

				hola_tree* der = new hola_tree();
				der = tree->right;
				tree->data = der->data;
				tree->right = NULL;
				der->father = NULL;
				der->data = NULL;
				delete der;
			}
			else 
			{
				cout << "\t*it is not possible to delete the node " << tree->left->data << " and " << tree->right->data << "\n";
			}

		}
		else if (tree->left == NULL && tree->right == NULL) { //Raíz sin hijos
			int fatherRaiz = 0;
			fatherRaiz = 0;
			tree = NULL;
			cout << "\tLa raiz no tiene hijos\n";
		}
		else if (tree->left != NULL)  //Raíz con hijo izq
		{
			hola_tree* izq = new hola_tree();
            izq = tree->left;
			tree->data = izq->data;

			if (tree->left->left != NULL && tree->left->right != NULL)
			{//Hijo izq tiene dos hijos

				izq->right->father = tree;
				izq->left->father = tree;
				tree->left = izq->left;
				tree->right = izq->right;
				izq->father = NULL;
				izq->left = NULL;
				izq->right = NULL;

				delete izq;
			}
			else if (izq->left == NULL && izq->right == NULL) {
				//Hijo izq no tiene hijos
				
				izq->father = NULL;
				tree->left = NULL;
				delete izq;
			}
			else if (izq->left != NULL)
			{
				//Hijo izq tiene un hijo izq
				
				izq->left->father = tree;
				tree->left = izq->left;
				izq->father = NULL;
				izq->left = NULL;
				delete izq;
			}
			else if (izq->right != NULL) {
				//Hijo izq tiene un hijo rightecho
				
				izq->right->father = tree;
				tree->left = izq->right;
				izq->father = NULL;
				izq->right = NULL;
				delete izq;
			}

		}
		else if (tree->right != NULL) {// Raíz con hijo der
			
			hola_tree* der = new hola_tree();

			der = tree->right;
			tree->data = der->data;

			if (tree->right->left != NULL && tree->right->right != NULL)
			{//Hijo der tiene dos hijos 
				
				der->right->father = tree;
				der->left->father = tree;
				tree->left = der->left;
				tree->right = der->right;
				der->father = NULL;
				der->left = NULL;
				der->right = NULL;

				delete der;
			}
			else if (der->left == NULL && der->right == NULL) {
				//Hijo der no tiene hijos 
				
				der->father = NULL;
				tree->right = NULL;
				delete der;
			}
			else if (der->left != NULL)
			{
				//Hijo der tiene un hijo izq
			
				der->left->father = tree;
				tree->left = der->left;
				tree->right = NULL;
				der->father = NULL;
				der->left = NULL;
				delete der;
			}
			else if (der->right != NULL) {
				//Hijo der tiene un hijo der
				
				der->right->father = tree;
				tree->right = der->right;
				der->father = NULL;
				der->right = NULL;
				delete der;
			}
		}
	}
	else if (tree->data != tree->father->data) {//Estamos hablando de cualquier hola_tree menos la raíz
		

		if (tree->left != NULL && tree->right != NULL) {// nodo a eliminar tiene 2 hijos

			if (tree->father->right == tree)
			{
				//El nodo a eliminar es un hijo der				
				if (tree->right->right == NULL && tree->right->left == NULL)
				{
					//Su hijo der no tiene hijos
					
					hola_tree* hijoder = new hola_tree();
					hijoder = tree->right;
					tree->data = hijoder->data;
					tree->right = NULL;
					hijoder->father = NULL;
					hijoder->data = NULL;
					delete hijoder;
				}
				else if (tree->right->right != NULL && tree->right->left == NULL)
				{
					//Caso A.1.2 Su hijo der tiene hijo der y este tiene hijos o no tiene pero el *NO tiene hijo izq
					
					hola_tree* hijoder = new hola_tree();
					hijoder = tree->right;
					tree->data = hijoder->data;
					tree->right = hijoder->right;
					hijoder->right->father = tree;
					hijoder->father = NULL;
					hijoder->right = NULL;
					hijoder->data = NULL;
					delete hijoder;
				}
				else if (tree->right->right != NULL && tree->right->left != NULL && (tree->right->left->left != NULL && (tree->right->left->right != NULL || tree->right->left->right == NULL)))
				{
					
					hola_tree* Elmasizq = minimum3(tree->right);
					cout << "\tEl más izq es: " << Elmasizq->data << endl;
					tree->data = Elmasizq->data;
					Elmasizq->father->left = NULL;
					Elmasizq->father = NULL;
					Elmasizq->data = NULL;
					delete Elmasizq;
				}
				else if (tree->right->left->right == NULL && tree->right->left->left == NULL && tree->right->right != NULL) {
					//El hijo der tiene dos hijos pero su nieto izq no tiene hijos

					hola_tree* Elmasizq = new hola_tree();
					Elmasizq = tree->right->left;
					cout << Elmasizq->data << endl;
					tree->data = Elmasizq->data;
					tree->right->left = NULL;
					Elmasizq->father = NULL;
					Elmasizq->data = NULL;
					delete Elmasizq;
				}
				else if (tree->right->left->right != NULL && tree->right->right != NULL) {
					// el máx izq tiene un unico hijo der
					hola_tree* Elmasizq = minimum3(tree->right);
					

					tree->data = Elmasizq->data;
					tree->right->left = Elmasizq->right;
					Elmasizq->right->father = tree->right;

					Elmasizq->father = NULL;
					Elmasizq->right = NULL;
					Elmasizq->data = NULL;
					delete Elmasizq;

				}
				else {
					cout << "\tit is impossible to delete the node\n";
				}

			}
			else if (tree->father->left == tree)
			{
				//nodo a eliminar es un hijo izq
								
				if (tree->right->right == NULL && tree->right->left == NULL)
				{
					//Su hijo der no tiene hijos
					
					hola_tree* hijoder = new hola_tree();
					hijoder = tree->right;
					tree->data = hijoder->data;
					tree->right = NULL;
					hijoder->father = NULL;
					hijoder->data = NULL;
					delete hijoder;
				}
				else if (tree->right->right != NULL && tree->right->left == NULL)
				{
					//Caso A.2.2 Su hijo der tiene hijo der y este tiene hijos o no tiene pero el *NO tiene hijo izq
					
					hola_tree* hijoder = new hola_tree();
					hijoder = tree->right;
					tree->data = hijoder->data;
					tree->right = hijoder->right;
					hijoder->right->father = tree;
					hijoder->father = NULL;
					hijoder->right = NULL;
					hijoder->data = NULL;
					delete hijoder;
				}
				else if (tree->right->right != NULL && tree->right->left != NULL && (tree->right->left->left != NULL && (tree->right->left->right != NULL || tree->right->left->right == NULL)))
				{
					//Caso A.2.3 EL hijo der tiene hijos, se debe encontrar a partir de su hijo der cuál es su 
					//tatara nieto más izq
					//El hijo izq tiene por lo menos un hijo izq
					hola_tree* Elmasizq = minimum3(tree->right);
					tree->data = Elmasizq->data;
					Elmasizq->father->left = NULL;
					Elmasizq->father = NULL;
					Elmasizq->data = NULL;
					delete Elmasizq;
				}
				else if (tree->right->left->right == NULL && tree->right->left->left == NULL && tree->right->right != NULL) {
					//Caso A.2.4 El hijo der tiene dos hijos pero su nieto izq no tiene hijos
					
					hola_tree* Elmasizq = new hola_tree();
					Elmasizq = tree->right->left;
					tree->data = Elmasizq->data;
					tree->right->left = NULL;
					Elmasizq->father = NULL;
					Elmasizq->data = NULL;
					delete Elmasizq;
				}
				else if (tree->right->left->right != NULL && tree->right->right != NULL) {
					//el máx izq tiene un unico der
					
					hola_tree* Elmasizq = minimum3(tree->right);

					tree->data = Elmasizq->data;
					tree->right->left = Elmasizq->right;
					Elmasizq->right->father = tree->right;

					Elmasizq->father = NULL;
					Elmasizq->right = NULL;
					Elmasizq->data = NULL;
					delete Elmasizq;

				}
				else {
					cout << "\tit is impossible to delete the node\n";
				}
			}
		}
		else if (tree->right != NULL && tree->left == NULL) {//nodo a eliminar tiene 1 hijo der
		
			if (tree->right->right == NULL && tree->right->left == NULL)
			{
				//nodo tiene un hijo der sin hijos 

				hola_tree* hijoder = new hola_tree();
				hijoder = tree->right;
				tree->data = hijoder->data;
				tree->right = NULL;
				hijoder->father = NULL;
				hijoder->data = NULL;
				delete hijoder;

			}
			else if (tree->right->right != NULL && tree->right->left == NULL) {
				//nodo tiene un hijo der con hijos
			
				hola_tree* hijoder = new hola_tree();
				hijoder = tree->right;
				tree->data = hijoder->data;
				tree->right = hijoder->right;
				hijoder->right->father = tree;
				hijoder->father = NULL;
				hijoder->right = NULL;
				hijoder->data = NULL;
				delete hijoder;
			}
			else if (tree->right->right != NULL && tree->right->left != NULL) {
				//nodo tiene un hijo der con hijo izq y der 
				
				hola_tree* hijoder = new hola_tree();
				hijoder = tree->right;
				tree->data = hijoder->data;
				tree->right = hijoder->right;
				tree->left = hijoder->left;
				hijoder->right->father = tree;
				hijoder->left->father = tree;
				hijoder->father = NULL;
				hijoder->left = NULL;
				hijoder->right = NULL;
				hijoder->data = NULL;
				delete hijoder;
			}
			else
			{
				cout << "\tit is impossible to delete the node\n";
			}

		}
		else if (tree->right == NULL && tree->left != NULL) {//nodo a eliminar tiene 1 hijo izq
			
			if (tree->left->right == NULL && tree->left->left == NULL)
			{
				//nodo tiene un hijo izq sin hijos 

				hola_tree* hijoizq = new hola_tree();
				hijoizq = tree->left;
				tree->data = hijoizq->data;
				tree->left = NULL;
				hijoizq->father = NULL;
				hijoizq->data = NULL;
				delete hijoizq;

			}
			else if (tree->left->right != NULL && tree->left->left == NULL) {
				//nodo tiene un hijo izq con hijos
			
				hola_tree* hijoizq = new hola_tree();
				hijoizq = tree->left;
				tree->data = hijoizq->data;
				tree->left = hijoizq->right;

				hijoizq->right->father = tree;

				hijoizq->father = NULL;
				hijoizq->right = NULL;
				hijoizq->data = NULL;
				delete hijoizq;
			}
			else if (tree->left->right != NULL && tree->left->left != NULL) {
				//nodo tiene un hijo izq con hijo izq y der
			
				hola_tree* hijoizq = new hola_tree();
				hijoizq = tree->left;
				tree->data = hijoizq->data;
				tree->right = hijoizq->right;
				tree->left = hijoizq->left;
				hijoizq->right->father = tree;
				hijoizq->left->father = tree;
				hijoizq->father = NULL;
				hijoizq->left = NULL;
				hijoizq->right = NULL;
				hijoizq->data = NULL;
				delete hijoizq;
			}
			else
			{
				cout << "\tit is impossible to delete the node\n";
			}

		}
		else if (tree->right == NULL && tree->left == NULL) {//nodo es una hoja
			
			hola_tree* hoja = new hola_tree();
			if (tree->father->left == tree)//hoja izq
			{
				hoja = tree;
				tree->father->left = NULL;
				hoja->father = NULL;
				hoja->data = NULL;
				delete hoja;
			}
			else if (tree->father->right == tree)//hoja der
			{

				hoja = tree;
				tree->father->right = NULL;
				hoja->father = NULL;
				hoja->data = NULL;
				delete hoja;
			}
		}
	}

}

void tree1::remove_element(hola_tree* tree, int n)
{
	/*hola_tree* tree=NULL;*/
	string flag = "1";

	flag = "0";
	if (find(tree, n, flag) == true)
	{
		cout << " and it has been deleted" << endl;
	}
	else
	{
		cout << " and it has not deleted\n";
	}flag = "1";
}



int main()
{
	cout << "------------Tree------------" << endl;

	tree1 l;
	l.insert(l.Tree, 10, NULL);
	l.insert(l.Tree, 5, NULL);
	l.insert(l.Tree, 3, NULL);
	l.insert(l.Tree, 8, NULL);
	l.insert(l.Tree, 6, NULL);
	l.insert(l.Tree, 9, NULL);
	l.insert(l.Tree, 7, NULL);
	l.insert(l.Tree, 15, NULL);
	l.insert(l.Tree, 12, NULL);
	l.insert(l.Tree, 20, NULL);
	l.insert(l.Tree, 30, NULL);
	l.print_tree(l.Tree, NULL);
	cout << endl;
	
	l.remove_element(l.Tree, 15);
	cout << endl;
	
    l.print_tree(l.Tree,NULL);
	cout << endl;

	l.find(l.Tree, 20, "1");
	cout << endl;

	cout << "Pre Order" << endl;
	l.print_pre_order(l.Tree);
	cout << endl;

	cout << "in Order" << endl;
	l.print_in_order(l.Tree);
	cout << endl;

	cout << "Post Order" << endl;
	l.print_post_order(l.Tree);
	cout << endl;

}
