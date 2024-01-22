//students_GPA_project
#include <iostream>
using namespace std;

char get_grade(double mark){
    if(mark >= 85){
        return 'A';
    }else if(mark >= 75){
        return 'B';
    }else if(mark >= 65){
        return 'C';
    }else if(mark >= 50){
        return 'D';
    }else{
        return 'F';
    }
}


int get_subject_gpa(char grade){
    if(grade == 'A')
        return 4;
    else if(grade == 'B')
        return 3;
    else if(grade == 'C')
        return 2;
    else if(grade == 'D')
        return 1;
    else
        return 0;
}

int main()
{
    int student_number;
    cout<<"Enter number of students: ";
    cin >> student_number;
    string student_names[student_number];

    char student_marks[student_number][5];

    cout<<endl;
    for(int i = 0 ; i < student_number; i++){
        cout<<"Enter student name: ";
        cin>>student_names[i];
        cout<<endl;
        for(int j = 0; j < 5; j++){
                cout<<"Enter subject number "<<j+1<<" : ";
                double mark;

                while(true){

                    cin>>mark;
                    if(mark >= 0 && mark <= 100){
                        break;
                    }
                    cout<<"Student mark must be between 0 and 100"<<endl;
                    cout<<"Enter subject number "<<j+1<<" : ";
                }
                student_marks[i][j] = get_grade(mark);
        }
         cout<<endl;
    }

    double max_gpa = -1;
    int first_student = -1;

    double student_gpa[student_number];
    for(int i = 0; i < student_number; i++){
        double current_gpa = 0;
        for(int j = 0 ; j < 5; j++){
            current_gpa += get_subject_gpa(student_marks[i][j]);
        }
        current_gpa /= 5.0;
        student_gpa[i] = current_gpa;

        if(current_gpa > max_gpa){
            max_gpa = current_gpa;
            first_student = i;
        }else if(current_gpa == max_gpa && student_names[i] < student_names[first_student]){
            first_student = i;
        }

    }

    for(int i = 0; i < student_number; i++){
        cout<<"Name: "<<student_names[i]<<endl<<"Grades: ";
        for(int j =0 ; j  < 5;  j++){
            cout<<student_marks[i][j]<<" ";
        }
        cout<<"GPA: "<<student_gpa[i]<<endl;
        cout<<endl;
    }

    cout<<endl;
    cout<<"First on class is: "<<student_names[first_student]<<" with a total gpa of: "<<student_gpa[first_student];
    cout<<endl<<"His/Her grades are: ";
    for(int j =0 ; j  < 5;  j++){
        cout<<student_marks[first_student][j]<<" ";
    }
    cout<<endl;
}
