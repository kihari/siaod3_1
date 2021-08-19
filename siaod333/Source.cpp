#include <iostream>
using namespace std;

//����
struct Node
{
    double data; //���� ������
    Node* prev; //��������� ���� Node �� ���������� �������
    Node* next; //��������� ���� Node �� ��������� �������
};

//��������� ��� ������������ ������ ������
Node* head = NULL;
//��������� ��� ������������ ����� ������
Node* tail = NULL;
Node* Curr = NULL;

//������� ��� �������� ������� ������
bool isempty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

//�������� ������ �� ��������� ����� 
void pushList(int SIZE)
{
    int i = 0;
    while (i < SIZE)
    {
        // ������ ����� ����
        Curr = new Node();
        Curr->data = (rand() % 901 + 100)/100.0;
        Curr->prev = NULL;
        Curr->next = NULL;

        //�������� ����� ����
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
//������ ������
void PrintList()
{
    if (isempty())
        cout << "\n������ ������\n";
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
//�������� ������
void pop()
{
    if (isempty())
        cout << "\n������ ������\n";
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
        cout << "\n������ ������\n";
    else
    {
        if (isempty()) cout << "\n������ ������\n";
        Node* temp = tail;// ���������, ��� ��� ����� �����
        tail = tail->prev;// ���������� ����� ������� �����
        tail->next = NULL;// ����������, ��� ������� �� ������� �����
        delete temp;
    }
}
void LargestInDLL(Node** head)
{
    if (isempty())
        cout << "\n������ ������\n";
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
        cout <<"���������� �������: "<< max->data<<endl;
    }
}
void pushsh(int n, int pos, double SIZE)
{
    if (isempty())
        cout << "\n������ ������\n";
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
            else cout << "\n�������������� �������";
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
        cout << "\n1.������� ������";
        cout << "\n2.������� ������";
        cout << "\n3.������ ������";
        cout << "\n4.�������� �������";
        cout << "\n5.�������� �������� � ����� ������";
        cout << "\n6.����� ����������� ��������";
        cout << "\n7.�����\n";
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
            cout << "�������� ������ ��������: ";
            cin >> N;
            cout << "����� ������ ��������: ";
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