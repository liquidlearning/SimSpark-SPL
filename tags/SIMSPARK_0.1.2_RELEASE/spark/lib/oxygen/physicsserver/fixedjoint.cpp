/* -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil -*-
   this file is part of rcssserver3D
   Fri May 9 2003
   Copyright (C) 2003 Koblenz University
   $Id$

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include "fixedjoint.h"
#include <zeitgeist/logserver/logserver.h>

using namespace oxygen;
using namespace boost;
using namespace salt;

FixedJoint::FixedJoint() : Joint()
{
}

FixedJoint::~FixedJoint()
{
}

void FixedJoint::OnLink()
{
    dWorldID world = GetWorldID();
    if (world == 0)
        {
            return;
        }

    mODEJoint = dJointCreateFixed(world, 0);
}

void FixedJoint::SetParameter(int /*parameter*/, float /*value*/)
{
    // no ode set param fkt. defined
}

float FixedJoint::GetParameter(int /*parameter*/) const
{
    // no ode get param fkt. defined
    return 0;
}

void FixedJoint::SetFixed()
{
    dJointSetFixed(mODEJoint);
}

