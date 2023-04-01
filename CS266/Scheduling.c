#include <stdio.h>      
#include <conio.h>  
#include <stdlib.h>
void FCFS(int n, int burst_time[], int arrival_time[]){
    int i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0, cpu_utilisation = 0;
    
    int waiting_time[n], turnaround_time[n];

    // sort processes by arrival time
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arrival_time[j] > arrival_time[j+1])
            {
                // swap arrival time
                int temp = arrival_time[j];
                arrival_time[j] = arrival_time[j+1];
                arrival_time[j+1] = temp;

                // swap burst time
                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;
            }
        }
    }

    // calculating waiting time and turnaround time
    int current_time = 0;
    for(i = 0; i < n; i++)
    {
        if(current_time < arrival_time[i])
        {
            current_time = arrival_time[i];
        }
        waiting_time[i] = current_time - arrival_time[i];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        current_time += burst_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        cpu_utilisation += burst_time[i];
    }

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage CPU Utilisation: %.2f", cpu_utilisation/current_time*100);

}
int main()
{
    int n = 10;
    int burst_time[n], arrival_time[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        int x = rand()%26;
        if(x<5){
            x += 5;
        }
        burst_time[i] = x;
    }
    for(int i=0;i<n;i++){
        int x = rand()%30;
        arrival_time[i] = x;
    }
    FCFS(n,burst_time,arrival_time);
    return 0;
}