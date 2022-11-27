#include <iostream>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class queueC
{
    private:
        struct queueNode{
            float queueValue;
            queueNode *next;
        };
        queueNode   *head;

    public:
        queueC();
        void startQueue();
        void enqueue (float);

        void dequeue();
        bool queueIsEmpty();

        void displayStats(float);
        void deleteQueue();


};


queueC::queueC(){

    head = NULL;

}

void queueC::startQueue(){

    int randInt;
    srand(time(0));
    float arrival =0.0;
    float avgRate = 1 / 10.0;

    for(int i = 0; i < 5; i++){

        float value = (float)rand() / (float)RAND_MAX;

        float sTime = -(avgRate)*(log(value));
        arrival = sTime + arrival;
        cout << arrival << "  " << sTime <<endl;
        enqueue(arrival);

    }


}


void queueC::enqueue(float process){

    queueNode *newNode;
    newNode = new queueNode;
    newNode->queueValue = process;

   if(head == NULL){

        head = newNode;
        head->next = NULL;

   }
    else{

        queueNode *nodePtr;
        nodePtr = head;

        while(nodePtr->next){

            nodePtr = nodePtr->next;

        }

        nodePtr->next = newNode;
        newNode->next = NULL;

    }
}


void queueC::dequeue(){

        if(queueIsEmpty()){


    }
    else{

        queueNode *nodePtr;
        nodePtr = head;
        head = nodePtr->next;
        delete nodePtr;

    }
}


bool queueC::queueIsEmpty(){

    if(head == NULL){

        return true;

    }
    else{

        return false;

    }
}


void queueC::displayStats(float lambda){
    queueC queueClass;
   
    int count = 0;

    float avgSer = .04;
    float service = 0.0;
    float z = (float)rand() / (float)RAND_MAX;
    service = -(avgSer)*(log(z));
    cout <<"The service time is " << service << endl;
    float serviceExit = avgSer;
    float clock = .0;
    float value = 0;
    float sTime = 0;
    float avgRate = 1 / lambda;
    float arrival =0.0;
    value = (float)rand() / (float)RAND_MAX;
    sTime = -(avgRate)*(log(value));
    arrival = sTime + arrival;
    queueClass.enqueue(arrival);

    for(int i = 1; i < 10000; i++){

        value = (float)rand() / (float)RAND_MAX;
        sTime = -(avgRate)*(log(value));
        arrival = sTime + arrival;

        while(clock <= arrival){
            clock = clock + .0001;


            if(clock >= serviceExit){
                queueClass.dequeue();
                serviceExit = serviceExit + service;

            }
            if(clock >= arrival){
               int empty = queueClass.queueIsEmpty();
               if(empty == 1){
                 serviceExit = arrival + service;

               }
            }

        }

        queueClass.enqueue(arrival);

    }


    double avgUtiliz = lambda / (avgSer*1000);
    double q = 1/(1-avgUtiliz);


    double avgTurn = q/lambda;

    double totalReady = q - avgUtiliz;
    cout << "The Average rate: " << lambda << endl;
    cout << "The average turnaround time: " << avgTurn << endl;
    cout << "The average CPU utilization: " << avgUtiliz << endl;
    double throughPut = 100/clock;
    cout << "The average number of processes in the Ready Queue: " << totalReady << endl;
    cout << "The Total throughput: " << throughPut << " per sec" << endl;
    queueClass.deleteQueue();
    cout << endl;

}
void queueC::deleteQueue(){

    queueNode *nodePtr;
    nodePtr = head;

    while(nodePtr != NULL){

        head = nodePtr->next;
        delete nodePtr;
        nodePtr = head;

    }
}


main(){
     srand(time(0));
    queueC queueClass;
    float lambda = 10.0;
   while(lambda != 31){

        queueClass.displayStats(lambda);
        lambda++;
   }

}






