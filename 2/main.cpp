#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <iostream>

int main(int argc, char** argv) 
{
    if(argc < 3)
    {
        std::cout << "Files are not given by arguments." << std::endl;
        exit(1);
    }

    char* src = argv[1];
    char* dest = argv[2];

    // open source file
    int f_read  = open(src, O_RDONLY);
    if(f_read  == -1)
    {
        std::cout << "Could not open source file." << std::endl;
        exit(errno);
    }

    // calculate logical size of source
    off_t srcLogSize = lseek(f_read , 0, SEEK_END);
    std::cout << "Source file logical size - " << srcLogSize << std::endl;
    lseek(f_read , 0, SEEK_SET);

   
    // calculate physical size of source
    long srcPhysSize = 0;
    int f_write = open(dest, O_WRONLY | O_CREAT);
   
    while (true)
    {
        // getting current position 
        off_t readCurrent =  lseek(f_read , 0, SEEK_CUR);

        std::cout << "Current - " << readCurrent << std::endl;
        // getting data postion from current
        off_t offsetData = lseek(f_read , 0, SEEK_DATA);

        std::cout << "offsetData - " << offsetData << std::endl;
        // seting again to current postion
        lseek(f_read , readCurrent, SEEK_SET);

        // getting next hole postion 
        off_t offsetHole = lseek(f_read , 0, SEEK_HOLE);

        std::cout << "offsetHole - " << offsetHole << std::endl;

        // end of file
        if(offsetData == srcLogSize || offsetHole == srcLogSize){
            break;
        }

        // setting cueent postion
        lseek(f_read , readCurrent, SEEK_SET);

        // when current is a hole
        if(readCurrent == offsetHole){
            lseek(f_write , offsetData - offsetHole, SEEK_CUR);
            lseek(f_read , 0, SEEK_DATA);
            std::cout << "when current is a hole - "  << std::endl;
        }
        else { // when current is a data
            int bufferSize = offsetHole - offsetData;
            char* buffer = new char[bufferSize];
            int readBytes = read(f_read, buffer, bufferSize);
            write(f_write, buffer, bufferSize);

        std::cout << "bufferSize - " << bufferSize << std::endl;
            srcPhysSize += bufferSize;
        }
    }

    std::cout << "Physical Size of files- " << srcPhysSize << std::endl;

    close(f_write);
    close(f_read);

    return 0;
}