
#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {

    FILE *file = fopen("employee_details.dat", "wb");
    
    if (file == NULL) {
        printf("Error creating the file.");
        return 1;
    }
    
    struct Employee employees[3];
    
    for (int i = 0; i < 3; i++) {
        printf("Enter details for employee %d:\n", i+1);
        
        printf("ID: ");
        scanf("%d", &employees[i].id);
        
        printf("Name: ");
        scanf("%s", employees[i].name);
        
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        
        fwrite(&employees[i], sizeof(struct Employee), 1, file);
    }
    

    fclose(file);
    
    
    file = fopen("employee_details.dat", "rb");
    
    if (file == NULL) {
        printf("Error opening the file.");
        return 1;
    }
    

    struct Employee employee;
    int employeeCount = 0;
    
    printf("\nEmployee details:\n");
    
    while (fread(&employee, sizeof(struct Employee), 1, file)) {
        printf("\nEmployee %d:\n", ++employeeCount);
        
        printf("ID: %d\n", employee.id);
        printf("Name: %s\n", employee.name);
        printf("Salary: %.2f\n", employee.salary);
    }
    
    fclose(file);
    
    return 0;
}
