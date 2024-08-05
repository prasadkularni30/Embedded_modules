#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<stdio_ext.h>


#define KEY1 5555


struct shm_area {

	unsigned short rd_index;  
	unsigned short wr_index;  
	unsigned short buf_size_max; 
	char buf_area[50]; 
	unsigned int used_slot_count;

};

union semun { 
	int val;
	unsigned short *array;

};

int stat_var;

int main()
{

  char value;
  int ret,ret1,ret2shm_area,status, shm_id1,sem_id2;
  struct sembuf sb1,sb2,sb3,sb_array[3];

  unsigned short ary1[3],ary[] = { 50,1,0};  

  union semun u1;

  struct shm_area *shma ;


  shm_id1 = shmget(KEY1,sizeof(struct shm_area),IPC_CREAT|0666);
                                        
                                        
  if(shm_id1<0 && errno != EEXIST) { 

              perror("error in creating the shared memory"); exit(1);
  }

  

  sem_id2 = semget(KEY1,3,IPC_CREAT | 0600);
  if(sem_id2<0) {

                perror("error in semget");
                exit(2);
  }


  shma = shmat(shm_id1,0,0);  

  

  printf("the attached address is %p\n", shma);
  printf("the amount of shm memory used is %ld\n", sizeof(struct shm_area));
 


  printf("the actual values of the semaphores are %d, %d, %d\n", ary[0], ary[1], ary[2]); 


  u1.array = ary; 

  ret1 = semctl(sem_id2,0,SETALL,u1);
  
  if(ret1<0) { perror("error in semctl setting"); exit(4); }

  u1.array = ary1;

  ret1 = semctl(sem_id2,0,GETALL,u1);


  if(ret1<0) { perror("error in semctl getting"); exit(5); }


  printf("the actual values of the semaphores are %d, %d, %d\n",  ary1[0], ary1[1], ary1[2]); 

  
  shma->rd_index = 0; 
  shma->wr_index = 0;
  shma->buf_size_max = 50;  
  shma->used_slot_count = 0; 
  
 
 
   while(1)
   {

 
    ret = read(STDIN_FILENO,&value,1);  
   
    printf("the value is %c\n", value);
   
    sb1.sem_num = 0;  
    sb1.sem_op = -1;  
    sb1.sem_flg = 0; 
    semop(sem_id2,&sb1,1); 
    
    
    sb2.sem_num = 1; 
    sb2.sem_op = -1;
    sb2.sem_flg = 0;
    semop(sem_id2,&sb2,1); 
   
   
    if(shma->used_slot_count < shma->buf_size_max)
    {
       shma->buf_area[shma->wr_index] = value;
       shma->wr_index = (shma->wr_index+1)%shma->buf_size_max;
       shma->used_slot_count++;
    }

    
    sb_array[2].sem_num = 1;  
    sb_array[2].sem_op = +1;  
    sb_array[2].sem_flg = 0;
    
    sb_array[1].sem_num = 2; 
    sb_array[1].sem_op = +1;  
    
    sb_array[1].sem_flg = 0;
 
    

    
    semop(sem_id2,&sb_array[1],2);    

    
   }
   
   
   exit(0);

}




