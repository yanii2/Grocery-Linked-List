/* Name: Yana Kuzmina, NSHE: 5007104058, CS202 1005, AS8
 * Description: using doubly linked lists
 * Input: list
 * Output: sorted DLL
 */
 
 #include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

template <class T>
struct Node{
    T data;
    Node * next;
    Node * prev;

    Node(T dat){
        next = nullptr;
        prev = nullptr;
        data = dat;
    }

    // ~node(){
    //     node * d = prev;
    //     head = prev->next;
    //     delete d;
    // }
};



template <class T>
class DoublyLinkedList{
    public:
        Node<T> * head;
        Node<T> * tail;
        void insert(T var);
        bool searchDelete(T var);
        void print();
        void backwardsPrint();

        DoublyLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

         ~DoublyLinkedList(){
             Node<T> * tmp = head;
             Node<T> * next = nullptr;
             while(tmp != NULL){
                 next = tmp->next;
                 delete tmp;
                 tmp = next;
             }
             
        }
};


template <class T> 
void DoublyLinkedList<T>::insert(T var){
    //create node
    Node<T> * newNode;
    Node<T> * next;
    Node<T> * prev;
    Node<T> * curr = head;
    T data;

    newNode = new Node<T>(var);
    //set value
 
    //inserting it into the 
    //sorted linked list
    if(head == NULL){
        //Case 1
        head = tail = newNode;
        return;
        
    }
    if(newNode->data <= head->data){
        //new minimum
        //create new head
        //make head->prev point to new pointer.
        //make newNode->next point to head 
        //make head = newNode
        // Node<T> * newHead;
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    else if(newNode->data >= tail->data){
        //New Maximum
        //use tail->next = the new node you created 
        //and newNode->prev = tail. Update tail to = newNode
        // Node<T> * newTail;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;

    }
    else{

        while(curr != nullptr){
           // traverse the DLL
            if(curr->data >= var){

                if(curr == head) {
                    //case 2
                    //head insert
                    newNode->next = head;
                    newNode->prev = nullptr;
                    head = newNode;
                    return;
                    //return if current is
                    //equal to head

                }else {
                    //insert the middle <-- case 4
                    newNode->next = curr;
                    newNode->prev = curr->prev;
                    curr->prev->next = newNode;
                    curr->prev = newNode;
                    return;
                }

            }else{
                //iterates to next node
               curr = curr->next; 
                
                // newNode->prev = curr;
                // newNode->next = curr->next;
                // newNode->prev->next = newNode;
                // newNode->next->prev = newNode;
            }
            // newNode->prev = curr;
            // newNode->next = curr->next;
            // newNode->prev->next = newNode;
            // newNode->next->prev = newNode;

           
        }
        
        //if reaches tail
        //breaks out of while loop
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;


    }
        
    
}


template <class T> 
bool DoublyLinkedList<T>::searchDelete(T var){

    
    // Node<T> * next;
    // Node<T> * prev;


    Node<T> * curr = head;
    if(head->next == nullptr){
        //only node in list
        // head = curr;
        // head = curr->next;
        delete curr;
        head = nullptr;
        tail = nullptr;
        curr = nullptr;
        return true;
        
    }
    
    while(curr != nullptr){
        if(curr->data == var){
            //Case 1
            //head deletion
            if(curr == head){
                //curr->next->prev = nullptr;
                head = curr->next;
                delete curr;
                curr = head;
            // 	move the pointer head to 
            //the next node, and deallocate curr
        	}
        	else if(curr == tail){
        	    curr->prev->next = nullptr;
        	    tail = curr->prev;
        	    delete curr;
                curr = nullptr;
        	    
        	} else{
        	   // std::cout << (curr->prev == nullptr) ? "Y":"N";
        	   // std::cout << "DEBUG";
        	    curr->prev->next = curr->next;
        	    //uses 7 to point to 12
        	    curr->next->prev = curr->prev;
        	    //uses 12 to point to 7
                Node<T> * temp = curr->next;
        	    delete curr;
                curr = temp;
        	}
        	
        }
        else{
            curr = curr->next;
        }

    }
    return false;
    
}

template <class T> 
void DoublyLinkedList<T>::print()
{
    //node * head
    Node<T> * traverse;
    traverse = head;
    // if(traverse->next == nullptr){
    //     std::cout << "hi";
    //     return;
    // }

    while(traverse != nullptr){
        std::cout << traverse->data << " -> ";
        traverse = traverse->next;
    }
   
    std::cout << "." << std::endl;
    //if null print period
    
}

template <class T> 
void DoublyLinkedList<T>::backwardsPrint()
{
    // if(tail == nullptr){
    //     //std::cout << "." << std::endl;
    //     return;
    // }
    //node * tail
    // Prints the existing linked list in reverse. 
    Node<T> * traverse;
    traverse = tail;
    while(traverse != nullptr){
        std::cout << traverse->data << " -> ";
        traverse = traverse->prev;
    }
    //if null then print period
    std::cout << "." << std::endl;

}

template <class T>
void readData(DoublyLinkedList<T> &list){
    //cout << "DEBUG 259\n";
    T data;
    std::ifstream myFile;
    myFile.open("list.txt");
    if(myFile.is_open()){
        while (myFile >> data){
            // myFile >> data;
            //cout << data << endl;
            //list.insert(data);
            if (data == "Source:"){
                break;
            }
            list.insert(data);
        }
        myFile.close();
    }
    //else
    //{
       //cout << "FILE DOES NOT EXIST\n";
    //}
    // while (myFile >> data){
    //     // myFile >> data;
    //     cout << "DEBUG " << data << endl;
    //     if (data == "Source:"){
    //         break;
    //     }
    //     list.insert(data);
    // }
    // myFile.close();
        
}
