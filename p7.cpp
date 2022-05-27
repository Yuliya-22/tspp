/*
#include <iostream>
#include <string>
using namespace std;

class Client {
    string plan;
    int balance;
    int entra;
public:
    void prosmP();
    void prosmB();
    void transP();
    void transB();
    void transE();
    void createZay();
};

void Client::prosmP() {
    cout << "Текущий тарифный план: " << plan << endl;
}

void Client::prosmB() {
    cout << "Текущий баланс: " << balance << endl;
}

void Client::transP() {
    system("cls");
    cout << "Выберите новый тарифный план из списка: " << endl;
    cout << "1 - МТС" << endl;
    cout << "2 - Волна" << endl;
    cout << endl;
    cout << "3 - Назад" << endl;
    cout << endl;
    cout << "Новый тариф: " << endl;
    int key;
    cin >> key;
    while (1) {
        switch (key) {
        case 1:
            plan = "МТС";
            system("cls");
            cout << "Тариф изменён" << endl;
        break;
        case 2:
            plan = "Волна";
            system("cls");
            cout << "Тариф изменён" << endl;
        break;
        case 3:
            return;
        default:
            cout << "Выберите один из предложенных пунктов" << endl;
            break;
        }
    }
}

void Client::transB() {
    system("cls");
    cout << "Текущий баланс: " << balance << endl;
    cout << "Сумма перевода: ";
    int per;
    cin >> per;
    //а здесь функция, которая снимает деньг с картточки клиента
    balance = balance + per;
    cout << endl;
    cout << "Счёт пополнен";
}

void Client::transE() {
    entra = 0;
}

void Client::createZay() {

}



int main() {
    setlocale(LC_ALL, "rus");



    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class Clientt {
    int ID;
    char* tarif;
    int balance;
    int entra;
public:
    Clientt* next;
    Clientt(int i) { ID = i;  tarif = (char*)"Volna", balance = 0; entra = 1; };
    int getID() { return ID; };
    char* getT() { return tarif; };
    int getB() { return balance; };
    void traT(char* nT) { tarif = nT; };
    void traB(int per) { balance = balance + per; };
    void traE(int fl) { entra = fl; };
};

class Basse {
    Clientt* beg;
    Clientt* end;
    int count;
    int Pod;
    int Otk;
public:
    Basse() { beg = NULL; end = NULL; };
    void dob(int i);
    void otc(int i);
    void prin();
    void prosmT(int i);
    void prosmB(int i);
    void traT(char* nT, int i);
    void traE(int fl, int i);
    int stat();
};

void Basse::dob(int i) {
    Clientt* n = new Clientt(i);
    n->next = NULL;
    if (!beg) {
        beg = n;
        end = n;
    }
    else {
        end->next = n;
        end = end->next;
    }
    count++;
    Pod++;
}

void Basse::otc(int i) {
    Clientt* temp = beg;
    int fl = 0;
    if (temp->getID() == i) {
        beg = beg->next;
        delete(temp);
    }
    else {
        while (temp) {
            if (temp->next->getID() == i) {
                fl++;
                break;
            }
            temp = temp->next;
        }
        if (fl) {
            Clientt* ttemp = temp->next;
            temp->next = temp->next->next;
            delete(ttemp);
        }
    }
    count--;
    Otk++;
}

void Basse::prin() {
    Clientt* temp = beg;
    while (temp) {
        cout << temp->getID() << endl;
        temp = temp->next;
    }
}

void Basse::prosmT(int i) {
    Clientt* temp = beg;
    int fl = 0;
    char* r;
    while (temp) {
        if (temp->getID() == i) {
            fl++;
            r = temp->getT();
            cout << r;
            break;
        }
        temp = temp->next;
    }
    if (!fl)
        cout << "Нет такого";
}

void Basse::prosmB(int i) {
    Clientt* temp = beg;
    int fl = 0;
    while (temp) {
        if (temp->getID() == i) {
            fl++;
            break;
        }
        temp = temp->next;
    }
    if (fl)
        cout << temp->getB();
    else
        cout << "Нет такого";
}

void Basse::traT(char* nT, int i) {
    Clientt* temp = beg;
    int fl = 0;
    while (temp) {
        if (temp->getID() == i) {
            fl++;
            break;
        }
        temp = temp->next;
    }
    if (fl)
        temp->traT(nT);
    else
        cout << "Нет такого";
}

void Basse::traE(int n, int i) {
    Clientt* temp = beg;
    int fl = 0;
    while (temp) {
        if (temp->getID() == i) {
            fl++;
            break;
        }
        temp = temp->next;
    }
    if (fl)
        temp->traE(n);
    else
        cout << "Нет такого";
}

int Basse::stat() {
    return count;
}

struct Zay {
    char* content;
    int ID;
    Zay* next;
};

class CatZay {
    Zay* Pbeg;
    Zay* Pend;
    Zay* Nbeg;
    Zay* Nend;
public:
    CatZay() { Pbeg = NULL; Pend = NULL; Nbeg = NULL; Nend = NULL; };
    void dobP(char* co, int i);
    void dobN(char* co, int i);
//    char* vivP(Zay* uk);
//    char* vivN(Zay* uk);
    void prinP();
    void prinN();
    void delAlP();
    void delAlN();
    ~CatZay() { delAlP(); delAlN(); };
};

void CatZay::dobP(char* co, int i) {
    Zay* n = new Zay;
    n->content = co;
    n->ID = i;
    n->next = NULL;
    if (!Pbeg) {
        Pbeg = n;
        Pend = n;
    }
    else {
        Pend->next = n;
        Pend = Pend->next;
    }
};

void CatZay::dobN(char* co, int i) {
    Zay* n = new Zay;
    n->content = co;
    n->ID = i;
    n->next = NULL;
    if (!Nbeg) {
        Nbeg = n;
        Nend = n;
    }
    else {
        Nend->next = n;
        Nend = Nend->next;
    }
};

/*
char* CatZay::vivP(Zay* uk) {
    char* rez = uk->content;
    strcat(rez, (char*)uk->ID);
    return rez;
}

char* CatZay::vivN(Zay* uk) {
    char* rez = uk->content;
    strcat(rez, uk->ID);
    return rez;
}
*/

void CatZay::prinP() {
    Zay* temp = Pbeg;
    char* rez;
    while (temp) {
        cout << "ID: " << temp->ID << ", Содержжание: " << temp->content << endl;
        temp = temp->next;
    }
}

void CatZay::prinN() {
    Zay* temp = Nbeg;
    char* rez;
    while (temp) {
        cout << "ID: " << temp->ID << ", Содержжание: " << temp->content << endl;
        temp = temp->next;
    }
}

void CatZay::delAlP() {
    Zay* temp = Pbeg;
    Zay* ttemp;
    while (temp) {
        ttemp = temp->next;
        delete(temp);
        temp = ttemp;
    }
    Pbeg = NULL; Pend = NULL;
}

void CatZay::delAlN() {
    Zay* temp = Nbeg;
    Zay* ttemp;
    while (temp) {
        ttemp = temp->next;
        delete(temp);
        temp = ttemp;
    }
    Nbeg = NULL; Nend = NULL;
}

int main() {
    setlocale(LC_ALL, "rus");
    Basse Basa;
    CatZay Catalog;

    Basa.dob(2);
    Basa.dob(3);

    cout << "Просмотрим текущую базу клиентов: \n";
    Basa.prin();
    cout << endl;

    cout << "Выберите клиента (введите его ID): ";
    int i;
    cin >> i;
    cout << "Тариф клиента: ";
    Basa.prosmT(i);
    cout << endl;
    cout << "Баланс клиента: ";
    Basa.prosmB(i);
    cout << endl;
    cout << "Изменим тариф клиента ";
    Basa.traT((char*)"MegaHit", i);
    cout << endl;
    cout << "Его новый тариф: ";
    Basa.prosmT(i);
    cout << endl;

    cout << "Заблокируем текущего клиента " << endl;
    Basa.traE(0, i);
    cout << endl;

    cout << "Отправим заявку о неисправности от другого клиента";
    Catalog.dobN((char*)"biada", 3);
    cout << endl;
    cout << "Просмотрим каталог заявок о неисправности:\n";
    Catalog.prinN();
    cout << endl;
    cout << "Очистим каталог заявок о неисправности:\n";
    Catalog.delAlN();
    cout << "Просмотрим каталог заявок о неисправности:\n";
    Catalog.prinN();
    cout << endl;
    cout << "Отправим заявку на подключение от другого клиента";
    Catalog.dobP((char*)"oraoraora", 4);
    cout << endl;
    cout << "Просмотрим каталог заявок на подключение:\n";
    Catalog.prinP();
    cout << endl;

    cout << "Подключим клиента из последней заявки\n";
    Basa.dob(4);
    cout << endl;
    cout << "Просмотрим текущую базу клиентов: \n";
    Basa.prin();
    cout << endl;
    cout << "Выберите клиента, чтобы отключить: ";
    cin >> i;
    Basa.otc(i);
    cout << "Просмотрим текущую базу клиентов: \n";
    Basa.prin();
    cout << endl;

    cout << "Просмотрим статистику: \n";
    int ry = Basa.stat();
    cout << "Количество клиентов: " << ry;

    return 0;
}