

/* 
 * File:   message.h
 * Author: peter
 *
 * Created on December 20, 2018, 3:04 PM
 */

#ifndef STRING_MESSAGE_H
#define STRING_MESSAGE_H

#ifdef __cplusplus
extern "C" {
#endif

 typedef struct msg_st {
        int fd;
        char * content;
    } message;


    message * message_create(int fd, char * str);
    
    void message_destroy(message * m);
#ifdef __cplusplus
}
#endif

#endif /* STRING_MESSAGE_H */
