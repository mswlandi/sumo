/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2022 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GUIPostDrawing.cpp
/// @author  Pablo Alvarez Lopez
/// @date    Jun 22
///
// Operations that must be applied after drawGL()
/****************************************************************************/
#include <config.h>

#include "GUIPostDrawing.h"


GUIPostDrawing::GUIPostDrawing() {}


void
GUIPostDrawing::executePostDrawingTasks() {
    // reset recompute boundaries
    recomputeBoundaries = GLO_NETWORK;
    // udate AC geometries
    for (const auto& GLObject : myGLObjectsToUpdate) {
        GLObject->updateGLObject();
    }
    myGLObjectsToUpdate.clear();
    // reset marked elements
    markedNode = nullptr;
    markedEdge = nullptr;
    markedLane = nullptr;
    markedTAZ = nullptr;
    markedRoute = nullptr;
}


void
GUIPostDrawing::markGLObjectToUpdate(GUIGlObject* GLObject) {
    if (GLObject) {
        myGLObjectsToUpdate.push_back(GLObject);
    }
}

/****************************************************************************/
