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


#include "kernel/log.h"
#include "arch/x86/vga.h"
#include "arch/x86/pic.h"
#include "arch/x86/interrupt.h"

#include <macro.h>
#include <stdint.h>
#include <stdlib.h>

void 
isr_default_int(void)
{
    PIC_sendEOI();
}

void 
interrupts_handler(uint32_t esp, struct InterruptStackFrame stackframe)
{
    __unused(esp);
    __unused(stackframe);

    PIC_sendEOI();
}