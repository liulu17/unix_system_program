//
// Created by Apple on 2022/10/23.
//

#include "copy.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include  <stdlib.h>

int main(int argc, char**argv) {
    char buff[1024];
    int in_fd,out_fd;
    if (argc < 3) {
        printf("Usage file_ops src_file dst_file\n");
    }
    char * src_file = argv[1];
    char * dst_file = argv[2];
    printf("source file is %s and dst file is %s\n",src_file,dst_file);
    in_fd = open(src_file,O_RDONLY);
    if (in_fd == -1) {
        printf("open error!\n");
    }

    int dst_open_flag = O_WRONLY|O_TRUNC|O_CREAT;
    mode_t dst_file_mode= S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    out_fd = open(dst_file,dst_open_flag,dst_file_mode);
    if (out_fd == -1) {
        printf("can't open %s\n",dst_file);
    }
    int nread;
    printf("sizeof is %lu\n",sizeof(buff));

    int read_count = 0;
    while( (nread = read(in_fd,buff,sizeof(buff))) > 0 ) {
        read_count++;
        printf("the %d time I read %d bytes\n",read_count,nread);
       if (write(out_fd,buff,nread) != nread) {
           printf("write error\n");
       }
    }
    if (nread == -1) {
        printf("error found!\n");
        exit(1);
    }
    exit(0);

}
