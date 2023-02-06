#include <iostream>
#include <set>
#include <vector>

using namespace std;

long get_max_xor(const set<long>& s) {
    long result = 0;
    for (long i : s) {
        for (long j : s) {
            if ((i ^ j) > result) result = (i ^ j);
        }
    }
    return result;
}

template <class T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "(";
    for (T t : s) {
        os << t << ", ";
    }
    os << ")";
    return os;
}

int main() {
    int q;
    cin >> q;
    set<long> s;
    long last_ans;
    vector<long> answers;
    for (int i = 0; i < q; i++) {
        long k;
        cin >> k;
        if (s.find(k) != s.end() && s.size() >= 2) { answers.push_back(last_ans); continue; }
        s.insert(k);
        //cout << "s: " << s << endl;
        last_ans = get_max_xor(s);
        answers.push_back(last_ans);
    }

    for (long a : answers) {
        cout << a << endl;
    }

    return 0;
}
