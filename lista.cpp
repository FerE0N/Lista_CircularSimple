#include <iostream>
using namespace std;

template <typename T>
class Nodo {
    T dato;
    Nodo *next;
public:
    Nodo(T dato) {
        this->dato = dato;
        this->next = nullptr;
    }

    T getDato() {
        return this->dato;
    }

    void setDato(T dato) {
        this->dato = dato;
    }

    Nodo* getNext() {
        return this->next;
    }

    void setNext(Nodo* next) {
        this->next = next;
    }
};

template <typename T>
class ListaCircular {
    Nodo<T>* head;
    int size;
public:
    ListaCircular() {
        head = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    void agregarInicio(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!head) {
            head = nuevo;
            nuevo->setNext(head);
        } else {
            Nodo<T>* temp = head;
            while (temp->getNext() != head) {
                temp = temp->getNext();
            }
            nuevo->setNext(head);
            temp->setNext(nuevo);
            head = nuevo;
        }
        size++;
    }

    void agregarFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!head) {
            head = nuevo;
            nuevo->setNext(head);
        } else {
            Nodo<T>* temp = head;
            while (temp->getNext() != head) {
                temp = temp->getNext();
            }
            temp->setNext(nuevo);
            nuevo->setNext(head);
        }
        size++;
    }

    void eliminarInicio() {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* temp = head;
        if (head->getNext() == head) {
            head = nullptr; // Si solo hay un nodo
        } else {
            Nodo<T>* last = head;
            while (last->getNext() != head) {
                last = last->getNext();
            }
            head = head->getNext();
            last->setNext(head); // Último nodo apunta al nuevo head
        }
        delete temp;
        size--;
    }

    void eliminarFinal() {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo<T>* temp = head;
        if (head->getNext() == head) {
            head = nullptr; // Si solo hay un nodo
        } else {
            Nodo<T>* prev = nullptr;
            while (temp->getNext() != head) {
                prev = temp;
                temp = temp->getNext();
            }
            prev->setNext(head); // El penúltimo nodo apunta al head
        }
        delete temp;
        size--;
    }

    void eliminarPorValor(T valor) {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return;
        }

        Nodo<T>* temp = head;
        Nodo<T>* prev = nullptr;

        // Caso especial: si el valor está en el head
        if (head->getDato() == valor) {
            eliminarInicio();
            return;
        }

        do {
            prev = temp;
            temp = temp->getNext();
        } while (temp != head && temp->getDato() != valor);

        if (temp == head) {
            cout << "Valor no encontrado en la lista." << endl;
        } else {
            prev->setNext(temp->getNext());
            delete temp;
            size--;
        }
    }

    void imprimirLista() {
        if (!head) {
            cout << "La lista está vacía" << endl;
            return;
        }
        Nodo<T>* current = head;
        do {
            cout << current->getDato() << " -> ";
            current = current->getNext();
        } while (current != head);
        cout << "HEAD" << endl;
    }
};

int main() {
    ListaCircular<int> lista;
    int opcion, valor;

    do {
        cout << "\nMenu de Lista Circular:" << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Eliminar al inicio" << endl;
        cout << "4. Eliminar al final" << endl;
        cout << "5. Eliminar por valor" << endl;
        cout << "6. Imprimir lista" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el valor a agregar al inicio: ";
            cin >> valor;
            lista.agregarInicio(valor);
            break;
        case 2:
            cout << "Ingrese el valor a agregar al final: ";
            cin >> valor;
            lista.agregarFinal(valor);
            break;
        case 3:
            lista.eliminarInicio();
            break;
        case 4:
            lista.eliminarFinal();
            break;
        case 5:
            cout << "Ingrese el valor a eliminar: ";
            cin >> valor;
            lista.eliminarPorValor(valor);
            break;
        case 6:
            lista.imprimirLista();
            break;
        case 7:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida, intente de nuevo." << endl;
        }
        lista.imprimirLista();
    } while (opcion != 7);

    return 0;
}
