#include<iostream>
using namespace std;
struct subjects{
    int sub_id;
    float gpa;
    struct subjects *next; 
};
struct student{
    int id;
    float gpa;
    struct student *next;
    struct student *previous;
    struct subjects *sub_next; 

};
student *next=NULL;
student *first=NULL;
student*last=NULL;
student *previous=NULL;
student *sub_next=NULL;
student *serch(int key){
    student *p=first;
    student *q=p;
    while (p->next!=NULL){
        if(key==p->id)
            return p;
        p=p->next;    
    }
    if(p->id==key){
        return p;
    }
    else{
        return NULL;
    }
    
}
student *serch_befor(int key){
    student *p=first;
    student *k;
    while (p->id!=key){
        if(p==NULL){
            break;
        }
        k=p;
        p=p->next;
    }
    cout<<k->id;
    return k;
}
void insert_at_first(){
    float gpa;
    int id;
    cout<<"Enter the id of the student :"<<endl;
    cin>>id;
    cout<<"Enter the gpa of the student :"<<endl;
    cin>>gpa;
    student *currrent_node=new student;
    currrent_node->gpa=gpa;
    currrent_node->id=id;
    if(first==NULL){
        first=last=currrent_node;
    }
    else{
        currrent_node->next=first;
        first->previous=currrent_node;
        first=currrent_node;
        currrent_node->previous=NULL;
    }
}
void insert_at_end(){
    float gpa;
    int id;
    cout<<"Enter the id of the student :"<<endl;
    cin>>id;
    cout<<"Enter the gpa of the student :"<<endl;
    cin>>gpa;
    student *current_node=new student;
    current_node->gpa=gpa;
    current_node->id=id;
    if(first==NULL){
        first=last=current_node;
    }
    else{
        last->next=current_node;
        current_node->previous=last;
        last=current_node;
    }

}
void insert_after_specific(int key){
    student *p=serch(key);
    student *current_node=new student;
    if(p==NULL){
        cout<<"Sorry the not found at the given index:"<<endl;
    }
    else if(p==last){
        insert_at_end();
    }
    else{

        float gpa;
        int id;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        cout<<"Enter the gpa of the student :"<<endl;
        cin>>gpa;
        current_node->gpa=gpa;;
        current_node->id=id;
        current_node->next=p->next;
        current_node->previous=p;
        p->next->previous=current_node;
        p->next=current_node;

    }

}
void insert_befor_specific(int key){
    student *p=serch(key);
    student *current_node=new student;
    if(p==first){
        insert_at_first();
    }
    else{
        float gpa;
        int id;
        cout<<"Enter the id of the student :"<<endl;
        cin>>id;
        cout<<"Enter the gpa of the student :"<<endl;
        cin>>gpa;
        current_node->gpa=gpa;
        current_node->id=id;
        student *q=serch_befor(key);
        current_node->next=q->next;
        current_node->previous=q;
        q->next->previous=current_node;
        q->next=current_node;

    }
}
void display(){
    student *p=first;
    while(p!=NULL){
        cout<<"The id of the student is: "<<p->id<<endl;
        cout<<"The gpa of the student is: "<<p->gpa<<endl;
        p=p->next;
    }
}
void add_subject(){
    int key;
    cout<<"Enter the id of the student which subjects you want to add"<<endl;
    cin>>key;
    student *p=serch(key);
    if(p==NULL){
        cout<<"The student not exist in the list"<<endl;
        }
    else{
        cout<<"Enter the subject id"<<endl;
        int sub_id;
        cin>>sub_id;
        cout<<"Enter the gpa of the subject"<<endl;
        float gpa;
        cin>>gpa;
        subjects *current_node=new subjects;
        current_node->gpa=gpa;
        current_node->sub_id=sub_id;
        if(p->sub_next==NULL){
            p->sub_next=current_node;
        }
        else{
            subjects *s;
            s=p->sub_next;
            while (s->next!=NULL)
            {
                s=s->next;
            }
            s->next=current_node;
            current_node->next=NULL;
        }
    }
}
void subject_display(){
    cout<<"Enter the id of the student which subjects you want to display"<<endl;
    int key;
    cin>>key;
    student *q;
    q=serch(key);
    if(q==NULL){
        cout<<"No such student exist in this list"<<endl;
    }
    else{
        subjects *p=q->sub_next;
        while (p!=NULL){
            cout<<"The id of the subject is: "<<p->sub_id<<endl;
            cout<<"The marks of the subject is: "<<p->gpa<<endl;
            p=p->next;
        }
    }
    
}
void total_cgpa(){
    cout<<"Enter the id of the student whose gpa you want to calculate"<<endl;
    int key;
    cin>>key;
    student *q=serch(key);
    if(q==NULL){
        cout<<"No such student exist in this list"<<endl;
    }
    else{
        subjects *p=q->sub_next;
        int num_of_subject=0;
        float cgpa=0;
        while (p!=NULL)
        {
            num_of_subject++;
            cgpa=cgpa+p->gpa;
            p=p->next;
        }
        int sub=num_of_subject;
        float average=cgpa/sub;
        cout<<"The total cgpa is "<<average<<endl;
    }
}
void higest_gpa(){
    student *p=first;
    float high_gpa=p->gpa;
    while (p->next!=NULL)
    {
        p=p->next;
        if(p->gpa>high_gpa){
            high_gpa=p->gpa;
        }
    }
    cout<<"Higest gpa is "<<high_gpa<<endl;
}

int main(){
    insert_at_first();
    insert_at_end();
    display();
    add_subject();
    add_subject();
    add_subject();
    subject_display();
    total_cgpa();
    higest_gpa();
    return 0;
}