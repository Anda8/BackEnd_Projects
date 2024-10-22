#include <bits/stdc++.h>
#include<fstream>
using namespace std;

const int maxraw = 10;
string EmpName[maxraw] = {};
string EmpID[maxraw] = {};

void OpenFile(){
    string line;
    ifstream myfile("D:/codeblocks/filepro/anda.txt");
    if(myfile.is_open()){
        int i=0;
        while(getline(myfile,line)){
        int l = line.length();
        EmpID[i]=line.substr(0,3);
        EmpName[i]=line.substr(4,l-4);
        i++;
        }
    }
    else{
        cout<<"Enable to open the file!"<<endl;
    }
}
void AddRecord(){
    char name[50];
    char empno[5];
    cin.ignore();
    //char address[50];
    cout<<"Employee ID.";
    cin.getline(empno,5);
     cout<<"Employee Name.";
    cin.getline(name,50);
    for(int i=0;i<maxraw;i++){
        if(EmpID[i]=="\0"){
            EmpID[i]=empno;
            EmpName[i]=name;
            break;
        }
    }
}
void ListRecord(){
    system("CLS");
    cout<<"Current Record(s)"<<endl;
    cout<<"========================"<<endl;
    int counter=0;
    cout<<"No.  |   ID   |     NAME     "<<endl<<"----------------------------------------------\n";
    for(int i=0;i<maxraw;i++)
    {
        if(EmpID[i]!="\0"){
            counter++;
            cout<<" "<<counter<<"   "<<EmpID[i]<<"           "<<EmpName[i]<<endl;
        }
    }
    if(counter==0){
       cout<<"No Record found!"<<endl;
    }
     cout<<"========================"<<endl;
}
void SearchRecord(string searcher){
    system("CLS");
    cout<<"Current Record(s)"<<endl;
    cout<<"========================"<<endl;
     int counter=0;
    for(int i=0;i<maxraw;i++)
    {
        if(EmpID[i]==searcher){
            counter++;
            cout<<" "<<counter<<"   "<<EmpID[i]<<"           "<<EmpName[i]<<endl;
            break;
        }
    }
    if(counter==0){
       cout<<"No Record found!"<<endl;
    }
     cout<<"========================"<<endl;
}
void UpdateRecord(string searcher){
   char name[50];
    char empno[5];
    int counter=0;
    for(int i=0;i<maxraw;i++)
    {
        if(EmpID[i]==searcher){
            counter++;
            cout<<"Employee Name.";
            cin.getline(name,50);
            EmpName[i]=name;
            cout<<" Update Successfull!"<<endl;
            break;
        }
    }
    if(counter==0){
       cout<<"ID Does not exist!"<<endl;
    }
}
void DeleteRecord(string searcher){
  int counter=0;
    for(int i=0;i<maxraw;i++)
    {
        if(EmpID[i]==searcher){
            counter++;
            EmpName[i]="";
            EmpID[i]="";
            cout<<"Successfully Deleted!"<<endl;
            break;
        }
    }
    if(counter==0){
       cout<<"ID Does not exist!"<<endl;
    }
}
void SaveToFile(){
    ofstream myfile;
    myfile.open("anda.txt");
    for(int i=0;i<maxraw;i++){
        if(EmpID[i]=="\0"){
            break;
        }
        else{

            myfile<<EmpID[i]<<","<< EmpName[i]<<endl;
        }
    }
}
int main()
{
    cout<<"MENU\n";
    int option;
    string empID;
    system("CLS");
    OpenFile();
    do{
        cout<<"1- Create Records"<<endl;
        cout<<"2- Update Records"<<endl;
        cout<<"3- Delete Records"<<endl;
        cout<<"4- Search Records"<<endl;
        cout<<"5- Display all Records"<<endl;
        cout<<"6- Exit and Save to textfile"<<endl;
        cout<<"*****************************"<<endl;
        cout<<"Select option>>";
        cin>>option;
        switch(option){
        case 1: AddRecord();
        system("CLS");
        break;

        case 2:
        cin.ignore();
        cout<<"Update by ID>>";
        getline(cin,empID);
        UpdateRecord(empID);
        system("CLS");
        break;

        case 3:
        cin.ignore();
        cout<<"Delete by ID>>";
        getline(cin,empID);
        DeleteRecord(empID);
        cin.ignore();
        system("CLS");
        break;

        case 4:
        cin.ignore();
        cout<<"Search by ID>>";
        getline(cin,empID);
        SearchRecord(empID);
        break;

         case 5: ListRecord();
        break;
        }
    }while(option!=6);
    SaveToFile();
    cout<<"Exit... Saving To File!"<<endl;

    return 0;
}
