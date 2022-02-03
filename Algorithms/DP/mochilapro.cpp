#include<bits/stdc++.h>
using namespace std;
int usados=0,espacio_usado;
int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1][3];


   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0){
               K[i][w][0]= 0;
               K[i][w][1]= 0;
               K[i][w][2]= 0;
           }
           else if (wt[i-1] <= w){
                 K[i][w][0] = max(val[i-1] + K[i-1][w-wt[i-1]][0],K[i-1][w][0]);
                 if(K[i-1][w][0]>val[i-1] + K[i-1][w-wt[i-1]][0])
                 {
                     K[i][w][1]=K[i-1][w][1];
                     K[i][w][2]=K[i-1][w][2];
                 }
                 else{
                    K[i][w][1]=K[i-1][w-wt[i-1]][1]+wt[i-1];
                    K[i][w][2]=K[i-1][w-wt[i-1]][2]+1;
                 }
       }
           else
           {
                 K[i][w][0] = K[i-1][w][0];
                 K[i][w][1] = K[i-1][w][1];
                 K[i][w][2] = K[i-1][w][2];
           }
       }
   }
    usados=K[n][W][2];
    espacio_usado=K[n][W][1];
    return K[n][W][0];
}

int main()
{
    int v,W,t;
    cin>>t;
    for(int o=0;o<t;o++)
    {
    W=50;
    usados=0;
    cin>>v;
    int val[v];
    int wt[v];
    for(int i=0;i<v;i++)
    {
        cin>>val[i];
        cin>>wt[i];
    }
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val, n)<<" brinquedos"<<endl;
    cout<<"Peso: "<<espacio_usado<<" kg"<<endl;
    cout<<"sobra(m) "<<v-usados<<" pacote(s)"<<endl<<endl;
    }
    return 0;
}
