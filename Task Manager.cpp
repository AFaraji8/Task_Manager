#include <iostream>
#include <chrono>
#include <ctime>
#include "day.h"
using namespace std;


int main (){

year sal99 ;
bool conti=true;
cout<<"                                             welcome                 \n";
cout << "now    today   month   add task    find time   free    add employee    assign task    schedule     show employee task    exit  \n";
cout << " Type your selection : ";
string code;
getline(cin,code);

while(conti)
{
    if(code=="now")
    {
        sal99.now();
        
    }
    else if (code=="today")
    {
       sal99.today();
       
    }
    else if (code=="month")
    {
       sal99.monthtasks();
       
    }
    else if (code=="add task")
    {
       sal99.addtask();
       
    }
    else if (code=="find time")
    {
       sal99.find_time();
       
    }
    else if (code=="free")
    {
       sal99.free();
       
    }
    else if (code=="add employee")
    {
       sal99.addemployee();
       
    }
    else if (code=="assign task")
    {
       sal99.assign_task();
       
    }
    else if (code=="schedule")
    {
       sal99.schedule();
       
    }
    else if (code=="show employee task")
    {
       sal99.showemployeetask();
       
    }    
    else if (code=="exit")
    {
       sal99.exit();
       conti=false;
       break;
    }
cout << " Type your selection : ";        
getline(cin,code);
}


cout << "                                       Goodbye :))))) \n";
return 0;
}