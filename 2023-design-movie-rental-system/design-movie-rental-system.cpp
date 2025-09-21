class MovieRentingSystem {
public:
    typedef pair<int, int> pp;
    unordered_map<int, set<pp>> movieToShop;
    map<pp, int> moviePrice;
    set<vector<int>> rented;
    int shops;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shops = n;
        for(auto x : entries) {
            movieToShop[x[1]].insert({x[2], x[0]});
            moviePrice[{x[0], x[1]}] = x[2];
        }
    }
    
    vector<int> search(int movie) {
        int count = 0;
        vector<int> ans;
        vector<pp> v;
        while(count < 5 && movieToShop[movie].size()) {
            pp t = *(movieToShop[movie].begin());
            ans.push_back(t.second);
            v.push_back(t);
            movieToShop[movie].erase(t);
            count++;
        }
        for(auto x : v) movieToShop[movie].insert(x);
        return ans;
    }
    
    void rent(int shop, int movie) {
        int p = moviePrice[{shop, movie}];
        movieToShop[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = moviePrice[{shop, movie}];
        movieToShop[movie].insert({p, shop});
        rented.erase({p, shop, movie});
    }
    
    vector<vector<int>> report() {
        int count = 0;
        vector<vector<int>> ans;
        vector<vector<int>> v;
        while(count < 5 && rented.size()) {
            auto t = *(rented.begin());
            ans.push_back({t[1], t[2]});
            v.push_back(t);
            rented.erase(t);
            count++;
        }
        for(auto x : v) rented.insert(x);
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */