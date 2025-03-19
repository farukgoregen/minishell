// void quotes(t_input *input)
// {
//     int i;

//     i = -1;
//     empty_line(input);
//     if (input->isdigit == 0)
//     {
//         input->error = 1;
//         return;
//     }
//     while (input->input[++i])
//     {
//         if (input->input[i] == 34)
//         {
//             input->quotes++;
//             i++;
//             while (input->input[i] != 34 && input->input[i] != '\0')
//                 i++;
//             if (input->input[i] == 34)
//                 input->quotes++;
//         }
//         if (input->input[i] == 39)
//         {
//             input->quotes++;
//             i++;
//             while (input->input[i] != 39 && input->input[i] != '\0')
//                 i++;
//             if (input->input[i] == 39)
//                 input->quotes++;
//         }
//     }
//     if (input->quotes%2!=0)
//         input->error=1;
// }


#include <stdio.h>
// #include <unistd.h>
// # include <sys/time.h>

// # include <pthread.h>
// unsigned long	get_ms(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_usec / 100 + tv.tv_sec * 100);
// }

// int main()
// {
//     int pid;
//     unsigned long time;
//     time = get_ms();
//     pid=fork();
    

//     if(pid==0)
//     {
//         printf("%lu\n",get_ms() - time);
//         printf("bu ilk çalışacak\n");
//     }
//     else
//     {
//         usleep(500);
//         printf("%lu\n",get_ms() - time);
//         printf("bu ikinci çalışacak\n");
//     }
        
// } 