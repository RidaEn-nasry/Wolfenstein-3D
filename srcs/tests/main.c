

#include <tests.h>

/** Start of parser tests **/


// invalid conret 
START_TEST(validate_map_tests) {
    char *map_file = "./maps/map.cub";
    validate_map(map_file);
    char *stdout = get_next_line(0);
    ck_assert_str_eq(stdout, "Error:\n\t unknown identifier in map\n");
    free(stdout);
} END_TEST

Suite   *parser_suit( void ) {

    Suite *s;
    TCase *tc_core;

    s = suite_create( "parser_suite" );
    tc_core = tcase_create( "Core" );
    tcase_add_test( tc_core, validate_map_tests );
    suite_add_tcase( s, tc_core );
    return s;
}

/* End of parser tests */

int main( int argc, char **argv ) {

    if (argc < 2) {
        printf("Usage: ./check <tests id>\n");
        return 1;
    }
    if (ft_strncmp(argv[1], "prs", 3) == 0)
    {
            Suite *s = parser_suit();
            SRunner *sr = srunner_create(s);
            srunner_run_all(sr, CK_NORMAL);
            srunner_free(sr);
    }
    else {
        printf("invalid test id\n\t available tests are:\n\t\tprs\n");
        return 1;
    }
    return 0;
}

