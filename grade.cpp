#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
   long int roll;
    int marks[3];
    string name;

public:
    double percent(int markss);
    int total_marks(){
        int sum=0;
        for(int i=0;i<3;i++){
                sum=sum+marks[i];
        }
        return sum;
    };//
    ~Student();//destructor
    char grade(double percent);//
    void set_roll(int r)/*Mutator*/{
        if(r<=0){
            roll=0;
        }
        else{
            roll=r;
        }
    }
    void set_mark(int *ptr)/*Mutator*/{
        for(int i=0;i<3;i++){
            marks[i]=(*ptr);
            ptr++;
        }
    }
    int get_roll(){
        return roll;
    }/*Accessor*/
    void get_mark_3(){
        for(int i=0;i<3;i++){
            cout<<marks[i]<<endl;
        }
    };//Accessor
    int sum(int *ptr);
    Student(int *mark,int roll);
};
    // void set_roll(int r){
    //     if(r<=0){
    //         roll=(long int)0;
    //     }
    //     else{

    //     }
    // }
    double Student:: percent(int markss){
        return (double)(markss/3.0);
    }
    int Student:: sum(int *ptr){
        int total=0;
        for(int i=0;i<3;i++){
            total=total+(*ptr);
            ptr=ptr+i;
        }
        return total;
    }
    char Student :: grade(double percent){
        if(percent>=60){
            return 'A';
        }
        else if((percent<60) && (percent>=40)){
            return 'B';
        }
        else if((percent<40)){
            return 'C';
        }
    };
    Student:: Student(int *mark,int roll){//Argumentative constructor
    // if(roll<=0){
    //     this->roll=0;
    // }
    // else{
    //     this->roll=(long int)roll;
    // }
    set_roll(roll);
    // mark=marks;
    // for(int i=0;i<3;i++){
    //     if(marks[i]<=0){
    //         marks[i]=0; 
    //     }
    set_mark(mark);
        // else{
        //     marks[i]=(*mark);
        //     mark=mark+i;
        // }
    }


Student::~Student()
{
    cout<<"The record of the student is deleted."<<endl;
}


int main()
{

    int rollno;
    string name_student;
    int marksss[3];
    cout<<"Enter the roll no below:"<<endl;
    cin>>rollno;
    cout<<"Enter the student name below:"<<endl;
    cin.ignore();
    getline(cin,name_student);
    cout<<"Enter the marks of 3- subjects below :"<<endl;
    for(int ii=0;ii<3;ii++){
        cout<<"Enter mark of Subject-"<<ii+1<<"-";
        cin>>marksss[ii];
    }
    cout<<"Student name is :"<<name_student<<endl;
    int *ptr;
    ptr=marksss;
    Student s(ptr,rollno);
    int total_mark=s.total_marks();
    double percen=s.percent(total_mark);
    cout<<"The roll of the student is :"<<s.get_roll()<<endl;
    cout<<"The marks of the student is :"<<s.total_marks()<<endl;
    cout<<"The percentage of the student is :"<<s.percent(total_mark)<<endl;
    cout<<"The grade of the student is :"<<s.grade(percen)<<endl;
    return 0;
}
