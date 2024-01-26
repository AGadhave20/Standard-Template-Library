// Doubly linear
#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> * First;
        int Count;

    public:
        DoublyLL();

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
DoublyLL<T> :: DoublyLL()
{
   First = NULL;
   Count = 0;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL))
    {
        First = newn;
    } 
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    struct node<T> * Temp = First;
    struct node<T> * newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL))
    {
        First = newn;
    } 
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
    }
    Count++;
}

template <class T>
int DoublyLL<T>:: CountNode()
{

    return Count;
}

template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(((First->next) == NULL) && ((First->prev) == NULL))
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete(First->prev);
        First->prev = NULL;
        Count--;
    }

}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> * Temp = First;
    if(First == NULL)
    {
        return;
    }
    else if(((First->next) == NULL) && ((First->prev) == NULL))
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        delete(Temp->next);
        Temp->next = NULL;
        Count--;
    }
}

template <class T>
void DoublyLL<T>:: Display()
{
    struct node<T> * Temp = First;
    cout<<"Contents of linked list are:\n";
    cout<<"NULL->";

    while(Temp != NULL)
    {
        cout<<"| "<<Temp->data<<" | ->";
        Temp = Temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int iPos)
{
    struct node<T> * newn = NULL;
    struct node<T> * Temp = First;

    if((iPos<1) || (iPos>(Count+1)))
    {
        printf("Invalid Position\n");
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
        newn->prev = NULL;      

        for(int i=1;i<iPos-1;i++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next->prev = newn;      
        Temp->next = newn;
        newn->prev = Temp; 
        Count++;          
    }

}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    struct node<T> * Temp = First;

    if((iPos<1) || (iPos>(Count)))
    {
        printf("Invalid Position\n");
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
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp; 
        Count--;          
    }
}

int main()
{
    DoublyLL <int>iobj;
    DoublyLL <float>fobj;
    DoublyLL <double>dobj;
    DoublyLL <char>cobj;

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