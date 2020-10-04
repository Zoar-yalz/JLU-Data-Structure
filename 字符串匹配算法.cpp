#includeiostream
#includestring
using namespace std;
void fail(string p, int f);
int main()
{
    string s, p;
    cin  s;
    cin  p;
    int m = p.length();
    int n = s.length();
    int i = 0;
    int j = 0;
    int next = new int[m];
    fail(p, next);
    for (int l = 0; l  m; l++)
    {
        printf(%d , next[l]);
    }
    cout  n;
    while (i  m && j  n)
    {
        if (p[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                i = next[i - 1] + 1;
            }
        }
    }
    if (i  m)
    {
        printf(%d, -1);
    }
    else
    {
        printf(%d, j - m);
    }
}
void fail(string p, int f)
{
    int m = p.length();
    f[0] = -1;
    int i = 0;
    for (int j = 1; j  m; j++)
    {
        i = f[j - 1];
        while (i = 0 && p[j] != p[i + 1])
        {
            i = f[i];
            
        }
        if(p[j]==p[i+1])
            {
                f[j]=i+1;
            }
            else
            {
                f[j]=-1;
            }
    }
}
