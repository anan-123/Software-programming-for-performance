## REPORT
ANALYSING TOOLS
PERF: It is a performance analysis tool for Linux
● perf stat: obtain event counts
● perf record: record events for later reporting
● perf report: break down events by process, function, etc.
● perf annotate: annotate assembly or source code with event counts
● perf top: see live event count
● perf bench: run different kernel microbenchmarks
 Performance counters for Linux are a new kernel-based subsystem that provides a framework for all things performance analysis. It covers hardware level (CPU/PMU, Performance Monitoring Unit) features and software features (software counters, tracepoints) as well.

CACHE GRIND: It helps you find bad memories and memory leaks. It helps count the number of cache hits and cache misses.

GPROF helps to analyze the behavior while running. It gives an analysis report of the program while running and gives the time consumption of each function. It analyses the connection between individual functions.

CLOCK_GETTIME: It is present in the time.h library and is used to get the current time of the clock.

syntax :
```
#include <time.h>
int clock_gettime( clockid_t clock_id , struct timespec* tp );
clock_id : clock id
tp: puts the time into the buffer pointed by tp
```
MATRIX MULTIPLICATION

BASIC OPTIMIZATIONS DONE: 
1. transpose of matrix - CACHE EFFECIENT
2. interchanging loops to find the most efficient.
3. Declaring global matrices.
 CODE 1: LOOP ORDER IJK :
 // loop order ijk
```
voidmultiply_1() {
_// Multiplying_
for(inti= 0 ;i<m1;++i) {
      for(intj= 0 ;j<m2;++j) {
          for(intk= 0 ;k<n1;++k) {
                        ans[i][j]+=first[i][k]*second[k][j];
}}}}

```
TIME :
real 1m37.055s
user 1m25.365s
sys 0m0.540s
REASON: This executes in the maximum time since there is a very poor spatial locality in loops, and there are many caches misses due to this. This is because since in the innermost loop we are running is k, the second[k][j] is always a cache miss since we are not accessing contiguous memory locations. So this has a very low spatial locality resulting in more time for execution.

CODE 2: LOOP ORDER IKJ :
```
_//loop order ikj_
voidmultiply_2() {

// Multiplying
for(inti= 0 ;i<m1;++i) {
       for(intk= 0 ;k<n1;++k) {
              for(intj= 0 ;j<m2;++j) {
                      ans[i][j]+=first[i][k]*second[k][j];
}}}}
```
TIME :
real 0m41.489s
user 0m40.986s
sys 0m0.388s

REASON: This executes in the least time since there is an excellent spatial locality in loops, and there are many cache hits due to this. This is because since in the innermost loop we are running is k and then j, we are accessing all the contiguous memory locations first. So this has an excellent spatial locality resulting in the least time for execution.

CODE 3: LOOP ORDER KIJ :
```
_//loop order kij_
voidmultiply_3() {

// Multiplying
for(intk= 0 ;k<n1;++k) {
      for(inti= 0 ;i<m1;++i) {
          for(intj= 0 ;j<m2;++j) {
                ans[i][j]+=first[i][k]*second[k][j];
}}}}
```
TIME :
real 0m42.021s
user 0m41.740s
sys 0m0.361s

REASON: This executes in moderate time since there are moderate spatial localities in loops, and there are both cache hits and misses. This is because the innermost loop we are running is j which results in cache hits for a second[k][j], but cache misses for first[i][k]. So this has a moderate spatial locality resulting in moderate time for execution.

RESULT: IKJ has the best spatial locality to due access from contiguous memory locations, and it runs in the least time.

# 1: PARALELLISING THE MULTIPLICATION (best-optimized version)

Setting threads as the number of processors. Parallelizing the loop with i,j,k as a private and first array, second array, and an array as shared. Variables in shared context are visible to all threads running in associated parallel regions. Variables in private contexts are hidden from other threads. Each
the thread has its own private copy of the variable, and modifications made by a thread to its copy are not visible to other threads.

# 2: ADDING REGISTER VARIABLES AND PARALLELISATION

Made all the local variables as register variables.
Parallelizing the initialization loop with I,j as private.
Parallelizing all 3 array copying loops.
This doesn't make a big difference in time.

# 3:LOOP UNROLLING

Tried loop unrolling by 4,8,16 times, and 16 times became the most efficient loop unrolling. Loop unrolling increases the program’s speed by eliminating loop control instruction and loop test instructions. But by the below table, we see that loop unrolling takes a bit more time than parallelized programs since parallel running is faster than loop unrolling and loop unrolling is unnecessary since parallelization is already done.


```
TIME TAKEN: is the time taken for matrix multiplication.
ELAPSED TIME: is the time taken in each matrix multiplication
TOTAL ELAPSED TIME: gives the total time after the input to the end of the program(1.1.total time of running after input)
```

TIME ANALYSIS, GPROF, PERF, CACHEGRIND REPORTS ARE GIVEN IN REPORT.PDF.
