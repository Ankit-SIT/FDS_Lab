/*
Ankit Das
23nd August 2020
Double Ended Queue
*/

#include<iostream>  
  
class DoubleEndedQueue{  
    int *array;  
    int front;  
    int rear;  
    int size;  
  
    public:  
  
    DoubleEndedQueue(int n){  
        front = -1;  
        rear = -1;  
        this->size = n;  
        array = (int*)malloc(n*sizeof(int));  
    }  
  
    void toFront(int n);  
    void toRear(int n);  
    int fromFront();  
    int fromRear();  
    bool isFull();  
    bool isEmpty();  
    int getFront();  
    int getRear();  
    void display();  
};  
  
void DoubleEndedQueue::display(){                                  // display the queue  
         unsigned int i = 0;  
         for(i = 0; i < this->size; i++){  
             std::cout<<*(array + i)<<" ";  
         }  
         std::cout<<std::endl;  
     }  
  
bool DoubleEndedQueue::isEmpty(){  
    if(front == rear == -1){  
        return true;  
    }  
    return false;  
}  
  
bool DoubleEndedQueue::isFull(){  
    if(front == 0 && rear == size - 1){  
        return true;  
    }  
    return false;  
}  
  
void DoubleEndedQueue::toFront(int value){  
    if(isFull()){  
        std::cout<<"Overflow Error: Queue is full!"<<std::endl;  
        return;  
    }  
  
    if(isEmpty()){  
            front = 0;  
            rear = 0;  
    }  
  
    if(front == 0){  
            front = size - 1;  
            *(array + front) = value;  
    }  
  
    else{      
            front = front - 1;  
            *(array + front) = value;  
    }  
}  
  
void DoubleEndedQueue::toRear(int value){  
    if(isFull()){  
        std::cout<<"Overflow Error: Queue is full!"<<std::endl;        
        return ;  
    }  
  
    else{  
        if(isEmpty()){  
            front = 0;  
            rear = 0;  
        }  
  
        else if(rear == size - 1){  
            rear = 0;  
        }  
  
        else{      
            rear = rear + 1;  
            *(array + rear) = value;  
        }  
    }  
}  
  
int DoubleEndedQueue::fromFront(){  
    if(isEmpty()){  
        std::cout<<"Underflow Error: Queue is empty!"<<std::endl;  
        return 0;  
    }  
  
    else{  
        int save = front;  
  
        if(front == rear){  
            front = -1;  
            rear = -1;  
        }  
  
        else{  
         if(front == size - 1){  
            front = 0;  
        }  
           
        else{      
            front = front+1;  
        }  
  
        return *(array + save);  
    }  
    }  
    return 0;  
}  
  
int DoubleEndedQueue::fromRear(){  
    if(isEmpty()){  
        std::cout<<"Underflow Error: Queue is empty!"<<std::endl;  
        return 0;  
    }  
  
    else{  
        int save = rear;  
  
        if(front == rear){  
            front = -1;  
            rear = -1;  
        }  
  
        else{  
         if(rear == 0){  
            rear = size - 1;  
        }  
           
        else{      
           rear = rear - 1;  
        }  
  
        return *(array + save);  
    }  
}  
return 0;  
}  
  
int DoubleEndedQueue::getFront(){  
    if(isEmpty()){  
        std::cout<<"Value Error: Queue is empty!"<<std::endl;  
        return 0;  
    }  
  
    else{  
     return *(array + front);  
    }  
}  
  
int DoubleEndedQueue::getRear(){  
    if(isEmpty()){  
        std::cout<<"Value Error: Queue is empty!"<<std::endl;  
        return 0;  
    }  
  
    else{  
     return *(array + rear);  
    }  
}  
  
int main(){  
    int n = 0;  
    std::cout<<"ENTER SIZE OF QUEUE: ";  
    std::cin>>n;  
  
    class DoubleEndedQueue Q(n);  
    int result = 0;  
    int choice = 0;  
  
    while(true){  
    std::cout<<"\n1. INSERT AT FRONT\n";  
    std::cout<<"2. INSERT AT REAR\n";  
    std::cout<<"3. DELETE FROM FRONT\n";  
    std::cout<<"4. DELETE FROM REAR\n";  
    std::cout<<"5. PEEK FRONT\n";  
    std::cout<<"6. PEEK REAR\n";  
    std::cout<<"7. DISPLAY\n";  
    std::cout<<"8. EXIT\n";  
  
    std::cout<<"\nENTER YOUR CHOICE: ";  
    std::cin>>choice;  
          
  
    switch(choice){  
    case 1:  
        std::cout<<"\nENTER VALUE TO BE INSERTED: ";  
        std::cin>>result;  
        Q.toFront(result);  
        break;  
  
    case 2:  
        std::cout<<"\nENTER VALUE TO BE INSERTED: ";  
        std::cin>>result;  
        Q.toRear(result);  
        break;  
  
    case 3:  
        result = Q.fromFront();  
        std::cout<<"ELEMENT "<<result<<" HAS BEEN REMOVED!"<<std::endl;  
        break;  
  
    case 4:  
        result = Q.fromRear();  
        std::cout<<"ELEMENT "<<result<<" HAS BEEN REMOVED!"<<std::endl;      
        break;  
    case 5:  
        result = Q.getFront();  
        std::cout<<"FRONT: "<<result<<std::endl;  
        break;  
    case 6:  
        result = Q.getRear();  
        std::cout<<"REAR: "<<result<<std::endl;  
        break;  
      
    case 7:  
        Q.display();  
        break;  
  
    case 8:  
        return 0;  
  
    default:  
        std::cout<<"INVALID CHOICE! TRY AGAIN"<<std::endl;  
    }  
   }  
}  
