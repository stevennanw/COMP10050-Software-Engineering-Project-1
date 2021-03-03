#include <stdio.h>
#include <stdlib.h>
#include "CUnit.h"
#include "Basic.h"
#include "avg_and_max.h"

//test max
void test_max(){
    double array1[1]={1};
    CU_ASSERT(max(array1,1) == 1);
    double array2[2]={-1};
    CU_ASSERT(max(array2,2) == -1);
    double array3[3]={1,2,3};
    CU_ASSERT(max(array3,3) == 3);
    double array4[4]={0,0,0};
    CU_ASSERT(max(array4,3) == 0);
    double array5[5]={-5,-3,-1};
    CU_ASSERT(max(array5,3) == -1);
}

//test average
void test_avg(){
    double array1[1]={1};
    CU_ASSERT(average(array1,1) == 1);
    double array2[2]={-1};
    CU_ASSERT(average(array2,2) == -1);
    double array3[3]={1,2,3};
    CU_ASSERT(average(array3,3) == 2);
    double array4[4]={0,0,0};
    CU_ASSERT(average(array4,3) == 0);
    double array5[5]={-5,-3,-1};
    CU_ASSERT(average(array5,3) == -3);
}


int main() {
    //max test
    CU_initialize_registry(); //initialise test registry
    CU_pSuite suite_max = CU_add_suite("max_test", 0, 0); //creat a test suite for max test
    CU_add_test(suite_max, "max", test_max); //test max
    CU_basic_set_mode(CU_BRM_VERBOSE); //set the run mode
    CU_basic_run_tests(); //run the test
    CU_cleanup_registry(); //cleanup test registry

    //average test
    CU_initialize_registry(); //initialise test registry
    CU_pSuite suite_avg = CU_add_suite("avg_test", 0, 0); //creat a test suite for average test
    CU_add_test(suite_avg, "avg", test_avg); //test average
    CU_basic_set_mode(CU_BRM_VERBOSE); //set the run mode
    CU_basic_run_tests(); //run the test
    CU_cleanup_registry(); //cleanup test registry
    return 0;
}


