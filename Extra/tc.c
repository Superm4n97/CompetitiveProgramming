#include <stdio.h>
#include <conio.h>
int main()
{
    FILE *fptr ;
    int i, n, empno ;
    float bpay, allow, ded ;
    char name[10] ;
    fptr = fopen("EMPLOYEE.DAT", "w") ;
    printf("Enter the number of employees : ") ;
    scanf("%d", &n) ;
    for(i = 0 ; i < n ; i++)
    {
        printf("Enter the employee number : ") ;
        scanf("%d", &empno) ;
        printf("Enter the name : ") ;
        scanf("%s", name) ;
        printf("Enter the basic pay, allowances & deductions : ") ;
        scanf("%f %f %f", &bpay, &allow, &ded) ;
        fprintf(fptr, "%d %s %f %f %f", empno, name, bpay, allow, ded) ;
    }
    fclose(fptr) ;
    fptr = fopen("EMPLOYEE.DAT", "r") ;
    printf("Emp.   No. Name  Bpay    Allow    Ded    Npay\n");
    for(i = 0 ; i < n ; i++)
    {
        fscanf(fptr,"%d %s %f %f %f", &empno, name, &bpay, &allow, &ded) ;
        printf("%d 	 %s 	 %.2f 	 %.2f 	 %.2f 	 %.2f\n", empno, name, bpay, allow, ded, bpay + allow - ded) ;
    }
    fclose(fptr);

    return 0;
}
