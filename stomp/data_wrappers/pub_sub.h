
/* 
 * File:   pub_sub.h
 * Author: peter
 *
 * Created on July 23, 2018, 3:37 PM
 */

#ifndef PUB_SUB_H
#define PUB_SUB_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct subscription_st {
        int session_id;
        char * topic_pattern;
        char * id;
    } subscription;

    void pubsub_init();
    void pubsub_dispose();

    void pubsub_subscribe(char* topic_str, int client_session_id, char* subscription);
    void pubsub_unsubscribe(char* topic_str, int client_session_id, char* subscription);

    void pubsub_remove_client(int client_session_id);

#include "../../lib/general_list.h"
    int pubsub_find_matching(char* topic_mask, general_list * matches);

    int pubsub_size();

    // For diagnostic only
    void pubsub_to_str(char* dst, size_t dst_size);

#ifdef __cplusplus
}
#endif

#endif /* PUB_SUB_H */

