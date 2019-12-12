#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void left(vector <int> & v, int k)
{
    for(int i=v.size()-1;i>=0;i--)
    {
        v[i] = v[i-1];
    }
    v[0] = k;
}
int main()
{
    int n;
    vector <int> pages;
    cout<<"Enter number of page requirements"<<endl;
    cin >> n;
    pages.resize (n,0);
    cout<<"Enter page requirements"<<endl;
    for(int i=0;i<n;i++)
        cin>>pages[i];
    int frames;
    cout<<"Enter number of page frames"<<endl;
    cin >> frames;
    vector <int> state;
    state.resize (frames,-1);
    int faults = 0;
    for(int i=0;i<n;i++)
    {
        if(find(state.begin(),state.end(),pages[i])== state.end())
        {
            faults++;
            left(state,pages[i]);
        }
        else
            continue;
    }
    cout<<"Number of page faults are "<<faults<<endl;
	return 0;
}
