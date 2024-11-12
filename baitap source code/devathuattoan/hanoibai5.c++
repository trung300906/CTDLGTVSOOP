#include<bits/stdc++.h>
using namespace std;

struct Employee {
    int index;
    int distance1; // Distance to warehouse 1
    int distance2; // Distance to warehouse 2
};
struct Request {
    int index;
    int distance1; // Distance from warehouse 1 to delivery point
    int distance2; // Distance from warehouse 2 to delivery point
};
bool compareEmployees(const Employee& emp1, const Employee& emp2) {
    return emp1.distance1 - emp1.distance2 < emp2.distance1 - emp2.distance2;
}
bool compareRequests(const Request& req1, const Request& req2) {
    return req1.distance1 - req1.distance2 < req2.distance1 - req2.distance2;
}
int main() {
    int N, T;
    cin >> N >> T;
    vector<Employee> employees(N);
    vector<Request> requests(T);
    for (int i = 0; i < N; ++i) {
        employees[i].index = i + 1;
        cin >> employees[i].distance1;
    }
    for (int i = 0; i < N; ++i) cin >> employees[i].distance2;
    for (int i = 0; i < T; ++i) {
        requests[i].index = i + 1;
        cin >> requests[i].distance1;
    }
    for (int i = 0; i < T; ++i) cin >> requests[i].distance2;
    sort(employees.begin(), employees.end(), compareEmployees);
    sort(requests.begin(), requests.end(), compareRequests);
    int totalDistance = 0;
    for (int i = 0; i < T; ++i) {
        totalDistance += min(employees[i].distance1 + requests[i].distance1, employees[i].distance2 + requests[i].distance2);
    }
    cout << totalDistance << endl;
    return 0;
}
