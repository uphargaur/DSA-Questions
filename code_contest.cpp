 #include <bits/stdc++.h>
 #define all(x) (x).begin(), (x).end()
 // #define int long long int 

 using namespace std;

 int getPrimeFactors(long long int n) 
 {
    vector<long long int> factors;
    // Check for factors 2 and 3
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    while (n % 3 == 0) {
        factors.push_back(3);
        n = n / 3;
    }

    // Check for factors up to sqrt(n)
    for (long long int i = 5; i * i <= n; i = i + 6) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
        while (n % (i + 2) == 0) {
            factors.push_back(i + 2);
            n = n / (i + 2);
        }
    }

    // Check for remaining prime factors
    if (n > 3) {
        factors.push_back(n);
    }
    // for(auto x : factors)
    // {
    // 	cout<<x;
    // }
    int sz=factors.size();
    sort(all(factors));
    for (auto x: factors)
    {
    	cout<<x<<" ";
    }
    cout<<factors[sz-1]*factors[sz-2];

    return sz;
}

 
int main() {
     
     int t;
     cin>>t;
     while (t>0)
             {
                
                long long int n;cin>>n; 
                long long int x= getPrimeFactors(n);
                // cout<<x;
               // cout<<x*(x+1)<<endl; 
			           
                 
                 
             t--;
             }
             return 0;
 }