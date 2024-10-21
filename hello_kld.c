#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/module.h>
#include <sys/systm.h>

static int hello_loader(struct module *m, int event, void *arg)
{
    switch(event)
    {
        case MOD_LOAD:
            uprintf("hello_kld - Hello World\n");
            break;
        case MOD_UNLOAD:
            uprintf("hello_kld - Goodbye, Kernel\n");
            break;
        default:
            return EOPNOTSUPP;
    }
    return 0;
}

static moduledata_t hello_mod = {
    "Hello World Kernel Module",
    hello_loader,
    NULL,
};

DECLARE_MODULE(hello_world, hello_mod, SI_SUB_KLD, SI_ORDER_ANY);

