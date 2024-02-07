

# include "sortCharactersByFrequency.hpp"

bool Solution::comp( pair<char, int> &a, pair<char , int> &b )
{
    return a.second > b.second;
}

string Solution::frequencySort( string s )
{
    std::unordered_map<char , int> umap;
    for ( int i = 0; i < s.length(); i++ )
        umap[s[i]]++;
    s = "";
    std::vector< pair< char, int > > umapsorted(umap.begin(), umap.end());
    sort (umapsorted.begin(), umapsorted.end(), comp);
    for ( auto const& pair : umapsorted )
        for ( int i = 0; i < pair.second; i++ )
            s += pair.first;
    return s;
}