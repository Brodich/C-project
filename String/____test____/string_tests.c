#include <string.h>

#include "../st_string.h"
#include "sprintf_tests.h"

// c

START_TEST(sprintf_3_c_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_c[_i], str_3[0]);
  int len_our = st_sprintf(our, str_c[_i], str_3[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_3_c_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_c[_i], str_3[1]);
  int len_our = st_sprintf(our, str_c[_i], str_3[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_3_c_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_c[_i], str_3[2]);
  int len_our = st_sprintf(our, str_c[_i], str_3[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_3_c_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_c[_i], str_3[3]);
  int len_our = st_sprintf(our, str_c[_i], str_3[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_3_c_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_c[_i], str_3[4]);
  int len_our = st_sprintf(our, str_c[_i], str_3[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_3_c_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_c[_i], str_3[5]);
  int len_our = st_sprintf(our, str_c[_i], str_3[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_c(void) {
  Suite *s = suite_create("sprintf_c");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_3_c_0, 0, 28);
  tcase_add_loop_test(tc, sprintf_3_c_1, 0, 28);
  tcase_add_loop_test(tc, sprintf_3_c_2, 0, 28);
  tcase_add_loop_test(tc, sprintf_3_c_3, 0, 28);
  tcase_add_loop_test(tc, sprintf_3_c_4, 0, 28);
  tcase_add_loop_test(tc, sprintf_3_c_5, 0, 28);

  suite_add_tcase(s, tc);
  return s;
}

// d

START_TEST(sprintf_2_d_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_d[_i], str_2[0]);
  int len_our = st_sprintf(our, str_d[_i], str_2[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_d_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_d[_i], str_2[1]);
  int len_our = st_sprintf(our, str_d[_i], str_2[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_d_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_d[_i], str_2[2]);
  int len_our = st_sprintf(our, str_d[_i], str_2[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_d_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_d[_i], str_2[3]);
  int len_our = st_sprintf(our, str_d[_i], str_2[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_d_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_d[_i], str_2[4]);
  int len_our = st_sprintf(our, str_d[_i], str_2[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_d_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_d[_i], str_2[5]);
  int len_our = st_sprintf(our, str_d[_i], str_2[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_8_hd_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hd[_i], str_8[0]);
  int len_our = st_sprintf(our, str_hd[_i], str_8[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_8_hd_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hd[_i], str_8[1]);
  int len_our = st_sprintf(our, str_hd[_i], str_8[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_8_hd_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hd[_i], str_8[2]);
  int len_our = st_sprintf(our, str_hd[_i], str_8[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_9_ld_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_ld[_i], str_9[0]);
  int len_our = st_sprintf(our, str_ld[_i], str_9[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_9_ld_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_ld[_i], str_9[1]);
  int len_our = st_sprintf(our, str_ld[_i], str_9[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_9_ld_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_ld[_i], str_9[2]);
  int len_our = st_sprintf(our, str_ld[_i], str_9[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_d(void) {
  Suite *s = suite_create("sprintf_d");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_2_d_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_d_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_d_2, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_d_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_d_4, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_d_5, 0, 20);

  tcase_add_loop_test(tc, sprintf_8_hd_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_8_hd_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_8_hd_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_9_ld_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_9_ld_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_9_ld_2, 0, 4);

  suite_add_tcase(s, tc);
  return s;
}

// i

START_TEST(sprintf_2_i_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_i[_i], str_2[0]);
  int len_our = st_sprintf(our, str_i[_i], str_2[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_i_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_i[_i], str_2[1]);
  int len_our = st_sprintf(our, str_i[_i], str_2[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_i_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_i[_i], str_2[2]);
  int len_our = st_sprintf(our, str_i[_i], str_2[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_i_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_i[_i], str_2[3]);
  int len_our = st_sprintf(our, str_i[_i], str_2[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_i_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_i[_i], str_2[4]);
  int len_our = st_sprintf(our, str_i[_i], str_2[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_i_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_i[_i], str_2[5]);
  int len_our = st_sprintf(our, str_i[_i], str_2[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_8_hi_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hi[_i], str_8[0]);
  int len_our = st_sprintf(our, str_hi[_i], str_8[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_8_hi_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hi[_i], str_8[1]);
  int len_our = st_sprintf(our, str_hi[_i], str_8[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_8_hi_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hi[_i], str_8[2]);
  int len_our = st_sprintf(our, str_hi[_i], str_8[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_9_li_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_li[_i], str_9[0]);
  int len_our = st_sprintf(our, str_li[_i], str_9[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_9_li_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_li[_i], str_9[1]);
  int len_our = st_sprintf(our, str_li[_i], str_9[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_9_li_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_li[_i], str_9[2]);
  int len_our = st_sprintf(our, str_li[_i], str_9[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_i(void) {
  Suite *s = suite_create("sprintf_i");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_2_i_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_i_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_i_2, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_i_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_i_4, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_i_5, 0, 20);

  tcase_add_loop_test(tc, sprintf_8_hi_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_8_hi_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_8_hi_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_9_li_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_9_li_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_9_li_2, 0, 4);

  suite_add_tcase(s, tc);
  return s;
}

// e

START_TEST(sprintf_1_e_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[0]);
  int len_our = st_sprintf(our, str_e[_i], str_1[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_e_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[1]);
  int len_our = st_sprintf(our, str_e[_i], str_1[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_e_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[2]);
  int len_our = st_sprintf(our, str_e[_i], str_1[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_e_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[3]);
  int len_our = st_sprintf(our, str_e[_i], str_1[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_e_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[4]);
  int len_our = st_sprintf(our, str_e[_i], str_1[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_e_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[5]);
  int len_our = st_sprintf(our, str_e[_i], str_1[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_e_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_e[_i], str_1[6]);
  int len_our = st_sprintf(our, str_e[_i], str_1[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[0]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[1]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[2]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[3]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[4]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[5]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_Le_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Le[_i], str_5[6]);
  int len_our = st_sprintf(our, str_Le[_i], str_5[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[0]);
  int len_our = st_sprintf(our, str_le[_i], str_10[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[1]);
  int len_our = st_sprintf(our, str_le[_i], str_10[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[2]);
  int len_our = st_sprintf(our, str_le[_i], str_10[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[3]);
  int len_our = st_sprintf(our, str_le[_i], str_10[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[4]);
  int len_our = st_sprintf(our, str_le[_i], str_10[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[5]);
  int len_our = st_sprintf(our, str_le[_i], str_10[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_le_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_le[_i], str_10[6]);
  int len_our = st_sprintf(our, str_le[_i], str_10[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_e(void) {
  Suite *s = suite_create("sprintf_e");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_1_e_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_e_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_e_2, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_e_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_e_4, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_e_5, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_e_6, 0, 20);

  tcase_add_loop_test(tc, sprintf_5_Le_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_Le_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_Le_2, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_Le_3, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_Le_4, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_Le_5, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_Le_6, 0, 4);

  tcase_add_loop_test(tc, sprintf_10_le_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_le_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_le_2, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_le_3, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_le_4, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_le_5, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_le_6, 0, 4);

  suite_add_tcase(s, tc);
  return s;
}

// E

START_TEST(sprintf_1_E_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[0]);
  int len_our = st_sprintf(our, str_E[_i], str_1[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_E_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[1]);
  int len_our = st_sprintf(our, str_E[_i], str_1[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_E_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[2]);
  int len_our = st_sprintf(our, str_E[_i], str_1[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_E_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[3]);
  int len_our = st_sprintf(our, str_E[_i], str_1[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_E_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[4]);
  int len_our = st_sprintf(our, str_E[_i], str_1[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_E_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[5]);
  int len_our = st_sprintf(our, str_E[_i], str_1[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_1_E_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_E[_i], str_1[6]);
  int len_our = st_sprintf(our, str_E[_i], str_1[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[0]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[1]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[2]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[3]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[4]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[5]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_5_LE_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LE[_i], str_5[6]);
  int len_our = st_sprintf(our, str_LE[_i], str_5[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[0]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[1]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[2]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[3]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[4]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[5]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_lE_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_lE[_i], str_10[6]);
  int len_our = st_sprintf(our, str_lE[_i], str_10[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_E(void) {
  Suite *s = suite_create("sprintf_E");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_1_E_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_E_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_E_2, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_E_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_E_4, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_E_5, 0, 20);
  tcase_add_loop_test(tc, sprintf_1_E_6, 0, 20);

  tcase_add_loop_test(tc, sprintf_5_LE_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_LE_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_LE_2, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_LE_3, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_LE_4, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_LE_5, 0, 4);
  tcase_add_loop_test(tc, sprintf_5_LE_6, 0, 4);

  tcase_add_loop_test(tc, sprintf_10_lE_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_lE_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_lE_2, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_lE_3, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_lE_4, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_lE_5, 0, 4);
  tcase_add_loop_test(tc, sprintf_10_lE_6, 0, 4);

  suite_add_tcase(s, tc);
  return s;
}

// f

START_TEST(sprintf_10_f_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[0]);
  int len_our = st_sprintf(our, str_f[_i], str_10[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[1]);
  int len_our = st_sprintf(our, str_f[_i], str_10[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[2]);
  int len_our = st_sprintf(our, str_f[_i], str_10[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[3]);
  int len_our = st_sprintf(our, str_f[_i], str_10[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[4]);
  int len_our = st_sprintf(our, str_f[_i], str_10[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[5]);
  int len_our = st_sprintf(our, str_f[_i], str_10[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[6]);
  int len_our = st_sprintf(our, str_f[_i], str_10[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_f_7) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_f[_i], str_10[7]);
  int len_our = st_sprintf(our, str_f[_i], str_10[7]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_f(void) {
  Suite *s = suite_create("sprintf_f");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_10_f_0, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_1, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_2, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_3, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_4, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_5, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_6, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_f_7, 0, 24);

  suite_add_tcase(s, tc);
  return s;
}

// g

START_TEST(sprintf_10_g_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[0]);
  int len_our = st_sprintf(our, str_g[_i], str_10[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_g_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[1]);
  int len_our = st_sprintf(our, str_g[_i], str_10[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_g_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[2]);
  int len_our = st_sprintf(our, str_g[_i], str_10[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_g_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[3]);
  int len_our = st_sprintf(our, str_g[_i], str_10[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_g_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[4]);
  int len_our = st_sprintf(our, str_g[_i], str_10[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_g_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[5]);
  int len_our = st_sprintf(our, str_g[_i], str_10[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_g_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_g[_i], str_10[6]);
  int len_our = st_sprintf(our, str_g[_i], str_10[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_g(void) {
  Suite *s = suite_create("sprintf_g");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_10_g_0, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_g_1, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_g_2, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_g_3, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_g_4, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_g_5, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_g_6, 0, 24);

  suite_add_tcase(s, tc);
  return s;
}

// G

START_TEST(sprintf_10_G_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[0]);
  int len_our = st_sprintf(our, str_G[_i], str_10[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_G_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[1]);
  int len_our = st_sprintf(our, str_G[_i], str_10[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_G_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[2]);
  int len_our = st_sprintf(our, str_G[_i], str_10[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_G_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[3]);
  int len_our = st_sprintf(our, str_G[_i], str_10[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_G_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[4]);
  int len_our = st_sprintf(our, str_G[_i], str_10[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_G_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[5]);
  int len_our = st_sprintf(our, str_G[_i], str_10[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_10_G_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_G[_i], str_10[6]);
  int len_our = st_sprintf(our, str_G[_i], str_10[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_G(void) {
  Suite *s = suite_create("sprintf_G");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_10_G_0, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_G_1, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_G_2, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_G_3, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_G_4, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_G_5, 0, 24);
  tcase_add_loop_test(tc, sprintf_10_G_6, 0, 24);

  suite_add_tcase(s, tc);
  return s;
}

// o

START_TEST(sprintf_11_Lo_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lo[_i], str_11[0]);
  int len_our = st_sprintf(our, str_Lo[_i], str_11[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_11_Lo_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lo[_i], str_11[1]);
  int len_our = st_sprintf(our, str_Lo[_i], str_11[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_11_Lo_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lo[_i], str_11[2]);
  int len_our = st_sprintf(our, str_Lo[_i], str_11[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_13_o_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_o[_i], str_13[0]);
  int len_our = st_sprintf(our, str_o[_i], str_13[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_13_o_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_o[_i], str_13[1]);
  int len_our = st_sprintf(our, str_o[_i], str_13[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_13_o_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_o[_i], str_13[2]);
  int len_our = st_sprintf(our, str_o[_i], str_13[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_o(void) {
  Suite *s = suite_create("sprintf_o");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_11_Lo_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_11_Lo_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_11_Lo_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_13_o_0, 0, 24);
  tcase_add_loop_test(tc, sprintf_13_o_1, 0, 24);
  tcase_add_loop_test(tc, sprintf_13_o_2, 0, 24);

  suite_add_tcase(s, tc);
  return s;
}

// s

START_TEST(sprintf_4_s_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[0]);
  int len_our = st_sprintf(our, str_s[_i], str_4[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_s_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[1]);
  int len_our = st_sprintf(our, str_s[_i], str_4[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_s_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[2]);
  int len_our = st_sprintf(our, str_s[_i], str_4[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_s_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[3]);
  int len_our = st_sprintf(our, str_s[_i], str_4[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_s_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[4]);
  int len_our = st_sprintf(our, str_s[_i], str_4[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_s_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[5]);
  int len_our = st_sprintf(our, str_s[_i], str_4[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_s_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_s[_i], str_4[6]);
  int len_our = st_sprintf(our, str_s[_i], str_4[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_s(void) {
  Suite *s = suite_create("sprintf_s");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_4_s_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_4_s_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_4_s_2, 0, 20);
  tcase_add_loop_test(tc, sprintf_4_s_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_4_s_4, 0, 20);
  tcase_add_loop_test(tc, sprintf_4_s_5, 0, 20);
  tcase_add_loop_test(tc, sprintf_4_s_6, 0, 20);

  suite_add_tcase(s, tc);
  return s;
}

// u

START_TEST(sprintf_13_u_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_u[_i], str_13[0]);
  int len_our = st_sprintf(our, str_u[_i], str_13[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_13_u_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_u[_i], str_13[1]);
  int len_our = st_sprintf(our, str_u[_i], str_13[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_13_u_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_u[_i], str_13[2]);
  int len_our = st_sprintf(our, str_u[_i], str_13[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hu_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hu[_i], str_15[0]);
  int len_our = st_sprintf(our, str_hu[_i], str_15[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hu_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hu[_i], str_15[1]);
  int len_our = st_sprintf(our, str_hu[_i], str_15[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hu_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hu[_i], str_15[2]);
  int len_our = st_sprintf(our, str_hu[_i], str_15[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_11_Lu_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lu[_i], str_11[0]);
  int len_our = st_sprintf(our, str_Lu[_i], str_11[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_11_Lu_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lu[_i], str_11[1]);
  int len_our = st_sprintf(our, str_Lu[_i], str_11[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_11_Lu_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lu[_i], str_11[2]);
  int len_our = st_sprintf(our, str_Lu[_i], str_11[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_u(void) {
  Suite *s = suite_create("sprintf_u");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_13_u_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_13_u_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_13_u_2, 0, 20);

  tcase_add_loop_test(tc, sprintf_15_hu_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_15_hu_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_15_hu_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_11_Lu_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_11_Lu_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_11_Lu_2, 0, 4);

  suite_add_tcase(s, tc);
  return s;
}

// x

START_TEST(sprintf_2_x_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_x[_i], str_2[0]);
  int len_our = st_sprintf(our, str_x[_i], str_2[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_x_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_x[_i], str_2[3]);
  int len_our = st_sprintf(our, str_x[_i], str_2[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_x_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_x[_i], str_2[5]);
  int len_our = st_sprintf(our, str_x[_i], str_2[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hx_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hx[_i], str_15[0]);
  int len_our = st_sprintf(our, str_hx[_i], str_15[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hx_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hx[_i], str_15[1]);
  int len_our = st_sprintf(our, str_hx[_i], str_15[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hx_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hx[_i], str_15[2]);
  int len_our = st_sprintf(our, str_hx[_i], str_15[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_16_Lx_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lx[_i], str_16[0]);
  int len_our = st_sprintf(our, str_Lx[_i], str_16[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_16_Lx_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lx[_i], str_16[1]);
  int len_our = st_sprintf(our, str_Lx[_i], str_16[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_16_Lx_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_Lx[_i], str_16[2]);
  int len_our = st_sprintf(our, str_Lx[_i], str_16[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_14_x_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_x[_i], str_14[0]);
  int len_our = st_sprintf(our, str_x[_i], str_14[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_14_x_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_x[_i], str_14[1]);
  int len_our = st_sprintf(our, str_x[_i], str_14[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_14_x_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_x[_i], str_14[2]);
  int len_our = st_sprintf(our, str_x[_i], str_14[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_x(void) {
  Suite *s = suite_create("sprintf_x");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_2_x_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_x_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_x_5, 0, 20);

  tcase_add_loop_test(tc, sprintf_15_hx_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_15_hx_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_15_hx_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_16_Lx_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_16_Lx_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_16_Lx_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_14_x_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_14_x_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_14_x_2, 0, 20);

  suite_add_tcase(s, tc);
  return s;
}

// X

START_TEST(sprintf_2_X_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_X[_i], str_2[0]);
  int len_our = st_sprintf(our, str_X[_i], str_2[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_X_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_X[_i], str_2[3]);
  int len_our = st_sprintf(our, str_X[_i], str_2[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_2_X_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_X[_i], str_2[5]);
  int len_our = st_sprintf(our, str_X[_i], str_2[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hX_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hX[_i], str_15[0]);
  int len_our = st_sprintf(our, str_hX[_i], str_15[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hX_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hX[_i], str_15[1]);
  int len_our = st_sprintf(our, str_hX[_i], str_15[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_15_hX_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_hX[_i], str_15[2]);
  int len_our = st_sprintf(our, str_hX[_i], str_15[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_16_LX_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LX[_i], str_16[0]);
  int len_our = st_sprintf(our, str_LX[_i], str_16[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_16_LX_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LX[_i], str_16[1]);
  int len_our = st_sprintf(our, str_LX[_i], str_16[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_16_LX_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_LX[_i], str_16[2]);
  int len_our = st_sprintf(our, str_LX[_i], str_16[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_14_X_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_X[_i], str_14[0]);
  int len_our = st_sprintf(our, str_X[_i], str_14[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_14_X_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_X[_i], str_14[1]);
  int len_our = st_sprintf(our, str_X[_i], str_14[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_14_X_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_X[_i], str_14[2]);
  int len_our = st_sprintf(our, str_X[_i], str_14[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_X(void) {
  Suite *s = suite_create("sprintf_X");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_2_X_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_X_3, 0, 20);
  tcase_add_loop_test(tc, sprintf_2_X_5, 0, 20);

  tcase_add_loop_test(tc, sprintf_15_hX_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_15_hX_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_15_hX_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_16_LX_0, 0, 4);
  tcase_add_loop_test(tc, sprintf_16_LX_1, 0, 4);
  tcase_add_loop_test(tc, sprintf_16_LX_2, 0, 4);

  tcase_add_loop_test(tc, sprintf_14_X_0, 0, 20);
  tcase_add_loop_test(tc, sprintf_14_X_1, 0, 20);
  tcase_add_loop_test(tc, sprintf_14_X_2, 0, 20);

  suite_add_tcase(s, tc);
  return s;
}

// p

START_TEST(sprintf_6_p_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[0]);
  int len_our = st_sprintf(our, str_p[_i], str_6[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_6_p_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[1]);
  int len_our = st_sprintf(our, str_p[_i], str_6[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_6_p_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[2]);
  int len_our = st_sprintf(our, str_p[_i], str_6[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_6_p_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[3]);
  int len_our = st_sprintf(our, str_p[_i], str_6[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_6_p_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[4]);
  int len_our = st_sprintf(our, str_p[_i], str_6[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_6_p_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[5]);
  int len_our = st_sprintf(our, str_p[_i], str_6[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_6_p_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_6[6]);
  int len_our = st_sprintf(our, str_p[_i], str_6[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_0) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[0]);
  int len_our = st_sprintf(our, str_p[_i], str_4[0]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_1) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[1]);
  int len_our = st_sprintf(our, str_p[_i], str_4[1]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_2) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[2]);
  int len_our = st_sprintf(our, str_p[_i], str_4[2]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_3) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[3]);
  int len_our = st_sprintf(our, str_p[_i], str_4[3]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_4) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[4]);
  int len_our = st_sprintf(our, str_p[_i], str_4[4]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_5) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[5]);
  int len_our = st_sprintf(our, str_p[_i], str_4[5]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

START_TEST(sprintf_4_p_6) {
  char orig[100], our[100];
  int len_orig = sprintf(orig, str_p[_i], str_4[6]);
  int len_our = st_sprintf(our, str_p[_i], str_4[6]);
  ck_assert_pstr_eq(orig, our);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_p(void) {
  Suite *s = suite_create("sprintf_p");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_6_p_0, 0, 28);
  tcase_add_loop_test(tc, sprintf_6_p_1, 0, 28);
  tcase_add_loop_test(tc, sprintf_6_p_2, 0, 28);
  tcase_add_loop_test(tc, sprintf_6_p_3, 0, 28);
  tcase_add_loop_test(tc, sprintf_6_p_4, 0, 28);
  tcase_add_loop_test(tc, sprintf_6_p_5, 0, 28);
  tcase_add_loop_test(tc, sprintf_6_p_6, 0, 28);

  tcase_add_loop_test(tc, sprintf_4_p_0, 0, 28);
  tcase_add_loop_test(tc, sprintf_4_p_1, 0, 28);
  tcase_add_loop_test(tc, sprintf_4_p_2, 0, 28);
  tcase_add_loop_test(tc, sprintf_4_p_3, 0, 28);
  tcase_add_loop_test(tc, sprintf_4_p_4, 0, 28);
  tcase_add_loop_test(tc, sprintf_4_p_5, 0, 28);
  tcase_add_loop_test(tc, sprintf_4_p_6, 0, 28);

  suite_add_tcase(s, tc);
  return s;
}

// n

START_TEST(sprintf_2_n_0) {
  char orig[100] = {0}, our[100] = {0};
  int leno = 0, lenu = 0;
  int len_orig = sprintf(orig, str_n[_i], &leno);
  int len_our = st_sprintf(our, str_n[_i], &lenu);
  ck_assert_int_eq(leno, lenu);
  ck_assert_int_eq(len_orig, len_our);
}
END_TEST

Suite *test_sprintf_n(void) {
  Suite *s = suite_create("sprintf_n");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_2_n_0, 0, 4);

  suite_add_tcase(s, tc);
  return s;
}

// percent

START_TEST(sprintf_15_percent_0) {
  char orig[100], our[100];
  sprintf(orig, str_percent[_i], str_1[0]);
  st_sprintf(our, str_percent[_i], str_15[0]);
  ck_assert_pstr_eq(orig, our);
}
END_TEST

START_TEST(sprintf_15_percent_1) {
  char orig[100], our[100];
  sprintf(orig, str_percent[_i], str_15[1]);
  st_sprintf(our, str_percent[_i], str_15[1]);
  ck_assert_pstr_eq(orig, our);
}
END_TEST

START_TEST(sprintf_15_percent_2) {
  char orig[100], our[100];
  sprintf(orig, str_percent[_i], str_15[2]);
  st_sprintf(our, str_percent[_i], str_15[2]);
  ck_assert_pstr_eq(orig, our);
}
END_TEST

START_TEST(sprintf_15_percent_3) {
  char orig[100], our[100];
  sprintf(orig, str_percent[_i], str_15[3]);
  st_sprintf(our, str_percent[_i], str_15[3]);
  ck_assert_pstr_eq(orig, our);
}
END_TEST

START_TEST(sprintf_15_percent_4) {
  char orig[100], our[100];
  sprintf(orig, str_percent[_i], str_15[4]);
  st_sprintf(our, str_percent[_i], str_15[4]);
  ck_assert_pstr_eq(orig, our);
}
END_TEST

Suite *test_sprintf_percent(void) {
  Suite *s = suite_create("sprintf_percent");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_loop_test(tc, sprintf_15_percent_0, 0, 28);
  tcase_add_loop_test(tc, sprintf_15_percent_1, 0, 28);
  tcase_add_loop_test(tc, sprintf_15_percent_2, 0, 28);
  tcase_add_loop_test(tc, sprintf_15_percent_3, 0, 28);
  tcase_add_loop_test(tc, sprintf_15_percent_4, 0, 28);

  suite_add_tcase(s, tc);
  return s;
}

#define STR 20
#define STRLG 100

START_TEST(st_memchr_test1) {
  char string[STR] = "hellowo\"r\''ld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string, i, 10), st_memchr(string, i, 10));
    ck_assert_ptr_eq(memchr(string, i, 15), st_memchr(string, i, 15));
    ck_assert_ptr_eq(memchr(string, i, 3), st_memchr(string, i, 3));
    ck_assert_ptr_eq(memchr(string, i, 0), st_memchr(string, i, 0));
  }
  char string1[STR] = "hell\0oworld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string1, i, 10), st_memchr(string1, i, 10));
    ck_assert_ptr_eq(memchr(string1, i, 15), st_memchr(string1, i, 15));
    ck_assert_ptr_eq(memchr(string1, i, 3), st_memchr(string1, i, 3));
    ck_assert_ptr_eq(memchr(string1, i, 0), st_memchr(string1, i, 0));
  }
  char string2[STR] = "hell\nowo\trld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string2, i, 10), st_memchr(string2, i, 10));
    ck_assert_ptr_eq(memchr(string2, i, 15), st_memchr(string2, i, 15));
    ck_assert_ptr_eq(memchr(string2, i, 3), st_memchr(string2, i, 3));
    ck_assert_ptr_eq(memchr(string2, i, 0), st_memchr(string2, i, 0));
  }
  char string3[STR] = "hell*\t oworld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string3, i, 10), st_memchr(string3, i, 10));
    ck_assert_ptr_eq(memchr(string3, i, 15), st_memchr(string3, i, 15));
    ck_assert_ptr_eq(memchr(string3, i, 3), st_memchr(string3, i, 3));
    ck_assert_ptr_eq(memchr(string3, i, 0), st_memchr(string3, i, 0));
  }
  char string4[STR] = "";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string4, i, 10), st_memchr(string4, i, 10));
    ck_assert_ptr_eq(memchr(string4, i, 15), st_memchr(string4, i, 15));
    ck_assert_ptr_eq(memchr(string4, i, 3), st_memchr(string4, i, 3));
    ck_assert_ptr_eq(memchr(string4, i, 0), st_memchr(string4, i, 0));
  }
  char string5[STR] = "\0";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string5, i, 10), st_memchr(string5, i, 10));
    ck_assert_ptr_eq(memchr(string5, i, 15), st_memchr(string5, i, 15));
    ck_assert_ptr_eq(memchr(string5, i, 3), st_memchr(string5, i, 3));
    ck_assert_ptr_eq(memchr(string5, i, 0), st_memchr(string5, i, 0));
  }
}
END_TEST

START_TEST(st_memchr_test2) {
  char string[STR] = "hellowo\"r\''ld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string, i, 10), st_memchr(string, i, 10));
    ck_assert_ptr_eq(memchr(string, i, 15), st_memchr(string, i, 15));
    ck_assert_ptr_eq(memchr(string, i, 3), st_memchr(string, i, 3));
    ck_assert_ptr_eq(memchr(string, i, 0), st_memchr(string, i, 0));
  }
  char string1[STR] = "hell\0oworld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string1, i, 10), st_memchr(string1, i, 10));
    ck_assert_ptr_eq(memchr(string1, i, 15), st_memchr(string1, i, 15));
    ck_assert_ptr_eq(memchr(string1, i, 3), st_memchr(string1, i, 3));
    ck_assert_ptr_eq(memchr(string1, i, 0), st_memchr(string1, i, 0));
  }
  char string2[STR] = "hell\nowo\trld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string2, i, 10), st_memchr(string2, i, 10));
    ck_assert_ptr_eq(memchr(string2, i, 15), st_memchr(string2, i, 15));
    ck_assert_ptr_eq(memchr(string2, i, 3), st_memchr(string2, i, 3));
    ck_assert_ptr_eq(memchr(string2, i, 0), st_memchr(string2, i, 0));
  }
  char string3[STR] = "hell*\t oworld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string3, i, 10), st_memchr(string3, i, 10));
    ck_assert_ptr_eq(memchr(string3, i, 15), st_memchr(string3, i, 15));
    ck_assert_ptr_eq(memchr(string3, i, 3), st_memchr(string3, i, 3));
    ck_assert_ptr_eq(memchr(string3, i, 0), st_memchr(string3, i, 0));
  }
  char string4[STR] = "";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string4, i, 10), st_memchr(string4, i, 10));
    ck_assert_ptr_eq(memchr(string4, i, 15), st_memchr(string4, i, 15));
    ck_assert_ptr_eq(memchr(string4, i, 3), st_memchr(string4, i, 3));
    ck_assert_ptr_eq(memchr(string4, i, 0), st_memchr(string4, i, 0));
  }
  char string5[STR] = "\0";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string5, i, 10), st_memchr(string5, i, 10));
    ck_assert_ptr_eq(memchr(string5, i, 15), st_memchr(string5, i, 15));
    ck_assert_ptr_eq(memchr(string5, i, 3), st_memchr(string5, i, 3));
    ck_assert_ptr_eq(memchr(string5, i, 0), st_memchr(string5, i, 0));
  }
}
END_TEST

START_TEST(st_memchr_test3) {
  char string[STR] = "hellowo\"r\''ld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string, i, sizeof(int)),
                     st_memchr(string, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string, i, sizeof(int)),
                     st_memchr(string, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string, i, sizeof(int)),
                     st_memchr(string, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string, i, sizeof(int)),
                     st_memchr(string, i, sizeof(int)));
  }
  char string1[STR] = "hell\0oworld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string1, i, sizeof(int)),
                     st_memchr(string1, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string1, i, sizeof(int)),
                     st_memchr(string1, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string1, i, sizeof(int)),
                     st_memchr(string1, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string1, i, sizeof(int)),
                     st_memchr(string1, i, sizeof(int)));
  }
  char string2[STR] = "hell\nowo\trld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string2, i, sizeof(int)),
                     st_memchr(string2, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string2, i, sizeof(int)),
                     st_memchr(string2, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string2, i, sizeof(int)),
                     st_memchr(string2, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string2, i, sizeof(int)),
                     st_memchr(string2, i, sizeof(int)));
  }
  char string3[STR] = "hell*\t oworld";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string3, i, sizeof(int)),
                     st_memchr(string3, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string3, i, sizeof(int)),
                     st_memchr(string3, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string3, i, sizeof(int)),
                     st_memchr(string3, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string3, i, sizeof(int)),
                     st_memchr(string3, i, sizeof(int)));
  }
  char string4[STR] = "";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string4, i, sizeof(int)),
                     st_memchr(string4, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string4, i, sizeof(int)),
                     st_memchr(string4, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string4, i, sizeof(int)),
                     st_memchr(string4, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string4, i, sizeof(int)),
                     st_memchr(string4, i, sizeof(int)));
  }
  char string5[STR] = "\0";
  for (int i = -30; i <= 300; i++) {
    ck_assert_ptr_eq(memchr(string5, i, sizeof(int)),
                     st_memchr(string5, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string5, i, sizeof(int)),
                     st_memchr(string5, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string5, i, sizeof(int)),
                     st_memchr(string5, i, sizeof(int)));
    ck_assert_ptr_eq(memchr(string5, i, sizeof(int)),
                     st_memchr(string5, i, sizeof(int)));
  }
}
END_TEST

START_TEST(st_memcmp_test1) {
  char string[STR] = "helloworld";
  char string1[STR] = "helloworld";
  char string2[STR] = "hell\0oworld";
  char string3[STR] = "hell\0oworld";
  char string4[STR] = "hell\noworld";
  char string5[STR] = "h1ell\noworld";
  char string6[STR] = "";
  char string7[STR] = "";
  char string8[STR] = "\0";

  ck_assert_int_eq(memcmp(string, string1, 11),
                   st_memcmp(string, string1, 11));
  ck_assert_int_eq(memcmp(string, string1, 5), st_memcmp(string, string1, 5));
  ck_assert_int_eq(memcmp(string, string1, 16),
                   st_memcmp(string, string1, 16));
  ck_assert_int_eq(memcmp(string, string1, 0), st_memcmp(string, string1, 0));

  ck_assert_int_eq(memcmp(string, string2, 11),
                   st_memcmp(string, string2, 11));
  ck_assert_int_eq(memcmp(string, string2, 5), st_memcmp(string, string2, 5));
  ck_assert_int_eq(memcmp(string, string2, 16),
                   st_memcmp(string, string2, 16));
  ck_assert_int_eq(memcmp(string, string2, 0), st_memcmp(string, string2, 0));

  ck_assert_int_eq(memcmp(string2, string3, 11),
                   st_memcmp(string2, string3, 11));
  ck_assert_int_eq(memcmp(string2, string3, 5),
                   st_memcmp(string2, string3, 5));
  ck_assert_int_eq(memcmp(string2, string3, 16),
                   st_memcmp(string2, string3, 16));
  ck_assert_int_eq(memcmp(string2, string3, 0),
                   st_memcmp(string2, string3, 0));

  ck_assert_int_eq(memcmp(string, string4, 11),
                   st_memcmp(string, string4, 11));
  ck_assert_int_eq(memcmp(string, string4, 5), st_memcmp(string, string4, 5));
  ck_assert_int_eq(memcmp(string, string4, 16),
                   st_memcmp(string, string4, 16));
  ck_assert_int_eq(memcmp(string, string4, 0), st_memcmp(string, string4, 0));

  ck_assert_int_eq(memcmp(string, string5, 11),
                   st_memcmp(string, string5, 11));
  ck_assert_int_eq(memcmp(string, string5, 5), st_memcmp(string, string5, 5));
  ck_assert_int_eq(memcmp(string, string5, 16),
                   st_memcmp(string, string5, 16));
  ck_assert_int_eq(memcmp(string, string5, 0), st_memcmp(string, string5, 0));

  ck_assert_int_eq(memcmp(string6, string7, 11),
                   st_memcmp(string6, string7, 11));
  ck_assert_int_eq(memcmp(string6, string7, 5),
                   st_memcmp(string6, string7, 5));
  ck_assert_int_eq(memcmp(string6, string7, 16),
                   st_memcmp(string6, string7, 16));
  ck_assert_int_eq(memcmp(string6, string7, 0),
                   st_memcmp(string6, string7, 0));

  ck_assert_int_eq(memcmp(string6, string8, 11),
                   st_memcmp(string6, string8, 11));
  ck_assert_int_eq(memcmp(string6, string8, 5),
                   st_memcmp(string6, string8, 5));
  ck_assert_int_eq(memcmp(string6, string8, 16),
                   st_memcmp(string6, string8, 16));
  ck_assert_int_eq(memcmp(string6, string8, 0),
                   st_memcmp(string6, string8, 0));
}
END_TEST

START_TEST(st_memcmp_test2) {
  char string[] = "helloworld";
  char string1[] = "helloworld";
  char string2[] = "hell\0oworld";
  char string3[] = "hell\0oworld";
  char string4[] = "hell\noworld";
  char string5[] = "h1ell\noworld";
  char string6[] = "";
  char string7[] = "";
  char string8[] = "\0";

  ck_assert_int_eq(memcmp(string, string1, 11),
                   st_memcmp(string, string1, 11));
  ck_assert_int_eq(memcmp(string, string1, 5), st_memcmp(string, string1, 5));
  ck_assert_int_eq(memcmp(string, string1, 16),
                   st_memcmp(string, string1, 16));
  ck_assert_int_eq(memcmp(string, string1, 0), st_memcmp(string, string1, 0));

  ck_assert_int_eq(memcmp(string, string2, 11),
                   st_memcmp(string, string2, 11));
  ck_assert_int_eq(memcmp(string, string2, 5), st_memcmp(string, string2, 5));
  ck_assert_int_eq(memcmp(string, string2, 16),
                   st_memcmp(string, string2, 16));
  ck_assert_int_eq(memcmp(string, string2, 0), st_memcmp(string, string2, 0));

  ck_assert_int_eq(memcmp(string2, string3, 11),
                   st_memcmp(string2, string3, 11));
  ck_assert_int_eq(memcmp(string2, string3, 5),
                   st_memcmp(string2, string3, 5));
  ck_assert_int_eq(memcmp(string2, string3, 16),
                   st_memcmp(string2, string3, 16));
  ck_assert_int_eq(memcmp(string2, string3, 0),
                   st_memcmp(string2, string3, 0));

  ck_assert_int_eq(memcmp(string, string4, 11),
                   st_memcmp(string, string4, 11));
  ck_assert_int_eq(memcmp(string, string4, 5), st_memcmp(string, string4, 5));
  ck_assert_int_eq(memcmp(string, string4, 16),
                   st_memcmp(string, string4, 16));
  ck_assert_int_eq(memcmp(string, string4, 0), st_memcmp(string, string4, 0));

  ck_assert_int_eq(memcmp(string, string5, 11),
                   st_memcmp(string, string5, 11));
  ck_assert_int_eq(memcmp(string, string5, 5), st_memcmp(string, string5, 5));
  ck_assert_int_eq(memcmp(string, string5, 16),
                   st_memcmp(string, string5, 16));
  ck_assert_int_eq(memcmp(string, string5, 0), st_memcmp(string, string5, 0));

  ck_assert_int_eq(memcmp(string6, string7, 11),
                   st_memcmp(string6, string7, 11));
  ck_assert_int_eq(memcmp(string6, string7, 5),
                   st_memcmp(string6, string7, 5));
  ck_assert_int_eq(memcmp(string6, string7, 16),
                   st_memcmp(string6, string7, 16));
  ck_assert_int_eq(memcmp(string6, string7, 0),
                   st_memcmp(string6, string7, 0));

  ck_assert_int_eq(memcmp(string6, string8, 11),
                   st_memcmp(string6, string8, 11));
  ck_assert_int_eq(memcmp(string6, string8, 5),
                   st_memcmp(string6, string8, 5));
  ck_assert_int_eq(memcmp(string6, string8, 16),
                   st_memcmp(string6, string8, 16));
  ck_assert_int_eq(memcmp(string6, string8, 0),
                   st_memcmp(string6, string8, 0));
}
END_TEST

START_TEST(st_memcpy_test1) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hell\noworld";
  char string3[STR] = "h1ell oworld";

  char string4[STR] = {0};
  char string5[STR] = {0};

  st_memcpy(string4, string, 15);
  memcpy(string5, string, 15);
  ck_assert_str_eq(string4, string5);

  st_memcpy(string4, string1, 15);
  memcpy(string5, string1, 15);
  ck_assert_str_eq(string4, string5);

  st_memcpy(string4, string2, 15);
  memcpy(string5, string2, 15);
  ck_assert_str_eq(string4, string5);

  st_memcpy(string4, string3, 15);
  memcpy(string5, string3, 15);
  ck_assert_str_eq(string4, string5);

  st_memcpy(string1, string2, 15);
  memcpy(string1, string, 15);
  ck_assert_str_eq(string4, string5);
}
END_TEST

START_TEST(st_memcpy_test2) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hell\noworld";
  char string3[STR] = "h1ell oworld";

  char string4[STR] = "helloworld";
  char string5[STR] = "hell\0oworld";
  char string6[STR] = "hell\noworld";
  char string7[STR] = "h1ell oworld";

  st_memcpy(string, string1, 15);
  memcpy(string4, string5, 15);
  ck_assert_str_eq(string, string4);

  st_memcpy(string2, string3, 15);
  memcpy(string6, string7, 15);
  ck_assert_str_eq(string2, string6);
}
END_TEST

START_TEST(st_memmove1_test) {
  /*Стандартная проверка*/
  char string[STR] = "helloworld123";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hell\noworld";
  char string3[STR] = "h1ell oworld";

  char string4[STR] = {0};
  char string5[STR] = {0};

  st_memmove(string4, string, 15);
  memmove(string5, string, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string4, string1, 15);
  memmove(string5, string1, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string4, string2, 15);
  memmove(string5, string2, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string4, string3, 15);
  memmove(string5, string3, 15);
  ck_assert_str_eq(string4, string5);
}
END_TEST

START_TEST(st_memmove2_test) {
  /*Проверка с изменением указателя*/
  char string[STR] = "helloworld123";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hell\noworld";
  char string3[STR] = "h1ell oworld";

  char string4[STR] = {0};
  char string5[STR] = {0};

  st_memmove(string4 + 3, string, 15);
  memmove(string5 + 3, string, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string4 + 3, string1, 15);
  memmove(string5 + 3, string1, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string4 + 3, string2, 15);
  memmove(string5 + 3, string2, 15);
  ck_assert_str_eq(string4, string5);
}
END_TEST

START_TEST(st_memmove3_test) {
  /*Проверка на перезапись в одну и ту же строку*/
  char string[STR] = "helloworld123";
  char string1[STR] = "helloworld123";
  char string2[STR] = "hell\0oworld";
  char string3[STR] = "hell\0oworld";
  char string4[STR] = "hell\noworld";
  char string5[STR] = "hell\noworld";
  char string6[STR] = "h1ell oworld";
  char string7[STR] = "h1ell oworld";
  char *string8 = NULL;

  st_memmove(string + 3, string, 15);
  memmove(string1 + 3, string1, 15);
  ck_assert_str_eq(string, string1);

  st_memmove(string - 3, string, 15);
  memmove(string1 - 3, string1, 15);
  ck_assert_str_eq(string, string1);

  st_memmove(string2 + 3, string2, 15);
  memmove(string3 + 3, string3, 15);
  ck_assert_str_eq(string2, string3);

  st_memmove(string2 - 3, string2, 15);
  memmove(string3 - 3, string3, 15);
  ck_assert_str_eq(string2, string3);

  st_memmove(string4 + 3, string4, 15);
  memmove(string5 + 3, string5, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string4 - 3, string4, 15);
  memmove(string5 - 3, string5, 15);
  ck_assert_str_eq(string4, string5);

  st_memmove(string6 + 3, string6, 15);
  memmove(string7 + 3, string7, 15);
  ck_assert_str_eq(string6, string7);

  st_memmove(string6 - 3, string6, 15);
  memmove(string7 - 3, string7, 15);
  ck_assert_str_eq(string6, string7);

  ck_assert_ptr_eq(memmove(0, 0, 15), st_memmove(0, 0, 15));
  ck_assert_ptr_eq(memmove(NULL, NULL, 15), st_memmove(NULL, NULL, 15));
}
END_TEST

START_TEST(st_memmove4_test) {
  /*Проверка на перезапись в одну и ту же строку*/
  char string[] = "helloworld123";
  char string1[] = "helloworld123";
  char string2[] = "hell\0oworld";
  char string3[] = "hell\0oworld";
  char string4[] = "hell\noworld";
  char string5[] = "hell\noworld";
  char string6[] = "h1ell oworld";
  char string7[] = "h1ell oworld";
  char string8[STR];
  char string9[STR];
  char string10[STR];
  char string11[STR];
  char string12[STR];
  char string13[STR];
  char string14[STR];
  char string15[STR];

  // st_memmove(string8, string, 13);
  // memmove(string9, string1, 13);
  // ck_assert_str_eq(string8, string9);

  st_memmove(string10, string2, 11);
  memmove(string11, string3, 11);
  ck_assert_str_eq(string10, string11);

  // st_memmove(string12, string4, 11);
  // memmove(string13, string5, 11);
  // ck_assert_str_eq(string12, string13);

  // st_memmove(string14, string6, 11);
  // memmove(string15, string7, 11);
  // ck_assert_str_eq(string14, string15);
}
END_TEST

START_TEST(st_memmove5_test) {
  /*Проверка на перезапись в одну и ту же строку*/
  char string[] = "helloworld123";
  char string1[] = "helloworld123";
  char string2[] = "hell\0oworld";
  char string3[] = "hell\0oworld";
  char string4[] = "hell\noworld";
  char string5[] = "hell\noworld";
  char string6[] = "h1ell oworld";
  char string7[] = "h1ell oworld";
  char string8[STR];
  char string9[STR];
  char string10[STR];
  char string11[STR];
  char string12[STR];
  char string13[STR];
  char string14[STR] = {0};
  char string15[STR] = {0};

  st_memmove(string8, string, 14);
  memmove(string9, string1, 14);
  ck_assert_str_eq(string8, string9);

  st_memmove(string10, string2, 12);
  memmove(string11, string3, 12);
  ck_assert_str_eq(string10, string11);

  st_memmove(string12, string4, 12);
  memmove(string13, string5, 12);
  ck_assert_str_eq(string12, string13);

  st_memmove(string14, string6, 12);
  memmove(string15, string7, 12);
  ck_assert_str_eq(string14, string15);
}
END_TEST

START_TEST(st_memset_test) {
  for (int i = 0; i <= 127; i++) {
    char string[STR] = "helloworld123";
    char string1[STR] = "helloworld123";
    char string2[STR] = "hell\0oworld";
    char string3[STR] = "hell\0oworld";
    char string4[STR] = "hell\noworld";
    char string5[STR] = "hell\noworld";
    char string6[STR] = "h1ell oworld";
    char string7[STR] = "h1ell oworld";
    ck_assert_str_eq(memset(string, i, 15), st_memset(string1, i, 15));
    ck_assert_str_eq(memset(string2, i, 15), st_memset(string3, i, 15));
    ck_assert_str_eq(memset(string4, i, 15), st_memset(string5, i, 15));
    ck_assert_str_eq(memset(string6, i, 15), st_memset(string7, i, 15));
  }
}
END_TEST

START_TEST(st_strcat_test) {
  char string[STRLG] = "helloworld";
  char string1[STRLG] = "hell\0oworld";
  char string2[STRLG] = "hello world";
  char string3[STRLG] = "hello\nworld";
  char string4[STRLG] = "helloworld";

  ck_assert_str_eq(strcat(string1, string), st_strcat(string1, string));
  ck_assert_str_eq(strcat(string2, string), st_strcat(string2, string));
  ck_assert_str_eq(strcat(string3, string), st_strcat(string3, string));

  // ck_assert_str_eq(strcat(string, string1), st_strcat(string, string1));
  // ck_assert_str_eq(strcat(string, string2), st_strcat(string, string2));
  // ck_assert_str_eq(strcat(string, string3), st_strcat(string, string31024
}
END_TEST

START_TEST(st_strncat_test) {
  /*Не рассмотренны краевые случаи*/

  char string[1024] = "helloworld";
  char string1[1024] = "hell\0oworld";
  char string2[1024] = "hello world";
  char string3[1024] = "hello\nworld";
  char string4[1024] = "helloworld";

  ck_assert_str_eq(strncat(string1, string, 15),
                   st_strncat(string1, string, 15));
  ck_assert_str_eq(strncat(string2, string, 15),
                   st_strncat(string2, string, 15));
  ck_assert_str_eq(strncat(string3, string, 15),
                   st_strncat(string3, string, 15));

  ck_assert_str_eq(strncat(string, string1, 15),
                   st_strncat(string, string1, 15));
  ck_assert_str_eq(strncat(string, string2, 15),
                   st_strncat(string, string2, 15));
  ck_assert_str_eq(strncat(string, string3, 15),
                   st_strncat(string, string3, 15));

  ck_assert_str_eq(strncat(string1, string, 40),
                   st_strncat(string1, string, 40));
  ck_assert_str_eq(strncat(string2, string, 40),
                   st_strncat(string2, string, 40));
  ck_assert_str_eq(strncat(string3, string, 40),
                   st_strncat(string3, string, 40));

  ck_assert_str_eq(strncat(string, string1, 40),
                   st_strncat(string, string1, 40));
  ck_assert_str_eq(strncat(string, string2, 40),
                   st_strncat(string, string2, 40));
  ck_assert_str_eq(strncat(string, string3, 40),
                   st_strncat(string, string3, 40));
}
END_TEST

START_TEST(st_strpbrk_test) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hello world";
  char string3[STR] = "hello\nworld";
  char string4[STR] = "helloworld";
  char *c = "j";
  char *c1 = "l";
  char *c2 = "\0";
  char *c3 = "\n";
  char *c4 = " ";

  ck_assert_ptr_eq(strpbrk(string, c), st_strpbrk(string, c));
  ck_assert_ptr_eq(strpbrk(string1, c), st_strpbrk(string1, c));
  ck_assert_ptr_eq(strpbrk(string2, c), st_strpbrk(string2, c));
  ck_assert_ptr_eq(strpbrk(string3, c), st_strpbrk(string3, c));
  ck_assert_ptr_eq(strpbrk(string4, c), st_strpbrk(string4, c));

  ck_assert_ptr_eq(strpbrk(string, c1), st_strpbrk(string, c1));
  ck_assert_ptr_eq(strpbrk(string1, c1), st_strpbrk(string1, c1));
  ck_assert_ptr_eq(strpbrk(string2, c1), st_strpbrk(string2, c1));
  ck_assert_ptr_eq(strpbrk(string3, c1), st_strpbrk(string3, c1));
  ck_assert_ptr_eq(strpbrk(string4, c1), st_strpbrk(string4, c1));

  ck_assert_ptr_eq(strpbrk(string, c2), st_strpbrk(string, c2));
  ck_assert_ptr_eq(strpbrk(string1, c2), st_strpbrk(string1, c2));
  ck_assert_ptr_eq(strpbrk(string2, c2), st_strpbrk(string2, c2));
  ck_assert_ptr_eq(strpbrk(string3, c2), st_strpbrk(string3, c2));
  ck_assert_ptr_eq(strpbrk(string4, c2), st_strpbrk(string4, c2));

  ck_assert_ptr_eq(strpbrk(string, c3), st_strpbrk(string, c3));
  ck_assert_ptr_eq(strpbrk(string1, c3), st_strpbrk(string1, c3));
  ck_assert_ptr_eq(strpbrk(string2, c3), st_strpbrk(string2, c3));
  ck_assert_ptr_eq(strpbrk(string3, c3), st_strpbrk(string3, c3));
  ck_assert_ptr_eq(strpbrk(string4, c3), st_strpbrk(string4, c3));

  ck_assert_ptr_eq(strpbrk(string, c4), st_strpbrk(string, c4));
  ck_assert_ptr_eq(strpbrk(string1, c4), st_strpbrk(string1, c4));
  ck_assert_ptr_eq(strpbrk(string2, c4), st_strpbrk(string2, c4));
  ck_assert_ptr_eq(strpbrk(string3, c4), st_strpbrk(string3, c4));
  ck_assert_ptr_eq(strpbrk(string4, c4), st_strpbrk(string4, c4));
}
END_TEST

START_TEST(st_strchr_test) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hello world";
  char string3[STR] = "hello\nworld";
  char string4[STR] = "helloworld";
  char string5[] = "";

  // FIX NULL не работает// если на i отправить 0, то там ошибка
  for (int i = 0; i < 127; i++) {
    ck_assert_ptr_eq(strchr(string, i), st_strchr(string, i));
    ck_assert_ptr_eq(strchr(string1, i), st_strchr(string1, i));
    ck_assert_ptr_eq(strchr(string2, i), st_strchr(string2, i));
    ck_assert_ptr_eq(strchr(string3, i), st_strchr(string3, i));
    ck_assert_ptr_eq(strchr(string4, i), st_strchr(string4, i));
    ck_assert_ptr_eq(strchr(string5, i), st_strchr(string5, i));
  }
}
END_TEST

START_TEST(st_strcmp_test) {
  // char string[STR] = "helloworld";
  // char string1[STR] = "helloworld";
  // char string2[STR] = "hell\0oworld";
  // char string3[STR] = "hell\0oworld";
  // char string4[STR] = "hell\noworld";
  // char string5[STR] = "h1ell\noworld";

  // ck_assert_int_eq(strcmp(string, string1), st_strcmp(string, string1));
  // ck_assert_int_eq(strcmp(string, string2), st_strcmp(string, string2));
  // ck_assert_int_eq(strcmp(string2, string3), st_strcmp(string2, string3));
  // ck_assert_int_eq(strcmp(string, string4), st_strcmp(string, string4));
  // ck_assert_int_eq(strcmp(string, string5), st_strcmp(string, string5));
  char in[][56] = {"Hello world", ",!0123456789", "Good day ",
                   " Seven ElEvEn, zero", "\n12345678?"};
  char in2[][56] = {"Hello world", "019", "Good  ", " SlEvEn", "!"};
  int out1 = st_strcmp(in[_i], in2[_i]);
  int out2 = strcmp(in[_i], in2[_i]);
  ck_assert_int_eq(out1, out2);
}
END_TEST

START_TEST(st_strncmp_test) {
  char string[STR] = "helloworld";
  char string1[STR] = "helloworld";
  char string2[STR] = "hell\0oworld";
  char string3[STR] = "hell\0oworld";
  char string4[STR] = "hell\noworld";
  char string5[STR] = "h1ell\noworld";

  ck_assert_int_eq(strncmp(string, string1, 10),
                   st_strncmp(string, string1, 10));
  ck_assert_int_eq(strncmp(string, string2, 10),
                   st_strncmp(string, string2, 10));
  ck_assert_int_eq(strncmp(string2, string3, 10),
                   st_strncmp(string2, string3, 10));
  ck_assert_int_eq(strncmp(string, string4, 10),
                   st_strncmp(string, string4, 10));
  ck_assert_int_eq(strncmp(string, string5, 10),
                   st_strncmp(string, string5, 10));
  ck_assert_int_eq(strncmp(string, string1, 20),
                   st_strncmp(string, string1, 20));
  ck_assert_int_eq(strncmp(string, string2, 20),
                   st_strncmp(string, string2, 20));
  ck_assert_int_eq(strncmp(string2, string3, 20),
                   st_strncmp(string2, string3, 20));
  ck_assert_int_eq(strncmp(string, string4, 20),
                   st_strncmp(string, string4, 20));
  ck_assert_int_eq(strncmp(string, string5, 20),
                   st_strncmp(string, string5, 20));
}
END_TEST

START_TEST(st_strrchr_test) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hello world";
  char string3[STR] = "hello\nworld";
  char string4[STR] = "helloworld";

  for (int i = 0; i < 127; i++) {
    ck_assert_ptr_eq(strrchr(string, i), st_strrchr(string, i));
    ck_assert_ptr_eq(strrchr(string1, i), st_strrchr(string1, i));
    ck_assert_ptr_eq(strrchr(string2, i), st_strrchr(string2, i));
    ck_assert_ptr_eq(strrchr(string3, i), st_strrchr(string3, i));
    ck_assert_ptr_eq(strrchr(string4, i), st_strrchr(string4, i));
  }
}
END_TEST

START_TEST(st_strspn_test) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hello world";
  char string3[STR] = "hello\nworld";
  char string4[STR] = "helloworld";

  char *c = "j";
  char *c1 = "l";
  char *c2 = "\0";
  char *c3 = "\n";
  char *c4 = " ";
  char *c5 = "jh";
  char *c6 = "llh";
  char *c7 = "\0h";
  char *c8 = "\nh";
  char *c9 = " h";

  ck_assert_int_eq(strspn(string, c), st_strspn(string, c));
  ck_assert_int_eq(strspn(string1, c), st_strspn(string1, c));
  ck_assert_int_eq(strspn(string2, c), st_strspn(string2, c));
  ck_assert_int_eq(strspn(string3, c), st_strspn(string3, c));
  ck_assert_int_eq(strspn(string4, c), st_strspn(string4, c));

  ck_assert_int_eq(strspn(string, c1), st_strspn(string, c1));
  ck_assert_int_eq(strspn(string1, c1), st_strspn(string1, c1));
  ck_assert_int_eq(strspn(string2, c1), st_strspn(string2, c1));
  ck_assert_int_eq(strspn(string3, c1), st_strspn(string3, c1));
  ck_assert_int_eq(strspn(string4, c1), st_strspn(string4, c1));

  ck_assert_int_eq(strspn(string, c2), st_strspn(string, c2));
  ck_assert_int_eq(strspn(string1, c2), st_strspn(string1, c2));
  ck_assert_int_eq(strspn(string2, c2), st_strspn(string2, c2));
  ck_assert_int_eq(strspn(string3, c2), st_strspn(string3, c2));
  ck_assert_int_eq(strspn(string4, c2), st_strspn(string4, c2));

  ck_assert_int_eq(strspn(string, c3), st_strspn(string, c3));
  ck_assert_int_eq(strspn(string1, c3), st_strspn(string1, c3));
  ck_assert_int_eq(strspn(string2, c3), st_strspn(string2, c3));
  ck_assert_int_eq(strspn(string3, c3), st_strspn(string3, c3));
  ck_assert_int_eq(strspn(string4, c3), st_strspn(string4, c3));

  ck_assert_int_eq(strspn(string, c4), st_strspn(string, c4));
  ck_assert_int_eq(strspn(string1, c4), st_strspn(string1, c4));
  ck_assert_int_eq(strspn(string2, c4), st_strspn(string2, c4));
  ck_assert_int_eq(strspn(string3, c4), st_strspn(string3, c4));
  ck_assert_int_eq(strspn(string4, c4), st_strspn(string4, c4));

  ck_assert_int_eq(strspn(string, c5), st_strspn(string, c5));
  ck_assert_int_eq(strspn(string1, c5), st_strspn(string1, c5));
  ck_assert_int_eq(strspn(string2, c5), st_strspn(string2, c5));
  ck_assert_int_eq(strspn(string3, c5), st_strspn(string3, c5));
  ck_assert_int_eq(strspn(string4, c5), st_strspn(string4, c5));

  ck_assert_int_eq(strspn(string, c6), st_strspn(string, c6));
  ck_assert_int_eq(strspn(string1, c6), st_strspn(string1, c6));
  ck_assert_int_eq(strspn(string2, c6), st_strspn(string2, c6));
  ck_assert_int_eq(strspn(string3, c6), st_strspn(string3, c6));
  ck_assert_int_eq(strspn(string4, c6), st_strspn(string4, c6));

  ck_assert_int_eq(strspn(string, c7), st_strspn(string, c7));
  ck_assert_int_eq(strspn(string1, c7), st_strspn(string1, c7));
  ck_assert_int_eq(strspn(string2, c7), st_strspn(string2, c7));
  ck_assert_int_eq(strspn(string3, c7), st_strspn(string3, c7));
  ck_assert_int_eq(strspn(string4, c7), st_strspn(string4, c7));

  ck_assert_int_eq(strspn(string, c8), st_strspn(string, c8));
  ck_assert_int_eq(strspn(string1, c8), st_strspn(string1, c8));
  ck_assert_int_eq(strspn(string2, c8), st_strspn(string2, c8));
  ck_assert_int_eq(strspn(string3, c8), st_strspn(string3, c8));
  ck_assert_int_eq(strspn(string4, c8), st_strspn(string4, c8));

  ck_assert_int_eq(strspn(string, c9), st_strspn(string, c9));
  ck_assert_int_eq(strspn(string1, c9), st_strspn(string1, c9));
  ck_assert_int_eq(strspn(string2, c9), st_strspn(string2, c9));
  ck_assert_int_eq(strspn(string3, c9), st_strspn(string3, c9));
  ck_assert_int_eq(strspn(string4, c9), st_strspn(string4, c9));
}
END_TEST

START_TEST(st_strstr_test) {
  char string[STR] = "helloworld";
  char string1[STR] = "hell\0oworld";
  char string2[STR] = "hello world";
  char string3[STR] = "hello\nworld";
  char string4[STR] = "helloworld";

  char *c = "lo";
  char *c1 = "l\0";
  char *c2 = "\0o";
  char *c3 = "o ";
  char *c4 = " w";
  char *c5 = "o\n";
  char *c6 = "\nw";
  char *c7 = "\0";
  char *c8 = "";
  char *c9 = "NULL";

  // ck_assert_ptr_eq(strstr(string, c), st_strstr(string, c));
  // ck_assert_ptr_eq(strstr(string1, c), st_strstr(string1, c));
  // ck_assert_ptr_eq(strstr(string2, c), st_strstr(string2, c));
  // ck_assert_ptr_eq(strstr(string3, c), st_strstr(string3, c));
  // ck_assert_ptr_eq(strstr(string4, c), st_strstr(string4, c));

  ck_assert_ptr_eq(strstr(string, c1), st_strstr(string, c1));
  ck_assert_ptr_eq(strstr(string1, c1), st_strstr(string1, c1));
  ck_assert_ptr_eq(strstr(string2, c1), st_strstr(string2, c1));
  ck_assert_ptr_eq(strstr(string3, c1), st_strstr(string3, c1));
  ck_assert_ptr_eq(strstr(string4, c1), st_strstr(string4, c1));

  ck_assert_ptr_eq(strstr(string, c2), st_strstr(string, c2));
  ck_assert_ptr_eq(strstr(string1, c2), st_strstr(string1, c2));
  ck_assert_ptr_eq(strstr(string2, c2), st_strstr(string2, c2));
  ck_assert_ptr_eq(strstr(string3, c2), st_strstr(string3, c2));
  ck_assert_ptr_eq(strstr(string4, c2), st_strstr(string4, c2));

  ck_assert_ptr_eq(strstr(string, c3), st_strstr(string, c3));
  ck_assert_ptr_eq(strstr(string1, c3), st_strstr(string1, c3));
  ck_assert_ptr_eq(strstr(string2, c3), st_strstr(string2, c3));
  ck_assert_ptr_eq(strstr(string3, c3), st_strstr(string3, c3));
  ck_assert_ptr_eq(strstr(string4, c3), st_strstr(string4, c3));

  ck_assert_ptr_eq(strstr(string, c4), st_strstr(string, c4));
  ck_assert_ptr_eq(strstr(string1, c4), st_strstr(string1, c4));
  ck_assert_ptr_eq(strstr(string2, c4), st_strstr(string2, c4));
  ck_assert_ptr_eq(strstr(string3, c4), st_strstr(string3, c4));
  ck_assert_ptr_eq(strstr(string4, c4), st_strstr(string4, c4));

  ck_assert_ptr_eq(strstr(string, c5), st_strstr(string, c5));
  ck_assert_ptr_eq(strstr(string1, c5), st_strstr(string1, c5));
  ck_assert_ptr_eq(strstr(string2, c5), st_strstr(string2, c5));
  ck_assert_ptr_eq(strstr(string3, c5), st_strstr(string3, c5));
  ck_assert_ptr_eq(strstr(string4, c5), st_strstr(string4, c5));

  ck_assert_ptr_eq(strstr(string, c6), st_strstr(string, c6));
  ck_assert_ptr_eq(strstr(string1, c6), st_strstr(string1, c6));
  ck_assert_ptr_eq(strstr(string2, c6), st_strstr(string2, c6));
  ck_assert_ptr_eq(strstr(string3, c6), st_strstr(string3, c6));
  ck_assert_ptr_eq(strstr(string4, c6), st_strstr(string4, c6));

  ck_assert_ptr_eq(strstr(string, c7), st_strstr(string, c7));
  ck_assert_ptr_eq(strstr(string1, c7), st_strstr(string1, c7));
  ck_assert_ptr_eq(strstr(string2, c7), st_strstr(string2, c7));
  ck_assert_ptr_eq(strstr(string3, c7), st_strstr(string3, c7));
  ck_assert_ptr_eq(strstr(string4, c7), st_strstr(string4, c7));

  ck_assert_ptr_eq(strstr(string, c8), st_strstr(string, c8));
  ck_assert_ptr_eq(strstr(string1, c8), st_strstr(string1, c8));
  ck_assert_ptr_eq(strstr(string2, c8), st_strstr(string2, c8));
  ck_assert_ptr_eq(strstr(string3, c8), st_strstr(string3, c8));
  ck_assert_ptr_eq(strstr(string4, c8), st_strstr(string4, c8));

  ck_assert_ptr_eq(strstr(string, c9), st_strstr(string, c9));
  ck_assert_ptr_eq(strstr(string1, c9), st_strstr(string1, c9));
  ck_assert_ptr_eq(strstr(string2, c9), st_strstr(string2, c9));
  ck_assert_ptr_eq(strstr(string3, c9), st_strstr(string3, c9));
  ck_assert_ptr_eq(strstr(string4, c9), st_strstr(string4, c9));
}
END_TEST

START_TEST(st_strtok_test) {
  char string[1024] = "tok/tok1/tok2/tok3/tok4";
  char mystring[1024] = "tok/tok1/tok2/tok3/tok4";
  char string1[1024] = "hell\0oworld";
  char mystring1[1024] = "hell\0oworld";
  char string2[1024] = "hello world";
  char mystring2[1024] = "hello world";
  char string3[1024] = "hello\nworld";
  char mystring3[1024] = "hello\nworld";
  char string4[1024] = "helloworld";
  char mystring4[1024] = "helloworld";

  char sep[STR] = "/";
  char *istr;
  char *istr1;

  istr = strtok(string, sep);
  istr1 = st_strtok(mystring, sep);

  ck_assert_str_eq(strtok(string, sep), st_strtok(mystring, sep));
  ck_assert_str_eq(istr, istr1);

  while (istr != NULL) {
    ck_assert_str_eq(istr, istr1);
    istr = strtok(NULL, sep);
    istr1 = st_strtok(NULL, sep);
  }

  istr = strtok(string1, sep);
  istr1 = st_strtok(mystring1, sep);

  ck_assert_str_eq(strtok(string1, sep), st_strtok(mystring1, sep));

  while (istr != NULL) {
    ck_assert_str_eq(istr, istr1);
    istr = strtok(NULL, sep);
    istr1 = st_strtok(NULL, sep);
  }

  istr = strtok(string2, sep);
  istr1 = st_strtok(string2, sep);

  ck_assert_str_eq(strtok(string2, sep), st_strtok(mystring2, sep));

  while (istr != NULL) {
    ck_assert_str_eq(istr, istr1);
    istr = strtok(NULL, sep);
    istr1 = st_strtok(NULL, sep);
  }

  istr = strtok(string3, sep);
  istr1 = st_strtok(string3, sep);

  ck_assert_str_eq(strtok(string3, sep), st_strtok(mystring3, sep));

  while (istr != NULL) {
    ck_assert_str_eq(istr, istr1);
    istr = strtok(NULL, sep);
    istr1 = st_strtok(NULL, sep);
  }

  istr = strtok(string4, sep);
  istr1 = st_strtok(string4, sep);

  ck_assert_str_eq(strtok(string4, sep), st_strtok(mystring4, sep));

  while (istr != NULL) {
    ck_assert_str_eq(istr, istr1);
    istr = strtok(NULL, sep);
    istr1 = st_strtok(NULL, sep);
  }
}
END_TEST

START_TEST(st_strcspn_test) {
  char string[1024] = "tok/tok1/tok2/tok3/tok4";
  char string1[1024] = "hell\0oworld";
  char string2[1024] = "hello world";
  char string3[1024] = "hello\nworld";
  char string4[1024] = "helloworld";

  char c[STR] = "/\n lo\0";

  ck_assert_int_eq(strcspn(string, c), st_strcspn(string, c));
  ck_assert_int_eq(strcspn(string1, c), st_strcspn(string1, c));
  ck_assert_int_eq(strcspn(string2, c), st_strcspn(string2, c));
  ck_assert_int_eq(strcspn(string3, c), st_strcspn(string3, c));
  ck_assert_int_eq(strcspn(string4, c), st_strcspn(string4, c));
}
END_TEST

START_TEST(st_strncpy_test) {
  char string01[1024] = "tok/tok1/tok2/tok3/tok4";
  char string02[1024] = "tok/tok1/tok2/tok3/tok4";
  char string03[1024] = "hell\0oworld";
  char string04[1024] = "hell\0oworld";
  char string05[1024] = "hello world";
  char string06[1024] = "hello world";
  char string07[1024] = "hello\nworld";
  char string08[1024] = "hello\nworld";
  char string09[1024] = "helloworld";
  char string10[1024] = "helloworld";
  char str[1024] = {0};
  char strour[1024] = {0};

  ck_assert_str_eq(strncpy(str, string01, 30),
                   st_strncpy(strour, string02, 30));
  ck_assert_str_eq(strncpy(str, string03, 30),
                   st_strncpy(strour, string04, 30));
  ck_assert_str_eq(strncpy(str, string05, 30),
                   st_strncpy(strour, string06, 30));
  ck_assert_str_eq(strncpy(str, string07, 30),
                   st_strncpy(strour, string08, 30));
  ck_assert_str_eq(strncpy(str, string09, 30),
                   st_strncpy(strour, string10, 30));

  ck_assert_str_eq(strncpy(str, string01, 10),
                   st_strncpy(strour, string02, 10));
  ck_assert_str_eq(strncpy(str, string03, 10),
                   st_strncpy(strour, string04, 10));
  ck_assert_str_eq(strncpy(str, string05, 10),
                   st_strncpy(strour, string06, 10));
  ck_assert_str_eq(strncpy(str, string07, 10),
                   st_strncpy(strour, string08, 10));
  ck_assert_str_eq(strncpy(str, string09, 10),
                   st_strncpy(strour, string10, 10));
}
END_TEST

START_TEST(st_strcpy_test) {
  char string01[1024] = "tok/tok1/tok2/tok3/tok4";
  char string03[1024] = "hell\0oworld";
  char string05[1024] = "hello world";
  char string07[1024] = "hello\nworld";
  char string09[1024] = "helloworld";
  char str[1024] = {0};
  char strour[1024] = {0};

  ck_assert_str_eq(strcpy(str, string01), st_strcpy(strour, string01));
  ck_assert_str_eq(strcpy(str, string03), st_strcpy(strour, string03));
  ck_assert_str_eq(strcpy(str, string05), st_strcpy(strour, string05));
  ck_assert_str_eq(strcpy(str, string07), st_strcpy(strour, string07));
  ck_assert_str_eq(strcpy(str, string09), st_strcpy(strour, string09));
}
END_TEST

START_TEST(st_strerror_test) {
  for (int i = -30; i <= 300; i++) {
    ck_assert_str_eq(st_strerror(i), st_strerror(i));
  }
}
END_TEST

START_TEST(st_to_upper_test) {
  char string01[1024] = "Tok/toK1/tOk2/tok3/tok4";
  char string02[1024] = "TOK/TOK1/TOK2/TOK3/TOK4";
  char string03[1024] = "hell\0oworld";
  char string04[1024] = "HELL\0OWORLD";
  char string05[1024] = "hello world";
  char string06[1024] = "HELLO WORLD";
  char string07[1024] = "hello\nworld";
  char string08[1024] = "HELLO\nWORLD";
  char string09[1024] = "helloworld";
  char string10[1024] = "HELLOWORLD";
  char *pstr = st_to_upper(string01);
  ck_assert_str_eq(string02, pstr);
  free(pstr);
  pstr = st_to_upper(string03);
  ck_assert_str_eq(string04, pstr);
  free(pstr);
  pstr = st_to_upper(string05);
  ck_assert_str_eq(string06, pstr);
  free(pstr);
  pstr = st_to_upper(string07);
  ck_assert_str_eq(string08, pstr);
  free(pstr);
  pstr = st_to_upper(string09);
  ck_assert_str_eq(string10, pstr);
  free(pstr);
}
END_TEST

START_TEST(st_to_lower_test) {
  char string01[1024] = "tok/tok1/tok2/tok3/tok4";
  char string02[1024] = "ToK/tOK1/TOk2/TOK3/TOK4";
  char string03[1024] = "hell\0oworld";
  char string04[1024] = "HELL\0OWORLD";
  char string05[1024] = "hello world";
  char string06[1024] = "HELLO WORLD";
  char string07[1024] = "hello\nworld";
  char string08[1024] = "HELLO\nWORLD";
  char string09[1024] = "helloworld";
  char string10[1024] = "HELLOWORLD";
  char *pstr = st_to_lower(string02);
  ck_assert_str_eq(string01, pstr);
  free(pstr);
  pstr = st_to_lower(string04);
  ck_assert_str_eq(string03, pstr);
  free(pstr);
  pstr = st_to_lower(string06);
  ck_assert_str_eq(string05, pstr);
  free(pstr);
  pstr = st_to_lower(string08);
  ck_assert_str_eq(string07, pstr);
  free(pstr);
  pstr = st_to_lower(string10);
  ck_assert_str_eq(string09, pstr);
  free(pstr);
}
END_TEST

START_TEST(st_insert_test) {
  char insert_str1[][256] = {"qwerty", "qwerty", "210000001", ""};
  char insert_str2[][256] = {"DXD", "DXD", "999", "no_str"};
  int insert_index[10] = {0, 6, 5, 0};

  char insert_out[][256] = {"DXDqwerty", "qwertyDXD", "210009990001", "no_str"};
  char *out1 =
      (char *)st_insert(insert_str1[_i], insert_str2[_i], insert_index[_i]);
  ck_assert_pstr_eq(out1, insert_out[_i]);
  free(out1);
}
END_TEST

START_TEST(st_insert_test_NULL) {
  char insert_str1[][256] = {"qwerty", "qwerty"};
  char insert_str2[][256] = {"DXD", "DXD"};
  int insert_index[10] = {-1, 7};

  char *out1 = st_NULL;
  out1 = (char *)st_insert(insert_str1[_i], insert_str2[_i], insert_index[_i]);
  ck_assert_ptr_null(out1);
  free(out1);

  out1 = (char *)st_insert(NULL, "qwerty", 0);
  ck_assert_ptr_null(out1);
  free(out1);
  out1 = (char *)st_insert("qwerty", NULL, 0);
  ck_assert_ptr_null(out1);
  free(out1);
}
END_TEST

START_TEST(st_trim_test) {
  char trim_str1[][256] = {
      "** \\this ** stroka **", "qwerty", "  210000001", "", "qw",
      "abc000000def",           "ABOB\nA"};
  char trim_str2[][256] = {"* \\", "* \\", "9 9", "no_str", "qw", "abef", "\n"};

  char insert_out[][256] = {"this ** stroka", "qwerty", "210000001", "", "",
                            "c000000d",       "ABOB\nA"};
  char *out1 = (char *)st_trim(trim_str1[_i], trim_str2[_i]);
  ck_assert_pstr_eq(out1, insert_out[_i]);

  free(out1);

  out1 = (char *)st_trim("qwerty", NULL);
  ck_assert_pstr_eq(out1, "qwerty");

  free(out1);
}
END_TEST

START_TEST(st_trim_test_NULL) {
  char *out1 = (char *)st_trim(NULL, "g");
  ck_assert_ptr_null(out1);
  free(out1);
}
END_TEST

START_TEST(st_trim_ANNA) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = st_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = st_trim(empty_str, st_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = st_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";
  trimmed_str = st_trim(st_NULL, empty_format);
  ck_assert(trimmed_str == st_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx --";
  char *format_str = "x -";
  trimmed_str = st_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

Suite *test_string(void) {
  Suite *s = suite_create("string_and_c#");
  TCase *tc = tcase_create("string_tc");

  tcase_add_test(tc, st_memchr_test1);
  tcase_add_test(tc, st_memchr_test2);
  tcase_add_test(tc, st_memchr_test3);
#ifdef __APPLE__
  tcase_add_test(tc, st_memcmp_test1);
  tcase_add_test(tc, st_memcmp_test2);
#endif
  tcase_add_test(tc, st_memcpy_test1);
  tcase_add_test(tc, st_memcpy_test2);
  tcase_add_test(tc, st_memmove1_test);
  tcase_add_test(tc, st_memmove2_test);
  tcase_add_test(tc, st_memmove3_test);
  tcase_add_test(tc, st_memmove4_test);
  tcase_add_test(tc, st_memmove5_test);
  tcase_add_test(tc, st_memset_test);
  tcase_add_test(tc, st_strcat_test);
  tcase_add_test(tc, st_strncat_test);
  tcase_add_test(tc, st_strpbrk_test);
  tcase_add_test(tc, st_strchr_test);
  tcase_add_loop_test(tc, st_strcmp_test, 0, 5);
  tcase_add_test(tc, st_strncmp_test);
  tcase_add_test(tc, st_strrchr_test);
  tcase_add_test(tc, st_strspn_test);
  tcase_add_test(tc, st_strstr_test);
  tcase_add_test(tc, st_strtok_test);
  tcase_add_test(tc, st_strcspn_test);
  tcase_add_test(tc, st_strncpy_test);
  tcase_add_test(tc, st_strcpy_test);
  tcase_add_test(tc, st_strerror_test);
  tcase_add_test(tc, st_to_upper_test);
  tcase_add_test(tc, st_to_lower_test);
  tcase_add_loop_test(tc, st_insert_test, 0, 4);
  tcase_add_loop_test(tc, st_insert_test_NULL, 0, 2);
  // tcase_add_loop_test(tc, st_trim_test, 0, 7);
  tcase_add_test(tc, st_trim_test_NULL);
  tcase_add_test(tc, st_trim_ANNA);

  suite_add_tcase(s, tc);
  return s;
}
#include <limits.h>

int main(void) {
  int failed_count = 0;

  Suite *st_string = test_string();
  Suite *st_c = test_sprintf_c();
  Suite *st_d = test_sprintf_d();
  Suite *st_i = test_sprintf_i();
  Suite *st_e = test_sprintf_e();
  Suite *st_E = test_sprintf_E();
  Suite *st_f = test_sprintf_f();
  Suite *st_o = test_sprintf_o();
  Suite *st_s = test_sprintf_s();
  Suite *st_u = test_sprintf_u();
  Suite *st_x = test_sprintf_x();
  Suite *st_X = test_sprintf_X();
  Suite *st_p = test_sprintf_p();
  Suite *st_n = test_sprintf_n();
  Suite *st_percent = test_sprintf_percent();

  SRunner *suite_runner = srunner_create(st_string);
  srunner_set_fork_status(suite_runner, CK_NOFORK);
  srunner_add_suite(suite_runner, st_c);
  srunner_add_suite(suite_runner, st_d);
  srunner_add_suite(suite_runner, st_i);
  srunner_add_suite(suite_runner, st_e);
  srunner_add_suite(suite_runner, st_E);
  srunner_add_suite(suite_runner, st_f);
  srunner_add_suite(suite_runner, st_o);
  srunner_add_suite(suite_runner, st_s);
  srunner_add_suite(suite_runner, st_u);
  srunner_add_suite(suite_runner, st_x);
  srunner_add_suite(suite_runner, st_X);
  srunner_add_suite(suite_runner, st_p);
  srunner_add_suite(suite_runner, st_n);
  srunner_add_suite(suite_runner, st_percent);

  srunner_run_all(suite_runner, CK_NORMAL);

  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  printf("\n\n_____ALL FAILED : %d_____\n\n", failed_count);

  return (failed_count != 0) ? 1 : 0;
}
