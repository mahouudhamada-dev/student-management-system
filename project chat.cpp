
#include <iostream>
#include<string>
#include <vector>

using namespace std;
struct Student
{
    string name;
    int age;
    int id;
    float gpa;

};
vector<Student> students;

//int studentcount=0;


void addStudent() 
{
   /* if (studentcount >= 100)
    {
        cout << "Database is Full\n";
        return;
    }*/
    Student newStudent ;
    cout <<"name: ";
    cin>> newStudent.name;
    cout <<"age: ";
    cin>> newStudent.age;
    cout<<"id: ";
    cin>> newStudent.id;
    cout<<"gpa: ";
    cin>> newStudent.gpa;
   /* studentcount++;*/
   students.push_back(newStudent);
    cout<<"Student Added Successfully\n";
}
void showStudent()
{
    
    if(students.empty())
    {
        cout<<"NO student\n";
        return;
    }

        for (int i = 0;i < students.size();i++)
        {
            cout << "name: " << students[i].name << "\n";
            cout << "age: " << students[i].age << "\n";
            cout << "id: " << students[i].id << "\n";
            cout << "gpa: " << students[i].gpa << "\n";
            cout << "=========_$_=========\n";
           
        }
       

}
void SearchStudent()
{   
    int searchid;
    cout<<"ENTER ID: ";
    cin>>searchid;
    bool found = false;
    for(int i =0;i<students.size();i++)
    {
        if(students[i].id==searchid)
        {
            cout << "name: " << students[i].name << "\n";
            cout << "age: " << students[i].age << "\n";
            cout << "id: " << students[i].id << "\n";
            cout << "gpa: " << students[i].gpa << "\n";
            cout << "=========_$_=========\n";
            found = true;
            break;
        }
    
    }
    if (!found)cout << "Not found" << "\n";
}
void  DeleteStudent()
{
    int searchId;
    cout<<"ENTER ID: ";
    cin>>searchId;
    bool found = false;
    for(int i=0;i<students.size();i++)
    {
        if(searchId== students[i].id)
        {
            for(int j=i;j< students.size() -1;j++)
            {
                students[j]=students[j+1];
                /*students[j].names= students[j+1].names;
                students[j].ages= students[j+1].ages;
                students[j].ids= students[j+1].ids;
                students[j].gpas= students[j+1].gpas;*/
            }
			students.pop_back();// حذف آخر عنصر من المصفوفة بعد نقل العناصر
			saveToFile();// حفظ البيانات في ملف  بعد حذف الطالب
            break;
        }
    }
   
    if(!found)
    {
        cout<<"Not found\n";
    }
    else
    {
        cout << "Student Deleted Successfully\n";

    }

}

int main()
{ 
    bool val = false;
    while(true){

        cout << "===== Student Management System =====" << "\n\n" <<
            "1. Add Student\n2. Show Students\n3. Search student\n4. Delete student\n5. Exit" 
            <<"\n\n" << "choose: ";

        int  choose;
        cin >> choose; 
       
        switch (choose)
        {
        case 1: addStudent();break;
        case 2: showStudent();break;
        case 3: SearchStudent();break;
        case 4: DeleteStudent();break;
        case 5: cout << "Good Bye";return 0;
        default:val=true; cout << "Invalid Choices\n";
        }

        };
   
    
}


