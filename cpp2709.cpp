class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, int> prime_index; 
        DSU dsu(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            for (int f : factorize(nums[i])) {
                auto detected = prime_index.find(f);
                if (detected != prime_index.end())
                    dsu.Unite(i, detected->second);
                else
                    prime_index[f] = i;
            }
        }
        return dsu.IsConnected();
    }

private:
    class DSU {
    private:
        vector<int> p, s;
    public:
        DSU(int n) : p(n), s(n, -1) { 
            iota(p.begin(), p.end(), 0); 
        }
        int Leader(int v) { 
            return (p[v] == v) ? v : p[v] = Leader(p[v]); 
        }
        void Unite(int a, int b) {
            a = Leader(a), b = Leader(b);
            if (a != b) {
                if (s[a] > s[b])
                    swap(a, b);
                s[b] += s[a];
                p[a] = b;
            }
        }
        bool IsConnected() {
            return abs(*min_element(begin(s), end(s))) == s.size();
        }
    };

    const int primes[65] = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
        43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
        103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
        173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
        241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
    vector<int> factorize(int n) {
        vector<int> facts;
        for (int p : primes)
            if (n % p == 0) {
                facts.push_back(p);
                while (n % p == 0)
                    n /= p;
            }
        if (n != 1) // Some large prime
            facts.push_back(n);
        return facts;
    }
};
