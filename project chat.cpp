
#include <iostream>
#include<string>
#include <vector>
#include<fstream>

using namespace std;
struct Student
{
    string name;
    int age;
    int id;
    float gpa;

};//sttuctفيها المحتويال لكل طالب مع بغعضها 
vector<Student> students;// لتخزين الطلاب في مصفوفة 
void saveToFile()
{
    ofstream outfile("students.txt");
    for (int i = 0;i < students.size();i++)
    {
        outfile << students[i].name << " "
            << students[i].age << " "
            << students[i].id << " "
            << students[i].gpa << "\n";//اضافه العناصر للمصفوفه علي سطر واحد
    }
    outfile.close();// قفل الملف بعد الانتهاء
}
//int studentcount=0;
void loadFromFile()
{
    ifstream infile("students.txt");
    if (!infile)
    {
        return;
    }
    Student temp;
    while (infile >> temp.name >> temp.age >> temp.id >> temp.gpa)
    {
        students.push_back(temp);//اضافة العناصر للمصفوفه
    }
    infile.close();// قفل الملف بعد الانتهاء

}


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
	students.push_back(newStudent);//اضافة الطالب إلى المصفوفة
   saveToFile();// حفظ البيانات في ملف  بعد إضافة الطالب
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

void searchStudent()
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

void  deleteStudent()
{
    int searchId;
    cout<<"ENTER ID: ";
    cin>>searchId;
    bool found = false;
    for(int i=0;i<students.size();i++)
    {
        if(searchId== students[i].id)
        {
            found = true;
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

void updateStudent()
{
	cout << "ENTER ID: ";
	int searchID;
	cin >> searchID;
    bool found = false;
	for (int i = 0;i < students.size();i++)
	{
	    if(searchID == students[i].id)
        {
			cout << "ENTER NEW NAME: ";
			cin >> students[i].name;
			cout << "ENTER NEW AGE: ";
			cin >> students[i].age;
			cout << "ENTER NEW GPA: ";
			cin >> students[i].gpa;
			found = true;
			saveToFile();// حفظ البيانات في ملف  بعد تحديث الطالب
			break;
        
        }
	}
	 if (!found)
     {
		 cout << "Student Not found\n";
     }
     else
     {
         cout << "Student Updated Successfully\n";
     }


}


int main()
{ 
	loadFromFile();// تحميل البيانات من الملف عند بدء البرنامج
    while(true){

        cout << "===== Student Management System =====" << "\n\n" <<
            "1. Add Student\n2. Show Students\n3. Search student\n4. Delete student\n5. Update student\n6. Exit" 
            <<"\n\n" << "choose: ";

        int  choose;
        cin >> choose; 
       
        switch (choose)
        {
        case 1: addStudent();break;
        case 2: showStudent();break;
        case 3: searchStudent();break;
        case 4: deleteStudent();break;
		case 5: updateStudent();break;
		case 6: cout << "Good Bye";return 0;
        default: cout << "Invalid Choices\n";
        }

    }
   
    
}


