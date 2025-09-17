class FoodRatings {
public:
    typedef pair<int, string> pp;
    unordered_map<string, int> foodRating;
    unordered_map<string, set<pp>> cuisineRating;
    unordered_map<string, string> foodToCuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            foodRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
            cuisineRating[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        cuisineRating[cuisine].erase({-foodRating[food], food});
        cuisineRating[cuisine].insert({-newRating, food});
        foodRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineRating[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */