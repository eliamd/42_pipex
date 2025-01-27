#include <criterion/criterion.h>
#include "../include/pipex.h"

// Test check_args function
Test(pipex_tests, check_args_valid)
{
    char *argv[] = {"pipex", "infile", "cmd1", "cmd2", "outfile", NULL};
    int argc = 5;

    cr_assert(check_args(argc, argv) == 1, "Valid arguments should return 1");
}

Test(pipex_tests, check_args_invalid)
{
    char *argv[] = {"pipex", "infile", "cmd1", NULL};
    int argc = 3;

    cr_assert(check_args(argc, argv) == 0, "Invalid arguments should return 0");
}

// Test ft_setup_files function
Test(pipex_tests, setup_files)
{
    char *test_infile = "tests/test_files/test_input.txt";
    char *test_outfile = "tests/test_files/test_output.txt";
    char *argv[] = {"pipex", test_infile, "cmd1", "cmd2", test_outfile, NULL};
    int fd_in, fd_out;

    // Create test input file
    system("mkdir -p tests/test_files");
    system("echo 'test content' > tests/test_files/test_input.txt");

    cr_assert(ft_setup_files(argv, &fd_in, &fd_out) == 1, "Setup files should succeed");

    close(fd_in);
    close(fd_out);
}
