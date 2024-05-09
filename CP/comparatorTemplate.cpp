
// For set 
struct compare {
    bool operator() (const int& x, const int& y) const {
        return x<y; // if x<y then x will come before y. Change this condition as per requirement
    }
};
int main()
{
  set<int,compare> s; //use the comparator like this
}
