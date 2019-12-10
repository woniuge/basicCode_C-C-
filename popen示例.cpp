/*
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

void print_result(FILE *fp)
{
        char buf[100];

        if(!fp) {
                return;
        }
        printf("\n>>>\n");
        while(memset(buf, 0, sizeof(buf)), fgets(buf, sizeof(buf) - 1, fp) != 0 ) {
                printf("%s", buf);
        }
        printf("\n<<<\n");
}

int main(void)
{
        FILE *fp = NULL;

        while(1) {
                fp = NULL;
                fp = popen("ls", "r");
                if(!fp) {
                        perror("popen");
                        exit(EXIT_FAILURE);
                }
                print_result(fp);
                pclose(fp);
                sleep(1);
        }
}
