/*
 * RSFS - Really Simple File System
 *
 * Copyright © 2010,2012,2019 Gustavo Maciel Dias Vieira
 * Copyright © 2010 Rodrigo Rocco Barbieri
 *
 * This file is part of RSFS.
 *
 * RSFS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "disk.h"
#include "fs.h"

#define CLUSTERSIZE 4096
#define FATCLUSTERS 65536
#define DIRENTRIES 128

unsigned short fat[FATCLUSTERS];

unsigned int formatado = 1;

typedef struct {
  char *buffer;
  int pos;
  int mode;
  unsigned short curr_block;
} file_info;

file_info info[DIRENTRIES];

typedef struct {
  char used;
  char name[25];
  unsigned short first_block;
  int size;
} dir_entry;

dir_entry dir[DIRENTRIES];

void init_info() {
  for(int i = 0; i < DIRENTRIES; i++) {
    info[i].buffer = NULL;
    info[i].mode = -1;
  }
}

void saveDS() { // salvar as estruturas de dados
  char* buffer = (char*)fat;
  
  for(int i = 0; i < sizeof(fat); i += CLUSTERSIZE) {
    bl_write(i/CLUSTERSIZE, &buffer[i]);
  }

  bl_write(32, (char*)dir);
}

int fs_init() {

  init_info();

  char *bytes = (char *)fat;

  for(int i = 0; i < sizeof(fat); i += CLUSTERSIZE) {
    bl_read(i/CLUSTERSIZE, &bytes[i]);
  }

  bl_read(32, (char*)dir);

  for(int i = 0; i < 32; i++) {
    if(fat[i] != 3) {
      printf("Disco nao formatado.\n");
      formatado = 0;
      break;
    }
  }

  if(formatado)
    printf("Disco ja formatado.\n");
  
  return 1;
}

int fs_format() {
  int i;
  for(i = 0; i < 32; i++)
    fat[i] = 3;
  
  fat[i++] = 4;

  for(; i < bl_size(); i++)
    fat[i] = 1;

  for(i = 0; i < DIRENTRIES; i++)
    dir[i].used = 0;

  saveDS();

  formatado = 1;

  return 1;
}

int fs_free() {
  int sectorNum = bl_size();
  int sum = 0;

  for(int i = 33; i < sectorNum; i++) {
    if(fat[i] == 1)
      sum += SECTORSIZE;
  }

  return sum;
}

int fs_list(char *buffer, int size) {
  if(!formatado) {
    printf("Formate o disco para iniciar o uso.\n");
    return 0;
  }

  buffer[0] = '\0';

  char num[20];
  for(int i = 0; i < DIRENTRIES; i++) {
    if(dir[i].used == 1) {
      strcat(buffer, dir[i].name);
      strcat(buffer, "\t\t");
      sprintf(num, "%d", dir[i].size);
      strcat(buffer, num);
      strcat(buffer, "\n");
    }
  }

  return 1;
}

int fs_create(char* file_name) {
  if(!formatado) {
    printf("Formate o disco para iniciar o uso.\n");
    return 0;
  }

  int dirIndex = -1;

  for(int i = 0; i < DIRENTRIES; i++) {
    if(dir[i].used == 1 && strcmp(dir[i].name, file_name) == 0) {
      printf("Arquivo com nome ja existente.\n");
      return 0;
    }
    if(dir[i].used == 0 && dirIndex == -1) {
      dirIndex = i;
    }
  }

  if(dirIndex == -1)
    return 0;

  for(int i = 33; i < bl_size(); i++) {
    if(fat[i] == 1) {
      fat[i] = 2;
      dir[dirIndex].used = 1;
      strcpy(dir[dirIndex].name, file_name);
      dir[dirIndex].size = 0;
      dir[dirIndex].first_block = i;
      saveDS();
      printf("Arquivo criado.\n");
      return 1;
    }
  }

  return 0;
}

int fs_remove(char *file_name) {
  if(!formatado) {
    printf("Formate o disco para iniciar o uso.\n");
    return 0;
  }

  for(int i = 0; i < DIRENTRIES; i++) {

    if(dir[i].used == 1 && !strcmp(dir[i].name, file_name)) {
      int fatIndex = dir[i].first_block;

      do {
        int next = fat[fatIndex];
        fat[fatIndex] = 1;
        fatIndex = next;
      }while(fatIndex != 2);

      dir[i].name[0] = '\0';
      dir[i].used = 0;
      saveDS();
      printf("Arquivo removido.\n");
      return 1;

    }

  }

  return 0;
}

int fs_open(char *file_name, int mode) {
  int existe = -1;

  for(int i = 0; i < DIRENTRIES; i++) {
    if(dir[i].used == 1 && strcmp(file_name, dir[i].name) == 0) {
      existe = i;
    }
  }
  
  if(existe == -1 && mode == FS_R)
    return -1;

  if(existe == -1 && mode == FS_W) {
    fs_create(file_name);
  }

  if(existe != -1 && mode == FS_W) {
    fs_remove(file_name);
    fs_create(file_name);
  }

  for(int i = 0; i < DIRENTRIES; i++) {
    if(dir[i].used == 1 && strcmp(file_name, dir[i].name) == 0) {
      existe = i;
    }
  }

  info[existe].buffer = (char*)malloc(sizeof(char)*SECTORSIZE);
  info[existe].mode = mode;
  info[existe].pos = 0;

  return existe;
}

int fs_close(int file)  {
  if(info[file].buffer == NULL)
    return 0;

  bl_write(info[file].curr_block, info[file].buffer);

  free(info[file].buffer);
  info[file].buffer = NULL;

  dir[file].size = info[file].pos;

  saveDS();

  return 1;
}

int fs_write(char *buffer, int size, int file) {
  if(info[file].buffer == NULL || info[file].mode == FS_R) {
    return -1;
  }

  if(info[file].pos == 0) {
    info[file].curr_block = dir[file].first_block;
  }

  for(int i = 0; i < size; i++) {
    info[file].buffer[info[file].pos % SECTORSIZE] = buffer[i];
    info[file].pos++;

    if(info[file].pos > 0 && info[file].pos % SECTORSIZE == 0) {
      bl_write(info[file].curr_block, info[file].buffer);
      info[file].buffer[0] = 42;
      printf("Salvando bloco %d\n", info[file].curr_block);

      unsigned short j;
      for(j = 33; j < bl_size(); j++) {
        if(fat[j] == 1) {
          fat[info[file].curr_block] = j;
          fat[j] = 2;
          info[file].curr_block = j;
          break;
        }
      }
      if(j == bl_size()) {
        printf("Tamanho do arquivo copiado maior que o livre.\n");
        // remover arquivo?
        return 0;
      }

    }
  }

  saveDS();
  return size;
}

int fs_read(char *buffer, int size, int file) {
  if(info[file].buffer == NULL || info[file].mode == FS_W) {
    return -1;
  }

  if(info[file].pos == 0) {
    info[file].curr_block = dir[file].first_block;
    bl_read(info[file].curr_block, info[file].buffer);
  }
    
  int i = 0;
  for(i = 0; i < size; i++) {
    if(info[file].pos == dir[file].size)
      return i;
      
    buffer[i] = info[file].buffer[info[file].pos % SECTORSIZE];
    info[file].pos++;

    if(info[file].pos > 0 && info[file].pos % SECTORSIZE == 0) {
      info[file].curr_block = fat[info[file].curr_block];
      bl_read(info[file].curr_block, info[file].buffer);

    }

  }

  return i;
}