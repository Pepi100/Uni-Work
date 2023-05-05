#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


//#define x first
//#define y second

using namespace std;



bool comp(double a, double b) {
    return a < b;
}

int main() {

    int N, M;

    vector <double> stanga, dreapta, sus,jos;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        double a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b < 0) {
                sus.push_back(-1.0* c / b);
            }
            else {
               jos.push_back(-1.0* c / b);
            }
        }
        else {
            if (a < 0) {
                dreapta.push_back(-1.0* c / a);
            }
            else {
                stanga.push_back(-1.0* c / a);
            }
        }
    }


    //sortam vectorii
    sort(sus.begin(), sus.end(), comp);
    sort(jos.begin(),jos.end(), comp);
    sort(stanga.begin(), stanga.end(), comp);
    sort(dreapta.begin(), dreapta.end(), comp);

    cin >> M;
    for (int i = 1; i <= M; i++) {
        double x, y;
        cin >> x >> y;
        if (stanga.size() == 0 || dreapta.size() == 0 || sus.size() == 0 ||jos.size() == 0) {
            cout << "NO\n";
            continue;
        }

        //calcutam pentru fiecare direcie cea mai mica dreapta mai mare decat x
        auto stangait = upper_bound(stanga.begin(), stanga.end(), x, comp);
        if (stangait == stanga.end()) {
            cout << "NO\n";
            continue;
        }
        auto dreaptait = lower_bound(dreapta.begin(), dreapta.end(), x, comp);

        if (dreaptait == dreapta.begin()) {
            cout << "NO\n";
            continue;
        }

        if (dreaptait == dreapta.end()) {
            if (dreapta.size() == 0 || dreapta[dreapta.size() - 1] > x) {
                cout << "NO\n";
                continue;
            }
        }


        double rival = dreapta[dreaptait - dreapta.begin() - 1];
        double leval = stanga[stangait - stanga.begin()];


        auto susit = lower_bound(sus.begin(), sus.end(), y, comp);
        if (susit == sus.begin()) {
            cout << "NO\n";
            continue;
        }
        if (susit == sus.end()) {
            if (sus.size() == 0 || sus[sus.size() - 1] > y) {
                cout << "NO\n";
                continue;
            }
        }
        auto josit = upper_bound(jos.begin(),jos.end(), y, comp);
        if (josit ==jos.end()) {
            cout << "NO\n";
            continue;
        }
        double susval = sus[susit - sus.begin() - 1];
        double doval =jos[josit -jos.begin()];


        cout << "YES\n";
        cout << fixed << setprecision(6) << (leval - rival) * (doval - susval) << "\n";

    }
    return 0;
}
