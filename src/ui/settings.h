#ifndef SETTINGS_H
#define SETTINGS_H

#include "src/configuration.h"

typedef int (*settings_handler)(configuration_t *);

void settings_init(configuration_t *, settings_handler);

#endif //SETTINGS_H
