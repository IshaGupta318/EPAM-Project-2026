#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long B;

    // Input number of students and total budget
    cin >> N >> B;

    vector<long long> scholarship(N);

    // Input minimum scholarship required by each student
    for (int i = 0; i < N; i++) {
        cin >> scholarship[i];
    }

    // Sort scholarships in increasing order
    sort(scholarship.begin(), scholarship.end());

    long long total = 0;
    int count = 0;

    // Select students with minimum scholarship requirements first
    for (int i = 0; i < N; i++) {

        if (total + scholarship[i] <= B) {
            total += scholarship[i];
            count++;
        }
        else {
            break;
        }
    }

    // Print maximum number of students
    cout << count << endl;

    return 0;
}