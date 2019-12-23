
// julian Augusto Poveda Garcia  Поведа Гарсия Хулиан Аугусто Группа Б8119.10.03.01 кзоин
//Односвязный список

#include <iostream>

using namespace std;

struct HOLA
{
	int data;
	HOLA* next;
	HOLA(int d,HOLA*n=nullptr)
	{
		this->data = d;
		this->next = n;
	}
};

class list
{
public:
	list();
	~list();
	int size()
	{
		return this->Size;
	}
	void push_back(int data);
	void push_front(int data);
	void insert(int data, unsigned int index);
	void pop_front();
	void pop_back(); 
	void pop_index(unsigned int index);
	void clean();
	void print();
	void find(int data);
	int& operator[](unsigned int index);

 private:
	HOLA* HEAD;
	int Size;	
};

list::list()
{
	this->HEAD = nullptr;
	this->Size = 0;
}

list::~list()
{
	this->clean();
}


void list::push_back(int data)
{
	if (this->size() == 0)
	    this->HEAD = new HOLA(data);
	else
	{
		HOLA* nuevo_hola = HEAD;
		while (nuevo_hola->next != nullptr)
			nuevo_hola = nuevo_hola->next;
		nuevo_hola->next= new HOLA(data);
	}
	this->Size++;
}

void list::push_front(int data)
{
	HOLA* nuevo_hola = new HOLA(data,HEAD);
	HEAD = nuevo_hola;
	this->Size++;
}

void list::insert(int data, unsigned int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		HOLA* previous = this->HEAD;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}
		HOLA* nuevo_hola = new HOLA(data, previous->next);
		previous->next = nuevo_hola;

		this->Size++;
	}

}
void list::pop_front()
{
	HOLA* nuevo_hola = this->HEAD;
	this->HEAD = this->HEAD->next;
	delete nuevo_hola;
	this->Size--;
}

void list::pop_back()
{
	pop_index(this->Size - 1);
}

void list::pop_index(unsigned int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		HOLA* previous = this->HEAD;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}
		HOLA* nuevo_delete = previous->next;
		previous->next = nuevo_delete->next;
		delete nuevo_delete;

		this->Size--;
	}

}

void list::clean()
{
	while (this->size() != 0)
	   this->pop_front();
	
}

void list::print()
{
	HOLA* nuevo_hola = HEAD;    //crear un  nuevo nodo ucasatel
	nuevo_hola = HEAD;  //se hace para que la lista se empiece a rrecorrer desde el comiezo
	if (nuevo_hola == NULL)
	{
		cout << "the list is empty---lista vacia"<<endl;
	}
	else
	{
		cout << "list ";
		while (nuevo_hola != NULL) //si la lista es diferente de cero, sigue mestrando datos de la lista
		{
			
			cout << nuevo_hola->data << "->";
			nuevo_hola = nuevo_hola->next;  //para que se siga moviendo de un espacio a otro
		}
		
		cout << endl;
	}
}

void list::find(int data)
{
	bool band = false;  //lo creamos para despues vwer si la se encontro el elemnto es verdad pero si no es falso
	HOLA* nuevo_hola = HEAD;  //crear un nuevo nodo nuevo ukasatel
	nuevo_hola = HEAD;  //se encarga de señalar a head al comiezo de la lista

	while ((nuevo_hola != NULL) && (nuevo_hola->data <= data)) //significa que el nodo es dirente de cero entonces hay elemtos en la lista y el otro si el numero es menor a n osea el numero a buscar
	{
		if (nuevo_hola->data == data)  //si el nievo nodo es igual al numero entonces la se encontro el numero
		{
			band = true; //dice que elemento si exiate
		}
		nuevo_hola = nuevo_hola->next; //si el dato no es igual significa que se apunta a la sig posisicon en la lista para buscarlo ahi
	}
	if (band == true)   //si es verdad el elemto se ha encontrado
	{
		cout << "the element " << data << " has been found--- el elemento " << data << " ha sido encontrado--the element\n";
		
	}
	else  //si no el elemto no se ha encontrado
	{
		cout << "the element " << data << " has not been found--the element " << data << " no fue encontrado\n";
	}
}

int& list::operator[](unsigned int index)
{
	HOLA* nuevo_hola = HEAD;
	for (int i = 0;nuevo_hola != nullptr; i++)
	{
		if (i == index)
			return nuevo_hola->data;
		else
			nuevo_hola = nuevo_hola->next;
	}
	abort();
}

int main()
{
	list l;
	int x, data,data2, index;
	do
	{
		cout << "\t. -----MENU---- .\n";
		cout << "1. -push back element---agregar elemento en la cola\n";
		cout << "2. -push front element---agregar elemento en el frente\n";
		cout << "3. -inser element by index---insertar elelemnto por index\n";
		cout << "4. -pop back-delete back--borrar en la cola\n";
		cout << "5. -pop front-delete front---borrar en el frente\n";
		cout << "6. -delete for index\n";
		cout << "7. -show list--- mostrar lista\n";
		cout << "8. -find element-- buscar elemnto\n";
		cout << "9. -delete all\n";
		cout << "10. -salir---Exit\n";
		cin >> x;

		switch (x)
		{
		case 1: cout << "push back:--enter a number: ";
			cin >> data;
			l.push_back(data);   //llamar la lista
			cout << "\n";
			cout << data << "  has been added";
			cout << endl;
			cout << "New List" << endl;
			for (int i = 0;i < l.size();i++)
				cout << l[i] << endl;
			break;

		case 2: cout << "push front--enter a number: ";
			cin >> data2;
			l.push_front(data2);   //llamar la lista
			cout << "\n";
			cout << data2 << "  has been added";
			cout << endl;
			cout << "New List" << endl;
			for (int i = 0;i < l.size();i++)
				cout << l[i] << endl;
			break;

		case 3: cout << "insert for index-- enter a number: ";
			cin >> data;
			cout << "enter the index: ";
			cin >> index;
			l.insert(data, index);
			cout << "\n";
			cout << data << "  has been added";
			cout << endl;
			cout << "List" << endl;
			for (int i = 0;i < l.size();i++)
				cout << l[i] << endl;
			break;

		case 4: cout << "Pop back--delete" << endl;
			l.pop_back();
			cout << "the element has been deleted";      //llamar la lista
			cout << "\n";
			cout << endl;
			cout << "New List" << endl;
			for (int i = 0;i < l.size();i++)
				cout << l[i] << endl;
			break;

		case 5: cout << "pop front delete" << endl;
			l.pop_front();   //llamar la lista
			cout << "the element has been deleted";
			cout << "\n";
			cout << endl;
			cout << "New List" << endl;
			for (int i = 0;i < l.size();i++)
				cout << l[i] << endl;
			break;
			
		case 6: cout << "delete for index-- enter the index: ";
			cin >> index;
			l.pop_index(index);
			cout << "the element has been deleted";
			cout << "\n";
			cout << endl;
			cout << "New List" << endl;
			for (int i = 0;i < l.size();i++)
				cout << l[i] << endl;
			break;

		case 7: cout << "show elements" << endl;
			l.print();
			cout << endl;//para que no desaparesaca la infomacion
			break;

		case 8: cout << "find element" << endl;
			cout << "insert the element: ";
			cin >> data;
			l.find(data);  //para que no desaparesaca la infomacion
			break;

		case 9: 
			l.clean();
			cout <<"the elements have been deleted from the list"<<endl;
			cout << " the list is empty!";
			system("pause");   //para que no desaparesaca la infomacion
			break;

		}

	} while (x != 10);
}

//int main()
//{
//	
//	list l;
//	l.push_back(10);
//	l.push_back(11);
//	l.push_back(102);
//	l.push_front(5);
//	l.push_front(7);
//	l.push_front(101);
//	/*l.push_front(102);*/
//    for (int i = 0;i < l.size();i++)
//		cout << l[i] << endl;
//	/*cout << l.size();*/
//
//
//	cout << "insert" << endl;
//	l.insert(99, 2);
//	for (int i = 0;i < l.size();i++)  
//		cout << l[i] << endl;
//	/*cout << l.size() << endl;*/
//
//	cout << "pop back" << endl;
//	l.pop_back();
//	for (int i = 0;i < l.size();i++)
//		cout << l[i] << endl;
//	/*cout << l.size();*/
//
//	cout << "eliminar" << endl;
//	l.pop_index(2);
//	for (int i = 0;i < l.size();i++)
//		cout << l[i] << endl;
//	/*cout << l.size();*/
//
//
//   return 0;
//   
//   cout << l.size();
//}


