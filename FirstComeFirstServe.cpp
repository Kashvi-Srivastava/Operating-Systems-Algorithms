#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool sortcol(vector<float> &v1,vector<float> &v2)
{
    return (v1[2]<v2[2]);
}
int main()
{
    int n;
    cout<<"Enter number of processes"<<endl;
    cin>>n;
    cout<<"Enter the following for each of the processes"<<endl;
    vector < vector<float> > fcfs;
    fcfs.resize(n, vector<float> (5,0));
    //First column contains process index
    for(int i=0;i<n;i++)
        fcfs[i][0] = i+1;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst time for process"<<i+1<<endl;
        //Second column contains burst time
        cin>>fcfs[i][1];
        cout<<"Enter Arrival time for process"<<i+1<<endl;
        //Third column contains arrival time
        cin>>fcfs[i][2];
    }
    //We sort the 2-D vector on the basis of arrival times
    sort(fcfs.begin(),fcfs.end(),sortcol);
    //Fourth column contains turn-around time
    float sum = 0;
    for(int i=0;i<n;i++)
    {
        sum = sum + fcfs[i][1];
        fcfs[i][3] = sum - fcfs[i][2];
    }
    //Fifth column contains waiting time
    for(int i=0;i<n;i++)
    {
        fcfs[i][4] = fcfs[i][3] - fcfs[i][1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
            cout<<fcfs[i][j]<<" ";
        cout<<endl;
    }
    float wt = 0;
    for(int i=0;i<n;i++)
    {
        wt += fcfs[i][4];
    }
    cout<<"Average waiting time is "<<wt/n<<endl;
    float tt = 0;
    for(int i=0;i<n;i++)
    {
        tt += fcfs[i][3];
    }
    cout<<"Average turn-around time is "<<tt/n<<endl;
    return 0;
}
