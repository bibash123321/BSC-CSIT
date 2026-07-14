#include <stdio.h>
#include <windows.h>

DWORD WINAPI thread_func(LPVOID arg) {
    int id = *(int*)arg;
    printf("Thread %d running\n", id);
    return 0;
}

int main() {
    HANDLE threads[3];
    int ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        threads[i] = CreateThread(
            NULL,
            0,
            thread_func,
            &ids[i],
            0,
            NULL
        );
        if (threads[i] == NULL) {
            fprintf(stderr, "Failed to create thread %d\n", ids[i]);
            return 1;
        }
    }

    WaitForMultipleObjects(3, threads, TRUE, INFINITE);

    for (int i = 0; i < 3; i++) {
        CloseHandle(threads[i]);
    }

    return 0;
}
