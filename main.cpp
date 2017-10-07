#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_input(int n, int seed) {
    vector<int> d(n * n);
    for (size_t i = 0; i < d.size(); ++i) {
        d[i] = seed;
        seed = ((long long) seed * 197 + 2017) & 987654;
    }
    return d;
}

long long get_hash(const vector<int>& d) {
    const long long MOD = 987654321054321LL;
    const long long MUL = 179;
    
    long long result_value = 0;
    for (size_t i = 0; i < d.size(); ++i)
        result_value = (result_value * MUL + d[i]) & MOD;
    return result_value;
}

void transpose(vector<int>& vec, int n, int chunk, int i_0, int j_0, int side)
{
    for (size_t i = 0; i < side; i += chunk)
    {
        for (size_t j = 0; j < side; j += chunk)
        {
            for (size_t ib = 0; ib < chunk && i + ib < side; ++ib)
            {
                for (size_t jb = 0; jb < chunk && j + jb < side; ++jb)
                {
                    if(j + jb > i + ib)
                        swap(vec[(i_0 + i + ib) * n + j_0 +j + jb] , vec[(i_0 + j + jb) * n + j_0 + i + ib]);
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int n, seed, chunk = 16;
    scanf("%d", &n);
    scanf("%d", &seed);
    vector<int> vec = generate_input(n, seed);
    int k, i_0, j_0, side;
    scanf("%d", &k);
    for (int kk = 0; kk < k; kk++)
    {
        scanf("%d", &i_0);
        scanf("%d", &j_0);
        scanf("%d", &side);
        transpose(vec, n, chunk, i_0, j_0, side);

    }
    printf("%lld\n", get_hash(vec));
}

