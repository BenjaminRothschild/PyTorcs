/***************************************************************************

    file                 : simuitf.cpp
    created              : Sun Mar 19 00:08:04 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: simuitf.cpp,v 1.7 2005/03/31 16:01:01 olethros Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <stdlib.h>

#include "tgf/tgf.h"

#include "sim.h"
#include "locale.h"

#ifdef _WIN32
BOOL WINAPI DllEntryPoint (HINSTANCE hDLL, DWORD dwReason, LPVOID Reserved)
{
    return TRUE;
}
#endif

/*
 * Function
 *	simuInit
 *
 * Description
 *	init the simu functions
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
extern "C" void
simuv2Init(tSimItf *sim)
{
    sim->init     = SimInit;
    sim->config   = SimConfig;
    sim->reconfig = SimReConfig;
    sim->update   = SimUpdate;
    sim->shutdown = SimShutdown;
}


/*
 * Function
 *	simuv1
 *
 * Description
 *	DLL entry point
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
extern "C" void simuv2(tModInfo *modInfo)
{
    modInfo->name = "simu";		/* name of the module (short) */
    modInfo->desc = "Simulation Engine V2.0";	/* description of the module (can be long) */
    modInfo->gfId = SIM_IDENT;		/* ident */
    modInfo->index = 0;
    setlocale(LC_ALL, "C");
}



