#include "stomp.h"
#include "../logger.h"
#include <sys/socket.h>

#include "../../lib/thread_safe_queue.h"


void doStomp(ts_queue* output_queue, message *input) {
    
    
    //strncmp(,input->content)
    
    //message * echo = message_create(input->fd,input->content,strlen(input->content));
    
    message * echo = message_error(input->fd, "Invalid message!\n\0");
    
    ts_enqueue(output_queue, echo);
}