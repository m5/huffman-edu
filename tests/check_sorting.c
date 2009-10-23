#include <check.h>
#include "../src/sorting.h"
START_TEST(test_gappy_bubble)
{
    int scrambled[] = { 1, 10, 7, 6, 3, 2, 5, 8, 4, 9 };
    int sorted[]    = { 1,  2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double swaps = 0;
    double comps = 0;
    int size = 10;

    gappy_bubble(scrambled, size, &comps, &swaps, 1, 0);
    fail_unless (memcmp( scrambled, sorted, size) == 0,
           "Array not sorted correctly!");
}
END_TEST

START_TEST(test_gappy_bubble_g2)
{
    int scrambled[] = { 1, 10, 7, 6, 3, 2, 5, 9, 4, 8 };
    int sorted_0[] = { 1, 10, 3, 6, 4, 2, 5, 9, 7, 8 };
    int sorted_1[] = { 1,  2, 3, 6, 4, 8, 5, 9, 7, 10 };
    double swaps = 0;
    double comps = 0;
    int size = 10;

    gappy_bubble(scrambled, size, &comps, &swaps, 2, 0);
    fail_unless (memcmp( scrambled, sorted_0, size) == 0,
           "Array not sorted correctly!");

    gappy_bubble(scrambled, size, &comps, &swaps, 2, 1);
    fail_unless (memcmp( scrambled, sorted_1, size) == 0,
           "Array not sorted correctly!");
}
END_TEST

START_TEST(test_gappy_insertion)
{
    int scrambled[] = { 1, 10, 7, 6, 3, 2, 5, 8, 4, 9 };
    int sorted[]    = { 1,  2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double swaps = 0;
    double comps = 0;
    int size = 10;

    gappy_insertion(scrambled, size, &comps, &swaps, 1);
    int i = 0;
    for(i=0; i<size; i++){
        printf("(%d, %d) ", scrambled[i], sorted[i]);
    }
    printf("\n");
    fail_unless (memcmp( scrambled, sorted, size) == 0,
           "Array not sorted correctly!");

}
END_TEST

START_TEST(test_gappy_insertion_g2)
{
    int scrambled[] = { 1, 10, 7, 6, 3, 2, 5, 9, 4, 8 };
    int sorted_g2[] = { 1,  2, 3, 6, 4, 8, 5, 9, 7, 10 };
    double swaps = 0;
    double comps = 0;
    int size = 10;

    gappy_insertion(scrambled, size, &comps, &swaps, 2);

    int i = 0;
    for(i=0; i<size; i++){
        printf("(%d, %d) ", scrambled[i], sorted_g2[i]);
    }
    printf("\n");
    fail_unless (memcmp( scrambled, sorted_g2, size) == 0,
           "Array not sorted correctly!");
}
END_TEST

Suite * sorting_suite (void){
    Suite *s = suite_create ("Sorting");

    TCase *tc_bubble = tcase_create("Bubble");
    tcase_add_test (tc_bubble,test_gappy_bubble);
    tcase_add_test (tc_bubble,test_gappy_bubble_g2);

    TCase *tc_insertion = tcase_create("Insertion");
    tcase_add_test (tc_insertion,test_gappy_insertion);
    tcase_add_test (tc_insertion,test_gappy_insertion_g2);

    suite_add_tcase(s, tc_bubble);
    suite_add_tcase(s, tc_insertion);
    return s;
}


int main (void){
    int number_failed;
    Suite *s = sorting_suite();
    SRunner *sr = srunner_create (s);
    srunner_run_all (sr, CK_NORMAL);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);
    return (number_failed == 0 ) ? EXIT_SUCCESS : EXIT_FAILURE;
    return 0;
}
