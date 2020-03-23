#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define die() do { \
    fprintf(stderr, "died in %s: %u\n", __func__, __LINE__); \
    exit(EXIT_FAILURE); \
} while (0)

int
main(const int argc, const char * const * const argv, const char * const * const envp)
{
    printf("argc %d\n", argc);

    char stack = '\0';
    printf("stack %p < %p < %p < %p < %p\n", &stack, argv, envp, *argv, *envp);

    #define LLP "LD_LIBRARY_PATH"
    const char * const llp = getenv(LLP);
    printf("getenv %p %s\n", llp, llp);

    const char * const * env;
    for (env = envp; *env; env++) {
        if (!strncmp(*env, LLP, sizeof(LLP)-1)) {
            printf("%p %s\n", *env, *env);
        }
    }
    exit(EXIT_SUCCESS);
}
