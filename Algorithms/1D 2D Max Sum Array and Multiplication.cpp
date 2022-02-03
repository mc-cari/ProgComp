#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
#define INF 1e8
double pi = 2 * acos(0.0);
#define ALL(x) x.begin() , x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

int main()
{
    // 1D Max Array Sum
    int n = 9, A[] = { 4, -5, 4, -3, 4, 4, -4, 4, -5 }; //Allow all negative numbers
    int sum = A[0], ans = A[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(A[i] + sum, A[i]); //Ignores sum if prev sum is worse than A[i]
        ans = max(ans, sum);
    }
    cout<<ans<<"\n";

    // 2D Max Array Sum
    int B [100][100];
    ans = -INF;
    cin>>n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        cin >> B[i][j];
        if (j > 0) B[i][j] += B[i][j-1]; //Acum sum per Row
    }
    for (int l = 0; l < n; l++) for (int r = l; r < n; r++)
    {
        sum = B[0][r];
        int SubAns = B[0][r];
        if (l > 0){ sum -= B[0][l-1]; SubAns -= B[0][l-1]; }
        for (int row = 1; row < n; row++)
        {
            int aux = B[row][r];
            if(l > 0) aux -= B[row][l-1];
            sum = max(sum + aux, aux);
            SubAns = max (SubAns, sum);
        }
        ans = max(ans, SubAns);
    }
    cout << ans << "\n";

    // Max Array Multiplication
    vl c;
    bool o=0;
    ans = 1;
    ll miniend=1, maxiend=1;
    for (int i = 0; i < c.size(); i++)
    {
        if(c[i]>0)
        {
            o=1;
            if(miniend < 0)miniend*=c[i];
            maxiend *= c[i];
        }
        else if(c[i] == 0)
        {
            miniend = 1;
            maxiend = 1;
        }
        else
        {
            int aux = maxiend;
            maxiend = max(1LL, miniend * c[i]);
            miniend = aux*c[i];
        }
        ans = max(ans,maxiend);
    }
    if(ans == 1 && !o)cout<<"0\n";
    else
    {
        cout << ans << "\n";
    }

}
