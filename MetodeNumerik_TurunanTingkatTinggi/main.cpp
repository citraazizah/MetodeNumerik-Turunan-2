#include <stdio.h>
#include <stdlib.h>
#define  maks 100
int m, n,i,j;
float b[maks];
float A[maks][maks];

void swap(int j, int k)
{
    float temp;
    for(i=0;i<=n;i++){
        if(i!=n){
            temp = A[j][i];
            A[j][i] = A[k][i];
            A[k][i] = temp;
        }
        else{
            temp = b[j];
            b[j] = b[k];
            b[k] = temp;
        }
    }
}
 void utama(int j)
 {
     float C = A[j][j];
     for(i=0;i<n;i++){
        A[j][i] = A[j][i]/C;
        if(j == i)
        b[j]=b[j]/C;
     }

 }
 void output()
{
    printf("\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%.2f\t",A[i][j]);
            }
            printf("\t| %.2f",b[i]);
            printf("\n");
    }
}

void pivot (int l)
{
    printf("\nmatriks setelah di pivot\n");
    int tujuan;
    if(A[l][l]==0)
    {
        for(i=0;i<n;i++)
        {
            if(A[i][l]!=0){
                tujuan=i+1;
                break;
            }
        }
        swap(l,tujuan);
    }
    if(A[l][l]!=1){
        utama(l);
    }
}

void nol(int i)
{
    int k;
    for(j=i+1;j<n;j++){
        float C = A[j][i];
        if(C==0)
            continue;
        for(k=0;k<n;k++){
            A[j][k] = A[j][k] - (C * A[i][k]);
            if(j==k)
            b[j] = b[j] - C*b[i];
        }
    }
    output();
}

void nol2(int f)
{
    int j,k;
    float c;
    printf("\nHasil dari Gaus Jordan: \n");
    for(j = f-1; j>=0; j--){
        c = A[j][f];
        if(c == 0)
            continue;
        for(k = f; k>=0; k--)
        {
            A[j][k] = A[j][k] - (c * A[f][k]);
            if(j == k)
                b[k] = b[k] - (c * b[f]);
        }
    }
    output();
}

/*void akar()
{
    float a[maks];
    for(i=n-1 ; i>=0 ; i--){
        if(i==n-1)
        {
            a[i] = b[i];
            continue;
        }
        float temp = b[i];
        for(j =0; j<n;j++){

            temp = temp - (A[i][i+j] * a[i+j]);
            a[i] = temp;
        }
    }
        printf("\n\n");
        printf("Akar dari Persamaan ini adalah\t: ");
        printf("X3 = %.2f\tX2 = %.2f\tX1 = %.2f\n\n",a[2],a[1],a[0]);
}*/

void gaus()
{
    int a;
    for(a=0;a<m;a++){

            pivot(a);
            output();
            printf("\nMatriks setelah di NOL kan\t: \n");
            nol(a);
            printf("------------------------------------------------------------------------");
    }
}

void gausJordan()
{
    int a;
    for(a=0;a<m;a++){

            pivot(a);
            output();
            printf("\nMatriks setelah di NOL kan\t: \n");
            nol(a);
            printf("------------------------------------------------------------------------");
        }

    for(a=n-1; a>= 0; a--){
        nol2(a);
    }
}

void seidel()
{
    int i,k,j;
    float e,iterasi;
    float temp;
    float s[maks],x[maks];
    printf("\nInput iterasi maksimum\t: ");
    scanf("%f",&iterasi);
    printf("Input toleransi error\t: ");
    scanf("%f",&e);
    for(i=0;i<n;i++){
        printf("Nilai x%d\t: ",i+1);
        scanf("%f",&x[i]);
        s[i] = x[i];
    }
    printf("===================================================================\n");
    printf("\t\tHasil Dari Gauss Seidell\n");
    printf("===================================================================\n");
    for(i=0;i<n;i++){ // untuk iterasi nya
            printf("\niterasi ke x%d\t: \n",i+1);
        for(j=0;j<n;j++){ // untuk penampungnya
            temp=0;
                for(k=0;k<n;k++){
                    if(j!=k)
                        temp += A[j][k]*x[j];
            x[i] = (1/A[j][k]*(b[i]-temp));
           // printf("\n%d-\n",k);
            printf("\nx-%d\t: %.3f",k+1,x[k]);
            }
        }
        //printf("|\t%d\t|\t%.3f\t|\t%.3f\t|\t%.3f\t|\n",i,x[i],x[i],x[i]);
    }
}

void menu()
{
    int menu;
    printf("\nDiselesaikan dengan metode apa\t: ");
    printf("\n\t  1. Metode Gauss");
    printf("\n\t  2. Metode Gauss Jordan");
    printf("\n\t  3. Metode Gauss Seidel\n");
    printf("\nInput menu pilihanmu\t: ");
    scanf("%d",&menu);

    if(menu==1){
        gaus();
    }else if(menu==2){
       gausJordan();
    }else if(menu==3){
        seidel();
    }else
        printf("Pilihan menu salah!\n");
}

void input()
{
    printf("\nInput jumlah variabel baris\t: ");
    scanf("%d",&m);
    printf("Input jumlah variabel kolom\t: ");
    scanf("%d",&n);
    printf("\n\nMatriks anda berordo\t: %d x %d\n",m,n);

    fflush(stdin);

    if(n==m)
    {
        printf("\nInput Matriks A\n\n");
        for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    printf("Baris ke-%d Kolom ke-%d\t: ",i+1,j+1);
                    scanf("%f",&A[i][j]);
            }
            printf("-----------------------------------\n");

        }
        printf("\n");
        fflush(stdin);

        printf("Input matriks vektor B\t: \n");
        for(i=0;i<m;i++){
                printf("Input nilai b\t: ");
                scanf("%f",&b[i]);
                A[i][j]=b[i];
        }
        printf("\nMatriks Augmented\t:\n");
        output();
        printf("\n");

    //ke pilihan menu
    menu();
    }
     else
    {
    printf("--------------------------------------------------------------------------\n");
    printf("\n\tPROGRAM SELESAI !! jumlah baris != jumlah kolom\n\n");
    printf("--------------------------------------------------------------------------\n");
    }
}


int main()
{
    char jwb;
    printf("by Citra Azizah Dewi\n");
    printf("\n==============================================================================\n");
    printf("\t\t M E T O D E--P E R S A M A A N--L I N I E R\n");
    printf("==============================================================================\n");

    do{
    //inputkan data
        input();
        fflush(stdin);
        printf("\n\nMau coba lagi ? ");
        scanf("%c",&jwb);
    }while(jwb=='Y' || jwb=='y');
    printf("\n\t\tS E L E S A I\n");

    return 0;
}
