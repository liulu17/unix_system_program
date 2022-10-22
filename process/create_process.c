//
// Created by Apple on 2022/10/23.
//
#include <unistd.h>
#include <stdio.h>
#include "create_process.h"
int main() {
     pid_t p1 = fork();
     if (p1 == 0) {
         printf("this is father process!\n");
     } else {
         printf("this is child process!\n");
     }
     return 0;
}
