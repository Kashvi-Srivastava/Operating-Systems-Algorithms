#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool sortcol (vector <float> &v1, vector <float> &v2)
{
    if(v1[1]!=v2[1])
        return v1[1]<v2[1];
    return v1[2]<v2[2];
}
int main()
{
    int n;
    cout<<"Enter the number of processes"<<endl;
    cin>>n;
    cout<<"Enter the following for each of the processes"<<endl;
    vector < vector<float> > sjf;
    sjf.resize(n, vector<float> (5,0));
    //First column contains process index
    for(int i=0;i<n;i++)
        sjf[i][0] = i+1;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Burst time for process "<<i+1<<endl;
        //Second column contains burst time
        cin>>sjf[i][1];
        cout<<"Enter Arrival time for process "<<i+1<<endl;
        //Third column contains arrival time
        cin>>sjf[i][2];
    }
    sort(sjf.begin(),sjf.end(),sortcol);
    float total = 0;
    for(int i=0;i<n;i++)
        total += sjf[i][1]; //Total Burst time
    float timer = 0;
    int i = 0;
    int counter = 0;
    bool processed[n] = {false};
    //Fourth column contains the turn-around time
    while(counter<n)
    {
        if(timer>=sjf[i][2]&&processed[i]==false)
        {
            timer += sjf[i][1];
            sjf[i][3] = timer - sjf[i][2];
            counter++;
            processed[i] = true;
            i = 0;
        }
        else
            i++;
        if(i==n)
        {
            timer++;
            i=0;
        }
    }
    //Fifth column contains the waiting time
    float tt = 0, wt = 0;
    for(int i=0;i<n;i++)
    {
        sjf[i][4] = sjf[i][3] - sjf[i][1];
        tt += sjf[i][3];
        wt += sjf[i][4];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
            cout<<sjf[i][j]<<" ";
        cout<<endl;
    }
    cout<<"The average turn-around time is "<<tt/n<<endl;
    cout<<"The average waiting time is "<<wt/n<<endl;
    return 0;}
