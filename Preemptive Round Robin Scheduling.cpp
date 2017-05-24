#include <bits/stdc++.h>

using namespace std;

typedef struct process
{
    int processId,arrivalTime,burstTime,finishTime;
    float waitingTime,turnAroundTime;
};

process process[101],hProcess[101];
queue<int> que;
int input();
void ganttChart(int in);
void turnwaitTime(int in);
void display(int in);

int main()
{
    cout<< " *************************************************************************\n";
    cout<< " ***   Problem Name  : Preemptive Round Robin Scheduling               ***\n";
    cout<< " ***   Type          : Time Schedule                                   ***\n";
    cout<< " ***   Author        : Al-Amin                                         ***\n";
    cout<< " ***   Student ID    :                                                 ***\n";
    cout<< " ***   Course        : Operating System Lab (CSE 324)                  ***\n";
    cout<< " ***   University    : DIU, Dept. of CSE                               ***\n";
    cout<< " ***   Facebook      : http://www.facebook.com/alamin25                ***\n";
    cout<< " ***   E-mail        : ialamin.pro@gmail.com,alamin.iyakub@diu.edu.bd  ***\n";
    cout<< " ***   Facebook      : http://www.facebook.com/alamin25                ***\n";
    cout<< " *************************************************************************\n";
    //#ifdef localhost

        //freopen("output.txt", "w", stdout);
     //# endif
    char ch='Y';
    while(ch=='y'||ch=='Y'){
        freopen("input.txt", "r", stdin);
        int in = input();
        ganttChart(in);
        turnwaitTime(in);
        display(in);
        cout<<"\n\nAre you want to continue? Y/N: ";
        cin>>ch;
        //if(ch!='y'||ch!='Y'){ break;}
    }

    return 0;
}

int input()
{
    int i,n;
    cout<<"Enter The no. of process: ";
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\nEnter The arrival time And The burst time for process P%d: ",i);
        scanf("%d %d",&process[i].arrivalTime,&process[i].burstTime);
        process[i].processId=i;
    }

    cout<<"\nInputs given by the user are:\n";
    cout<<"===========================";
    cout<<"\n Process\tAT\tBT";
    for(i=1;i<=n;i++)
        printf("\n P%d\t\t%d\t%d",process[i].processId,process[i].arrivalTime,process[i].burstTime);
    cout<<"\n===========================";
    for(i=1;i<=n;i++)
        {
            hProcess[i]=process[i];
        }
return n;
}


void ganttChart(int n)
{
    int i,timeQuantum,temp,nextvalue,nextArray;
    nextvalue=process[1].arrivalTime;
    cout<<"\nEnter time Quantum/Slice: ";
    cin>>timeQuantum;
    nextvalue=hProcess[1].arrivalTime;
    cout<<"Gantt chart is as follows\n\n";
    cout<<hProcess[1].arrivalTime;
    for(i=1;hProcess[i].arrivalTime<=nextvalue;i++)
        {
            que.push(hProcess[i].processId);
        }
    nextArray=hProcess[i].arrivalTime;

    while(!que.empty())
    {
        temp=que.front();
        que.pop();
        if(hProcess[temp].burstTime>=timeQuantum)
        {
            nextvalue=nextvalue+timeQuantum;
        }
        else
        {
            nextvalue=nextvalue+hProcess[temp].burstTime;
        }

        cout<<" | P"<<hProcess[temp].processId<<" | "<<nextvalue;

        hProcess[temp].burstTime=hProcess[temp].burstTime-timeQuantum;
        if(nextvalue<nextArray)
        {
            if(hProcess[temp].burstTime>0)
            que.push(temp);
            if(hProcess[temp].burstTime<=0)
            process[temp].finishTime=nextvalue;
        }
        else
        {
            while(i<=n&&hProcess[i].arrivalTime<=nextvalue)
            {
                que.push(hProcess[i].processId);
                i++;
            }
            if(i<=n)
            {
                nextArray=hProcess[i].arrivalTime;
            }

            if(hProcess[temp].burstTime>0)
            {
                que.push(temp);
            }

            if(hProcess[temp].burstTime<=0)
            {
                process[temp].finishTime=nextvalue;
            }
        }
    }
}

void turnwaitTime(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        process[i].turnAroundTime=process[i].finishTime-process[i].arrivalTime;
        process[i].waitingTime=process[i].turnAroundTime-process[i].burstTime;
        process[0].turnAroundTime=process[0].turnAroundTime+process[i].turnAroundTime;
        process[0].waitingTime=process[0].waitingTime+process[i].waitingTime;
    }
    process[0].turnAroundTime=process[0].turnAroundTime/n;
    process[0].waitingTime=process[0].waitingTime/n;
}

void display(int n)
{
    int i;

    cout<<"\n\n================ TABLE ========================\n";
    cout<<"\nProcess\tAT\tBT\tFT\tTAT\tWT";
    for(i=1;i<=n;i++)
    printf("\nP%d\t%d\t%d\t%d\t%0.2f\t%0.2f",process[i].processId,process[i].arrivalTime,process[i].burstTime,process[i].finishTime,process[i].turnAroundTime,process[i].waitingTime);
    cout<<"\n\n===============================================";
    printf("\nAverage Turn Around Time: %0.2f",process[0].turnAroundTime);
    printf("\nAverage Waiting Time: %0.2f",process[0].waitingTime);
}
