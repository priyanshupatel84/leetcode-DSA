class FoodRatings {
public:
    unordered_map<string, set<pair<int,string>>> c2s;
    unordered_map<string, pair<string,int>> f2c;

    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for (int i = 0; i < f.size(); i++) {
            c2s[c[i]].insert({-r[i], f[i]});
            f2c[f[i]] = {c[i], r[i]};
        }
    }
    
    void changeRating(string x, int y) {
        auto &z = f2c[x];
        c2s[z.first].erase({-z.second, x});
        z.second = y;
        c2s[z.first].insert({-y, x});
    }
    
    string highestRated(string c) {
        return c2s[c].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */