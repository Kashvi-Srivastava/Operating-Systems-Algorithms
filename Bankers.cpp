#include<iostream>
using namespace std;
const int P = 5;
const int R = 3;
// Function to find the need of each process
void calculateNeed(int need[P][R], int maxm[P][R], int allot[P][R])
{
    for (int i = 0 ; i < P ; i++)
        for (int j = 0 ; j < R ; j++)
            need[i][j] = maxm[i][j] - allot[i][j];
}
// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][R],
            int allot[][R])
{
    int need[P][R];
    calculateNeed(need, maxm, allot);
    bool finish[P] = {0};
    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R ; i++)
        work[i] = avail[i];
    int count = 0;
    while (count < P)
    {
        bool found = false;
        for (int p = 0; p < P; p++)
        {
            if (finish[p] == 0)
            {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;
                if (j == R)
                {
                    for (int k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];
                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = true;
                }
            }
        }
        if (found == false)
        {
            cout << "System is not in safe state";
            return false;
        }
    }
    cout << "System is in safe state.\nSafe"
         " sequence is: ";
    for (int i = 0; i < P ; i++)
        cout << safeSeq[i] << " ";
    return true;
}
int main()
{
    int processes[] = {0, 1, 2, 3, 4};
    int avail[R];
    int maxm[P][R];
    int allot[P][R];
    cout<<"Enter the initial available resources"<<endl;
    for(int i=0;i<R;i++)
        cin>>avail[i];
    for(int i=0;i<P;i++)
    {
        cout<<"Enter the max resource req for process : "<<i<<endl;
        for(int j=0;j<R;j++)
            cin>>maxm[i][j];
    }
    for(int i=0;i<P;i++)
    {
        cout<<"Enter the initial allocated resource for process : "<<i<<endl;
        for(int j=0;j<R;j++)
            cin>>allot[i][j];
    }
    isSafe(processes, avail, maxm, allot);
    return 0;
}
