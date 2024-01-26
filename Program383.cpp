// Singly circular
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> * First;
        struct node<T> * Last;
        int Count;

    public:
        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int iPos);
        void DeleteAtPos(int iPos);
};

/*
Return Value class Name :: function name()
{

}
*/
template <class T>
SinglyCL<T> :: SinglyCL()
{
   First = NULL;
   Last = NULL;
   Count = 0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    Count++;
}


template <class T>
void SinglyCL<T>:: InsertLast(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    Count++;
}

template <class T>
void SinglyCL<T> :: Display()
{
    cout<<"Contents of linked list are:\n";
    
    if((First != NULL) && (Last != NULL))
    {
        do
        {
            cout<<"| "<<First->data<<" | ->";
            First = First->next;
        }while(First != Last->next);
        cout<<" \n";
    }
}

template <class T>
int SinglyCL<T> :: CountNode()
{

    return Count;
}

template <class T>
void SinglyCL<T>:: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete (Last->next);
        Last->next = First;
    }
    Count--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct node<T> * Temp = First;

    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while(Temp->next != Last)
        {
            Temp = Temp->next;
        }
        delete Last;
        Last = Temp;
        Last->next = First;
    }
    Count--;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no,int iPos)
{
    struct node<T> * newn = NULL;

    struct node<T> * Temp = First;
    
    if((iPos<1) || (iPos>Count+1))
    {
        printf("Invalid position\n");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        for(int i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
        Count++;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    struct node<T> * Temp = First;
    struct node<T> * targetednode = NULL;

    if((iPos<1) || (iPos>Count))
    {
        printf("Invalid position\n");
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Count)
    {
        DeleteLast();
    }
    else
    {
        for(int i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        targetednode = Temp->next;
        Temp->next = Temp->next->next;
        delete(targetednode);
    }
}

int main()
{
    SinglyCL <int>iobj;
    SinglyCL <float>fobj;
    SinglyCL <double>dobj;
    SinglyCL <char>cobj;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);

    cout<<"Linked list of integers:"<<"\n";
    iobj.Display();

    fobj.InsertLast(11.5);
    fobj.InsertLast(21.2);
    fobj.InsertLast(51.2);
    fobj.InsertLast(101.5);

    cout<<"Linked list of floats:"<<"\n";
    fobj.Display();

    dobj.InsertLast(11.5555);
    dobj.InsertLast(21.2222);
    dobj.InsertLast(51.23333);
    dobj.InsertLast(101.5122);

    cout<<"Linked list of doubles:"<<"\n";
    dobj.Display();

    cobj.InsertLast('a');
    cobj.InsertLast('b');
    cobj.InsertLast('c');
    cobj.InsertLast('d');

    cout<<"Linked list of characters:"<<"\n";
    cobj.Display();

    return 0;
}