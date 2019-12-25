//JULIAN AUGUSTO POVEDA GARCIA ПОВЕДА ГАРСИЯ ХУЛИАН АУГУСТО Б8119-10.03.01-КЗОИН

//двусвязный список

#include <iostream>

using namespace std;

struct hola
{
	int data;
	hola* next;
	hola* prev;

	hola(int data , hola* next = nullptr, hola* prev = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}

};


class List
{
public:

	List();
	~List();

	int GetSize() { return Size; }
	void push_front(int data);
	void push_back(int data);
    void insert_by_index(int data, int index);
	void pop_front();
	void pop_back();
	void pop_by_index(int index);
	void find_head(int data);
	void find_tail(int data);
	void clear();
	
    void showFromHead();
	void showFromTail();
    int& operator [] (const int index);
	

private:
	hola * head;
	hola * tail;
	int Size;

};

List::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

List::~List()
{
	clear();
}

void List::clear()
{
	while (Size!=0)
	{
		pop_front();
	}
}

void List::push_front(int data)
{
	if (Size > 1)
	{
		hola * nuevo_hola = head;
		head = new hola(data, head);
		nuevo_hola->prev = head;
	}
	else if (Size == 1)
	{
		head = new hola(data, head);
		tail->prev = this->head;
	}
	else
	{
		head = tail = new hola(data, head, tail);
	}
	Size++;
}

void List::push_back(int data)
{
	if (Size > 1)
	{
		hola* nuevo_hola = tail;
		tail = new hola(data, nullptr, tail);
		nuevo_hola->next = tail;
	}
	else if (Size == 1)
	{
		tail = new hola(data, nullptr, tail);
		head->next = this->tail;
	}
	else
	{
		head = tail = new hola(data, head, tail);
	}
	Size++;
};

void List::pop_front()
{
	if (Size > 1)
	{
		hola* deletehola = head;
		head = head->next;
		delete deletehola;
	}
	else if (Size == 1)
	{
		hola* deletehola = head;
		tail = head = head->next;
		delete deletehola;
	}

	Size--;
}

void List::pop_back()
{
	if (Size > 1)
	{
		hola* deletehola = tail;
		tail = tail->prev;
		delete deletehola;
	}
	else if (Size == 1)
	{
		hola* deletehola = tail;
		tail = head = tail->prev;
		delete deletehola;
	}

	Size--;
}

void List::find_head(int data)
{
	bool band = false;  //lo creamos para despues vwer si la se encontro el elemnto es verdad pero si no es falso
	hola* nuevo_hola = head;  //crear un nuevo nodo nuevo ukasatel
	nuevo_hola = head;  //se encarga de señalar a head al comiezo de la lista

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

void List::find_tail(int data)
{
	bool band = false;  //lo creamos para despues vwer si la se encontro el elemnto es verdad pero si no es falso
	hola* nuevo_hola = tail;  //crear un nuevo nodo nuevo ukasatel
	nuevo_hola = tail;  //se encarga de señalar a head al comiezo de la lista

	while ((nuevo_hola != NULL) && (nuevo_hola->data <= data)) //significa que el nodo es dirente de cero entonces hay elemtos en la lista y el otro si el numero es menor a n osea el numero a buscar
	{
		if (nuevo_hola->data == data)  //si el nievo nodo es igual al numero entonces la se encontro el numero
		{
			band = true; //dice que elemento si exiate
		}
		nuevo_hola = nuevo_hola->prev; //si el dato no es igual significa que se apunta a la sig posisicon en la lista para buscarlo ahi
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

void List::insert_by_index(int data, int index)
{
	if (index == 0) push_front(data);

	else if (index == Size || index > Size) push_back(data);

	else if (index <= Size / 2)
	{
		hola * previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		hola * nuevo_hola = new hola (data, previous->next, previous);

		previous->next = nuevo_hola;
		hola * next1 = nuevo_hola->next;
		next1->prev = nuevo_hola;

		Size++;
	}

	else if (index > Size / 2)
	{
		hola* next1 = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next1 = next1->prev;
		}

		hola* nuevo_hola = new hola(data, next1, next1->prev);

		next1->prev = nuevo_hola;
		hola * previous = nuevo_hola->prev;
		previous->next = nuevo_hola;

		Size++;
	}
}

void List::pop_by_index(int index)
{
	if (index == 0) pop_front();

	else if (index == Size || index > Size) pop_back();

	else if (index <= Size / 2)
	{
		hola * previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		hola * deletehola = previous->next;
		previous->next = deletehola->next;
		hola* next1 = deletehola->next;
		delete deletehola;
		next1->prev = previous;

		Size--;
	}

	else if (index > Size / 2)
	{
		hola* next1 = this->tail;
		for (int i = Size - 1; index < i; i--)
		{
			next1 = next1->prev;
		}

		hola* deletehola = next1->prev;
		next1->prev = deletehola->prev;
		hola* previous = deletehola->prev;
		delete deletehola;
		previous->next = next1;

		Size--;
	}
}

int& List::operator[] (const int index)
{
	if (index <= Size / 2)
	{
		int counter = 0;
		hola* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
				return current->data;
			current->next;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;
		hola* current = this->tail;

		while (current != nullptr)
		{
			if (counter == index) return current->data;
			current->prev;
			counter--;
		}
	}
}

void List::showFromHead()
{
	hola* nuevo_hola = head;    //crear un  nuevo nodo ucasatel
	nuevo_hola = head;  //se hace para que la lista se empiece a rrecorrer desde el comiezo
	if (nuevo_hola == NULL)
	{
		cout << "the list is empty---lista vacia" << endl;
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

void List::showFromTail()
{
	hola* nuevo_hola = tail;    //crear un  nuevo nodo ucasatel
	nuevo_hola = tail;  //se hace para que la lista se empiece a rrecorrer desde el comiezo
	if (nuevo_hola == NULL)
	{
		cout << "the list is empty---lista vacia" << endl;
	}
	else
	{
		cout << "list ";
		while (nuevo_hola != NULL) //si la lista es diferente de cero, sigue mestrando datos de la lista
		{

			cout << nuevo_hola->data << "->";
			nuevo_hola = nuevo_hola->prev;  //para que se siga moviendo de un espacio a otro
		}

		cout << endl;
	}
}

//int main()
//{
//	List lst;
//	cout << "list" << endl;
//	lst.push_back(8);
//	lst.insert_by_index(1, 0);
//	lst.insert_by_index(2, 1);
//	lst.insert_by_index(4, 2);
//	lst.insert_by_index(5, 3);
//	lst.insert_by_index(6, 4);
//	lst.insert_by_index(7, 5);
//	lst.push_front(0);
//	cout << "show list from head" << endl;
//	lst.showFromHead();
//	cout << "show list from tail" << endl;
//	lst.showFromTail();
//	cout << "delete" << endl;
//	/*lst.pop_back();*/
//	lst.pop_by_index(3);
//	/*lst.pop_front();*/
//
//	lst.find_head(6);
//	lst.find_tail(6);
//
//	cout << "show list from head" << endl;
//	lst.showFromHead();
//
//	cout << "show list from Tail" << endl;
//	lst.showFromTail();
//
//
//	return 0;
//}

int main()
{
	List l;
	int x, data, data2, index;
	do
	{
		cout << "\t. -----MENU---- .\n";
		cout << "1. -push back element---agregar elemento en la cola\n";
		cout << "2. -push front element---agregar elemento en el frente\n";
		cout << "3. -inser element by index---insertar elelemnto por index\n";
		cout << "4. -delete by index\n";
		cout << "5. -show list from head--- mostrar lista\n";
		cout << "6. -show list from tail--- mostrar lista\n";
		cout << "7. -find element\n";
		cout << "8. -delete all\n";
		cout << "9. -salir---Exit\n";
		cin >> x;

		switch (x)
		{
		case 1: cout << "push back:--enter a number: ";
			cin >> data;
    		l.push_back(data);   //llamar la lista
			cout << "\n";
			cout << data << "  has been added";
			cout << endl;
			break;

		case 2: cout << "push front--enter a number: ";
			cin >> data2;
			l.push_front(data2);   //llamar la lista
			cout << "\n";
			cout << data2 << "  has been added";
			cout << endl;
			
			break;

		case 3: cout << "insert for index-- enter a number: ";
			cin >> data;
			cout << "enter the index: ";
			cin >> index;
			l.insert_by_index(data, index);
			cout << "\n";
			cout << data << "  has been added";
			cout << endl;
			break;

	
		case 4: cout << "delete for index-- enter the index: ";
			cin >> index;
			l.pop_by_index(index);
			cout << "the element has been deleted";
			cout << "\n";
			cout << endl;
			break;

		case 5: cout << "show elements from head" << endl;
			l.showFromHead();
			cout << endl;//para que no desaparesaca la infomacion
			break;

		case 6: cout << "show elements from tail" << endl;
			l.showFromTail();
			cout << endl;//para que no desaparesaca la infomacion
			break;

		case 7: cout << "find element" << endl;
			cout << "enter the number: ";
			cin >> data2;
			l.find_head(data2);
			cout << endl;//para que no desaparesaca la infomacion
			break;

		case 8:
			l.clear();
			cout << "the elements have been deleted from the list" << endl;
			cout << " the list is empty!"<<endl;
			system("pause");   //para que no desaparesaca la infomacion
			break;

		}

	} while (x != 9);
	cout << "made by julian Poveda B8119-10.03.01 -kzoin" << endl;
	system("pause");
}
