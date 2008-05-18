/*
---------------------------------------------------------------------------
Free Asset Import Library (ASSIMP)
---------------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

#if (!defined AV_MESH_RENDERER_H_INCLUDED)
#define AV_MESH_RENDERER_H_INCLUDED


#define AI_VIEW_ALPHA_SORT_DELTA 3

//-------------------------------------------------------------------------------
/* Helper class tp render meshes
*/
//-------------------------------------------------------------------------------
class CMeshRenderer
{
private:

	// default constructor
	CMeshRenderer() 
		:	m_bRotationChanged(true),
			m_iFrameCount(AI_VIEW_ALPHA_SORT_DELTA-1)
	{
		// no other members to initialize
	}

public:

	//------------------------------------------------------------------
	// Singleton accessors
	static CMeshRenderer s_cInstance;
	inline static CMeshRenderer& Instance ()
	{
		return s_cInstance;
	}


	//------------------------------------------------------------------
	// Draw a mesh in the global mesh list using the current pipeline state
	// iIndex Index of the mesh to be drawn
	//
	// The function draws all faces in order, regardless of their distance
	int DrawUnsorted(unsigned int iIndex);

	//------------------------------------------------------------------
	// Draw a mesh in the global mesh list using the current pipeline state
	// iIndex Index of the mesh to be drawn
	//
	// The method sorts all vertices by their distance (back to front)
	//
	// mWorld World matrix for the node
	int DrawSorted(unsigned int iIndex,
		const aiMatrix4x4& mWorld);


	//------------------------------------------------------------------
	// Indicate that the rotation of the object or the camera has
	// been changed, thus the alpha order tree must be updated
	inline void SetRotationChangedFlag()
	{
		this->m_bRotationChanged = true;
	}

	//------------------------------------------------------------------
	// Reset the state of the class
	// Called whenever a new asset is loaded
	inline void Reset()
	{
		this->m_bRotationChanged = true;
		this->m_iFrameCount = 2;
	}

	//------------------------------------------------------------------
	// Called at the beginning of the frame. Reset the state
	// of the instance
	inline void OnBeginFrame()
	{
		if (0 == this->m_iFrameCount)
		{
			this->m_bRotationChanged = false;
		}
	}

private:

	// true if the rotation of the object or camera has changed
	// in the last frame. If there were no changes it should
	// not be necessary to update the alpha ordering tree
	bool m_bRotationChanged;

	// only update the alpha order each AI_VIEW_ALPHA_SORT_DELTA frames
	unsigned int m_iFrameCount;
};

#endif //!! include guard