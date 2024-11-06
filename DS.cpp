#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear,Stack,Queue and singly circular Linked List

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular Linked List

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
public:
    struct NodeS<T> *first;
    int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int Frequency(T);
    T Maximum();
    T Minimum();
    T Summation();
    T Average();  
};

////////////////////////////////////////////////////////////
// 
//  Constructor Name : SinglyLL
//  Input : None
//  Output : None
//  Description : Initializes a new Singly Linear Linked list with no elements.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Input : None
//  Output : void
//  Description : Displays the elements of a Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
    cout << "Elements of Singly Linear Linked list are : "
         << "\n";

    NodeS<T> *temp = first;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Count
//  Input : None
//  Output : int
//  Description : Returns the Count of elements present in Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :   July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertFirst
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the beginning of the Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the end of the Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteFirst
//  Input : None
//  Output : void
//  Description : Deletes the first node from the Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteLast
//  Input : None
//  Output : void
//  Description : Deletes the last node from the Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertAtPos
//  Input : T (template parameter), int (iPos)
//  Output : void
//  Description : Inserts a new node with the given value at the specified position in the Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteAtPos
//  Input : int (iPos)
//  Output : void
//  Description : Delete a node at the specified position in the Singly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchFirstOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the first occurrence of the given value in the Singly Linear Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::SearchFirstOcc(T no)
{
    int iCnt=0; 
    int iFirstOccurance =-1;
    NodeS<T> *temp = first;
    while(temp!=NULL)
    {
        if(no == temp->data)
        {
            iFirstOccurance = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }
    return iFirstOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchLastOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the last occurrence of the given value in the Singly Linear Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::SearchLastOcc(T no)
{
    int iCnt=0; 
    int iLastOccurance =-1;
    NodeS<T> *temp = first;
    while(temp!=NULL)
    {
        if(no == temp->data)
        {
            iLastOccurance = iCnt;
            
        }
        iCnt++;
        temp = temp->next;
    }
    return iLastOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Frequency
//  Input : T (template parameter)
//  Output : int
//  Description : Counts the frequency of the given value in the Singly Linear Linked list and returns the count.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Frequency(T no)
{
    int iCnt=0; 
    NodeS<T> *temp = first;
    while(temp!=NULL)
    {
        if(no == temp->data)
        {
           iCnt++;
            
        }
        temp = temp->next;
    }
    return iCnt;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Maximum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the maximum value in the Singly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::Maximum()
{
    
    NodeS<T> *temp = first;
    T Max = temp->data; 
    while(temp!=NULL)
    {
        if(Max < temp->data)
        {
            Max = temp->data;   
        }
        temp = temp->next;
    }
    return Max;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Minimum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the minimum value in the Singly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::Minimum()
{

    NodeS<T> *temp = first;
    T Min = temp->data; 
    while(temp!=NULL)
    {
        if(Min > temp->data)
        {
            Min = temp->data;   
        }
        temp = temp->next;
    }
    return Min;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Summation
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the summation of all elements in the Singly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::Summation()
{

    T Sum =0;
    NodeS<T> *temp = first;
     
    while(temp!=NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Average
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the average of all elements in the Singly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::Average()
{
    T Sum=0;
    NodeS<T> *temp = first;
     
    while(temp!=NULL)
    {
        Sum = Sum+temp->data;
        temp = temp->next;
    }
    if(iCount==0)
    {
        return 0;
    }
    return Sum/iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
public:
    struct NodeS<T> *first;
    struct NodeS<T> *last;
    int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int Frequency(T);
    T Maximum();
    T Minimum();
    T Summation();
    T Average();
};

////////////////////////////////////////////////////////////
// 
//  Constructor Name : SinglyLL
//  Input : None
//  Output : None
//  Description : Initializes a new Singly Circular Linked list with no elements.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Input : None
//  Output : void
//  Description : Displays the elements of a Singly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::Display()
{
    cout << "Elements of Singly Circular List are : "
         << "\n";
    if (first != NULL && last != NULL)
    {
        NodeS<T> *temp = first;
        do
        {
            cout << "| " << temp->data << "| -> ";
            temp = temp->next;
        } while (temp != last->next);

        cout << "\n";
    }
    else
    {
        cout << "Linked List is empty"
             << "\n";
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Count
//  Input : None
//  Output : int
//  Description : Returns the Count of elements present in Singly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :   July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertFirst
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the beginning of the Singly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the end of the Singly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteFirst
//  Input : None
//  Output : void
//  Description : Deletes the first node from the Singly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteLast
//  Input : None
//  Output : void
//  Description : Deletes the last node from the Singly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertAtPos
//  Input : T (template parameter), int (iPos)
//  Output : void
//  Description : Inserts a new node with the given value at the specified position in the Singly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *temp = first;
        NodeS<T> *newn = new NodeS<T>;

        newn->data = no;
        newn->next = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteAtPos
//  Input : int (iPos)
//  Output : void
//  Description : Delete a node at the specified position in the Singly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp1 = first;
        NodeS<T> *temp2 = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchFirstOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the first occurrence of the given value in the Singly Circular Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::SearchFirstOcc(T no)
{
    int iCnt=0; 
    int iFirstOccurance =-1;
    NodeS<T> *temp = first;
    if(temp!=NULL)
    {
         do
        {
            if(no == temp->data)
            {
                iFirstOccurance = iCnt;
                break;
            }
            iCnt++;
            temp = temp->next;
        }while(temp!= last->next);
    }
   
    return iFirstOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchLastOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the last occurrence of the given value in the Singly Circular Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::SearchLastOcc(T no)
{
    int iCnt=0; 
    int iLastOccurance =-1;
   NodeS<T> *temp = first;
   if(temp!=NULL)
    {
        do
        {
            if(no == temp->data)
            {
                iLastOccurance = iCnt;
                
            }
            iCnt++;
            temp = temp->next;
        }while(temp!= last->next);
    }
    return iLastOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Frequency
//  Input : T (template parameter)
//  Output : int
//  Description : Counts the frequency of the given value in the Singly Circular Linked list and returns the count.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int SinglyCL<T>::Frequency(T no)
{
    int iCnt=0; 
    NodeS<T> *temp = first;
    if(temp!=NULL)
    {
        do
        {
            if(no == temp->data)
            {
            iCnt++;
                
            }
            temp = temp->next;
        }while(temp!= last->next);
    }
    return iCnt;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Maximum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the maximum value in the Singly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyCL<T>::Maximum()
{
    
    NodeS<T> *temp = first;
    T Max = temp->data; 
    if(temp!=NULL)
    {
        do
        {
            if(Max < temp->data)
            {
                Max = temp->data;   
            }
            temp = temp->next;
        }while(temp!= last->next);
    }
    return Max;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Minimum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the minimum value in the Singly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyCL<T>::Minimum()
{

    NodeS<T> *temp = first;
    T Min = temp->data; 
    if(temp!=NULL)
    {
        do
        {
            if(Min > temp->data)
            {
                Min = temp->data;   
            }
            temp = temp->next;
        }while(temp!= last->next);
    }
    return Min;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Summation
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the summation of all elements in the Singly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyCL<T>::Summation()
{

    T Sum =0;
    NodeS<T> *temp = first;
    if(temp!=NULL)
    {
        do
        {
            Sum = Sum + temp->data;
            temp = temp->next;
        }while(temp!= last->next);
    }
    return Sum;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Average
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the average of all elements in the Singly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T SinglyCL<T>::Average()
{
    T Sum=0;
    NodeS<T> *temp = first;
    if(temp!=NULL)
    {
    do
    {
        Sum = Sum+temp->data;
        temp = temp->next;
    }while(temp!= last->next);
    }

    return Sum/iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
public:
    struct NodeD<T> *first;
    int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int Frequency(T);
    T Maximum();
    T Minimum();
    T Summation();
    T Average();
};

////////////////////////////////////////////////////////////
// 
//  Constructor Name : DoublyLL
//  Input : None
//  Output : None
//  Description : Initializes a new Doubly Linear Linked list with no elements.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Input : None
//  Output : void
//  Description : Displays the elements of a Doubly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::Display()
{
    NodeD<T> *temp = first;
    cout << "Elements of Doubly Linked List are: "
         << "\n";

    cout << "NULL <=> ";
    for (int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Count
//  Input : None
//  Output : int
//  Description : Returns the Count of elements present in Doubly Linear Linked list
//  Author : Arnav R Tanawade
//  Date :   July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertFirst
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the beginning of the Doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the end of the Doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
        iCount++;
    }
    else
    {
        NodeD<T> *temp = first;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = NULL;
        iCount++;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteFirst
//  Input : None
//  Output : void
//  Description : Deletes the first node from the Doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteLast
//  Input : None
//  Output : void
//  Description : Deletes the last node from the Doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *temp = first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertAtPos
//  Input : T (template parameter), int iPos
//  Output : void
//  Description : Inserts a new node with the given value at the specified position in the Doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    // int iCount = Count();

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteAtPos
//  Input : int iPos
//  Output : void
//  Description : Deletes a node at the specified position in the Doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    //  int iCount = Count();

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchFirstOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the first occurrence of the given value in the Doubly Linear Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::SearchFirstOcc(T no)
{
    int iCnt=0; 
    int iFirstOccurance =-1;
    NodeD<T> *temp = first;
    while(temp!=NULL)
    {
        if(no == temp->data)
        {
            iFirstOccurance = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }
    return iFirstOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchLastOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the last occurrence of the given value in the doubly Linear Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::SearchLastOcc(T no)
{
    int iCnt=0; 
    int iLastOccurance =-1;
   NodeD<T> *temp = first;
    while(temp!=NULL)
    {
        if(no == temp->data)
        {
            iLastOccurance = iCnt;
            
        }
        iCnt++;
        temp = temp->next;
    }
    return iLastOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Frequency
//  Input : T (template parameter)
//  Output : int
//  Description : Counts the frequency of the given value in the doubly Linear Linked list and returns the count.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T>::Frequency(T no)
{
    int iCnt=0; 
    NodeD<T> *temp = first;
    while(temp!=NULL)
    {
        if(no == temp->data)
        {
           iCnt++;
            
        }
        temp = temp->next;
    }
    return iCnt;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Maximum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the maximum value in the doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::Maximum()
{
    
    NodeD<T> *temp = first;
    T Max = temp->data; 
    while(temp!=NULL)
    {
        if(Max < temp->data)
        {
            Max = temp->data;   
        }
        temp = temp->next;
    }
    return Max;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Minimum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the minimum value in the doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::Minimum()
{

    NodeD<T> *temp = first;
    T Min = temp->data; 
    while(temp!=NULL)
    {
        if(Min > temp->data)
        {
            Min = temp->data;   
        }
        temp = temp->next;
    }
    return Min;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Summation
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the summation of all elements in the doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::Summation()
{

    T Sum =0;
    NodeD<T> *temp = first;
     
    while(temp!=NULL)
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }
    return Sum;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Average
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the average of all elements in the doubly Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyLL<T>::Average()
{
    T Sum=0;
    NodeD<T> *temp = first;
     
    while(temp!=NULL)
    {
        Sum = Sum+temp->data;
        temp = temp->next;
    }
    if(iCount==0)
    {
        return 0;
    }
    return Sum/iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
public:
    struct NodeD<T> *first;
    struct NodeD<T> *last;
    int iCount;

    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOcc(T);
    int SearchLastOcc(T);
    int Frequency(T);
    T Maximum();
    T Minimum();
    T Summation();
    T Average();
};

////////////////////////////////////////////////////////////
// 
//  Constructor Name : DoublyCL
//  Input : None
//  Output : None
//  Description : Initializes a new Doubly Circular Linked list with no elements.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
DoublyCL<T>::DoublyCL()
{
    last = NULL;
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Input : None
//  Output : void
//  Description : Displays the elements of a Doubly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> *temp = first;
    cout << "Elements of Doubly Circular List are: "
         << "\n";
    for (int icnt = 1; icnt <= iCount; icnt++)
    {
        cout << "| " << temp->data << " | <-> ";
        temp = temp->next;
    }
    cout << "\n";
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Count
//  Input : None
//  Output : int
//  Description : Returns the Count of elements present in Doubly Circular Linked list
//  Author : Arnav R Tanawade
//  Date :   July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertFirst
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the beginning of the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertLast
//  Input : T (template parameter)
//  Output : void
//  Description : Inserts a new node with the given value at the end of the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = last->next;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteFirst
//  Input : None
//  Output : void
//  Description : Deletes the first node from the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (iCount == 0) 
    {
        return;
    }
    else if (iCount == 1) 
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        first = first->next;
        delete last->next; // delete First->prev;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteLast
//  Input : None
//  Output : void
//  Description : Deletes the last node from the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (iCount == 0) 
    {
        return;
    }
    else if (iCount == 1) 
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else 
    {
        last = last->prev;
        delete last->next;

        first->prev = last;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertAtPos
//  Input : T (template parameter), int iPos
//  Output : void
//  Description : Inserts a new node with the given value at the specified position in the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp = first;
        NodeD<T> *newn = new NodeD<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : DeleteAtPos
//  Input : int iPos
//  Output : void
//  Description : Deletes a node at the specified position in the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;

        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchFirstOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the first occurrence of the given value in the Doubly Circular Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::SearchFirstOcc(T no)
{
    int iCnt=0; 
    int iFirstOccurance =-1;
    NodeD<T> *temp = first;
    if(temp!=NULL)
    {
    do
    {
        if(no == temp->data)
        {
            iFirstOccurance = iCnt;
            break;
        }
        iCnt++;
        temp = temp->next;
    }while(temp!= last->next);
    }
    return iFirstOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : SearchLastOcc
//  Input : T (template parameter)
//  Output : int
//  Description : Searches for the last occurrence of the given value in the Doubly Circular Linked list and returns its position (0-indexed). Returns -1 if the value is not found.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::SearchLastOcc(T no)
{
    int iCnt=0; 
    int iLastOccurance =-1;
   NodeD<T> *temp = first;
   if(temp!=NULL)
    {
    do
    {
        if(no == temp->data)
        {
            iLastOccurance = iCnt;
            
        }
        iCnt++;
        temp = temp->next;
    }while(temp!= last->next);
    }
    return iLastOccurance;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Frequency
//  Input : T (template parameter)
//  Output : int
//  Description : Counts the frequency of the given value in the Doubly Circular Linked list and returns the count.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int DoublyCL<T>::Frequency(T no)
{
    int iCnt=0; 
    NodeD<T> *temp = first;
    if(temp!=NULL)
    {
    do
    {
        if(no == temp->data)
        {
           iCnt++;
            
        }
        temp = temp->next;
    }while(temp!= last->next);
    }
    return iCnt;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Maximum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the maximum value in the Doubly Circular Linear Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyCL<T>::Maximum()
{
    
    NodeD<T> *temp = first;
    T Max = temp->data; 
    if(temp!=NULL)
    {
    do
    {
        if(Max < temp->data)
        {
            Max = temp->data;   
        }
        temp = temp->next;
    }while(temp!= last->next);
    }
    return Max;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Minimum
//  Input : None
//  Output : T (template parameter)
//  Description : Finds and returns the minimum value in the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyCL<T>::Minimum()
{

    NodeD<T> *temp = first;
    T Min = temp->data; 
    if(temp!=NULL)
    {
    do
    {
        if(Min > temp->data)
        {
            Min = temp->data;   
        }
        temp = temp->next;
    }while(temp!= last->next);
    }
    return Min;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Summation
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the summation of all elements in the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyCL<T>::Summation()
{

    T Sum =0;
    NodeD<T> *temp = first;
    if(temp!=NULL)
    {
    do
    {
        Sum = Sum + temp->data;
        temp = temp->next;
    }while(temp!= last->next);
    }
    return Sum;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Average
//  Input : None
//  Output : T (template parameter)
//  Description : Calculates and returns the average of all elements in the Doubly Circular Linked list.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T DoublyCL<T>::Average()
{
    T Sum=0;
    NodeD<T> *temp = first;
    if(temp!=NULL)
    {
    do
    {
        Sum = Sum+temp->data;
        temp = temp->next;
    }while(temp!= last->next);
    }
    if(iCount==0)
    {
        return 0;
    }
    return Sum/iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of searching and sorting Algorithms

///////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template <class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        
        void Accept();
        void Display();

        bool LinearSearch(T);
        bool BidirectinalSearch(T);
        bool BinarySearch(T);
        bool CheckSorted();

        void BubbleSort(int option = 0);
        void BubbleSortEfficient(int option=0);
        void SelectionSort(int option =0);
        void InsertionSort(int option=0);
};

////////////////////////////////////////////////////////////
// 
//  Constructor Name : ArrayX
//  Input : int iNo
//  Output : None
//  Description : Creates an ArrayX object with a specified size and dynamically allocates memory for the array.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];
}

////////////////////////////////////////////////////////////
// 
//  Destructor Name : ~ArrayX
//  Input : None
//  Output : None
//  Description : Destroys the ArrayX object and frees the dynamically allocated memory for the array.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Accept
//  Input : None
//  Output : void
//  Description : Accepts input from the user for filling the elements of the array.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: Accept()
{
    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Input : None
//  Output : void
//  Description : Displays the elements of the array.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: Display()
{    
    cout<<"Elements of array are: \n";
    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////
// 
//  Function Name : LinearSearch
//  Input : T (template parameter) No
//  Output : bool
//  Description : Performs a linear search in the array to find the given value.
//                Returns true if the value is found, otherwise returns false.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: LinearSearch(T No)
{
    bool flag  = false;

    for(int iCnt = 0; iCnt < iSize ; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : BidirectinalSearch
//  Input : T (template parameter) No
//  Output : bool
//  Description : Performs a bidirectional search in the array to find the given value.
//                Returns true if the value is found, otherwise returns false.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: BidirectinalSearch(T No)
{
    bool flag  = false;
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : BinarySearch
//  Input : T (template parameter) No
//  Output : bool
//  Description : Performs a binary search in the sorted array to find the given value.
//                Returns true if the value is found, otherwise returns false.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd = 0, iMid = 0;
    
    iStart = 0;
    iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if( (Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : CheckSorted
//  Input : None
//  Output : bool
//  Description : Checks if the elements of the array are sorted in ascending order.
//                Returns true if the array is sorted, otherwise returns false.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else 
        {
            flag = false;
            break;
        }
    }
    return flag;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : BubbleSort
//  Input : int option
//  Output : void
//  Description : Sorts the array using the Bubble Sort algorithm in either ascending or descending order based on the given option (0 for ascending, 1 for descending).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSort(int option)
{
    T temp;
    int i = 0, j = 0;

    if(option==0)
    {
        for(i = 0; i < iSize; i++)
        {
            for(j = 0; j < iSize - i - 1; j++)
            {
                if(Arr[j] > Arr[j+1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;
                }
            }
            cout<<"Data after pass : "<<i+1<<"\n";
            Display();
        }
    }
    else if(option==1)
    {
        for(i = 0; i < iSize; i++)
        {
            for(j = 0; j < iSize - i - 1; j++)
            {
                if(Arr[j] < Arr[j+1])
                {
                    temp = Arr[j];
                    Arr[j] = Arr[j+1];
                    Arr[j+1] = temp;
                }
            }
            cout<<"Data after pass : "<<i+1<<"\n";
            Display();
        }
    }
    
}

////////////////////////////////////////////////////////////
// 
//  Function Name : BubbleSortEfficient
//  Input : int option
//  Output : void
//  Description : Sorts the array using the Bubble Sort algorithm (optimized) in either ascending or descending order based on the given option (0 for ascending, 1 for descending).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void ArrayX<T> :: BubbleSortEfficient(int option)
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    if(option==0)
    {
            for(i = 0; i < iSize; i++)
            {
                flag = false;

                for(j = 0; j < iSize - i - 1; j++)
                {
                    if(Arr[j] > Arr[j+1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = temp;
                        flag = true;
                    }
                }
                if(flag == false)
                {
                    break;
                }
                cout<<"Data after pass : "<<i+1<<"\n";
                Display();
            }
    }
    else if(option==1)
    {
            for(i = 0; i < iSize; i++)
            {
                flag = false;

                for(j = 0; j < iSize - i - 1; j++)
                {
                    if(Arr[j] < Arr[j+1])
                    {
                        temp = Arr[j];
                        Arr[j] = Arr[j+1];
                        Arr[j+1] = temp;
                        flag = true;
                    }
                }
                if(flag == false)
                {
                    break;
                }
                cout<<"Data after pass : "<<i+1<<"\n";
                Display();
            }
    }

}

////////////////////////////////////////////////////////////
// 
//  Function Name : SelectionSort
//  Input : int option
//  Output : void
//  Description : Sorts the array using the Selection Sort algorithm in either ascending or descending order based on the given option (0 for ascending, 1 for descending).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void ArrayX <T>::SelectionSort(int option)
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    if(option==0)
    {
        for(i = 0; i < iSize-1; i++)
        {
            min_index = i;

            for(j = i+1; j < iSize; j++)
            {
                if(Arr[j] < Arr[min_index])
                {
                    min_index = j;
                }
            }
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
    else if(option==1)
    {
        for(i = 0; i < iSize-1; i++)
        {
            min_index = i;

            for(j = i+1; j < iSize; j++)
            {
                if(Arr[j] > Arr[min_index])
                {
                    min_index = j;
                }
            }
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
    
}

////////////////////////////////////////////////////////////
// 
//  Function Name : InsertionSort
//  Input : int option
//  Output : void
//  Description : Sorts the array using the Insertion Sort algorithm in either ascending or descending order based on the given option (0 for ascending, 1 for descending).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void ArrayX <T>::InsertionSort(int option)
{
    int i =0, j = 0;
    T selected;
    if(option==0)
    {
        for(i = 1; i < iSize; i++)
        {
            for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] > selected)) ; j--)
            {
                Arr[j + 1] = Arr[j];
            }
            Arr[j + 1] = selected;
        }
    }
    else if(option==1)
    {
        for(i = 1; i < iSize; i++)
        {
            for(j = i -1, selected = Arr[i] ; ((j >= 0) && (Arr[j] < selected)) ; j--)
            {
                Arr[j + 1] = Arr[j];
            }
            Arr[j + 1] = selected;
        }
    }
    
}

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for Binary Search Tree

///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct NodeT
{
    T data;
    struct NodeT *lchild;
    struct NodeT *rchild;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Binary Search Tree

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BST
{
public:
    struct NodeT<T> *first;
    int iCount;

    BST();

    int CountNodes(NodeT<T> *node);
    int CountLeafNodes(NodeT<T> *node);
    void Insert(T);
    bool Search(T, NodeT<T> *node);

    void Preorder(NodeT<T> *node);
    void Postorder(NodeT<T> *node);
    void Inorder(NodeT<T> *node);
};

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Constructor Name : BST
//  Description : Default constructor for the Binary Search Tree (BST) class.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
BST <T>::BST()
{
    first = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Function Name : Insert
//  Input : T No (the value to be inserted into the Binary Search Tree)
//  Output : void
//  Description : Inserts a new node with the given value into the Binary Search Tree (BST) while maintaining the BST property.
//                If the value already exists in the BST, it displays a message and does not insert the duplicate element.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Insert(T No)
{
    NodeT<T> *newn = new NodeT<T>;
    NodeT<T> *temp = first;

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (1)
        {
            if (No == temp->data)
            {
                cout << "Duplicate element: Unable to insert\n";
                delete newn;
                break;
            }
            else if (No > temp->data)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if (No < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Function Name : Preorder
//  Input : NodeT<T> *node (the root node of the current subtree)
//  Output : void
//  Description : Performs Preorder traversal on the Binary Search Tree (BST) starting from the given node.
//                It visits the current node, then recursively traverses the left subtree, and finally the right subtree.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Preorder(NodeT<T> *node)
{
    if (node != NULL)
    {
        cout << node->data << endl;
        Preorder(node->lchild);
        Preorder(node->rchild);
    }
}

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Function Name : Postorder
//  Input : NodeT<T> *node (the root node of the current subtree)
//  Output : void
//  Description : Performs Postorder traversal on the Binary Search Tree (BST) starting from the given node.
//                It recursively traverses the left subtree, then the right subtree, and finally visits the current node.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Postorder(NodeT<T> *node)
{
    if (node != NULL)
    {
        Postorder(node->lchild);
        Postorder(node->rchild);
        cout << node->data << endl;
    }
}

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Function Name : Inorder
//  Input : NodeT<T> *node (the root node of the current subtree)
//  Output : void
//  Description : Performs Inorder traversal on the Binary Search Tree (BST) starting from the given node.
//                It recursively traverses the left subtree, then visits the current node, and finally the right subtree.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Inorder(NodeT<T> *node)
{
    if (node != NULL)
    {
        Inorder(node->lchild);
        cout << node->data << endl;
        Inorder(node->rchild);
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Search
//  Input : T No (value to be searched)
//          NodeT<T> *node (root node of the subtree)
//  Output : bool (true if value is found, otherwise false)
//  Description : Performs iterative search in the Binary Search Tree (BST).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
bool BST<T>::Search(T No, NodeT<T> *node)
{
    bool flag = false;

    if (node == NULL)
    {
        cout << "Tree is empty" << endl;
        return flag;
    }

    while (node != NULL)
    {
        if (No == node->data)
        {
            flag = true;
            break;
        }
        else if (No > node->data)
        {
            node = node->rchild;
        }
        else if (No < node->data)
        {
            node = node->lchild;
        }
    }
    return flag;
}

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Function Name : CountNodes
//  Input : NodeT<T> *node (root node of the current subtree)
//  Output : int (number of nodes in the subtree)
//  Description : Recursively counts the number of nodes in the Binary Search Tree (BST) starting from the given node.
//                It counts the current node and recursively counts the nodes in the left and right subtrees.
//                If the node is NULL, it returns 0 (base case).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountNodes(NodeT<T> *node)
{
    if (node == NULL)
        return 0;

    return 1 + CountNodes(node->lchild) + CountNodes(node->rchild);
}

////////////////////////////////////////////////////////////
// 
//  Class Name : BST
//  Function Name : CountLeafNodes
//  Input : NodeT<T> *node (root node of the current subtree)
//  Output : int (number of leaf nodes in the subtree)
//  Description : Recursively counts the number of leaf nodes in the Binary Search Tree (BST) starting from the given node.
//                It checks if the current node is a leaf node and recursively counts leaf nodes in the left and right subtrees.
//                If the node is NULL, it returns 0 (base case).
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int BST<T>::CountLeafNodes(NodeT<T> *node)
{
    if (node == NULL)
        return 0;

    if (node->lchild == NULL && node->rchild == NULL)
        return 1;

    return CountLeafNodes(node->lchild) + CountLeafNodes(node->rchild);
}


///////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    public:
        struct NodeS<T> *First;
        int iCount;
    


        Stack();
        void Push(T);      // InsertLast
        T Pop();              // DleteLast
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////
// 
//  Class Name : Stack
//  Function Name : Stack (Constructor)
//  Input : None
//  Output : None
//  Description : Initializes the stack by setting the 'First' pointer to NULL and 'iCount' to 0.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
Stack<T>:: Stack()
{
    First = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Push
//  Input : T no (element to be pushed onto the stack)
//  Output : None
//  Description : Inserts the given element at the end of the stack.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void Stack<T>::Push(T no)        // InsertLast
{

    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 

////////////////////////////////////////////////////////////
// 
//  Function Name : Pop
//  Input : None
//  Output : T (value of the element popped from the stack)
//  Description : Removes the last element (top) from the stack and returns its value.
//                If the stack is empty, it displays "Stack is empty" message and returns -1.
//                If there is only one element in the stack, it removes the element and updates 'First' to NULL.
//                For stacks with more than one element, it traverses the stack to find the last element, removes it, and updates 'iCount'.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////


template <class T>
T Stack<T>::Pop()        // DeleteLast
{
    T Value ;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First -> data;
        delete First;
        First = NULL;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        Value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;

    return Value;
}              

////////////////////////////////////////////////////////////
// 
//  Function Name : Display
//  Input : None
//  Output : None
//  Description : Displays the elements of the stack starting from the top (last element) to the bottom (first element).
//                If the stack is empty, it displays "Nothing to display as Stack is empty" message.
//                It traverses the stack from 'First' to the last element and prints each element's value.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////


template <class T>
void Stack<T>::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as Stack is empty\n";
        return;
    }
    
    cout<<"Elements of stack are : \n";

    NodeS<T> *temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

////////////////////////////////////////////////////////////
// 
//  Function Name : Count
//  Input : None
//  Output : int (number of elements in the stack)
//  Description : Returns the number of elements currently present in the stack.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////


template <class T>
int Stack<T>::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////


template <class T>
class Queue
{
    public:
        struct NodeS<T> *First;
        int iCount;


        Queue();
        void Enqueue(T);      // InsertLast
        T Dequeue();              // DleteFirst
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////
//  Class Name : Queue
//  Constructor : Queue()
//  Input : None
//  Output : None
//  Description : This is the constructor of the Queue class.
//                It initializes the queue by setting the 'First' pointer to NULL and 'iCount' to 0.
//                This signifies an empty queue as there are no elements present in the queue initially.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
Queue<T>:: Queue()
{
    First = NULL;
    iCount = 0;
}

////////////////////////////////////////////////////////////
// 
// Class Name: Queue
// Function Name: Enqueue
// Input: T no (the element to be inserted into the queue)
// Output: void
// Description: Enqueues an element into the queue. This function inserts a new element at the end of the queue, 
// creating a new node with the given element and adding it as the last node. If the queue is empty, the new node becomes the first node.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Enqueue(T no)        // InsertLast
{
    NodeS<T> *newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        NodeS<T> *temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
} 

//////////////////////////////////////////////////////////////
// 
// Class Name: Queue
// Function Name: Dequeue
// Input: None
// Output: T (the element dequeued from the queue)
// Description: Dequeues an element from the queue. This function removes the first element from the queue and returns its value.
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
T Queue<T>::Dequeue()        // DeleteFirst
{
    T Value ;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = First -> data;
        delete First;
        First = NULL;
    }
    else
    {
        Value = First -> data;
        NodeS<T> *temp = First;
        First = First -> next;
        delete temp;
    }

    iCount--;

    return Value;
}              

//////////////////////////////////////////////////////////////
// 
// Class Name: Queue
// Function Name: Display
// Input: None
// Output: None
// Description: Displays the elements of the queue. I
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
void Queue<T>::Display()
{
    if(First == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    
    cout<<"Elements of Queue are : \n";

    NodeS<T> *temp = First;

    for(int icnt = 1; icnt <= iCount; icnt++)
    {
        cout<<temp->data<<"\n";
        temp = temp -> next;
    }
}

//////////////////////////////////////////////////////////////
// 
// Class Name: Queue
// Function Name: Count
// Input: None
// Output: int (number of elements in the queue)
// Description: Returns the count of elements in the queue. 
//  Author : Arnav R Tanawade
//  Date :  July 2023
// 
//////////////////////////////////////////////////////////////

template <class T>
int Queue<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
// Entry Point function
///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
