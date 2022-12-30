class Solution {
private:
    inline int genVal(int n)
    {
        int m{0};

        while (n)
            m += pow(n % 10, 2), n /= 10;

        return m;
    }
public:
    bool isHappy(int n) {
        
        set<int> token;

        token.emplace(n);

        while (n > 0)
        {
            n = genVal(n);

            if (n == 1)
                return true;
            
            if (token.find(n) != token.end())
                return false;
            
            token.emplace(n);
        }

        return false;
    }
};