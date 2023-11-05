//
// Created by quicklybly on 11/5/23.
//

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

char const usage[] = "usage: prntxt -n|--number <N> [-t|--timeout [<T>]] -- <TEXT>";

int cast_incorrect(char const *str, char const *convert_err_ptr, char *param_name) {
    if (convert_err_ptr == str) {
        printf("%s\n", usage);
        printf("%s argument not provided or not an actual number", param_name);
        convert_err_ptr = NULL;
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    int timeout = 0;
    int repeat_times = 0;
    char *convert_err_ptr;

    struct option longopts[] = {
            {
                .name = "number",
                .has_arg = required_argument,
                .flag = NULL,
                .val = 'n'
            },{
                .name = "timeout",
                .has_arg = optional_argument,
                .flag = NULL,
                .val = 't'
            },
            {}
    };

    int c;
    while ((c = getopt_long(argc, argv, "n:t::", longopts, NULL)) != -1) {
        switch (c) {
            case 'n':
                repeat_times = (int) strtol(optarg, &convert_err_ptr, 10);
                if (cast_incorrect(optarg, convert_err_ptr, "number")) {
                    return 1;
                }
                break;
            case 't':
                timeout = optarg ? (int) strtol(optarg, &convert_err_ptr, 10) : 1;
                if (cast_incorrect(optarg, convert_err_ptr, "timeout")) {
                    return 1;
                }
                break;
            case '?':
            case ':':
                printf("%s", usage);
                return 1;
            default:
                // not gonna happen
                break;
        }
    }

    char *text = argv[optind];

    if (repeat_times < 0 || timeout < 0 || text == NULL || text[0] == '\0') {
        printf("%s\n", usage);
        printf("number and timeout should be equal or greater than 0");
        return 1;
    }

    while (repeat_times--) {
        printf("%s\n", text);
        sleep(timeout);
    }

    return 0;
}