//
// Created by quicklybly on 11/13/23.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: launch <program> <file>");
        return 1;
    }

    char *child = argv[1];
    char *output = argv[2];

    pid_t pid = fork();
    if (0 == pid) {
        FILE *fp = freopen(output, "a", stdout);
        int fail = execl(child, output, NULL);
        fclose(fp);
        if (fail) return 1;
    } else if (pid < 0) {
        printf("something bad happened, just rewrite it on rust!");
        return 1;
    }
    int code;
    pid_t cpid = wait(&code);

    if (code == 256) {
        printf("Child program doesn't exist: %s\n", child);
    }
    printf("Child pid: %d, return code: %d", cpid, code);

    return 0;
}