#include<stdio.h>
#include<string.h>
struct Employee {
    int employee_id ;
    char name[30];
    char job_title[20];
    char department[20];
    float salary;
};
    struct Employee emp[50];
    int num;
    int count=0;

void addEmployee();
void displayEmployees();
void updateEmployee();
void deleteEmployee();
void calculateBonus();

int main()
{ 
    int choice;

    printf("\nEnter the number of Employees : ");
    scanf("%d", &num);

    do{
        printf("\nEmployee Management Menu \n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Calculate Bonus\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addEmployee();
            break;
            case 2: displayEmployees();
            break;
            case 3: updateEmployee();
            break;
            case 4: deleteEmployee();
            break;
            case 5: calculateBonus();
            break;
            case 6: printf("Exiting the program \n");
            default: printf("Invalid choice! \n"); 
        }
    }
    while(choice != 6);
    return 0;
}


void addEmployee(){
    for(int i = 0; i < num; i++) {
        printf("\nEnter the details of Employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &emp[i].employee_id);

        printf("Name of the Employee: ");
        scanf("%s", emp[i].name);

        printf("Job Title: ");
        scanf("%s", emp[i].job_title);

        printf("Department: ");
        scanf("%s", emp[i].department);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }
    count=num;
    printf("All employees details added successfully! \n");
}


void displayEmployees() {
    if(count==0){
        printf("NO EMPLOYEE RECORDS FOUND \n");
        return ;
    }
    
    for(int i=0 ; i < count; i++){
        printf("\nEmployee %d\n", i + 1);
        printf("ID: %d\n", emp[i].employee_id);
        printf("Name: %s\n", emp[i].name);
        printf("Job Title: %s\n", emp[i].job_title);
        printf("Department: %s\n", emp[i].department);
        printf("Salary: %.2f\n", emp[i].salary);
    }
}



void updateEmployee() {
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(emp[i].employee_id == id) {
            printf("New Name: ");
            scanf("%s", emp[i].name);

            printf("New Job Title: ");
            scanf("%s", emp[i].job_title);

            printf("New Department: ");
            scanf("%s", emp[i].department);

            printf("New Salary: ");
            scanf("%f", &emp[i].salary);

            printf("Employee updated successfully!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}



void deleteEmployee() {
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(emp[i].employee_id == id) {
            for(int j = i; j < count-1; j++) {
                emp[j] = emp[j + 1];
            }
            count--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee not found!\n");
}



void calculateBonus() {
    int i;
    float bonus;

    for(i = 0; i < count; i++) {
        bonus = emp[i].salary * 0.10;
        printf("\nEmployee ID: %d", emp[i].employee_id);
        printf("\nName: %s", emp[i].name);
        printf("\nBonus (10%%): %.2f\n", bonus);
    }
}





