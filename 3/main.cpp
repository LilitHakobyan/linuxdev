#include <sys/wait.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string>
#include <cerrno>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <fcntl.h>

std::vector<std::string> split(const char* s, const char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);

   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }

   return tokens;
}

int main(){

    while(true)
    {
            std::cout << "Shell is waiting..." << std::endl;

            std::string command;
            getline(std::cin, command); 

            // get program name and args
            std::vector<std::string> parts = split(command.c_str(), ' ');

            // extra room for sentinel
            const char** argv = new const char* [parts.size() + 1];   

            // copy args
            for(int i = 0; i < parts.size(); ++i)
            {
                argv[i] = parts[i].c_str();
            }

            argv[parts.size() + 1] = NULL;

            // create process
            pid_t child = fork();

            // exit on failure
            if(child == -1)
            {
             std::cout << "child -1"  << std::endl;
                exit(errno);
            }

            if(child == 0)
            {
                std::cout << "child"  << std::endl;
                const char* outPath = "/opt/silentshell/out.std";
                const char* inPath = "/opt/silentshell/in.std";

                // close standart input and output
                close(0);
                close(1);

                // open our input and output
                int out = open(outPath,O_WRONLY | O_CREAT);
                int in = open(inPath, O_RDONLY | O_CREAT);

                std::cout << "Out path" <<  out << std::endl;
                std::cout << "In path" << in << std::endl;

                execv(argv[0], (char **)argv);
                exit(0);
            }
            else
            {
               std::cout << "else"  << std::endl;
                // waiting for child
                int status = -1;
                waitpid(child, &status, 0);
            }
    
    }
}
