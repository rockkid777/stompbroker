/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.h
 * Author: peter
 *
 * Created on December 30, 2018, 9:11 PM
 */

#ifndef BUFFER_H
#define BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct buffer_item_t {
        int fd;
        char mask[4];
        size_t received_len;
        size_t frame_len; // total len (calculated on for the first header in the buffer)
        char* received;
    } buffer_item;

#define WS_CONTINUATION_BUFFER 1000
#define WS_MAX_BUFFER_SIZE 10000000


    void ws_init_buffer();

    void ws_deinit_buffer();

    void ws_buffer_shrink(buffer_item * buffer, size_t old_len, size_t new_len);

#ifdef __cplusplus
}
#endif

#endif /* BUFFER_H */

