
#include "string_message.h"
#include "../../lib/emalloc.h"
#include "session_storage.h"

message * message_create(int fd, char * str) {
    message * new_m = emalloc(sizeof (message));

    new_m->content = clone_str(str);
    new_m->fd = fd;

    return new_m;
}

message_with_frame_len * message_create_with_frame_len(int fd, char * str) {
    message_with_frame_len * new_m = emalloc(sizeof (message_with_frame_len));

    size_t len = strlen(str);
    if(fd>0){ 
        if(session_is_encoded(fd)) { // calculate websocket message frame length
            int header_len = 0;
            if (len < 126) header_len = 2;
            else if (len < 65536) header_len = 4;
            else header_len = 10;
            len+=header_len;
        } 
        len+=1; // stomp message ends with \0
        
    }
    new_m->content = clone_str_len(str, len);
    new_m->fd = fd;
    new_m->frame_len = len;

    return new_m;
}

void message_destroy(message * m) {
    free(m->content);
    free(m);
}

void message_wl_destroy(message_with_frame_len *m){
    free(m->content);
    m->content=NULL;
    free(m);
}