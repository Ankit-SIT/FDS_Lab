/*
Ankit Das
Double Ended Queue in Pure C++
*/

#include<iostream>

class DoubleEndedQueue{
 int *array;
 int front;
 int rear;
 int size;

 public:

 DoubleEndedQueue(int size){
     array = (int*)malloc(size * sizeof(int));
     this->size = size;
     front = -1;
     rear = 0;
 }

 void Display();
 void getPositions();
 void insertFront(int value);
 void insertRear(int value);
 int deleteFront();
 int deleteRear();
 bool isFull();
 bool isEmpty();
 int getFront();
 int getRear();
};

void DoubleEndedQueue::Display(){
    int i = 0;
    while(i < (this->size)){
        std::cout<<array[i]<<" ";
        i++;
    }
    std::cout<<std::endl;
}

void DoubleEndedQueue::getPositions(){
    std::cout<<"\nFRONT: "<<this->front<<std::endl;
    std::cout<<"REAR: "<<this->rear<<std::endl;
}

bool DoubleEndedQueue::isFull(){
    return((front == 0 && rear == size - 1) || front == rear + 1);
}

bool DoubleEndedQueue::isEmpty(){
    return (front == -1);
}

void DoubleEndedQueue::insertFront(int value){
    if(isFull()){
        std::cout<<"SizeError! OverFlow!" << std::endl;
        return;
    }

    if(front == -1){                     // initial insert at 0
        front = 0;
        rear = 0;
    }
    
    else if(front == 0){
        front = size - 1;                // loop back to rear
    }

    else{
        front -= 1;
    }
 getPositions();
 array[front] = value;                     // insert at front
}

void DoubleEndedQueue::insertRear(int value){
    if(isFull()){
        std::cout<<"SizeError! OverFlow!"<<std::endl;
        return;
    }

    if(front == -1){            // initial insert at 0
        front = 0;
        rear = 0;
    }

    else if(rear == size - 1){
        rear = 0;                // loop back to front
    }

    else{
        rear += 1;
    }
 getPositions();
 array[rear] = value;              // insert at rear
}

int DoubleEndedQueue::deleteFront(){
    int save = array[front];
    if(isEmpty()){
        std::cout<<"SizeError! UnderFlow!"<<std::endl;
        return -1;
    }

    if(front == rear){               // only one element i.e at 0
        front = -1;
        rear  = -1;
    }

    else{
        if(front == size - 1){
            front = 0;                // loop back to front after deleting last element
        }

        else{
            front += 1;
        }
    }
    getPositions();
    return save;
}

int DoubleEndedQueue::deleteRear(){
    int save = array[rear];
    if(isEmpty()){
        std::cout<<"SizeError! UnderFlow!"<<std::endl;
        return -1;
    }

    if(front == rear){               // only one element i.e at 0
        front = -1;
        rear  = -1;
    }

    else if(rear == 0){
            rear = size - 1;                // loop back to rear after deleting last element
        }

        else{
            rear -= 1;
        }
    
    getPositions();
    return save;
}

int DoubleEndedQueue::getFront(){
    if(isEmpty()){
        std::cout<<"SizeError! No Element in the Queue"<<std::endl;
        return -1;
    }
    return array[front];
}

int DoubleEndedQueue::getRear(){
    if(isEmpty() || rear < 0){
        std::cout<<"SizeError! No Element in the Queue"<<std::endl;
        return -1;
    }
    return array[rear];
}


int main(){

int n = 0;
int choice = 0;
int value = 0;
int ret = 0;

std::cout<<"ENTER SIZE:";
std::cin>>n;

DoubleEndedQueue Q(n);

while(true){
    std::cout<<"\n\n-- MENU -- \n";
    std::cout<<"1. INSERT AT FRONT"<<std::endl;
    std::cout<<"2. INSERT AT REAR"<<std::endl;
    std::cout<<"3. DELETE FROM FRONT"<<std::endl;
    std::cout<<"4. DELETE FROM REAR"<<std::endl;
    std::cout<<"5. GET FRONT VALUE"<<std::endl;
    std::cout<<"6. GET REAR VALUE"<<std::endl;
    std::cout<<"7. DISPLAY QUEUE"<<std::endl;
    std::cout<<"8. EXIT"<<std::endl;
    std::cout<<"ENTER YOUR CHOICE: ";
    std::cin>>choice;

    switch (choice)
    {
    case 1:
        std::cout<<"ENTER VALUE: ";
        std::cin>>value;

        Q.insertFront(value);
        break;

    case 2:
        std::cout<<"ENTER VALUE: ";
        std::cin>>value;

        Q.insertRear(value);
        break;

    case 3:
        ret = Q.deleteFront();
        if(ret != -1){
        std::cout<<ret<<" DELETED FROM FRONT"<<std::endl;
        }
        break;
      
    case 4:
        ret = Q.deleteRear();
        if(ret != -1){
        std::cout<<ret<<" DELETED FROM REAR"<<std::endl;
        }
        break;
    
    case 5:
        Q.getPositions();
        std::cout<<"VALUE AT FRONT: "<<Q.getFront()<<std::endl;
        break;

    case 6:
        Q.getPositions();
        std::cout<<"VALUE AT REAR: "<<Q.getRear()<<std::endl;
        break;
    
    case 7:
        Q.Display();
        break;
    
    case 8:
        return 0;
    
    default:
        std::cout<<"Invalid Choice! Try Again"<<std::endl;
        break;
    }
 }
}
