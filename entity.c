
#include <stdio.h>
#include <stdlib.h>

#include "entity.h"



capacities ctList [5] = {
    {
        .name = "Scratch",
        .target = 2,
        .howMuch= 3,
        .effect = 1
    },
    {
        .name = "grawl",
        .target = 1,
        .howMuch = 1,
        .effect = 2
    },
    {
        .name = "Pound",
        .target = 2,
        .howMuch = 2,
        .effect = 1
    },
    {
        .name = "Foliage",
        .target = 1,
        .howMuch = 1,
        .effect = 4
    },
    {
        .name = "shell",
        .target = 1,
        .howMuch = 1,
        .effect = 3
    }
};

Supemon Supedex[3] = {{
    .name = "Supmander",
    .experience = 0,
    .HP = 10,
    .level = 1,
    .experience = 0,
    .atk = 1,
    .atk_base =1,
    .def =1,
    .def_base = 1,
    .evs = 1,
    .evs_base = 1,
    .acy = 2,
    .acy_base = 2,
    .speed = 1,
    .selfCapa = {{ 
        .name = "Scratch",
        .target = 2,
        .howMuch= 3,
        .effect = 1
   },
    { .name = "grawl",
        .target = 1,
        .howMuch = 1,
        .effect = 2
    }
    }},
    {
    .name = "Supasaur",
    .level = 1,
    .experience = 0,
    .HP = 9,
    .HP_max = 9,
    .atk = 1,
    .atk_base = 1,
    .def=1,
    .def_base = 1,
    .evs = 3,
    .evs_base = 3,
    .acy = 2,
    .acy_base= 2,
    .speed= 2},
    {
    .name = "Supirtle",
    .level = 1,
    .experience = 0,
    .HP = 11,
    .HP_max = 11,
    .atk = 1,
    .atk_base=1,
    .def=2,
    .def_base=2,
    .evs=2,
    .evs_base = 2,
    .acy = 1,
    .acy_base = 1,
    .speed=2
    }
    };


Objects BookOfObject [3] = {{

    .name = "Potion",
    .cost = 100,
    .power = 5,
    .effect = 1,
    .number = 1,
}
,
{
    .name = "Super Potion",
    .cost = 300,
    .power = 10,
    .effect = 1,
    .number = 1
}
,
{
    .name = "Rare candy",
    .cost = 700,
    .power = 1,//niveau ++
    .effect= 2,
    .number = 1
}
};

Player mainUser = {
    .name = "",
    .supemonList = {0},
    .curSupemon = 1,
    .Supcoins = 0,
    .objectList = {{.name = "Potion", .cost = 100, .power = 5, .effect = 1, .number = 0},
                    {.name = "Super Potion", .cost = 300, .power = 10, .effect = 1, .number = 0},
                    {.name = "Rare candy", .cost = 700, .power = 1, .effect = 2, .number = 0}
    }
};








