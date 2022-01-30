#include <iostream>
#include <iomanip>
#include <cstring>
#include<utility>
#include<fstream>
#include <vector>
#include <list>
#include <chrono>
#include <ctime>
using namespace std;


class task
{
    friend class Day;
private:

    string name;
    int startm;
    int startd;
    int start_hour;
    int start_minute ;
    int finishm;
    int finishd;
    int finish_hour;
    int finish_minute ;
public:
 task(string , int , int , int , int ,int , int , int , int);
string getname(){return name ;}
int sd(){return startd;}
int sm(){return startm;}
int sh(){return start_hour;}
int smin(){return start_minute;}
int fd(){return finishd;}
int fm(){return finishm;}
int fh(){return finish_hour;}
int fmin(){return finish_minute;}
 void show();
 
};
class Employee
{
private:
   string name;
    int start_hour;
    int start_minute;
    int finish_hour;
    int finish_minute;

public:
    Employee(string , long,int,int,int,int);
    vector<task> taskforthis ;
    long ssid;

    ~Employee();
};
 
/***************************  Day  ******************************/


class Day
{
    
private:
bool freetime(int , int , int , int );
void freetable(int sh , int sm , int eh , int em);


public:
    Day();
    int tasknumber=0;
    int hours [24][60]={0};
    void showtask();
    void free(int sh , int sm );
    bool por=false;

    vector <task> tasks_of_day;
    ~Day();

    
    
    void taskadd(task a)
    {   
        tasknumber++;
        tasks_of_day.push_back(a);
        int j=a.start_minute;
        int i=a.start_hour; 
        for( ; i <=a.finish_hour; i++)
        {
            if (a.finish_hour>i )
            {
                for (;j<=60 ;j++)
                {
                hours [i][j]=1;
                }
                j=0;
            }

            else
            {
                for (;j<=a.finish_minute ;j++)
                    {   
                        hours [i][j]=1;
                    }
            }
        }

        int check=0;
        int hhh=a.start_hour;
        int mmm=a.start_minute;
        task temp=a ;
        task tempp=a ;
        for (int t= 0 ; t<tasks_of_day.size();t++)
        {
        if (check==0)
        {  if (tasks_of_day.at(t).start_hour>a.start_hour)
                {
                    temp = tasks_of_day.at(t);
                    tasks_of_day.at(t)=a;
                    check=1;

                }
                else if (tasks_of_day.at(t).start_hour==a.start_hour &&tasks_of_day.at(t).start_minute>a.start_minute )
                    {

                    temp = tasks_of_day.at(t);
                    tasks_of_day.at(t)=a;
                    check=1;
                    }
        }
        else
        {
            tempp = tasks_of_day.at(t);
            tasks_of_day.at(t)=temp;
            temp = tempp;
        }
        
        }



    }
    


};

Day::Day()
{
    
}

Day::~Day()
{
}
void Day::freetable (int sh , int sm , int eh , int em)
{
    int j=sm ;
for ( int i =sh ; i<=eh ; i++)
{
        if (eh>i )
        {
            for (j=sm ;j<=60 ;j++)
            {
                hours[i][j]=0;   
            }
            j=0;
        }
        else
        {
            for (;j<em ;j++)
                {   
                    hours[i][j]=0;   
                }
        }
}



}






void Day::free (int shh , int smm )
{
    // freetable(sh,sm,eh,em);

vector <task> :: iterator it;

for(it=tasks_of_day.begin();it!=tasks_of_day.end();it++)
{
    if((*it).fh()>24 ||(*it).fh()<0)
    {break;}
    if((*it).fh()>shh &&(*it).sh()<shh )
    {
        freetable((*it).start_hour,(*it).start_minute,(*it).finish_hour,(*it).finish_minute);
        tasks_of_day.erase(it);
    }
    else if((*it).start_hour==shh &&(*it).start_minute<=smm  )
    {
        if ((*it).finish_hour>shh || ((*it).finish_hour==shh && (*it).finish_minute>=smm ))
        freetable((*it).start_hour,(*it).start_minute,(*it).finish_hour,(*it).finish_minute);
        tasks_of_day.erase(it);
    }

}



}






void Day:: showtask(){

vector <task> :: iterator it;
int n=1;
for(it=tasks_of_day.begin();it!=tasks_of_day.end();++it)
{
    cout << "("<< n << ") ";
    (*it).show();
    n++;

}

}



bool Day::freetime (int h1 , int m1 , int h2 , int m2)
{       int j=m1 ;
    for(int i =h1 ; i <=h2; i++)
    {
        if (h2>i )
        {
            for (j=m1 ;j<=60 ;j++)
            {
                if (hours[i][j]!=0)
                   { return false;}
            }
            j=0;
        }
        else
        {
            for (;j<m2 ;j++)
                {   if (hours[i][j]!=0)
                        { return false;}
                }
        }
    }
    return true;
}














/****************************   month   *****************************/





class Month
{
private:
   int rooz;
public:
    Month();
    bool por=false;
    vector<Day> days;

    ~Month();
};

Month::Month()
{
    for (int i=0;i<32;i++)
    {    
        Day a;
        days.push_back(a);
    }
}


Month::~Month()
{
}






/***************************   task  *****************************/





void task::show()
{
cout << " \"" << name << " \" ["<<setfill('0')<<setw(2)<< start_hour 
    << ":"<<setw(2)<<start_minute <<" - "<<setw(2)<< finish_hour<< ":"
    << setw(2);cout<< finish_minute << setfill(' ') <<"]"<<endl;


}



task:: task(string a , int sm  , int sd , int sh, int smin ,int fm , int fd, int fh , int fmin)
{
    name =a ;
    startm = sm;
    startd= sd ;
    start_hour=sh;
    start_minute =smin;
    finishm= fm;
    finishd = fd;
    finish_hour = fh;
    finish_minute =fmin ;


}






/***************************   year   ***************************/





class year
{
private:

vector<Month> months;
vector<Employee> employees ;
void start();
void end();
public:
 year(/* args */);
vector <task> alta;
void addtask();
void free();
void now();
void today();
void monthtasks();
void find_time();
void addemployee();
void assign_task();
void exit(){end();}
void schedule();
void showemployeetask();




~year();
};
 year:: year(/* args */)
{       
    
    for (int i=0;i<13;i++)
    {    
        Month a;
        months.push_back(a);
        
    }
    start();

}
year:: ~ year()
{
    
}

void year::free()
{
    int startday;
    int startmonth;
    cout<< "day-month :";
    cin>>startday;
    cin.ignore();
    cin>>startmonth;
    int starthour;
    int startmin;
    cin.ignore();
    cout<< "hour:minute : ";
    cin>>starthour;
    cin.ignore();
    cin>>startmin;
    cin.ignore();

    months.at(startmonth).days.at(startday).free(starthour,startmin);
    
}




void year::now()
{
        auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout << ctime(&timenow) << endl;
/*
    time_t t = time(0);
    struct tm * now = localtime(&t);

    int daynow = now->tm_mday;
    int monthnow = now->tm_mon + 1;
    int yearnow = now->tm_year + 1900;
    int hournow = now ->tm_hour;
    int minnow = now ->tm_min;

*/

}

void year::today()
{
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int daynow = now->tm_mday;
    int monthnow = now->tm_mon + 1;
    months.at(monthnow).days.at(daynow).showtask();
    /*
    for (int i = 0 ; i<months.at(monthnow).days.at(daynow).tasknumber;i++)
    {
        months.at(monthnow).days.at(daynow).tasks_of_day.at(i).show();
    }
    */
    
}



void year::monthtasks()
{
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int monthnow = now->tm_mon + 1;
    int n=1;
    for (auto it=months.at(monthnow).days.begin();it!=months.at(monthnow).days.end();it++)
    {
    if((*it).por)
    {

    for(auto i=(*it).tasks_of_day.begin();i!=(*it).tasks_of_day.end();++i)
        {
            cout << "(" << n << ") ";
            (*i).show();
            n++;
        }
    }
    }
    /*
    months.at(monthnow).days.at(j).showtask();
    for (int i = 0 ; i<months.at(monthnow).days.at(j).tasknumber;i++)
    {   cout << "("<<i << ")";
        months.at(monthnow).days.at(j).tasks_of_day.at(i).show();
    }
   */ 
}


void year::find_time()
{   cout<<"freetime for : ";
    time_t t = time(0);
    struct tm * now = localtime(&t);
    int daynow = now->tm_mday;
    int monthnow = now->tm_mon + 1;
    int hournow = now ->tm_hour;
    int minnow = now ->tm_min;

    int shour,smin;
    cin >> shour;
    cin.ignore();
    cin >> smin;
    cin.ignore();


    int boxnumber = (shour *60) + smin;
    bool find=false;
    int box=0;
    int startfromh=hournow;
    int startfromm=minnow;
    int startfromd=daynow;
    int endinh;
    int endinm;
    

    int i =hournow;
    for (int d =daynow;d<31;d++)
    {
        for (;i<24;i++)
        {int j;
        if(i==hournow)
            j=minnow;
        else
        {
             j=0;
        }
        
            for (;j<60;j++)
            {
                box++;

                if (months.at(monthnow).days.at(d).hours[i][j]==1)
                    {
                        box=0;
                        startfromh=i;
                        startfromm=j;
                        startfromd=d;

                    }

                if (box==boxnumber)
                    {
                        find = true;
                        endinh=i;
                        endinm=j+1;
                        if(endinm>=60)
                        {
                            endinh++;
                            endinm-=60;
                        }
                        break;
                    }       

            }
            if (box==boxnumber)
                {
                    find = true;
                    break;
                }
        }
        if (box==boxnumber)
                {
                    find = true;
                    break;
                }
        if(i==24)
        {
            i=0;
            

        }

    }

if (box==boxnumber)
{
cout << startfromd <<"-"<< monthnow << " [" <<setfill('0') <<setw(2) << startfromh << ":"<<setw(2)<< startfromm
<<" - " <<setw(2)<< endinh << ":" <<setw(2)<< endinm <<"] " << setfill(' ')<< endl;

}

}


void year::start()
{
    fstream file ("data",ios::binary| ios::in);
    int sizestring;
    if(!file)
    {
        cout<<" empty";
    }
    file.read(reinterpret_cast<char*>(&sizestring),sizeof(int));
    

    while(!file.eof())
    {   
        string name="";
        char nam[sizestring];
        file.read(reinterpret_cast<char*>(&nam),sizestring);
        for (int q=0;q<sizestring;q++)
        {
        name+=nam[q];
        }

        int aaa[8];
        int fff;
        for (int q=0;q<8;q++)
        {file.read(reinterpret_cast<char*>(&fff),sizeof(int));
        aaa[q]=fff;
        }
        int startday=aaa[0];
        int startmonth=aaa[1];
        int starthour=aaa[2];
        int startmin=aaa[3];
        int finishday=aaa[4];
        int finishmonth=aaa[5];
        int finishhour=aaa[6];
        int finishmin=aaa[7];



/*
        file.read(reinterpret_cast<char*>(&startday),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&startmonth),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&starthour),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&startmin),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&finishday),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&finishmonth),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&finishhour),(sizeof(int)));
        file.read(reinterpret_cast<char*>(&finishmin),(sizeof(int)));
*/


        task a ( name , startmonth  , startday , starthour, startmin , finishmonth , finishday, finishhour , finishmin);
        alta.push_back(a);
        months.at(startmonth).days.at(startday).taskadd(a);
        months.at(startmonth).por=true;
        months.at(startmonth).days.at(startday).por=true;
        char ddd[5];
        file.read(reinterpret_cast<char*>(&ddd),sizeof(char)*5);
        long pos = file.tellp();
        file.read(reinterpret_cast<char*>(&ddd),sizeof(char)*5); 
        char eed[5]="endd" ;     
            if (ddd[0]==eed[0])
            {
                break;
            }
            else
            {
                file.seekp(pos,ios::beg);
                file.read(reinterpret_cast<char*>(&sizestring),sizeof(int));
            }
            
        }

        
    file.close();
}
    


void year::end ()
{   int f=0;
    fstream file ("data",ios::binary| ios::out);
    for (auto m=months.begin();m!=months.end();++m)
    {   if((*m).por)
        {
            for (auto d=(*m).days.begin();d!=(*m).days.end();++d)
                {
                    if((*d).por)
                    {
             for (auto t=(*d).tasks_of_day.begin();t!=(*d).tasks_of_day.end();++t)
             {   int sizes;
                 if (f==0)
                 {sizes=((*t).getname().length())+1;}
                 else
                 {
                 {sizes=((*t).getname().length());}
                 }
                 

                 char name[sizes];
                strcpy(name, (*t).getname().c_str());
                 int sizename=sizeof(name);
                 file.write(reinterpret_cast<char*>(&sizename),sizeof(int));
                 file.write(reinterpret_cast<char*>(name),sizename);
                 int sd=(*t).sd();
                int www[8]={(*t).sd(),(*t).sm(),(*t).sh(),(*t).smin(),(*t).fd(),(*t).fm(),(*t).fh(),(*t).fmin()};
                file.write(reinterpret_cast<char*>(www),sizeof(www));
                /*
                 file.write(reinterpret_cast<char*>(&sd),sizeof(int));
                 sd=(*t).sm();

                 file.write(reinterpret_cast<char*>(&sd),sizeof(int));
                sd=(*t).sh();

                file.write(reinterpret_cast<char*>(&sd),sizeof(int));
                sd=(*t).smin();

                file.write(reinterpret_cast<char*>(&sd),sizeof(int));

                int fd=(*t).fd();

                file.write(reinterpret_cast<char*>(&fd),sizeof(int));
                fd=(*t).fm();
 
                file.write(reinterpret_cast<char*>(&fd),sizeof(int));
                fd=(*t).fh();

                file.write(reinterpret_cast<char*>(&fd),sizeof(int));
                fd=(*t).fmin();

                file.write(reinterpret_cast<char*>(&fd),sizeof(int));
                */
                char dd[5]="done";
                f=1;
                file.write(reinterpret_cast<char*>(&dd),sizeof(char)*5);

             } 

                    }
                }
        }
    }
    char dd[5]="endd";
    file.write(reinterpret_cast<char*>(&dd),sizeof(char)*5);
    file.close();

}

void year::schedule()
{
    int cday;
    int cmonth;
    long sss;
cout<<" day-month: "  ; 
    cin>>cday;
    cin.ignore();
    cin>>cmonth;
    cin.ignore();
    cout << " ssid :";
    cin>>sss;
    int f=0;
    vector <Employee> :: iterator it= employees.begin();
for(;it != employees.end();++it)
{
    if ((*it).ssid==sss)
    { 
        f=1; 
    for(auto t=(*it).taskforthis.begin();t!=(*it).taskforthis.end();t++)
        {
            if((*t).sd()==cday &&(*t).sm()==cmonth)
            {   
                (*it).taskforthis.erase(t);               
            }
        }
    }
    if(f==1)
    {break;}
}

if(months.at(cmonth).days.at(cday).por==true)
{
    vector <task> :: iterator t=months.at(cmonth).days.at(cday).tasks_of_day.begin();
    vector<pair<int,int>> starttime;
    vector<pair<int,int>> endtime;
    vector <task> scheduleee;
    for(;t!=months.at(cmonth).days.at(cday).tasks_of_day.end();t++)
    {
        pair<int , int >st((*t).sh(),(*t).smin());
        starttime.push_back(st);
        // pair<int , int >et((*t).fh(),(*t).fmin());
        // endtime.push_back(et);
    }

    vector <task> :: iterator i=months.at(cmonth).days.at(cday).tasks_of_day.begin();
    vector<pair<int,int>> :: iterator s=starttime.begin();
    // vector<pair<int,int>> :: iterator e=endtime.begin();
    scheduleee.push_back(*i);
    (*it).taskforthis.push_back(*i);

    task a=(*i);
    i++;
    s++;
    for (;i!=months.at(cmonth).days.at(cday).tasks_of_day.end();i++,s++)
    {
        if(a.fh()<(*s).first)
        {
        scheduleee.push_back(*i);
        (*it).taskforthis.push_back(*i);
        a=(*i);
        }
        else if (a.fh()==(*s).first && a.fmin()<(*s).second)
        {
        scheduleee.push_back(*i);
        (*it).taskforthis.push_back(*i);
        a=(*i);
        }

    }
    int num=1;
    for (auto r=scheduleee.begin();r!=scheduleee.end();++r)
    {
        cout<< "(" << num << ") ";
        (*r).show();
        num++;
    }



}


}



void year::addemployee()
{
    cout <<"name is ";
    string n;
    getline(cin , n);
    cout <<"ssid is ";
    long ssi;
    cin >> ssi;
    cout <<"starts at ";
    int hs,ms;
    cin >> hs;
    cin.ignore();
    cin >> ms;
    cout <<"ends at ";
    int hf,mf;
    cin >> hf;
    cin.ignore();
    cin >> mf;
    cin.ignore();
    Employee a(n,ssi,hs,ms,hf,mf);
    employees.push_back(a);


}


void year::assign_task()
{
cout << " ssid is ";
long s;
cin >> s;
cin.ignore();
cout << " task is ";
string t;
getline(cin,t);
int f=0;
vector <task> :: iterator emp;



for(auto it = employees.begin();it != employees.end();++it)
{

    if ((*it).ssid==s)
    {  
    for(auto itit=alta.begin();itit!=alta.end();itit++)
        {
            if((*itit).getname()==t)
            {
                (*it).taskforthis.push_back(*itit);
                f=1;
                break;
            }

        }
    if(f==1)
    {break;}
    }
}

}

void year::showemployeetask()
{


long sss;
cout << " ssid :";
cin>>sss;
cin.ignore();
int f=0;
int num=1;
vector <Employee> :: iterator it= employees.begin();
for(;it != employees.end();++it)
{
    if ((*it).ssid==sss)
    { 
        f=1; 
    for (auto r=(*it).taskforthis.begin();r!=(*it).taskforthis.end();++r)
    {
        cout<< "(" << num << ") ";
        (*r).show();
        num++;
    }
    }
    if(f==1)
    {break;}
}




}




void year:: addtask(){

    string namee;
    cout << " title : ";
    getline(cin, namee);
    int startday;
    int startmonth;
    cout << " starts at : ";
    cin>>startday;
    cin.ignore();
    cin>>startmonth;
    int starthour;
    int startmin;
    cin.ignore();
    cin>>starthour;
    cin.ignore();
    cin>>startmin;
    cin.ignore();
    int finishday;
    int finishmonth;
    cout << " ends at : ";
    cin>>finishday;
    cin.ignore();
    cin>>finishmonth;
    cin.ignore();
    int finishhour;
    int finishmin;
    cin>>finishhour;
    cin.ignore();
    cin>>finishmin;
    cin.ignore();


    task a ( namee , startmonth  , startday , starthour, startmin , finishmonth , finishday, finishhour , finishmin);
    alta.push_back(a);
    months.at(startmonth).por=true;
    months.at(startmonth).days.at(startday).por=true;
    months.at(startmonth).days.at(startday).taskadd(a);
   
}



/***************************** employee *******************************/








Employee::Employee(string n , long s,int sh,int sm,int fh ,int fm)
{
   name=n;
    ssid=s;
    start_hour=sh;
    start_minute=sm;
    finish_hour=fh;
    finish_minute=fm;
}

Employee::~Employee()
{
}



