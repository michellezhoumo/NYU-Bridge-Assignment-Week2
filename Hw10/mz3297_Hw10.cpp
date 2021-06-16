#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Employee;
template <class T>
class Node;
template <class T>
class DbList;

void importEmpInfo(ifstream& inFileEmps, DbList<Employee>& emp);
void matchHours(DbList<Employee>& emp);
void selectionSortPayVector(vector<Employee>& vt);
void vectorToDbList(vector<Employee>& vt,DbList<Employee>& empList);
void printPayroll(DbList<Employee>* emp);

class Employee {
    int employeeID;
    string employeeName;
    double employeeWage;
    int hoursWorked;
    double pay;

public:
    //Employee constructor with initialization list
    Employee(int id=0, string name="", double wage=0, int hours=0, double totalPay=0) :
            employeeID(id), employeeName(name), employeeWage(wage), hoursWorked(hours), pay(totalPay) {};
    friend ostream& operator<<(ostream& output, const Employee& employee);

    //Getters and setters to access private members
    void setID(int id){employeeID = id;}
    void setWage(double wage){employeeWage = wage;}
    void setName(string name){employeeName = name;}
    Employee setHours(int hours){hoursWorked = hours; return *this;}
    int getID() const{return employeeID;}
    double getWage() const{return employeeWage;}
    string getName() const{return employeeName;}
    int getHours() const{return hoursWorked;}
    Employee setPay(double totalPay){pay = totalPay; return *this;}
    double getPay() const{return pay;}
};

ostream& operator<< (ostream& output, Employee& employee){
    output << employee.getName() <<'\t'<<employee.getPay()<< endl;
    return output;
}

//Sort pay from max to min using selection sort

void selectionSortPayVector(vector<Employee>& vt){
    unsigned int maxInd_i = 0;
    unsigned int maxInd_j = 1;

    for(unsigned int i = 0; i < vt.size(); i++){
        if(vt.size() <= 1) {
            cout << "No sorting necessary" << endl;
        }
        else {
            for(unsigned int j = i+1; j < vt.size(); j++){
                if(vt[j].getPay() > vt[maxInd_j].getPay())
                    maxInd_j = j;
            }
            if(vt[maxInd_i].getPay() < vt[maxInd_j].getPay()){
                Employee temp;
                temp = vt[maxInd_i];
                vt[maxInd_i] = vt[maxInd_j];
                vt[maxInd_j] = temp;
            }
        }
    }
}

template <class T>
class Node{
    T data; //info in that node
    Node<T>* next; //pointer to the next node
    Node<T>* prev; //pointer to the previous node

public:
    friend class DbList<T>;
    Node(){};
    Node(T newData = T(), Node<T>* newNext = nullptr, Node<T>* newPrev = nullptr):
    data(newData),next(newNext),prev(newPrev){}; //Doubly LList Node Constructor
    ~Node()=default;
    T getData(){return data;}
    void setData(T newData){data = newData;}
    Node<T>* getNext(){return next;}
};

template <class T>
class DbList{
    Node<T>* head;
    //Node<T>* recursiveCopy(Node<T>* rhs);
public:
    DbList(): head(nullptr){} //create an empty DbLlist
    DbList(const DbList<T>& rhs){*this = rhs;} //Big 3-1, Copy Constructor used in recursively coping nodes
    DbList<T>& operator=(const DbList<T>& rhs); //Big 3-2, Overloaded assignment operator to assign DbLlist object
    ~DbList(){clear();} //Big 3-3, destructor to de-allocation memory for DbList pointers.

    Node<T>* getHead(){return head;}
    void removeFromHead();
    void insertAtTail(T newData);
    vector<T>* dbListToVector();
    //DbList<T> sortNodesDesc(vector<T> vt);
    void clear();
    void displayInfo();
};

template<class T>
void DbList<T>:: removeFromHead(){
    if(head != nullptr){
        Node<T>* temp = head;
        head = head->next;
        delete temp; //calls Node destructor
        if(head != nullptr){
            head->prev = nullptr;
        }
    }
}

template<class T>
void DbList<T>::clear(){
    while(head != nullptr)
        removeFromHead();
} //Empty out DbLlist

template<class T>
void DbList<T>:: insertAtTail(T newData){
    Node<T>* newNode = new Node<T>(newData);

    if(head == nullptr){
        //Case when Dblist Object is empty
        head = newNode;
        return;
    }
    else {
        //Case when DbList Object is not empty
        Node<T>* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

template<class T>
void DbList<T> ::displayInfo(){
    Node<T>* temp = head;
    if(temp == nullptr){
        cout << "There's no information to be printed." << endl;
    }
    else {
        cout << "*********Payroll Information********"<< endl;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
        }
        cout << "*********End payroll**************"<< endl;
    }
}

void vectorToDbList(vector<Employee>& vt,DbList<Employee>& empList){
    empList.clear();
    for(Employee i: vt){
        empList.insertAtTail(i);
    }
}
/*
vector<Employee> Employee::getInfoFromEmp(){
    //openInputFile()
    ifstream inFileEmps("emps.txt");
    vector<Employee> emp;
    Employee currEmp;

    //Put info from input file into inFileEmps
    while(inFileEmps >> currEmp.employeeID){
        inFileEmps >> currEmp.employeeWage;
        inFileEmps.ignore(9999,'\t');
        inFileEmps >> currEmp.employeeName;
        getline(inFileEmps, currEmp.employeeName);
        emp.push_back(currEmp);
    }
    return emp;
};*/

//Can also write a method to readfiles into linkedlist instead of doing it in main
//void fillEmployeeDbList(ifstream& inFileEmps, DbList<T>& emp);
//implement if there's time

int main() {
    int empID;
    double empWage;
    string empName;

    ifstream inFileEmps("emps.txt");
    DbList<Employee>* emp = new DbList<Employee>();
    Employee currEmp;
    importEmpInfo(inFileEmps, *emp);
    inFileEmps.close();
    printPayroll(emp);

    delete emp; //Call DbList Destructor
    return 0;
}

template <class T>
vector<T>* DbList<T>:: dbListToVector(){
    Node<T>* temp = head;
    vector<T>* vt = new vector<T>();
    while(temp != nullptr){
        vt->push_back(temp->data);
        temp = temp->next;
    }
    return vt;
}


//Try to imput the files here
void importEmpInfo(ifstream& inFileEmps, DbList<Employee>& emp){
    int empID;
    double empWage;
    string empName;

    Employee currEmp;

    while(inFileEmps >> empID) {
        //Read emps info into currEmp
        currEmp.setID(empID);
        inFileEmps >> empWage;
        currEmp.setWage(empWage);
        getline(inFileEmps, empName);
        empName = empName.erase(empName.size() - 1); //get rid of carriage return \r
        currEmp.setName(empName);
        emp.insertAtTail(currEmp);
    }
    //Read hours info into currEmp only if ID matches from both files
    matchHours(emp);


}
//This function matches the

//still need to add file open check;
void matchHours(DbList<Employee>& emp){
    int hourID;
    int empHours;

    Node<Employee>* temp;
    temp = emp.getHead();

    if(temp == nullptr){
        cout << "No data to match" << endl;
    }else {
        while (temp != nullptr) {
            //need to involve a check here to see whether file could be open;
            ifstream inFileHours("hours.txt");
            while (inFileHours >> hourID) {
                if (temp->getData().getID() == hourID) {
                    inFileHours.ignore(9999, ' ');
                    inFileHours >> empHours;
                    temp->setData(temp->getData().setHours(temp->getData().getHours() + empHours));
                    temp->setData(temp->getData().setPay((double) temp->getData().getHours()
                                                         * temp->getData().getWage()));
                    inFileHours.ignore(9999, '\n');
                } else {
                    inFileHours.ignore(9999, '\n');
                }
            }
            inFileHours.clear();
            inFileHours.close();
            temp = temp->getNext();
        }
    }
}


void printPayroll(DbList<Employee>* emp){
    //change DbList object to vector for sorting
    vector<Employee>* vEmp;
    vEmp= emp->dbListToVector();
    //apply selection sort and rearrange vector
    selectionSortPayVector(*vEmp);
    //Reorder Dblist object according to sorted vector
    vectorToDbList(*vEmp,*emp);
    emp->displayInfo();
}


