#include <iostream>
using namespace std;

//Узел
struct Node
{
    double data; //Поле данных
    Node* prev; //Указатель типа Node на предыдущий элемент
    Node* next; //Указатель типа Node на следующий элемент
};

//Указатель для отслеживания начала списка
Node* head = NULL;
//Указатель для отслеживания конца списка
Node* tail = NULL;
Node* Curr = NULL;

//Функция для проверки пустоты списка
bool isempty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

//Создание списка из случайных чисел 
void pushList(int SIZE)
{
    int i = 0;
    while (i < SIZE)
    {
        // Создаю новый узел
        Curr = new Node();
        Curr->data = (rand() % 901 + 100)/100.0;
        Curr->prev = NULL;
        Curr->next = NULL;

        //Заполняю новый узел
        if (head == NULL) head = tail = Curr;
        else
        {
            tail->next = Curr;
            Curr->prev = tail;
            tail = Curr;
        }
        i++;
    }
}
//Печать списка
void PrintList()
{
    if (isempty())
        cout << "\nСписок пустой\n";
    else
    {
        Curr = head;
        for (int i=0;Curr;i++)
        {
            cout <<i<<". "<< (double)Curr->data << endl;
            Curr = Curr->next;
        }
    }
}
//Удаление списка
void pop()
{
    if (isempty())
        cout << "\nСписок пустой\n";
    else
    {
        Curr = tail;
        while (Curr)
        {
            Node* tmp = Curr;
            Curr = Curr->next;
            delete tmp;
        }
        head = tail = NULL;
    }
}
void deleteelem()
{
    if (isempty())
        cout << "\nСписок пустой\n";
    else
    {
        if (isempty()) cout << "\nСписок пустой\n";
        Node* temp = tail;// Указываем, что нам нужен хвост
        tail = tail->prev;// Отодвигаем хвост немного назад
        tail->next = NULL;// Обозначаем, что впереди за хвостом пусто
        delete temp;
    }
}
void LargestInDLL(Node** head)
{
    if (isempty())
        cout << "\nСписок пустой\n";
    else
    {
        struct Node* max, * temp;
        temp = max = *head;
 
        while (temp != NULL)
        {
            if (temp->data > max->data)
                max = temp;

            temp = temp->next;
        }
        cout <<"Наибольший элемент: "<< max->data<<endl;
    }
}
void pushsh(int n, int pos, double SIZE)
{
    if (isempty())
        cout << "\nСписок пустой\n";
    else
    {
        Node* temp, * s;
        temp = new Node;
        temp->data = n;
        s = head;
        int count = 1, flag = 1;
        if (pos == 1)
        {
            temp->data = n;
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else if (pos == SIZE)
        {
            temp->prev = tail;
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
        }
        else
        {
            while (count != pos)
            {
                s = s->next;
                if (s == NULL)
                {
                    flag = 0;
                    break;
                }
                count++;
            }
            if (flag == 1)
            {
                temp->next = s->next;
                s->next->prev = temp;
                s->next = temp;
                temp->prev = s;
            }
            else cout << "\nНесуществующая позиция";
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int choice, flag = 1;
    const double size=9;
    int N;
    int posiciya;
    int Curr;
    while (flag == 1)
    {
        cout << "\n1.Создать список";
        cout << "\n2.Удалить список";
        cout << "\n3.Печать списка";
        cout << "\n4.Добавить элемент";
        cout << "\n5.Удаление элемента с конца списка";
        cout << "\n6.Поиск наибольшего элемента";
        cout << "\n7.Выход\n";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1: pushList(size);
            PrintList();
            break;
        case 2: pop();
            break;
        case 3: PrintList();
            break;
        case 4:
            cout << "Значение нового элемента: ";
            cin >> N;
            cout << "Место нового элемента: ";
            cin >> posiciya;
            pushsh(N, posiciya,size);
            PrintList();
            break;
        case 5: deleteelem();
            PrintList();
            break;
        case 6: LargestInDLL(&head);
            break;
        case 7: flag = 0;
            break;
        }
    }
    return 0;
}