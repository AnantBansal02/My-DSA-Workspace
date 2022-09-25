#include<iostream>
using namespace std;
struct student{
    public:
    string name;
    int Enrollment_No;
    int marks_Science;
    int marks_Math;
    int marks_English;
};
double percentage(student s){
    double x = s.marks_English + s.marks_Math + s.marks_Science;
    return x/3;
}
void printDetails(student s){
    cout<<"Name : "<<s.name<<endl;
    cout<<"Enrollment No. : "<<s.Enrollment_No<<endl;
    cout<<"Percentage Marks : "<<percentage(s)<<endl;
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        student s;
        string str;
        int x;
        cin>>str;s.name = str;
        cin>>x;s.Enrollment_No = x;
        cin>>x;s.marks_Science = x;
        cin>>x;s.marks_Math = x;
        cin>>x;s.marks_English = x;
        printDetails(s);
    }
    
}