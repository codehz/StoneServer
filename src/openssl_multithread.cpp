#include "openssl_multithread.h"

#include <openssl/crypto.h>
#include <thread>

OpenSSLMultithreadHelper OpenSSLMultithreadHelper::instance;

OpenSSLMultithreadHelper::OpenSSLMultithreadHelper() {
    mutexes = std::vector<PThreadMutex>(CRYPTO_num_locks());
    CRYPTO_set_id_callback([]() {
        return (unsigned long) pthread_self();
    });
    CRYPTO_set_locking_callback([](int mode, int n, const char*, int) {
        if (mode & CRYPTO_LOCK)
            pthread_mutex_lock(&mutexes[n].mutex);
        else
            pthread_mutex_unlock(&mutexes[n].mutex);
    });
}