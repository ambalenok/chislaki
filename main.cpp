#include <locale>
#include <iostream>
using namespace std;
const int n=4;
int i, j, m, k;
double MaxEl, bb;
 
double a[n][n+1]={{  1, 2, 3, 4, 4}, 
{-15, -12,  50, -16, 44}, 
{-27, -36,  73,   8, 142},
{  9,  12, -10, -16, -76}};
 
int main()
{
    setlocale(LC_ALL, "Russian");
    double* x; 
    x = (double *)malloc(n* sizeof(double));
 
    for (k = 0; k<n; k++) 
    {
        MaxEl = abs(a[k][k]);
        i = k;
        for(m = k+1; m<n; m++)
            if(abs(a[m][k])>MaxEl)
            {
                i = m;
                MaxEl = abs(a[m][k]);
            }
 
             if (i != k)  //  перестановка i-ой строки, содержащей главный элемент k-ой строки
            {
                for (j=k; j < n+1; j++)
                {
                    bb = a[k][j];
                    a[k][j] = a[i][j];
                    a[i][j] = bb;
                }
            }
            MaxEl = a[k][k];//преобразование k-ой строки (Вычисление масштабирующих множителей)
            a[k][k] = 1;   
            for (j=k+1;j<n+1;j++) 
                a[k][j] = a[k][j]/MaxEl;
            for (i = k+1; i < n; i++)//преобразование строк с помощью k-ой строки
            {
                bb = a[i][k];
                a[i][k] = 0;
                if (bb!=0)
                    for (j=k+1; j< n+1; j++)
                        a[i][j]=a[i][j]-bb*a[k][j];
            }
    }
 
    for (i=n-1; i>=0; i--)   //Нахождение решений СЛАУ
    {
        x[i] = 0;
        MaxEl = a[i][n];
        for (j = n; j>i; j--) 
            MaxEl = MaxEl-a[i][j]*x[j];
        x[i] = MaxEl;
    }
 
    for (i = 0; i< n; i++)
    {
        cout<<"x["<<i+1<<"]="<<x[i];
        cout<<endl;
    }
 return 0;
}