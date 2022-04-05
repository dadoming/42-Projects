#include <unistd.h> //fork function
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>


/*

###  FORK  ###

int main(void)
{
    fork();    
    printf("hello world, id: %d\n", id);
    return 0;
}

OUTPUT:
hello world
hello world

Isto acontence porque quando se exxecuta a função
fork, a execution line é dividida em 2.
É chamada a criação do child process.
Isto faz com que estejam a correr dois processos. O
que se criou normalmente (parent) e o novo (fork)(child).

    child \  | parent
           \ |
            \|
             |
             |
             |

________________________________
Return values:

int main(void)
{
    int id;

    id = fork();
    printf("hello world, id: %d\n", id);
    return 0;
}

OUTPUT:

hello world, id: 0
hello world, id: 900

Tudo antes da linha de execução da função fork vai
ser apenas executado uma vez, mas assim que executa,
tudo vai ser executado duas vezes por processo.

O id do child process vai ser sempre 0.
Se não for zero, não vai ser o child.

OU SEJA:

int main(void)
{
    int id;

    id = fork();
    printf("hello world, id = %d\n", id);
    if(id == 0)
        printf("Hello from child, id = %d\n", id);
    else
        printf("Hello from parent, id = %d\n", id);
    return 0;
}

OUTPUT:

hello world, id = 1421
Hello from parent, id = 1421
hello world, id = 0
Hello from child, id = 0

Neste caso não há influência na ordem.
(Estudar melhor esta parte)
_______________________________________


int main(void)
{
    fork();
    fork();
    printf("hello world\n");
    return 0;
}

OUTPUT:
hello world
hello world
hello world
hello world

Quando se executam multiplas vezes a funçao fork,
iremos ter 2^n (sendo n a quantidade de vezes que 
se executou a função) vezes a realização da ação. 

CHAMANDO FORK MÚLTIPLAS VEZES:
Isto é o que acontece quando a função fork é chamada
duas veszes:
id1 = fork();
id2 = fork();

        ---------
        | id1=x |--------
        | id2=z |       |
        ---------       |
           |            |
        ---------    ---------
      x | id1=0 |    | id1=x | z
        | id2=y |    | id2=0 |
        ---------    ---------
           |
        ---------
      y | id1=0 |
        | id2=0 |
        ---------

int main(void)
{
    int id1;
    int id2;

    id1 = fork();
    id2 = fork();
    if(id1 == 0)
    {
        if(id2 == 0)
            printf("We are process y\n");
        else
            printf("We are process x\n");
    }
    else
        if(id2 == 0)
            printf("We are process z\n");
        else
            printf("We are parent process\n");
    while (wait(NULL) != -1 || errno != ECHILD)
        printf("Waited for a child to finish\n");
    return 0;
}

OUTPUT:

We are parent process
We are process z
We are process x
We are process y
Waited for a child to finish
Waited for a child to finish
Waited for a child to finish


__
E se for chamada dentro de um dos processos:

int main(void)
{
    int id;

    id = fork();
    if(id != 0)
        fork();    
    printf("Hello World\n");
    return 0;
}

Hello World
Hello World
Hello World

         \   |  /
          \  | /
           \ |/
            \|
             |
             |


int main(void)
{
    int id;
    int n;
    int i = 1;

    id = fork();
    if(id == 0)
        n = 1;
    else 
        n = 6;    
    i = n;
    while(i++ < (n + 5))
    {
        printf("%d ", i);
        fflush(stdout); //função para fazer com que
                        //venha na ordem certa
    }
    printf("\n");
    return 0;
}

OUTPUT: 
Supostamente seria: 1 6 2 7 3 8 4 9 5 10
(
No WSL printou: 
6 7 8 9 10
1 2 3 4 5
)
Notar que há um padrão de filho e a seguir pai.
A ordem é ditada pelo sistema operativo.

WAIT FUNCTION

Tal como o nome diz, a função wait serve para fazer
esperar o processo que queremos fazer esperar.
Neste caso:

int main(void)
{
    int id;
    int n;
    int i = 1;

    id = fork();
    if(id == 0)
        n = 1;
    else 
        n = 6;    
    i = n;
    if(id != 0)
        wait();
    while(i < (n + 5))
    {
        printf("%d ", i);
        fflush(stdout);
        i++;
    }
    printf("\n");
    return 0;
}

OUTPUT:
1 2 3 4 5
6 7 8 9 10

E se trocarmos o if para if(id == 0) então:
6 7 8 9 10
1 2 3 4 5


### id ###

pid_t is usually an integer

pid_t getpid(void)
Get the process ID of the calling process.

pid_t getppid(void)
Get the process ID of the calling process's parent.

int main(void)
{
    int id = fork();
    printf("Current process id: %d, parent id: %d\n", getpid(), getppid());
    return 0;
}

OUTPUT:

Current process id: 21973, parent id: 10
Current process id: 21974, parent id: 21973

For every process there is always an id. There needs to be
something before starting anything.






Em colocando o child process a dormir por um segundo, vai fazer com que o main process
acabe primeiro e o será dado ao child process um novo parent ID.

int main(void)
{
    int id = fork();
    if(id == 0)
        sleep(1);
    printf("Current process id: %d, parent id: %d\n", getpid(), getppid());
    return 0;
}

OUTPUT:
Current process id: 23074, parent id: 10
dadoming@DESKTOP-RL833RI:~/pipex$ Current process id: 23075, parent id: 9

Para obter o output correto dando o parent id ao child process 
e para não haver memória perdida, inserir:
    if(id != 0)
        wait(NULL);
Assim, o output será:
dadoming@DESKTOP-RL833RI:~/pipex$ ./a.out
Current process id: 23581, parent id: 10
Current process id: 23582, parent id: 23581

Quando wait não tem de esperar por nada retorna -1.

int main(void)
{
    int id = fork();
    if(id == 0)
        sleep(1);
    printf("Current process id: %d, parent id: %d\n", getpid(), getppid());
    int res = wait(NULL);
    if(res == -1)
        printf("No children to wait for.\n");
    else
        printf("%d Finished execution.\n", res);    
    return 0;
}

OUTPUT:
Current process id: 24205, parent id: 10
Current process id: 24206, parent id: 24205
No children to wait for.
24206 Finished execution.

### PIPE ###

https://www.youtube.com/watch?v=Mqb2dVRe0uo

int pipe(int *__pipedes)
Create a one-way communication channel (pipe).
If successful, two file descriptors are stored in PIPEDES;
bytes written on PIPEDES[1] can be read from PIPEDES[0].
Returns 0 if successful, -1 if not.

Um pipe é basicamente um in-memory file com habilidade de dar 
write ou read.

fd[2] porque um pipe tem sempre uma entrada e saída.
fd[0] - read
fd[1] - write 


int main(void)
{
    int fd[2];
    int id;
    int x;
    int y;

    if(pipe(fd) == -1)
        printf("Ocorreu um erro a abrir o pipe\n");
    id = fork();
    if(id == -1)
    {
        printf("An error ocurred with fork\n");
        return 4;
    }
    if(id == 0)
    {
        close(fd[0]);
        printf("Input a number: ");
        scanf("%d", &x);  
        if(write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("Ocorreu um erro a escrever no pipe.\n");
            return 2;
        }
        close(fd[1]); //  isto faz com que se tire a possibilidade de se
                      //  escrever texto adicional neste file descriptor
    }
    else 
    {
        close(fd[1]);
        if(read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("Ocorreu um erro a ler do pipe.\n");
            return 3;
        }
        close(fd[0]);
        printf("Got from child process %d\n", y);
    }
    return 0;
}

OUTPUT:
Input a number: 10
Got from child process 10



COMO COMUNICAR ENTRE PIPES

pipe1[2]
pipe2[2]

              PARENT                               CHILD

              WRITE-> |-------------------------| <- [X] WRITE [X]
                      |         PIPE 1          |
      [X] READ [X] <- |-------------------------| -> READ
      


     [X] WRITE [X] -> |-------------------------| <- WRITE
                      |         PIPE 2          |
              READ <- |-------------------------| -> [X] READ [X]
     


int main(void)
{
    // 5 => 5 * 4 = 20 => 20
    int p1[2]; // C => P
    int p2[2]; // P => C
    int pid;
    int x;
    int y;

    if(pipe(p1) == -1)  
        return 1;
    if(pipe(p2) == -1)  
        return 1;
    pid = fork();
    if(pid == -1)   
        return 2;
    if (pid == 0){
        //Child
        close(p1[0]);
        close(p2[1]);
        if(read(p2[0], &x, sizeof(x) == -1))    
            return 3;
        printf("received %d\n", x);
        x *= 4;
        if(write(p1[1], &x, sizeof(x)) == -1)   
            return 4;
        printf("child wrote %d\n", x);
        close(p1[1]);
        close(p2[0]);
    }
    else{
        //parent
        close(p1[1]);
        close(p2[0]);
        srand(time(NULL));
        y = rand() % 10; //para dar random algarismo entre 1 e 10
        if(write(p2[1], &y, sizeof(y)) == -1)   
            return 5;
        printf("parent wrote %d\n", y);
        if(read(p1[0], &y, sizeof(y)) == -1)    
            return 6;
        printf("result is: %d\n", y);
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }
    return 0;
}

OUTPUT:
Deu mal, testar em mac que no wsl foi buscar valores de pid?



_______________________________________________________________
*/          


int main(void)
{
    // 5 => 5 * 4 = 20 => 20
    int p1[2]; // C => P
    int p2[2]; // P => C
    int pid;
    int x;
    int y;

    if(pipe(p1) == -1)  
        return 1;
    if(pipe(p2) == -1)  
        return 1;
    pid = fork();
    if(pid == -1)   
        return 2;
    if (pid == 0){
        //Child
        close(p1[0]);
        close(p2[1]);
        if(read(p2[0], &x, sizeof(x) == -1))    
            return 3;
        printf("received %d\n", x);
        x *= 4;
        if(write(p1[1], &x, sizeof(x)) == -1)   
            return 4;
        printf("child wrote %d\n", x);
        close(p1[1]);
        close(p2[0]);
    }
    else{
        //parent
        close(p1[1]);
        close(p2[0]);
        srand(time(NULL));
        y = rand() % 10; //para dar random algarismo entre 1 e 10
        if(write(p2[1], &y, sizeof(y)) == -1)   
            return 5;
        printf("parent wrote %d\n", y);
        if(read(p1[0], &y, sizeof(y)) == -1)    
            return 6;
        printf("result is: %d\n", y);
        close(p1[0]);
        close(p2[1]);
        wait(NULL);
    }
    return 0;
}

