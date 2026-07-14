#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("Child %s: PID = %d\n", argv[1], GetCurrentProcessId());
        return 0;
    }

    int result1 = _spawnl(_P_NOWAIT, argv[0], argv[0], "1", NULL);
    int result2 = _spawnl(_P_NOWAIT, argv[0], argv[0], "2", NULL);
    _cwait(NULL, result1, WAIT_CHILD);
    _cwait(NULL, result2, WAIT_CHILD);
    printf("Parent: PID = %d\n", GetCurrentProcessId());
    return 0;
}
