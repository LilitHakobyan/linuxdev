#include <sys/wait.h>
#include <iostream> 
#include <unistd.h> 
#include <stdlib.h>
#include <cerrno>


#define READ_END 0
#define WRITE_END 1

int main(){

    int arrayCapacity = 500;
    int workersCount = 2;

    int* array = new int[arrayCapacity];
    pid_t* workers = new pid_t[workersCount];
    
    

    // fill array with random numbers
    for(int i = 0; i < arrayCapacity; ++i)
    {
        array[i] = rand() % 2;
        std::cout <<  array[i] << " ";
    }

    int pipeResult;

    int** parentChildFileDes = new int*[workersCount];
    int** childParentFileDes = new int*[workersCount];
    
    // create two pipes for each worker
    for(int i = 0; i < workersCount; ++i)
    {
        childParentFileDes[i] = new int[2];
        parentChildFileDes[i] = new int[2];
        pipeResult = pipe(parentChildFileDes[i]);

        // exit on failure
        if(pipeResult == -1)
        {
            exit(errno);
        }

        pipeResult = pipe(childParentFileDes[i]);

        // exit on failure
        if(pipeResult == -1)
        {
            exit(errno);
        }
    }

    int factor = arrayCapacity / workersCount;

    for(int i = 0; i < workersCount; ++i)
    {
       // create a process
       workers[i] = fork();

        // exit on failure
        if(workers[i] == -1)
        {
            exit(errno);
        }

        if(workers[i] == 0)
        {
            int pid = i;

            // close write end of parent to child pipe
            close(parentChildFileDes[pid][WRITE_END]);

            // close read end of child to parent pipe
            close(childParentFileDes[pid][READ_END]);

            int from;
            int to;
            int sum = 0;
            
            // read 'from' and 'to' from parent to child pipe
            read(parentChildFileDes[pid][READ_END], &from, sizeof(from));
            read(parentChildFileDes[pid][READ_END], &to, sizeof(to));

            // calculate sum
            for(int j = from; j < to; ++j)
            {
                sum += array[j];
            }

            // print sum
            std::cout << "Sum from " << from << " to " << to << " is " << sum << std::endl;

            // send sum to parent
            write(childParentFileDes[pid][WRITE_END], &sum, sizeof(sum)); 

            exit(0);
        }
        else
        {
            // close read end of parent to child pipe
            close(parentChildFileDes[i][READ_END]);

            // close write end of child to parent pipe
            close(childParentFileDes[i][WRITE_END]);

            int from = i * factor;
            int to = (i + 1) * factor;

            // up to end for the last element
            if(i == workersCount - 1)
            {
                to =  arrayCapacity;
            }
            
            // send 'from' and 'to' to child
            write(parentChildFileDes[i][WRITE_END], &from, sizeof(from));
            write(parentChildFileDes[i][WRITE_END], &to, sizeof(from));
        }
    }

    int total = 0;

    for(int i = 0; i < workersCount; ++i)
    {
        int sum = 0;

        // read 'sum' from child to parent pipe
        read(childParentFileDes[i][READ_END], &sum, sizeof(int));

        total += sum;
    }

    
    std::cout << "Total sum is " << total << std::endl;

    exit(0); 
}