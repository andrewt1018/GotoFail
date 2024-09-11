#include <stdbool.h>
#include <stdio.h>

int
RandomCheck(int Input)
{
    int Status = false;
 
    if (Input >= 2) Status = false;
 
    return false;
}
 
int
BuggedFunction(int Input)
{
    int Status = false;
    int Err;
 
    fprintf(stdout, "Reachable code\n");
    if ((Err = RandomCheck(Input)) != true) {
        goto fail;
        goto fail;
    }
 
    Status = true;
 
    fprintf(stdout, "Unreachable code.\n");
 
fail:
    return Status;
}
 
int main(int argc, char **argv)
{
    int Err;
 
    // UNREFERENCED_PARAMETER(argv);
 
    Err = BuggedFunction(argc);
    fprintf(stdout, "BuggedFunction(%d) = %d\n", argc, Err);
}