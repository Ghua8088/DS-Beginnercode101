#include <iostream>
#include <string>
using namespace std;
class record{
    private:
    int registernumber;
    string name;
    string course;
    string dob;
    public:
    record(){
        registernumber=0;
        name="";
        course="";
        dob="";
    }
    void get(){
        cout<<"give:"<<endl<<"Reg_no:";
        cin>>registernumber;
        cout<<"name:";
        cin>>name;
        cout<<"course:";
        cin>>course;
        cout<<"dob:";
        cin>>dob;
    }
    int getregisternumber(){
        return registernumber;
    }
    void update(int reg, string name, string course, string dob){
        registernumber=reg;
        this->name=name;
        this->course=course;
        this->dob=dob;
    }
    void display(){
        cout<<"RegNo: "<<registernumber<<endl;
        cout<<"course: "<<course<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"dob:"<<dob<<endl;
    }
};
struct Node{
    record data;
    Node* next;
    Node(){
        next=nullptr;
    }
    Node(record data){
        next=nullptr;
        this->data=data;
    }
    ~Node(){
        delete next;
    }
};
class List{
    private:
    Node* head;
    public:
    int count;
    List(){
        head=nullptr;
        count=0;
    }
    void insert(record data){
        Node* temp=new Node(data);
        temp->next=head;
        head = temp;
        count++;
    }
    Node* getHead(){
        return head;
    }
    void search(int reg){
       Node* temp=head;
        while(temp!=nullptr){
            if(temp->data.getregisternumber()==reg){
                temp->data.display();
                return;
            }
            temp=temp->next;
        }
        
        cout<<"Data not found: with registernumber: "<<reg;
    }
    void print(){
        Node* temp=head;
        cout<<endl<<"[";
        while(temp!=nullptr){
            temp->data.display();
            temp=temp->next;
        }
        cout<<"]\n";
    }
    void remove(int reg){
        Node* temp=head;
        Node* prev=nullptr;
        while(temp!=nullptr){
            if(temp->data.getregisternumber()==reg){
                cout<<"Removed student>"<<endl;
                temp->data.display();
                if(prev!=nullptr){
                    prev->next=temp->next;
                }else{
                    head=temp->next;
                }
                delete temp;
                count--;
                return;
            }
            prev=temp;
            temp=temp->next;
        }
        cout<<"data not found";
    };
};

class Hashtab{
    private:
    List* L;
    int size;
    public:
    Hashtab(){
        cout<<"Enter the target size: ";
        cin>>size;
        size*=1.25;//load factor
        L=new List[size];
    }
    int Hash(record k){
        int key=k.getregisternumber();
        return key%size;
    }
    inline int Hash(int key){
        return key%size;
    }
    List* getaddr(){
        return L;
    }
    void insert(record k){
        int address=Hash(k);
        (L+address)->insert(k);
    }
    void get(int reg){
        int address=Hash(reg);
        (L+address)->search(reg);
    }
    void print(){
        cout<<"[";
        for(int i=0;i<size;i++){
            if ((L+i)->getHead()!=nullptr){
                (L+i)->print();
            }
        }
        cout<<"]"<<endl;
    }
};
int main(){
    record tmp;
    Hashtab Sec_k;
    int running;
    while(running!=5) {
        cout<<"Enter the command:"<<endl;
        cout<<"1.insert"<<endl;
        cout<<"2.get"<<endl;
        cout<<"3.remove"<<endl;
        cout<<"4.display"<<endl;
        cout<<"5.end"<<endl;
        cin>>running;
        int searchreg;
        int addr;
        switch(running){
            case 1:
            tmp.get();
            Sec_k.insert(tmp);
            break;
            case 2:
            cout<<"What element do you want to search:";
            cin>>searchreg;
            Sec_k.get(searchreg);
            break;
            case 3:
            cout<<"What element do you want to remove:";
            cin>>searchreg;
            addr=Sec_k.Hash(searchreg);
            (Sec_k.getaddr()+addr)->remove(searchreg);
            break;
            case 4:
            Sec_k.print();
            break;
            case 5:
            cerr<<"Hash completed successfully"<<endl;
            break;
        };
    }
    
    return 0;
}