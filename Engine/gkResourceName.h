/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2013 harkon.kr

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/

#ifndef _gkResourceName_h_
#define _gkResourceName_h_

class gkResourceName
{
public:
	gkResourceNameString name;
	gkResourceNameString group;

	gkResourceName() {}
	gkResourceName(const char* inName, const char* inGroup="") : name(inName), group(inGroup) {}
	gkResourceName(const gkString& inName, const gkString& inGroup="") : name(inName), group(inGroup) {}
	gkResourceName(const gkHashedString& inName, const gkHashedString& inGroup="") : name(inName), group(inGroup) {}

	GK_INLINE const gkString& getName() const  { return name.str();  }
	GK_INLINE const gkString& getGroup() const { return group.str(); }

	GK_INLINE const gkString  getFullName() const { return group.str() + name.str(); }

	GK_INLINE bool operator==(const gkResourceName& other) const { return name == other.name && group == other.group; }
	GK_INLINE bool isNameEqual(const gkResourceName& other) const { return name == other.name; }
	GK_INLINE bool isGroupEqual(const gkResourceName& other) const { return group == other.group; }
	GK_INLINE bool isGroupEmpty() const { return group.str().empty(); }
};

#endif//_gkResourceName_h_