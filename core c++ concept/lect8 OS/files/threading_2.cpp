#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std ;
void task1(){
    for(int e=0 ;e< 10 ;e++){
        sleep(1) ;
        cout<<"Task1 "<<e<<endl ;
    }
}

void task2(){
    for(int e=0 ;e< 10 ;e++){
        sleep(1) ;
        cout<<"Task2 "<<e<<endl ;
    }
}

int main(){
    thread t1(task1) ;
    thread t2(task2) ;

    t1.join() ;
    t2.join() ;
}