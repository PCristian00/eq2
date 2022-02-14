#include <iostream>
using namespace std;

struct element{
    int value;
    element* next;
};
typedef element* list;

bool isOrdered(list& inz){
    list p,q;
    for(q=inz;q!=0;q=q->next) {
        for (p = q; p != 0; p = p->next) {

            if (p->value < q->value) return false;
        }
    }
    return true;
}

list creaLista(int n) {
    list p, p0 = 0;
    for (int i = 1; i <= n; i++) {
        p = new element; //Crea nuovo elem
        cout << "INSERIRE VALORE " << i << "/" << n << endl;
        cin >> p->value; //Inserisce elem nella lista
        p->next = p0;
        p0 = p;
    }
    return p0;
}

void ordinaLista(list &inz) {
    list q, p;
    double temp; //Variabile di memorizzazione temporanea valore
    for (q = inz; q != 0; q = q->next) //Ricerca a due indici
        for (p = q; p != 0; p = p->next)
            if (q->value > p->value) { //Se q > p scambia di posto
                temp = q->value;
                q->value = p->value;
                p->value = temp;
            }
}

void stampaLista(list &inz) {
    list p;



    //Se la lista è vuota non stampa statistiche
    if (inz == 0) {
        cout << "LISTA VUOTA" << endl;
        return;
    }

    for (p = inz; p != 0; p = p->next) { //Per ogni elemento della lista

        cout << p->value << '\t'; //Stampa l'elemento
    }
    cout<<endl;
}

int main(){
    list inizio;
    int n;
    cout << "Quanti valori vuoi inserire nella lista per iniziare? (0 per passare al MENU)" << endl;
    cin >> n;
    if (n != 0) { //Possibilità di saltare la fase di creazione
        inizio = creaLista(n);
        stampaLista(inizio);
        if(isOrdered(inizio)==true) cout<<"CRESCENTE"<<endl;
        else cout<<"NON CRESCENTE"<<endl;

        ordinaLista(inizio);
        stampaLista(inizio);

        if(isOrdered(inizio)==true) cout<<"CRESCENTE"<<endl;
        else cout<<"NON CRESCENTE"<<endl;
    }
}