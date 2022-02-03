#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define INF 1e8
double pi = 2 * acos(0.0);
#define ALL(x) x.begin() , x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

vl A,p;
void print_LIS(int i) {                          // backtracking routine
  if (p[i] == -1) { printf("%d", A[i]); return; }// base case
  print_LIS(p[i]);                               // backtrack
  printf(" %d", A[i]);
}
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            A.push_back(x);
        }
        

        ll LIS[100][100] // LIS for any (i, j)
        for(int z = 0; z < n; z++){
            int k = z, lis_end = z;
            vl L(n, 0), L_id(n, 0);
            p.assign (n, -1)

            for (int i = z; i < n; ++i) {
                int pos = lower_bound(L.begin() + z, L.begin()+k, c[i]) - L.begin();
                if(A[i]==L[pos])pos++;//For non strickly increasing subsequence
                L[pos] = c[i];
                L_id[pos] = i;
                p[i] = pos ? L_id[pos-1] : -1;
                if (pos == k) {
                k = pos+1;
                lis_end = i;
                }
            }
            for(int i = z; i < n; i++)
            {
                if(p[i] == -1) LIS[z][i] = 1;
                else LIS[z][i] = 1 + LIS[z][p[i]];
            }
        }
        cout<<"Final LIS is of length: "<< k<<"\n";
        print_LIS(lis_end);cout<<"\n";


        //DP
        vl LI(n, 0), LD(n,0);
        ll in=0,dec=0;
        for(int i=0;i<n;i++)
        {
            LI[i]=1;
            LD[i]=1;
            for(int j=0;j<i;j++)
            {
                if(A[j]>A[i])
                {
                    LI[i]=max(LI[i],LI[j]+1);
                }
                if(A[j]<A[i])
                {
                    LD[i]=max(LD[i],LD[j]+1);
                }
            }
            in=max(in,LD[i]);
            dec=max(dec,LI[i]);

        }
    }

    return 0;
}
