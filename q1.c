#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

long long int ans[1001][1001];
long long int first[1001][1001];
long long int second[1001][1001];
long long int input_m[1001][1001];

int s1,s2,m1,m2,n1,n2,i1,i2;
void input() {
    scanf("%d %d",&i1,&i2);
    for (int i = 0; i < i1; ++i) {
        for (int j = 0; j < i1; ++j) {
            scanf("%lld", &input_m[i][j]);
      }
   }
}
/*
// loop order ijk
void multiply_1() {

   // Initializing 
   for (int i = 0; i < 1001; ++i) {
      for (int j = 0; j < 1001; ++j) {
         ans[i][j] = 0;
      }
   }

   // Multiplying 
   for (int i = 0; i < m1; ++i) {
      for (int j = 0; j < m2; ++j) {
         for (int k = 0; k < n1; ++k) {
            ans[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}
*/
//loop order ikj
/*void multiply_2() {
    register int i,j,k;
    struct timeval tv1, tv2;
    struct timezone tz;
    double elapsed; 
    omp_set_num_threads(omp_get_num_procs());
   // Initializing 
    #pragma omp parallel for private(i,j)
   for (i = 0; i < 1001; ++i) {
      for (j = 0; j < 1001; ++j) {
         ans[i][j] = 0;
      }
   }
   gettimeofday(&tv1, &tz);
  #pragma omp parallel for private(i,k,j) shared(first,second,ans)
   // Multiplying 
   for (i = 0; i < m1; ++i) {
       for (k = 0; k < n1; ++k) {

      for (j = 0; j < m2-15; j+=16) {
         
            ans[i][j+0] += first[i][k] * second[k][j+0];
            ans[i][j+1] += first[i][k] * second[k][j+1];
            ans[i][j+2] += first[i][k] * second[k][j+2];
            ans[i][j+3] += first[i][k] * second[k][j+3];
            ans[i][j+4] += first[i][k] * second[k][j+4];
            ans[i][j+5] += first[i][k] * second[k][j+5];
            ans[i][j+6] += first[i][k] * second[k][j+6];
            ans[i][j+7] += first[i][k] * second[k][j+7];
            ans[i][j+8] += first[i][k] * second[k][j+8];
            ans[i][j+9] += first[i][k] * second[k][j+9];
            ans[i][j+10] += first[i][k] * second[k][j+10];
            ans[i][j+11] += first[i][k] * second[k][j+11];
            ans[i][j+12] += first[i][k] * second[k][j+12];
            ans[i][j+13] += first[i][k] * second[k][j+13];
            ans[i][j+14] += first[i][k] * second[k][j+14];
            ans[i][j+15] += first[i][k] * second[k][j+15];

         }
         for(;j<m2;j++)
         {
          ans[i][j] += first[i][k] * second[k][j];
         }
      }
   }
   gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("elapsed time = %f seconds.\n", elapsed);
}*/
/*void multiply_2() {
    register int i,j,k;
    struct timeval tv1, tv2;
    struct timezone tz;
    double elapsed; 
    omp_set_num_threads(omp_get_num_procs());
   // Initializing 
    #pragma omp parallel for private(i,j)
   for (i = 0; i < 1001; ++i) {
      for (j = 0; j < 1001; ++j) {
         ans[i][j] = 0;
      }
   }
   gettimeofday(&tv1, &tz);
  #pragma omp parallel for private(i,k,j) shared(first,second,ans)
   // Multiplying 
   for (i = 0; i < m1; ++i) {
       for (k = 0; k < n1; ++k) {
      for (j = 0; j < m2; ++j) {
         
            ans[i][j] += first[i][k] * second[k][j];
         }
      }
   }
   gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    printf("elapsed time = %f seconds.\n", elapsed);
}*/
void multiply_2() {
    int i,j,k;
    struct timeval tv1, tv2;
    struct timezone tz;
    double elapsed; 
    omp_set_num_threads(omp_get_num_procs());
   // Initializing 
   for (i = 0; i < 1001; ++i) {
      for (j = 0; j < 1001; ++j) {
         ans[i][j] = 0;
      }
   }
   gettimeofday(&tv1, &tz);
  #pragma omp parallel for private(i,k,j) shared(first,second,ans)
   // Multiplying 
   for (i = 0; i < m1; ++i) {
       for (k = 0; k < n1; ++k) {
      for (j = 0; j < m2; ++j) {
         
            ans[i][j] += first[i][k] * second[k][j];
         }
      }
   }
   gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    //printf("elapsed time = %f seconds.\n", elapsed);
}
/*
//loop order kij
void multiply_3() {

   // Initializing 
   for (int i = 0; i < 1001; ++i) {
      for (int j = 0; j < 1001; ++j) {
         ans[i][j] = 0;
      }
   }

   // Multiplying 
   for (int k = 0; k < n1; ++k) {
   for (int i = 0; i < m1; ++i) {
      for (int j = 0; j < m2; ++j) {
            ans[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}
*/

void print_matrix()
{
    printf("%d %d\n",s1,s2);
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            printf("%lld ",ans[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    input();
    for (int i = 0; i < i1; ++i) {
    for (int j = 0; j < i2; ++j) {   
        first[i][j]=input_m[i][j]; 
    }
    }
    m1=i1;
    m2=i2;
    struct timeval tv1, tv2;
    struct timezone tz;
    double elapsed; 
     gettimeofday(&tv1, &tz);
    if(n == 1)
    {
        printf("%d %d\n",m1,m2);
        for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            printf("%lld ",first[i][j]);
        }
        printf("\n");
    }

        return 0;
    }
    for(int i =1;i<n;i++)
    {
        input();
        for (int i = 0; i < i1; ++i) {
        for (int j = 0; j < i2; ++j) {   
            second[i][j]=input_m[i][j]; 
        }
        }
        n1=i1;
        n2=i2;
        s1 = m1;
        s2 = n2;
        multiply_2();
        for (int i = 0; i < s1; ++i) {
        for (int j = 0; j < s2; ++j) {   
        first[i][j]=ans[i][j]; 
        }
        }
        m1=s1;
        m2=s2;
    }
    gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
    //printf("total elapsed time = %f seconds.\n", elapsed);
    print_matrix();
    return 0;
}