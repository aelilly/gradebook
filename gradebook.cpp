// gradebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Grade {
    string name;
    int worth, earned;
};

int main()
{
    int c{};
    vector<Grade>assnm(1);
    
    do {
        cout << "Input assignment name: ";
        getline(cin, assnm[c].name);
        if (c > 0)
            getline(cin, assnm[c].name);
        if (assnm[c].name == "stop")
            break;

        cout << "Input point worth: ";
        cin >> assnm[c].worth;

        cout << "Input points earned: ";
        cin >> assnm[c].earned;
        c++;
        assnm.resize(c + 1);
    } while (assnm[c].name != "stop");

    cout << endl << "GRADES" << endl;

    int ;
    double gradeAvg, sumEarned{}, sumWorth{};
    for (int i = 0; i < (assnm.size()-1); i++) {
        cout << setw(20) << left << assnm[i].name << assnm[i].earned << " / " << assnm[i].worth << endl;
        sumEarned += assnm[i].earned;
        sumWorth += assnm[i].worth;
    }
    for (int i = 0; i < 13; i++)
        cout << "- ";
    gradeAvg = sumEarned / sumWorth * 100;
    cout << endl << setw(20) << left << "AVG" << sumEarned << " / " << sumWorth;
    cout << setprecision(1) << fixed << " (" << gradeAvg << ")";
}

/*
Input assignment name: Week 14 Lab
Input point worth: 20
Input points earned: 20
Input assignment name: Week 13 Lab
Input point worth: 20
Input points earned: 15
Input assignment name: stop

GRADES
Week 14 Lab         20 / 20
Week 13 Lab         15 / 20
- - - - - - - - - - - - -
AVG                 35 / 40 (87.5)
*/