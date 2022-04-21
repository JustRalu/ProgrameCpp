#include <iostream>
#include <cstring>

using namespace std;

void tipar2(int v[], int n, char s[])
{
    for(int i = 0; i < strlen(s); i ++)
        cout << v[i] << s[i];
    cout << v[n-1];
    cout << endl;
}

int verificare(int v[], int n, char s[])
{
    for(int i = 0; i < strlen(s); i ++)
        if(s[i] == '<')
        {
            if(v[i] >= v[i+1])
                return 0;
        }
        else
            if(v[i] <= v[i+1])
                return 0;
    return 1;
}
void tipar(int v[], int n)
{
     for(int i = 0; i < n; i ++)
        cout << v[i] << " ";
     cout << endl;

}
int solutie(int k, int n)
{
    return k == n - 1;
}

int succesor(int v[], int k, int n)
{
    if(v[k] < n)
    {
        v[k]++;
        return 1;
    }
    return 0;
}

int valid(int v[], int k)
{
    for(int i = 0; i < k; i ++)
        if(v[i] == v[k])
        return 0;
    return 1;
}


void init(int v[], int k)
{
    v[k] = 0;
}

void backtrack(int n, char s[])
{
    int v[101], k = 0, as, ev;
    init(v,k);

    while(k >= 0)
    {
        do
        {
           as =  succesor(v,k,n);
            if(as)
            {
                ev = valid(v,k);
            }
        }while(as && !ev);

        if(as)
            if(solutie(k,n))
            {
                ///tipar(v,n);
                if(verificare(v,n,s))
                {
                    tipar2(v,n,s);
                    break;
                }

            }

            else
            {
                k ++;
                init(v,k);
            }
       else
            k --;


    }
}
int main()
{
    int n;

    char s[101];
    cin >> s;
    n = strlen(s)+1;
   backtrack(n,s);

    return 0;
}
