

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;



class Solution {
public:
    
    
    bool numberBooquetsInDays(vector<int>& bloomDay, int &m, int &k, int &mid)
    {
        int count = 0;
        int flowers = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                flowers++;
                if (flowers == k)
                {
                    count++;
                    flowers = 0;
                }
            }
            else 
                flowers = 0;
        }
        return count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        if (static_cast<long long>(m) * k > n) {
            return -1;
        }
        int res = -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int mid;
        for (;l < r;)
        {
            mid = l +(r - l) / 2;

            if (numberBooquetsInDays(bloomDay,m, k, mid) == true)
                r = mid;
            else 
                l = mid + 1;
        }
        return l;
    }
};
// class Solution {
// public:
//     void generateBouquetes(vector<int>& bloomDay,vector<int>& bloomFlower, int &i)
//     {
//         for (int u = 0; u < bloomDay.size(); u++)
//         {
//             if (bloomDay[i] >= bloomDay[u])
//                 bloomFlower[u] = 1;
//             else 
//                 bloomFlower[u] = 0;
//         }
//     }
    
//     void nbBouquwtsInDay(std::vector<int> &bloomFlower, int &k, int &nbBouquets)
//     {
//         nbBouquets = 0;
//         int diff = 0;
//         for (int i = 0 ,  j = 0 ; i < bloomFlower.size() && j < bloomFlower.size();)
//         {
//             if (bloomFlower[j] == 1)
//             {
//                 j++;
//                 diff = j - i;
//                 if (diff == k)
//                 {
//                     nbBouquets++;
//                     i = j;
//                 }
//             }
//             else
//             {
//                 j = i;
//                 j++;
//                 i++;
//             }
//         }
//     }
    
//     int minDays(vector<int>& bloomDay, int m, int k) 
//     {
//         int n = bloomDay.size();
//         if (m * k > n)
//             return -1;
//         std::multimap<int , int> copyBloomDay;
//         std::vector<int> bloomFlower(n);
//         int nbBouquets;
//         for (int i =0; i < n; i++)
//             copyBloomDay.insert({bloomDay[i], i});
//         for (auto x : copyBloomDay)
//         {
//             generateBouquetes(bloomDay, bloomFlower , x.second);
//             nbBouquwtsInDay(bloomFlower, k, nbBouquets);
//             if (m <= nbBouquets)
//                 return x.first;
//         }
//         return -1;
//     }
// };