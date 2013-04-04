
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include "NWNXDefenses.h"


void Func_GetBaseSaveBonus (CGameObject *ob, char *value) {
    int val = 0;
    const CNWSCreature *cre;

    if (ob == NULL                                    ||
        (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
        cre->cre_stats == NULL                        ||
        (val = atoi(value)) < 1 || val > 3) {

        snprintf(value, strlen(value), "0");
        return;
    }

    switch (val) {
        case 1:  val = CNWSCreatureStats__GetFortSavingThrow(cre->cre_stats, 1);    break;
        case 2:  val = CNWSCreatureStats__GetReflexSavingThrow(cre->cre_stats, 1);  break;
        default: val = CNWSCreatureStats__GetWillSavingThrow(cre->cre_stats, 1);    break;
    }

    snprintf(value, strlen(value), "%d", val);
}


/* vim: set sw=4: */