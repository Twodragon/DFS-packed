//
// Created by Сергей Ефимочкин on 18.04.2018.
//

#ifndef FS_BLOCK_H
#define FS_BLOCK_H

#include "superblock.h"

struct block{
    char *data;
    unsigned int number_of_block;
};

typedef
struct FS_Handler
        FS_Handler;


int get_number_of_address_blocks(struct superblock *sb, int number_of_adresses);
unsigned int put_data_in_blocks(struct superblock *sb, char* data, int size_of_data, FS_Handler *fs_handler);
char* read_data_in_blocks(struct superblock *sb, struct block* address_blocks, int size_of_data);
void free_data_in_blocks(struct superblock *sb, struct block* address_blocks, int size_of_data, short is_inodes, FS_Handler *fs_handler);

#endif //FS_BLOCK_H
