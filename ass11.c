#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// The following is a employee in the organisation, it has the pointer to two more employees a subordinate_1 and a subordinate_2
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};

// The following function creates a employee and returns its pointer
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organisation from scanning the input file
struct Employee* create_company() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

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
    printf("%d ", ceo->emp_id);
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

struct Employee* CEO = NULL;
// CEO is a global pointer that points to the CEO of the company


/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */
void EmployeesAtSameLevel_helper(struct Employee* ptr, int level){
    struct Employee* ptr1 = ptr ->subordinate_1;
    struct Employee* ptr2 = ptr->subordinate_2;
    if(level ==0){
        printf("%d ", ptr->emp_id);
    }else if( level ==1){
        if(ptr1 != NULL){
            printf("%d ", ptr1->emp_id);
        }
        if(ptr2 != NULL){
            printf("%d ", ptr2->emp_id);
        }else{
            return;
        }
    }
    else{
        if(ptr1 != NULL){
            EmployeesAtSameLevel_helper(ptr1,level-1);
        }
        if(ptr2 != NULL){
            EmployeesAtSameLevel_helper(ptr2, level-1);
        }else{
            return; 
        }
    }
}

void EmployeesAtSameLevel(int level) {
    // The level may be any integer
    EmployeesAtSameLevel_helper(CEO , level);
    return;
}

// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers
void preorder(struct Employee* ptr){
        if(ptr==NULL) {
            return;
        }
        else{
            printf("%d ", ptr->emp_id);
            preorder(ptr->subordinate_1);
            preorder(ptr -> subordinate_2);
        }
    }
void get_employees() {
    preorder(CEO);
    return;
}

/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */
void Immediate_helper(struct Employee* ptr, int emp_id){
    int x = emp_id;
    if (ptr == CEO && ptr->emp_id ==x){
        if (ptr->subordinate_1==NULL && ptr->subordinate_2 != NULL){
            printf("%d", ptr->subordinate_2->emp_id);
            return;
        }
        else if (ptr->subordinate_2==NULL && ptr->subordinate_1 != NULL){
            printf("%d", ptr->subordinate_1->emp_id);
            return;
        }else if (ptr->subordinate_1 != NULL && ptr->subordinate_2 != NULL){
            printf("%d %d", ptr->subordinate_1->emp_id,ptr->subordinate_2->emp_id);
            return;
        }
    } 
        struct Employee* ptr3 = ptr->subordinate_1->subordinate_1;
        struct Employee* ptr4 = ptr->subordinate_1->subordinate_2;
        if(ptr->subordinate_1->emp_id==x){
            if(ptr3== NULL && ptr4 != NULL ){
                printf("%d %d", ptr->emp_id, ptr4->emp_id);
                return;
            }
            if(ptr4== NULL && ptr3 != NULL){
                printf("%d %d", ptr->emp_id, ptr3->emp_id);
                return;
            }
            if(ptr4 != NULL && ptr3 != NULL){
                printf("%d %d %d", ptr->emp_id, ptr3->emp_id, ptr4 -> emp_id);
                return;
            }else{
                printf("%d", ptr->emp_id);
                return;
            }
        }else{
            Immediate_helper(ptr->subordinate_1,x);
        }
     
        struct Employee* ptr5 = ptr->subordinate_2->subordinate_1;
        struct Employee* ptr6 = ptr->subordinate_2->subordinate_2;
        if(ptr->subordinate_2->emp_id==x){
            printf("%d", ptr -> emp_id);
            return;
            if (ptr5 != NULL){
                printf("%d", ptr5->emp_id);
                return;
            }if (ptr6 != NULL){
                printf("%d", ptr6->emp_id);
                return;
            }

        }else{
            Immediate_helper(ptr->subordinate_2,x);
        }
        
}

void ImmediateTeam(int emp_id) {
    int x = emp_id ;
    Immediate_helper(CEO,x);
}
// The following function returns the level of a employee with the given emp_id
int Level_helper(struct Employee* ptr, int emp_id){
    
    int x = emp_id;
    if(ptr ==NULL){
        return 0;
    }
    if(ptr->emp_id==x ){
        return 0;
    }
    if(ptr->subordinate_1 != NULL){
        if(ptr->subordinate_1-> emp_id==x ){
            return 1;
     }
    }
    if(ptr->subordinate_2 != NULL){
        if(ptr->subordinate_2-> emp_id==x ){
            return 1;
        }
    }
        /*if(ptr->subordinate_1 != NULL && ptr->subordinate_2==NULL){
            return Level_helper(ptr->subordinate_1,x) +1;
        }
        if (ptr->subordinate_2 !=  NULL && ptr->subordinate_1==NULL){
            return Level_helper(ptr->subordinate_2,x) +1;
        }
        if(ptr->subordinate_1== NULL && ptr->subordinate_2== NULL){
            return 0;
        }*/
        int z = Level_helper(ptr->subordinate_1,x)+Level_helper(ptr->subordinate_2,x); 
        //printf("%d ",z);
        if (z!=0){
            return z+1;
        }
        else{
            return z;
        }
}
int Level(int emp_id) {
    // Note that ceo has level 0
    int x = emp_id ;
    return Level_helper(CEO,x);
}

// The following function gives the distance between employees with emp_id1 and emp_id2
int IsSiblings (struct Employee* ptr, int x , int y){
    struct Employee* ptr1 = ptr->subordinate_1;
    struct Employee* ptr2 = ptr->subordinate_2;
    if (ptr1 ->emp_id == x && ptr2 ->emp_id == y){
        return 1;
    }else if (ptr2 ->emp_id == x && ptr1 ->emp_id == y){
        return 1;
    }else if((ptr1->emp_id == x || ptr1->emp_id == y)&& ((ptr2->emp_id != x && ptr2->emp_id != y)||ptr2 == NULL)){
        return 0;
    }else if ((ptr2->emp_id == x || ptr2->emp_id == y)&& ((ptr1->emp_id != x && ptr1->emp_id != y)||ptr1 == NULL)){
        return 0;
    }else{
        if (ptr1->subordinate_1 != NULL || ptr1->subordinate_2 != NULL){
            return IsSiblings(ptr1,x,y);
        }else if(ptr2->subordinate_1 != NULL || ptr2->subordinate_2 != NULL){
            return IsSiblings(ptr2,x,y);
        }else {
            return;
        }
    }


}
int Distance(int emp_id1, int emp_id2) {
    // If emp_id1 and emp_id2 are equal the distance is 0, both emp_id's will exist in the organisation
    int level1 = Level(emp_id1);
    int level2 = Level(emp_id2);
    if (IsSiblings(CEO,emp_id1,emp_id2)){
        return 2;
    }else{
        return level1 + level2;
    }
    
    return 0;
}

/* The following function takes an emp_id this will belong to a employee in the organisation and your task is to return the emp_id of its boss
Note: If the boss does not exit return -1 */
int Boss_helper(struct Employee* ptr, int emp_id){
    struct Employee* ptr1 = ptr->subordinate_1;
    struct Employee* ptr2 = ptr->subordinate_2;
    if(ptr == NULL){
        return -1;
    } 
    if(emp_id==CEO->emp_id){
        return -1;
    }
    if(ptr1 != NULL){
    if(emp_id==ptr1->emp_id ){
        return ptr->emp_id;
    }
    }
    if(ptr2 != NULL){
    if(emp_id==ptr2->emp_id){
        return ptr->emp_id;
    }
    }
    if(ptr1 != NULL){
        int x = Boss_helper(ptr1,emp_id);
        if (x==0){
            return Boss_helper(ptr2,emp_id);
        }else{
            return x;
        }

    }
    if(ptr2 != NULL){
        int x = Boss_helper(ptr2,emp_id);
        if (x==0){
            return Boss_helper(ptr1,emp_id);
        }else{
            return x;
        }
    }
    if(ptr1==NULL && ptr2==NULL){
        return 0;
    }




}
int Boss(int emp_id) {
    int x = emp_id;
    return Boss_helper(CEO,x);
    return 0;
}

/* The following function returns the diameter of a Organisation - 
a diameter is the maximum distance between any two emp_ids in the organisation. You can use the distance function implemented above */
int max(int i, int j){
    if(i>j){
        return i;
    }else if(i==j){
        return i;
    }else{
        return j;
    }
}
int height(struct Employee *ptr){
    if (ptr == NULL){
        return 0;
    }
    int left = height(ptr->subordinate_1);
    int right = height(ptr->subordinate_2);
    int h;
    if (left > right){
        h = 1 + left;
    }else{
        h = 1 + right;
    }
    return h;
}
int Diameter_helper(struct Employee* ptr){
    if (ptr == NULL){
        return 0;
    }
    int left_height = height(ptr->subordinate_1);
    int right_height = height(ptr->subordinate_2);
    int left_diameter = Diameter_helper(ptr->subordinate_1);
    int right_diameter = Diameter_helper(ptr->subordinate_2);
    int diameter = max(left_height + right_height , max(left_diameter,right_diameter) );
    return diameter;
}
int Diameter() {
    return Diameter_helper(CEO);
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */
int TeamSize_helper(struct Employee* ptr, int emp_id){
    struct Employee* ptr1 = ptr->subordinate_1;
    struct Employee* ptr2 = ptr->subordinate_2;
    if(ptr->emp_id == emp_id){
        if(ptr1 != NULL && ptr2 != NULL){
            return 2;
        }
        else if (ptr1 == NULL && ptr2 != NULL){
            return 1;
        }
        else if (ptr1 != NULL && ptr2 == NULL){
            return 1;
        }
        else{
            return;
        }
    }
        if(ptr1 != NULL){
            if (ptr1 ->emp_id == emp_id){
                if (ptr1->subordinate_1 !=NULL && ptr1->subordinate_2 != NULL){
                    return 2;
                }
                else if (ptr1->subordinate_1 == NULL && ptr1->subordinate_2 != NULL){
                    return 1;
                }
                else if (ptr1->subordinate_1 != NULL && ptr1->subordinate_2 == NULL){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        if(ptr2 != NULL){
            if (ptr2 ->emp_id == emp_id){
                if (ptr2->subordinate_1 !=NULL && ptr2->subordinate_2 != NULL){
                return 2;
            }
                else if (ptr2->subordinate_1==NULL && ptr2->subordinate_2 != NULL){
                return 1;
            }
                else if (ptr2->subordinate_1 != NULL && ptr2->subordinate_2 == NULL){
                return 1;
            }
                else{
                return 0;
            }
            }
        }
        else{
            if(ptr1 != NULL){
                return TeamSize_helper(ptr1,emp_id);
            }
            else if (ptr2 != NULL){
                return TeamSize_helper(ptr2,emp_id);
            }else{
                return;
            }
        }
      }
    
   
 

int TeamSize(int emp_id) {
    int x = emp_id;
    return TeamSize_helper(CEO,x);
    
}

// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[]){
    CEO = create_company();
    print_company(CEO);

    int T; 
    scanf("%d", &T);

    char operation_type[20];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "level") == 0) {
            int x;
            scanf("%d", &x);
            int d = Level(x);
            printf("%d\n", d);
        } 

        if(strcmp(operation_type, "distance") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int d = Distance(x, y);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "employees_at_same_level") == 0) {
            int x;
            scanf("%d", &x);
            EmployeesAtSameLevel(x);
            printf("\n");
        }

        if(strcmp(operation_type, "get_employees") == 0) {
            get_employees();
            printf("\n");
        }

        if(strcmp(operation_type, "boss") == 0) {
            int x;
            scanf("%d", &x);
            int d = Boss(x);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "diameter") == 0) {
            int d = Diameter();
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "immediate_team") == 0) {
            int x;
            scanf("%d", &x);
            ImmediateTeam(x);
            printf("\n");
        }

        if(strcmp(operation_type, "team_size") == 0) {
            int x;
            scanf("%d", &x);
            int d = TeamSize(x);
            printf("%d\n", d);
        }
    }

    return 0;
}
