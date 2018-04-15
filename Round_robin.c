//RR scheduling
#include<iostream>
using namespace std;
void findWaitingTime(int process[], int n, int bt[], int wt[], int q){
int rem_bt[n];
for (int i = 0 ; i < n ; i++)
    rem_bt[i] =  bt[i];

int t = 0; 
while (1)
{
    bool done = true;
for (int i = 0 ; i < n; i++)
    {
        if (rem_bt[i] > 0)
        {
            done = false;
            if (rem_bt[i] > q)
            {t += q;
	   rem_bt[i] -= q;
            }
            else
            {
                t = t + rem_bt[i];
                wt[i] = t - bt[i];
                rem_bt[i] = 0;
            }
        }
    }
    if (done == true)
      break;
}
}
void findTurnAroundTime(int process[], int n,
                    int bt[], int wt[], int tat[])
{
for (int i = 0; i < n ; i++)
    tat[i] = bt[i] + wt[i];
}
void findavgTime(int process[], int n, int bt[],
                                 int q)
{
int wt[n], tat[n], total_wt = 0, total_tat = 0;

findWaitingTime(process, n, bt, wt, q);
findTurnAroundTime(process, n, bt, wt, tat);
cout << "process "<< " Burst time "
     << " Waiting time " << " Turn around time\n";
for (int i=0; i<n; i++)
{
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
         << wt[i] <<"\t\t " << tat[i] <<endl;
}

cout << "Average waiting time = "
     << (float)total_wt / (float)n;
cout << "\nAverage turn around time = "
     << (float)total_tat / (float)n;
}

int main()
{
int process[] = { 1, 2, 3};
int n = sizeof process / sizeof process[0];
int burst_time[] = {10, 5, 8};
int q = 2;
findavgTime(process, n, burst_time, q);
return 0;
}
