//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
public:
    vector<int> t, lazy;
    int n;
    segmentTree(int n)
    {
        this->n = n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    void push(int v, int tl, int tr)
    {
        if (lazy[v] != 0)
        {
            t[v] = max(t[v], lazy[v]);
            if (tl != tr)
            {
                lazy[v * 2] = max(lazy[v], lazy[v * 2]);
                lazy[v * 2 + 1] = max(lazy[v], lazy[v * 2 + 1]);
            }
            lazy[v] = 0;
        }
    }
    template <class T>
    void update(T v, T tl, T tr, T l, T r, T val)
    {
        if (tl > r || tr < l)
            return;
        if (t[v] >= val)
            return;
        push(v, tl, tr);
        if (tl >= l and tr <= r)
        {
            t[v] = max(t[v], val);
            if (tl != tr)
            {
                lazy[v * 2] = max(val, lazy[v * 2]);
                lazy[v * 2 + 1] = max(val, lazy[v * 2 + 1]);
            }
            return;
        }
        T tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
    }
    template <class T>
    T get_query(T v, T tl, T tr, T p)
    {
        if (tl > tr)
            return 0;
        push(v, tl, tr);
        if (tr == tl)
            return t[v];
        T tm = (tl + tr) / 2;
        if (tm >= p)
        {
            return get_query(v * 2, tl, tm, p);
        }
        else
            return get_query(v * 2 + 1, tm + 1, tr, p);
    }
    template <class T>
    void update(T l, T r, T val)
    {
        update(T(1), T(0), T(n - 1), l, r, val);
    }
    template <class T>
    T get_query(T r)
    {
        return get_query(T(1), T(0), T(n - 1), r);
    }
};

// may! I hadn't understand properly.
void Solution()
{
    int n, m;
    cin >> n >> m;
    int tp, l, r, val, x;
    segmentTree st(n);
    while (m--)
    {
        cin >> tp;
        if (tp == 1)
        {
            cin >> l >> r >> val;
            r--;
            st.update(l, r, val);
        }
        else
        {
            cin >> x;
            int ans = st.get_query(x);
            cout << ans << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    // #endif

    int tt = 1;
    while (tt--)
    {
        Solution();
    }

    return 0;
}