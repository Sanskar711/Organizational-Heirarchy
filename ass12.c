#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Node

{

    int data;

    struct Node* next;

};


// create a node with data as x

struct Node* create_node(int x) {

    struct Node* ptr = malloc(sizeof(struct Node));

    ptr->data = x;

    ptr->next = NULL;

    return ptr;

}


// delete the node at `ptr` and free its memory

void delete_node(struct Node* ptr) {

    free(ptr);

}


// ------------------------------ Node struct definition ends here ------------------------------


// Use this to operate on the list, this will always point at the head of the list.

struct Node* PythonListHead = NULL;


int len();

// prints the list in space seperated format

void print_list(struct Node* head) {

    struct Node* cur = head;

    while(cur) {

        printf("%d ", cur->data);

        cur = cur->next;

    }

   // printf("\n");

}



// Add an item to the end of the list
struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        if(pos == position) return cur;
        pos++;
        cur = cur->next;
    }
    return NULL;
}

void append(struct Node *cur, int x) {
    if(cur == NULL) {
        // no list exists, we have to create one
        PythonListHead = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}
// Insert an item at a given position. 

// The first argument is the index of the element before which to insert

// second argument is the value to insert at that position

// if the position does not exist, do nothing

void insert(int position, int x) {

    if(position>=len()) return;

    if (position >1){

        struct Node* ptr;

        ptr = create_node(x);

        struct Node* p = PythonListHead;

        int i = 0;

        while (i != position-1){

            p= p->next;

            i++;

        }

        ptr -> next = p->next;

        p->next = ptr;

    }else{

        struct Node* ptr = create_node(x);

        ptr->next = PythonListHead;

        PythonListHead = ptr;

    }

}



// Remove the item at the end of the list

void pop() {

    struct Node* ptr = PythonListHead;

    struct Node* d;

    while (ptr->next!=NULL){

        if(ptr->next->next ==NULL)

        {

            d = ptr->next;

            ptr->next = NULL;

        }

        else{

        ptr = ptr->next;}

    }

    delete_node(d);

    

}



// Remove all items from the list

void clear(struct Node* ptr) {

    while(ptr!=NULL){

        struct Node* temp = ptr;

        ptr= ptr->next;

        delete_node(temp);

    }

    PythonListHead = NULL;

}



// Return the number of times x appears in the list.

int count(int x) {

    // your code goes here

    int count = 0;

    struct Node*ptr = PythonListHead;

    while(ptr!=NULL){

        if (ptr->data == x){

            count++;

            ptr = ptr->next;

        }else{

            ptr = ptr -> next;

        }

        

    }

    return count;

    return 0;

}



// Reverse the elements of the list in place.

// Make sure you change `PythonListHead` accordingly
struct Node* reverse_helper(struct Node* cur_node) {
    if(cur_node == NULL) return NULL;

    if(cur_node->next == NULL) {
        // this is the first node of the reversed list
        PythonListHead = cur_node;
        return cur_node;
    }

    // recursively solve for the next node
    struct Node* next_node = reverse_helper(cur_node->next);

    // set the next of next_node to cur_node
    next_node->next = cur_node;

    // also make the cur_node->next as NULL, since cur_node is the last node of the list
    cur_node->next = NULL;

    return cur_node;
}

void reverse() {

    struct Node* cur = PythonListHead;

    struct Node* prev = NULL;

    if (cur==NULL){

        return;

    }

    while(cur->next != NULL){

        struct Node* temp = cur ->next;

        cur->next = prev;

        prev = cur;

        cur = temp;

    }

    cur->next = prev;

    PythonListHead = cur;

}



// Return the number of elements in the list

int len() {

    // your code goes here

    int count = 0;

    struct Node* ptr = PythonListHead;

    while (ptr!=NULL)

    {

        ptr= ptr->next;

        count++;

    }

    return count;

    return 0;

}



// Set the data attribute of the node at `position` to `x`

// if no such position, do nothing

void setitem(int position, int x) {

    int i = 0;

    struct Node* ptr = PythonListHead;

    while (i != position)

    {

        if (ptr != NULL)

        {

            ptr = ptr->next;

            i++;

        }else

        {

            break;

        }

    }

    if(ptr==NULL) return;

    ptr -> data = x;

}



// Return the data of the node at `position` 

// if no such position, return -1

int getitem(int position) {

    // your code goes here

    int i = 0;

    struct Node* ptr = PythonListHead;

    

    while(i != position)

    {

        i++;

        ptr = ptr->next;

        

        if(ptr==NULL) return -1;

        

    }

    if(ptr==NULL) return -1;

    return ptr->data;

}



// erase the node at position

// if no such position, do nothing

void erase(int position){

    int i = 0;

    struct Node* ptr = PythonListHead;

    if(position==0){

        if(ptr==NULL) return;

        else{

            PythonListHead = ptr->next;

        }return;

    }

    while(i!=position-1)

    {

        i++;

        ptr = ptr->next;

        

    }

    if (ptr == NULL) return;

    if(ptr!=NULL){

            struct Node* temp = ptr->next;

            ptr -> next = temp->next;

            delete_node(temp);

        }

}


void swap(int position) {

    int i = 0;

    if(position>len()-2) return;

    struct Node* ptr = PythonListHead;

    

    if (position==0){

        struct Node* temp = ptr->next;

        PythonListHead = temp;

        ptr->next = temp->next;

        temp->next = ptr;

    }return;

    while (i !=position){

        i++;

        ptr = ptr->next;

        if (ptr == NULL || ptr->next ==NULL){

            break;

        }else

        {

            struct Node* temp = ptr->next;

            ptr = temp;

            temp->next = ptr;

            ptr->next = temp->next;

        }

    }

}



// sort the Python list

// you may use the above defined swap function to 

// implement bubble sort. But its upto you, use whatever algorithm

// that you seem comfortable.

void sort() {

    struct Node *cur = PythonListHead, *index = NULL;

    int temp;

 

  if (PythonListHead == NULL) {

  return;

  } else {

  while (cur != NULL) {

    index = cur->next;

 

    while (index != NULL) {

    if (cur->data > index->data) {

      temp = cur->data;

      cur->data = index->data;

      index->data = temp;

    }

    index = index->next;

    }

    cur = cur->next;

  }

  }

}


// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    char* emp_name;
    int emp_salary;
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int id, char* name, int salary) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = id;
    ptr->emp_salary = salary;
    ptr->emp_name = strdup(name);
    // strdup() creates a copy of the string or char pointer and stores it in the new char pointer of the employee
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int id, salary;
    char name[100];
    scanf("%d", &id);
    if(id == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present

    scanf("%s %d", name, &salary);
    struct Employee* par = create_employee(id, name, salary);

    par->subordinate_1 = create_company();
    par->subordinate_2 = create_company();
    
    return par;
}

// The following function 
void print_company_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d %s %d ", ceo->emp_id, ceo->emp_name, ceo->emp_salary);
    print_company_helper(ceo->subordinate_1);
    print_company_helper(ceo->subordinate_2);
    return;
}

void print_company(struct Employee* ceo) {
    print_company_helper(ceo);
    printf("\n");
    return;
} 

// --------------------------------------------------- YOU CAN EDIT BELOW THIS LINE -----------------------------------
struct Employee * employee(int emp_id, struct Employee *emp){
    if (emp==NULL){
        return NULL;
    }
    else{
        if (emp->emp_id==emp_id){
            return emp;
        }
        else{
            struct Employee *x;
            struct Employee *y;
            x = employee(emp_id,emp->subordinate_1);
            y = employee(emp_id,emp->subordinate_2);
            if (x!=NULL){
                return x;
            }
            else if (y!=NULL){
                return y;
            }
            else{
                return NULL;
            }
        }
    }
}

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company

// The below function returns the employee id of the first common boss
int get_first_common_boss_helper(struct Employee* ptr, int x, int y){
    int a,b;
    if(ptr == NULL){
        return -1;
    }
    if(ptr->emp_id == x || ptr->emp_id==y){
        return ptr->emp_id;
    }
    a = get_first_common_boss_helper(ptr->subordinate_1,x,y);
    b = get_first_common_boss_helper(ptr->subordinate_2,x,y);
    if (a != -1 && b != -1){
        return ptr->emp_id;
    }else {
        if (a == -1){
            return b;
        }else if(b== -1){
            return a;
        }else {
            return -1;
        }
    }

}
int get_first_common_boss(int emp_id1,int emp_id2){
    return get_first_common_boss_helper(CEO,emp_id1,emp_id2);
    return 0;
}

//Print the employees with the same last name sperated by a space in the order of their level

int employee_with_same_name_finder(struct Employee* ptr, char* name){
    int left, right;
    if (ptr == NULL)return -1 ;
    if (strcmp(name,ptr->emp_name)==0 ){
        printf("%d ",ptr->emp_id);
    }
    left = employee_with_same_name_finder(ptr->subordinate_1,name);
    right = employee_with_same_name_finder(ptr->subordinate_2,name);

    if (left == -1 && right == -1){
        return -1;
    }
}
void same_last_names(int emp_id){       
    char* name;
    struct Employee* ptr;
    ptr = employee(emp_id,CEO);
    name = ptr->emp_name;
    employee_with_same_name_finder(CEO,name);
}

// Print the bosses of the given employee in the order from CEO to immediate boss
int get_all_bosses_helper(struct Employee* ptr, int x, struct Node *cur){
    
    if (ptr==NULL){
        return -1;
    }
    if (CEO->emp_id==x){
        printf("%d ", -1);
    }
    if(ptr->emp_id==x){
        return ptr->emp_id;
    }
    int a,b;
    a = get_all_bosses_helper(ptr->subordinate_1,x,cur);
    b = get_all_bosses_helper(ptr->subordinate_2,x,cur);


    if (a == -1 && b == -1){
        return -1;
    }else{
        
        if (a>b){
            struct Node *abc;
            abc = create_node(ptr->emp_id);
            struct Node *nod;
            nod = PythonListHead;
            if (nod==NULL){
                PythonListHead=abc;
            }
            else{
                while(nod->next!=NULL){
                    nod=nod->next;
                }
                nod->next=abc;
            }
            return a;
            
        }else{
            struct Node *abc;
            abc = create_node(ptr->emp_id);
            struct Node *nod;
            nod = PythonListHead;
            if (nod==NULL){
                PythonListHead=abc;
            }
            else{
                while(nod->next!=NULL){
                    nod=nod->next;
                }
                nod->next=abc;
            }
            
            return b;
        }
    }

}
void get_all_bosses(int emp_id){
    get_all_bosses_helper(CEO,emp_id,PythonListHead);
    struct Node* head;
    head = reverse_helper(PythonListHead);
    print_list(PythonListHead);
    clear(PythonListHead);
}

// Return the average salary of the team with the given employee as head
double no_of_employees(struct Employee* ptr){
    int count = 0;
    
    if(ptr != NULL){
        count ++;
        count += no_of_employees(ptr->subordinate_1);
        count += no_of_employees(ptr->subordinate_2);
    }
    return count;

}
double sum_of_salaries(struct Employee*ptr , int x){
    int sum = 0;
    if (ptr == NULL){
        return 0;
    }
    if (ptr->emp_id == x){
        sum = sum + ptr -> emp_salary;
        if(ptr ->subordinate_1 != NULL){
        sum+= sum_of_salaries(ptr->subordinate_1,ptr->subordinate_1->emp_id);
        }
        if(ptr ->subordinate_2 != NULL){
        sum+= sum_of_salaries(ptr->subordinate_2,ptr->subordinate_2->emp_id);
        }
    }
    return sum;
}


double get_average_salary(int emp_id){
    double s,n;
    s= sum_of_salaries(employee(emp_id,CEO),emp_id);
    n = no_of_employees(employee(emp_id,CEO));
    return s/n;
}
// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "get_first_common_boss") == 0) {
            int x,y;
            scanf("%d %d", &x, &y);
            int ans = get_first_common_boss(x,y);
            printf("%d\n", ans);
        } 
        else if(strcmp(operation_type, "same_last_names") == 0) {
            int x;
            scanf("%d", &x);
            same_last_names(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_all_bosses") == 0) {
            int x;
            scanf("%d", &x);
            get_all_bosses(x);
            printf("\n");
        } 
        else if(strcmp(operation_type, "get_average_salary") == 0) {
            int x;
            scanf("%d", &x);
            double ans = get_average_salary(x);
            printf("%.2f\n", ans);
        } 

    }

    return 0;
}
