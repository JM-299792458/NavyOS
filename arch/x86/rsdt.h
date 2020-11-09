/*
 * Copyright (C) 2020 Jordan DALCQ & contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _NAVY_x86_RSDT_H_
#define _NAVY_x86_RSDT_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct ACPISDTHeader
{
    char Signature[4];
    uint32_t Length;
    uint8_t Revision;
    uint8_t Checksum;
    char OEMID[6];
    char OEMTableID[8];
    uint32_t OEMRevision;
    uint32_t CreatorID;
    uint32_t CreatorRevision;
} __attribute__((packed));

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic" 
struct RSDT
{
    struct ACPISDTHeader h;
    uintptr_t PointerToOtherSDT[];
};

#pragma GCC diagnostic pop

bool rsdt_checksum(struct ACPISDTHeader *);
void *find_SDT(void *, char *);

#endif
